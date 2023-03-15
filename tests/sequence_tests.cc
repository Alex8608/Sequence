#include <gtest/gtest.h>
#include <sequence/sequence.h>
using namespace SEQUENCE;
TEST(sequenceTests, SumStubTest1) {
    // Arrange
    Sequence s = Sequence::create_ARITHMETIC(3, 5);
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
    Sequence s = Sequence::create_GEOMETRIC(3, 5);
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
    Sequence s = Sequence::create_ARITHMETIC(3, 5);
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
    Sequence s = Sequence::create_GEOMETRIC(3, 5);
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

TEST(sequenceTests, SumStubTest5)
{
    SequenceList mas;
    mas.add(Sequence::create_ARITHMETIC(-23, 10));
    mas.add(Sequence::create_ARITHMETIC(20, -9));
    mas.add(Sequence::create_GEOMETRIC(16, 0.5));
    mas.add(Sequence::create_GEOMETRIC(3, 2));
    mas.add(Sequence::create_ARITHMETIC(3.2, 5.1));
    int size_of_mas = mas.size();
    EXPECT_EQ(size_of_mas, 5);
    Sequence item = mas[3];
    item.print();
    mas[3] = Sequence::create_GEOMETRIC(3, 3);
    item = mas[3];
    item.print();
    mas[3].print();
    EXPECT_EQ(item.get_type(),GEOMETRIC);
    EXPECT_EQ(item.get_first_n(), 3);
    EXPECT_EQ(item.get_d_q(), 3);
    int r = mas.search(4);
    EXPECT_EQ(r, 3);
    for (int i = 0; i < size_of_mas; ++i)
        mas[i].print();
    mas.add_index(Sequence::create_GEOMETRIC(2, 3), 3);
    size_of_mas = mas.size();
    EXPECT_EQ(size_of_mas, 6);
    for (int i = 0; i < size_of_mas; ++i)
        mas[i].print();
    mas.del_index(1);
    size_of_mas = mas.size();
    EXPECT_EQ(size_of_mas, 5);
    for (int i = 0; i < size_of_mas; ++i){
        mas[i].print();
    }
};

