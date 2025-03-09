#include <cstdio>
#include <array>
#include <string>

#include <gtest/gtest.h>  // sudo apt install libgtest-dev


TEST(myTests, hello_is_runnable) {
  int result = system("./hello");
  EXPECT_EQ(result, 0);
}


TEST(myTests, hello_output_ok) {
  // Open the command for reading the output
  FILE *fp = popen("./hello", "r");

  ASSERT_NE(fp, nullptr);

  // Create a buffer to store the output
  std::array<char, 128> buffer;
  std::string result;
  // Read the output of the command and append it to the result string
  while (fgets(buffer.data(), buffer.size(), fp) != nullptr) {
    result.append(buffer.data());
  }

  // Close the pipe
  int returnCode = pclose(fp);
  EXPECT_NE(returnCode, -1) << "Failed to close the file pointer";

  EXPECT_EQ(result, "Hello, World!\n");
}


// main, not needed when linked with gtest_main
//int main(int argc, char **argv) {
//  testing::InitGoogleTest(&argc, argv);
//  return RUN_ALL_TESTS();
//}
