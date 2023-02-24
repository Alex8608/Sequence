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

TEST(sequenceTests, SumStubTest3) {
    // Arrange
    Sequence s(ARITHMETIC, 3, 5);
    // Act
    int r1 = s.sum_of_first_n_progression(1);
    int r2 = s.sum_of_first_n_progression(2);
    int r3 = s.sum_of_first_n_progression(3);
    int r4 = s.sum_of_first_n_progression(4);
    int r5 = s.sum_of_first_n_progression(5);
    // Assert
    EXPECT_EQ(r1, 3);
    EXPECT_EQ(r2, 11);
    EXPECT_EQ(r3, 24);
    EXPECT_EQ(r4, 42);
    EXPECT_EQ(r5, 65);
}

TEST(sequenceTests, SumStubTest4) {
    // Arrange
    Sequence s(GEOMETRIC, 3, 5);
    // Act
    int r1 = s.sum_of_first_n_progression(1);
    int r2 = s.sum_of_first_n_progression(2);
    int r3 = s.sum_of_first_n_progression(3);
    int r4 = s.sum_of_first_n_progression(4);
    int r5 = s.sum_of_first_n_progression(5);
    // Assert
    EXPECT_EQ(r1, 3);
    EXPECT_EQ(r2, 18);
    EXPECT_EQ(r3, 93);
    EXPECT_EQ(r4, 468);
    EXPECT_EQ(r5, 2343);
}
