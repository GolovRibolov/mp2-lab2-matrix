#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
    ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
    ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
    TMatrix<int> m(5);

    ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
    TMatrix<int> m(5), m1(m);
    EXPECT_EQ(m, m1);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> m(5);
    m[0][0] = 1;
    TMatrix<int> m1(m);
    m1[0][0] = 2;
    EXPECT_NE(m1, m);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> m(5);
    EXPECT_EQ(m.GetSize(), 5);
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> m(5);
    m[0][0] = 1;
    EXPECT_EQ(m[0][0], 1);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> m(5);
    ASSERT_ANY_THROW(m[-1][2]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> m(5);
    ASSERT_ANY_THROW(m[MAX_MATRIX_SIZE][2]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> first(3);
    first[0][0] = 1;
    first[0][1] = 2;
    first[0][2] = 3;
    first[1][1] = 4;
    first[1][2] = 5;
    first[2][2] = 6;
    TMatrix<int> standart(first);
    first = first;
    EXPECT_EQ(first, standart);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    const int size = 5;
    TMatrix<int> first(size), second(size);
    first = second;
    EXPECT_EQ(first, second);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    TMatrix<int> first(3), second(6);
    first = second;
    EXPECT_EQ(first.GetSize(), 6);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    const int size1 = 5, size2 = 7;
    TMatrix<int> first(size1), second(size2);
    first = second;
    EXPECT_EQ(first, second);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> first(3), second(3);
    for (int i = 0; i < 3; i++)
        for (int j = i; j < 3; j++)
        {
            first[i][j] = i + j;
            second[i][j] = i + j;
        }
    EXPECT_EQ(first, second);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> m(3);
    EXPECT_EQ(m, m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> first(3), second(5);
    EXPECT_NE(first, second);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    const int size = 5;
    TMatrix<int> first(size), second(size), result(size);
    for (int i = 0; i < size; i++)
        for (int j = i; j < size; j++)
        {
            first[i][j] = i + j;
            second[i][j] = -j;
            result[i][j] = i;
        }
    EXPECT_EQ(first + second, result);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    const int size1 = 5, size2 = 7;
    TMatrix<int> first(size1), second(size2);
    ASSERT_ANY_THROW(first + second);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    const int size = 5;
    TMatrix<int> first(size), second(size), result(size);
    for (int i = 0; i < size; i++)
        for (int j = i; j < size; j++)
        {
            first[i][j] = i + j;
            second[i][j] = -j;
            result[i][j] = i + 2 * j;
        }
    EXPECT_EQ(first - second, result);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    const int size1 = 5, size2 = 7;
    TMatrix<int> first(size1), second(size2);
    ASSERT_ANY_THROW(first - second);
}
