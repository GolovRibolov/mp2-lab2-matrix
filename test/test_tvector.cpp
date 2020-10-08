#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
    ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
    ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
    ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
    TVector<int> v(10);

    ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
    TVector<int> v(2);
    v[0] = 1;
    v[1] = 2;
    TVector<int> v1(v);
    EXPECT_EQ(v1, v);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> v(3);
    v[0] = 1;
    TVector<int> v1(v);
    v1[0] = 2;
    EXPECT_NE(v1[0], v[0]);
}

TEST(TVector, can_get_size)
{
    TVector<int> v(4);

    EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
    TVector<int> v(4, 2);

    EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
    TVector<int> v(4);
    v[0] = 4;

    EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
    TVector<int> v(5);
    ASSERT_ANY_THROW(v[-5]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
    TVector<int> v(MAX_VECTOR_SIZE);
    ASSERT_ANY_THROW(v[MAX_VECTOR_SIZE]);
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int> first(5), standart(first);
    first = first;
    EXPECT_EQ(first, standart);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    TVector<int> first(5), second(5);
    first = second;
    EXPECT_EQ(first, second);
}

TEST(TVector, assign_operator_change_vector_size)
{
    TVector<int> first(5), second(7);
    first = second;
    EXPECT_EQ(first.GetSize(), 7);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    TVector<int> first(5), second(7);
    first = second;
    EXPECT_EQ(first, second);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    TVector<int> first(3);
    first[0] = 1;
    first[1] = 2;
    first[2] = 3;
    TVector<int>  second(first);
    EXPECT_EQ(first, second);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    TVector<int> first(3);
    EXPECT_EQ(first, first);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector<int> first(3), second(10);
    EXPECT_NE(first, second);
}

TEST(TVector, can_add_scalar_to_vector)
{
    TVector<int> first(4), standart(4);
    for (int i = 0; i < 4; i++)
    {
        first[i] = 2;
        standart[i] = 10;
    }
    first = first + 8;
    EXPECT_EQ(first, standart);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
    TVector<int> first(4), standart(4);
    for (int i = 0; i < 4; i++)
    {
        first[i] = 10;
        standart[i] = 2;
    }
    first = first - 8;
    EXPECT_EQ(first, standart);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
    TVector<int> first(4), standart(4);
    for (int i = 0; i < 4; i++)
    {
        first[i] = 2;
        standart[i] = 10;
    }
    first = first * 5;
    EXPECT_EQ(first, standart);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
    TVector<int> first(4), second(4), result(4);
    for (int i = 0; i < 4; i++)
    {
        first[i] = i;
        second[i] = 5;
        result[i] = 5 + i;
    }
    EXPECT_EQ(first + second, result);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
    TVector<int> first(4), second(6);
    ASSERT_ANY_THROW(first + second);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
    TVector<int> first(4), second(4), result(4);
    for (int i = 0; i < 4; i++)
    {
        first[i] = 5;
        second[i] = i;
        result[i] = 5 - i;
    }
    EXPECT_EQ(first - second, result);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
    TVector<int> first(4), second(6);
    ASSERT_ANY_THROW(first - second);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
    TVector<int> first(4), second(4);
    int result = 0;
    for (int i = 0; i < 4; i++)
    {
        first[i] = 5;
        second[i] = i;
        result = result + 5 * i;
    }
    EXPECT_EQ(first * second, result);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
    TVector<int> first(4), second(6);
    ASSERT_ANY_THROW(first * second);
}

