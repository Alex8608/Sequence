#include <gtest/gtest.h>

#include <sequence/sequence.h>

TEST(sequenceTests, SumStubTest1) {
    // Arrange
    Sequence s(ARITHMETIC, 3, 5);
    // Act
    int r1 = s.progression_n(1);
    int r2 = s.progression_n(2);
    int r3 = s.progression_n(3);
    int r4 = s.progression_n(4);
    int r5 = s.progression_n(5);
    // Assert
    EXPECT_EQ(r1, 3);
    EXPECT_EQ(r2, 8);
    EXPECT_EQ(r3, 13);
    EXPECT_EQ(r4, 18);
    EXPECT_EQ(r5, 23);
}

TEST(sequenceTests, SumStubTest2) {
    // Arrange
    Sequence s(GEOMETRIC, 3, 5);
    // Act
    int r1 = s.progression_n(1);
    int r2 = s.progression_n(2);
    int r3 = s.progression_n(3);
    int r4 = s.progression_n(4);
    int r5 = s.progression_n(5);
    // Assert
    EXPECT_EQ(r1, 3);
    EXPECT_EQ(r2, 15);
    EXPECT_EQ(r3, 75);
    EXPECT_EQ(r4, 375);
    EXPECT_EQ(r5, 1875);
}