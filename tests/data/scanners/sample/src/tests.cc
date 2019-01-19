#include <gtest/gtest.h>

#include "../src/sample.cc"

class SampleScannerTest : public ::testing::Test {};


char fizz[] = "fizz";
char buzz[] = "buzz";
size_t size = sizeof(fizz);

TEST_F(SampleScannerTest, Hit) {
    char fizz[] = "fizz";
    bool result = scan((unsigned char *)fizz, size, (unsigned char *)fizz, size);
    ASSERT_TRUE(result);
}

TEST_F(SampleScannerTest, UnHit) {
    bool result = scan((unsigned char *)fizz, size, (unsigned char *)buzz, size);
    ASSERT_FALSE(result);
}

int main(int argc, char **argv) {
    printf("hello");
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


