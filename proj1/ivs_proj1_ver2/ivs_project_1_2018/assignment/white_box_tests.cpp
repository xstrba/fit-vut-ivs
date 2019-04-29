//======== Copyright (c) 2017, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - Tests suite
//
// $NoKeywords: $ivs_project_1 $white_box_code.cpp
// $Author:     Boris Strbak <xstrba05@stud.fit.vutbr.cz>
// $Date:       $2017-01-04
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author JMENO PRIJMENI
 *
 * @brief Implementace testu prace s maticemi.
 */

#include "gtest/gtest.h"
#include "white_box_code.h"

//============================================================================//
// ** ZDE DOPLNTE TESTY **
//
// Zde doplnte testy operaci nad maticemi. Cilem testovani je:
// 1. Dosahnout maximalniho pokryti kodu (white_box_code.cpp) testy.
// 2. Overit spravne chovani operaci nad maticemi v zavislosti na rozmerech
//    matic.
//============================================================================//


class TestMatrix : public ::testing::Test
{
    protected:
        Matrix result_m;
        Matrix cmp_m;
        Matrix expected;
        std::vector<std::vector< double > > values;
};

class TestMatrix1x1 : public TestMatrix
{
    protected:
        Matrix matrix = Matrix();

};

class TestMatrix2x2 : public TestMatrix
{
    protected:
        std::vector<std::vector< double > > values = {{4, 2}, {6, 4}};

        Matrix matrix = Matrix(2, 2);

};

class TestMatrix3x3 : public TestMatrix
{
    protected:
        std::vector<std::vector< double > > values = {{4, 2, 3}, {6, 4, 5}, {5, 6, 3}};

        Matrix matrix = Matrix(3, 3);

};

class TestMatrix4x4 : public TestMatrix
{
    protected:
        std::vector<std::vector< double > > values = {{4, 2, 3, 6}, {6, 4, 5, 10}, {5, 6, 3, 8}, {1, 2, 4, 4}};

        Matrix matrix = Matrix(4, 4);

};

class TestMatrix5x7 : public TestMatrix
{
    protected:
        std::vector<std::vector< double > > values = {{4, 2, 3, 6, 4, 5, 6}, {6, 4, 5, 10, 8, 10 ,1}, {5, 6, 3, 8, 27, 9, 3},
        {1, 2, 4, 4, 5, 10, 9}, {2, 5, 6, 7, 10, 11, 7}};

        Matrix matrix = Matrix(5, 7);

};

class TestMatrix7x5 : public TestMatrix
{
    protected:
        std::vector<std::vector< double > > values = {{4, 2, 3, 6, 4}, {6, 4, 5, 10, 8}, {5, 6, 3, 8, 27},
        {1, 2, 4, 4, 5}, {2, 5, 6, 7, 10}, {8, 1, 11, 2, 6}, {9, 0, 12, 1, 18}};

        Matrix matrix = Matrix(7, 5);

};


TEST_F(TestMatrix, construct)
{

    ASSERT_NO_THROW(Matrix(2, 2));
    ASSERT_NO_THROW(Matrix(20, 20));
    ASSERT_NO_THROW(Matrix(5, 10));
    ASSERT_NO_THROW(Matrix(10, 5));

    EXPECT_ANY_THROW(Matrix matrix = Matrix(0, 0));
    EXPECT_ANY_THROW(Matrix(10, 0));
    EXPECT_ANY_THROW(Matrix(0, 5));
    EXPECT_ANY_THROW(Matrix(-10, -10));
    EXPECT_ANY_THROW(Matrix(-5, -10));
    EXPECT_ANY_THROW(Matrix(-10, -5));

};

// =============1x1==============

TEST_F(TestMatrix1x1, get1x1)
{


    ASSERT_NO_THROW(matrix.get(0, 0));
    EXPECT_EQ(matrix.get(0, 0), 0);
    ASSERT_ANY_THROW(matrix.get(1, 1));
    ASSERT_ANY_THROW(matrix.get(-1, -1));
    ASSERT_ANY_THROW(matrix.get(2, 3));

}

TEST_F(TestMatrix1x1, set1x1)
{

    EXPECT_TRUE(matrix.set(0, 0, 2));
    ASSERT_EQ(matrix.get(0, 0), 2);
    EXPECT_FALSE(matrix.set(1, 1, 2));
    EXPECT_FALSE(matrix.set(-1, -1, 2));
    EXPECT_FALSE(matrix.set(2, 3, 2));
    values = {{4}};
    EXPECT_TRUE(matrix.set(values));
    values = {{4, 2},{2, 3}};
    EXPECT_FALSE(matrix.set(values));

}

TEST_F(TestMatrix1x1, opeq1x1)
{
    cmp_m = Matrix();
    cmp_m.set(0, 0, 4);
    matrix.set(0, 0, 4);
    EXPECT_TRUE(matrix == cmp_m);
    cmp_m.set(0, 0, 3);
    EXPECT_FALSE(matrix == cmp_m);
    cmp_m = Matrix(2, 2);
    EXPECT_ANY_THROW(matrix == cmp_m);

}

TEST_F(TestMatrix1x1, opp1x1)
{

    cmp_m = Matrix(2, 2);
    matrix.set(0, 0, 3);
    ASSERT_ANY_THROW(matrix + cmp_m);
    cmp_m = Matrix();
    cmp_m.set(0, 0, 4);
    ASSERT_NO_THROW(result_m = matrix + cmp_m); //4+3
    EXPECT_EQ(result_m.get(0, 0), 7);
    EXPECT_NO_THROW(result_m == matrix);

}

TEST_F(TestMatrix1x1, opmult1x1)
{

    //1x1 * 2x2
    matrix.set(0, 0, 2);
    cmp_m = Matrix(2, 2);
    EXPECT_ANY_THROW(matrix * cmp_m);
    EXPECT_ANY_THROW(cmp_m * matrix);

    //1x1 * 1x2
    cmp_m = Matrix(1, 2);
    expected = Matrix(1, 2);
    values = {{3, 4}};
    cmp_m.set(values);
    values = {{6, 8}}; //result
    expected.set(values);
    EXPECT_ANY_THROW(cmp_m * matrix);
    ASSERT_NO_THROW(result_m = matrix * cmp_m);
    EXPECT_TRUE(result_m == expected);

    //1x1 * 2x1
    cmp_m = Matrix(2, 1);
    expected = Matrix(2, 1);
    values = {{3}, {4}};
    cmp_m.set(values);
    values = {{6}, {8}}; //result
    expected.set(values);
    EXPECT_ANY_THROW(matrix * cmp_m);
    ASSERT_NO_THROW(result_m = cmp_m * matrix);
    EXPECT_TRUE(result_m == expected);

    //1x1 * 1x1
    cmp_m = Matrix(1, 1);
    expected = Matrix(1, 1);
    cmp_m.set(0, 0, 3);
    expected.set(0, 0, 6);
    ASSERT_NO_THROW(result_m = cmp_m * matrix);
    EXPECT_TRUE(result_m == expected);
    ASSERT_NO_THROW(result_m = matrix * cmp_m);
    EXPECT_TRUE(result_m == expected);

    //1x1 * 2
    matrix.set(0, 0, 4);
    matrix = matrix*2;
    EXPECT_EQ(matrix.get(0, 0), 8);

}


// =============2x2==============

TEST_F(TestMatrix2x2, get2x2)
{

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ASSERT_NO_THROW(matrix.get(i, j));
            EXPECT_EQ(matrix.get(i, j), 0);
        }
    }
    ASSERT_ANY_THROW(matrix.get(1, 2));
    ASSERT_ANY_THROW(matrix.get(-1, -1));
    ASSERT_ANY_THROW(matrix.get(2, 1));

}

TEST_F(TestMatrix2x2, set2x2)
{

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            EXPECT_TRUE(matrix.set(i, j, 2));
            EXPECT_EQ(matrix.get(i, j), 2);
        }
    }
    EXPECT_FALSE(matrix.set(1, 2, 2));
    EXPECT_FALSE(matrix.set(-1, -1, 2));
    EXPECT_FALSE(matrix.set(2, 1, 2));

    values = {{4, 2},{2, 3}};
    EXPECT_TRUE(matrix.set(values));
    values = {{2, 3, 3}, {3, 5, 4}};
    EXPECT_FALSE(matrix.set(values));

}

TEST_F(TestMatrix2x2, opeq2x2)
{

    cmp_m = Matrix(2, 2);
    values = {{4, 2}, {6, 4}};
    cmp_m.set(values);
    matrix.set(values);
    EXPECT_TRUE(matrix == cmp_m);
    cmp_m.set(0, 0, 3);
    EXPECT_FALSE(matrix == cmp_m);
    cmp_m = Matrix(2, 3);
    EXPECT_ANY_THROW(matrix == cmp_m);

}

TEST_F(TestMatrix2x2, opp2x2)
{

    values = {{8, 4}, {8, 7}};
    expected = Matrix(2, 2);
    expected.set(values);

    cmp_m = Matrix(2, 3);

    values = {{4, 2}, {6, 4}};
    matrix.set(values);
    EXPECT_ANY_THROW(matrix + cmp_m);

    values = {{4, 2},{2, 3}};
    cmp_m = Matrix(2, 2);
    cmp_m.set(values);
    ASSERT_NO_THROW(result_m = matrix + cmp_m);
    EXPECT_TRUE(result_m == expected);
    ASSERT_NO_THROW(result_m == matrix);

}

TEST_F(TestMatrix2x2, opmult2x2)
{

    //2x2 * 3x3
    matrix.set(values);
    cmp_m = Matrix(3,3);
    EXPECT_ANY_THROW(matrix * cmp_m);
    EXPECT_ANY_THROW(cmp_m * matrix);

    //2x2 * 2x3
    cmp_m = Matrix(2, 3);
    expected = Matrix(2, 3);
    values = {{2, 4, 3}, {3, 5, 7}};
    cmp_m.set(values);
    values = {{14, 26, 26}, {24, 44, 46}}; //result
    expected.set(values);
    EXPECT_ANY_THROW(cmp_m * matrix);
    ASSERT_NO_THROW(result_m = matrix * cmp_m);
    EXPECT_TRUE(result_m == expected);

    //2x2 * 3x2
    cmp_m = Matrix(3, 2);
    expected = Matrix(3, 2);
    values = {{2, 3}, {4, 5}, {3, 7}};
    cmp_m.set(values);
    values = {{26, 16}, {46, 28}, {54, 34}}; //result
    expected.set(values);
    ASSERT_NO_THROW(result_m = cmp_m * matrix);
    EXPECT_ANY_THROW(matrix * cmp_m);
    EXPECT_TRUE(result_m == expected);

    //2x2 * 2x2
    cmp_m = Matrix(2, 2);
    expected = Matrix(2, 2);
    values = {{4, 2}, {2, 3}};
    cmp_m.set(values);
    values = {{20, 14}, {32, 24}}; //result
    expected.set(values);
    ASSERT_NO_THROW(result_m = matrix * cmp_m);
    EXPECT_TRUE(result_m == expected);
    values = {{28, 16}, {26, 16}}; //result
    expected.set(values);
    ASSERT_NO_THROW(result_m =  cmp_m * matrix);
    EXPECT_TRUE(result_m == expected);

    //2x2 * 2
    matrix = matrix*2;
    values = {{8, 4}, {12, 8}};
    expected.set(values);
    EXPECT_TRUE(matrix == expected);

}

// =============5x7==============

TEST_F(TestMatrix5x7, get5x7)
{

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            ASSERT_NO_THROW(matrix.get(i, j));
            EXPECT_EQ(matrix.get(i, j), 0);
        }
    }
    ASSERT_ANY_THROW(matrix.get(4, 7));
    ASSERT_ANY_THROW(matrix.get(-1, -1));
    ASSERT_ANY_THROW(matrix.get(5, 6));

}

TEST_F(TestMatrix5x7, set5x7)
{

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 7; j++) {
            EXPECT_TRUE(matrix.set(i, j, 2));
            EXPECT_EQ(matrix.get(i, j), 2);
        }
    }
    EXPECT_FALSE(matrix.set(4, 7, 2));
    EXPECT_FALSE(matrix.set(-1, -1, 2));
    EXPECT_FALSE(matrix.set(5, 6, 2));

    EXPECT_TRUE(matrix.set(values));
    values = {{2, 3, 3}, {3, 5, 4}};
    EXPECT_FALSE(matrix.set(values));

}

TEST_F(TestMatrix5x7, opeq5x7)
{

    cmp_m = Matrix(5, 7);
    cmp_m.set(values);
    matrix.set(values);
    EXPECT_TRUE(matrix == cmp_m);
    cmp_m.set(0, 0, 3);
    EXPECT_FALSE(matrix == cmp_m);
    cmp_m = Matrix(5, 5);
    EXPECT_ANY_THROW(matrix == cmp_m);

}

TEST_F(TestMatrix5x7, opp5x7)
{

    matrix.set(values);
    expected = Matrix(5, 7);

    cmp_m = Matrix(5, 8);
    EXPECT_ANY_THROW(matrix + cmp_m);

    values = {{6, 7, 8, 9, 2, 4, 5}, {2, 3, 5, 1, 12, 10 , 8}, {9, 1, 20, 21, 8, 2, 5},
                {1, 3, 4, 5, 5, 10, 7}, {3, 4, 5, 1, 10, 11, 13}};
    cmp_m = Matrix(5, 7);
    cmp_m.set(values);
    values = values = {{10, 9, 11, 15, 6, 9, 11}, {8, 7, 10, 11, 20, 20 , 9}, {14, 7, 23, 29, 35, 11, 8},
                {2, 5, 8, 9, 10, 20, 16}, {5, 9, 11, 8, 20, 22, 20}}; //result
    expected.set(values);
    ASSERT_NO_THROW(result_m = matrix + cmp_m);
    EXPECT_TRUE(result_m == expected);
    ASSERT_NO_THROW(result_m == matrix);

}

TEST_F(TestMatrix5x7, opmult5x7)
{

    //5x7 * 4x4
    matrix.set(values);
    cmp_m = Matrix(4,4);
    EXPECT_ANY_THROW(matrix * cmp_m);
    EXPECT_ANY_THROW(cmp_m * matrix);
    //
    //5x7 * 7x3
    cmp_m = Matrix(7, 3);
    expected = Matrix(5, 3);
    values = {{6, 7, 8}, {2, 3, 5}, {9, 1, 20}, {4, 6, 2}, {10, 12, 1}, {13, 8, 2}, {0, 2, 5}};
    cmp_m.set(values);
    values = {{184, 173, 158}, {339, 297, 221}, {488, 506, 206}, {242, 199, 176}, {347, 299, 242}}; //result
    expected.set(values);
    EXPECT_ANY_THROW(cmp_m * matrix);
    ASSERT_NO_THROW(result_m = matrix * cmp_m);
    EXPECT_TRUE(result_m == expected);

    //5x7 * 3x5
    cmp_m = Matrix(3, 5);
    expected = Matrix(3, 7);
    values = {{6, 7, 8, 4, 10}, {2, 3, 5, 4, 7}, {9, 1, 20, 22, 1}};
    cmp_m.set(values);
    values = {{130, 146, 153, 256, 416, 322, 173}, {69, 89, 94, 147, 257, 202, 115}, {166, 191, 186, 319, 704, 466, 320}}; //result
    expected.set(values);
    ASSERT_NO_THROW(result_m = cmp_m * matrix);
    EXPECT_ANY_THROW(matrix * cmp_m);
    EXPECT_TRUE(result_m == expected);

    //5x7 * 2
    expected = Matrix(5, 7);
    matrix = matrix*2;
    values = {{8, 4, 6, 12, 8, 10, 12}, {12, 8, 10, 20, 16, 20 ,2}, {10, 12, 6, 16, 54, 18, 6},
    {2, 4, 8, 8, 10, 20, 18}, {4, 10, 12, 14, 20, 22, 14}};
    expected.set(values);
    EXPECT_TRUE(matrix == expected);

}

// =============7x5==============

TEST_F(TestMatrix7x5, get7x5)
{

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 5; j++) {
            ASSERT_NO_THROW(matrix.get(i, j));
            EXPECT_EQ(matrix.get(i, j), 0);
        }
    }
    ASSERT_ANY_THROW(matrix.get(6, 5));
    ASSERT_ANY_THROW(matrix.get(-1, -1));
    ASSERT_ANY_THROW(matrix.get(7, 4));

}

TEST_F(TestMatrix7x5, set7x5)
{

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 5; j++) {
            EXPECT_TRUE(matrix.set(i, j, 2));
            EXPECT_EQ(matrix.get(i, j), 2);
        }
    }
    EXPECT_FALSE(matrix.set(6, 5, 2));
    EXPECT_FALSE(matrix.set(-1, -1, 2));
    EXPECT_FALSE(matrix.set(7, 4, 2));

    EXPECT_TRUE(matrix.set(values));
    values = {{4, 2, 3, 6, 4, 3}, {6, 4, 5, 10, 8, 1}, {5, 6, 3, 8, 27, 7},
    {1, 2, 4, 4, 5, 5}, {2, 5, 6, 7, 10, 6}, {8, 1, 11, 2, 6, 3}, {9, 0, 12, 1, 18, 10}};
    EXPECT_FALSE(matrix.set(values));

}

TEST_F(TestMatrix7x5, opeq7x5)
{

    cmp_m = Matrix(7, 5);
    cmp_m.set(values);
    matrix.set(values);
    EXPECT_TRUE(matrix == cmp_m);
    cmp_m.set(0, 0, 3);
    EXPECT_FALSE(matrix == cmp_m);
    cmp_m = Matrix(7, 6);
    EXPECT_ANY_THROW(matrix == cmp_m);

}

TEST_F(TestMatrix7x5, opp7x5)
{

    matrix.set(values);
    expected = Matrix(7, 5);

    cmp_m = Matrix(8, 5);
    EXPECT_ANY_THROW(matrix + cmp_m);

    values = {{7, 10, 13, 5, 12}, {7, 9, 12, 6, 1}, {12, 17, 1, 2, 2},
    {5, 2, 6, 10, 2}, {2, 5, 8, 9, 10}, {8, 4, 12, 13, 5}, {1, 2, 16, 2, 15 }};
    cmp_m = Matrix(7, 5);
    cmp_m.set(values);
    values = values = {{11, 12, 16, 11, 16}, {13, 13, 17, 16, 9}, {17, 23, 4, 10, 29},
    {6, 4, 10, 14, 7}, {4, 10, 14, 16, 20}, {16, 5, 23, 15, 11}, {10, 2, 28, 3, 33}}; //result
    expected.set(values);
    ASSERT_NO_THROW(result_m = matrix + cmp_m);
    EXPECT_TRUE(result_m == expected);
    ASSERT_NO_THROW(result_m == matrix);

}

TEST_F(TestMatrix7x5, opmult7x5)
{

    //7x5 * 8x6
    matrix.set(values);
    cmp_m = Matrix(8, 6);
    EXPECT_ANY_THROW(matrix * cmp_m);
    EXPECT_ANY_THROW(cmp_m * matrix);
    //
    //7x5 * 5x3
    cmp_m = Matrix(5, 3);
    expected = Matrix(7, 3);
    values = {{6, 7, 8}, {2, 3, 5}, {9, 1, 20}, {4, 6, 2}, {10, 12, 1}};
    cmp_m.set(values);
    values = {{119, 121, 118}, {209, 215, 196}, {371, 428, 173}, {112, 101, 111}, {204, 197, 185},
                {217, 154, 299}, {346, 297, 332}}; //result
    expected.set(values);
    EXPECT_ANY_THROW(cmp_m * matrix);
    ASSERT_NO_THROW(result_m = matrix * cmp_m);
    EXPECT_TRUE(result_m == expected);

    //7x5 * 3x7
    cmp_m = Matrix(3, 7);
    expected = Matrix(3, 5);
    values = {{6, 7, 8, 4, 10, 7, 8}, {2, 3, 5, 4, 7, 12, 3}, {9, 1, 20, 22, 1, 16, 19}};
    cmp_m.set(values);
    values = {{258, 153, 326, 278, 602}, {192, 101, 262, 174, 383}, {465, 207, 590, 370, 1142}}; //result
    expected.set(values);
    ASSERT_NO_THROW(result_m = cmp_m * matrix);
    EXPECT_ANY_THROW(matrix * cmp_m);
    EXPECT_TRUE(result_m == expected);

    //7x5 * 2
    expected = Matrix(7, 5);
    matrix = matrix*2;
    values = {{8, 4, 6, 12, 8}, {12, 8, 10, 20, 16}, {10, 12, 6, 16, 54},
    {2, 4, 8, 8, 10}, {4, 10, 12, 14, 20}, {16, 2, 22, 4, 12}, {18, 0, 24, 2, 36}};
    expected.set(values);
    EXPECT_TRUE(matrix == expected);

}

// =============equations==============

TEST_F(TestMatrix1x1, equation1x1)
{

    matrix.set(0, 0, 4);
    std::vector<double> results;
    ASSERT_NO_THROW(results = matrix.solveEquation({8}));
    EXPECT_EQ(results[0], 2);
    EXPECT_ANY_THROW(matrix.solveEquation({8, 3}));
    EXPECT_ANY_THROW(matrix.solveEquation({}));
    matrix.set(0, 0, 0);
    EXPECT_ANY_THROW(matrix.solveEquation({8}));

}

TEST_F(TestMatrix2x2, equation2x2)
{

    matrix.set(values);
    std::vector<double> results;
    ASSERT_NO_THROW(results = matrix.solveEquation({6, 2}));
    EXPECT_EQ(results[0], 5);
    EXPECT_EQ(results[1], -7);
    EXPECT_ANY_THROW(matrix.solveEquation({8, 3, 4}));
    EXPECT_ANY_THROW(matrix.solveEquation({2}));
    values = {{1, -2},{-2, 4}};
    matrix.set(values);
    EXPECT_ANY_THROW(matrix.solveEquation({6, 2}));

}

TEST_F(TestMatrix3x3, equation3x3)
{

    matrix.set(values);
    std::vector<double> results;
    ASSERT_NO_THROW(results = matrix.solveEquation({6, 2, 7}));
    EXPECT_EQ(results[0], 9.8);
    EXPECT_EQ(results[1], -2.2);
    EXPECT_EQ(results[2], -9.6);
    EXPECT_ANY_THROW(matrix.solveEquation({8, 3, 4, 5}));
    EXPECT_ANY_THROW(matrix.solveEquation({2, 4}));
    values = {{1, 2, 3},{2, 4, 6}, {4, 8, 12}};
    matrix.set(values);
    EXPECT_ANY_THROW(matrix.solveEquation({6, 2, 7}));

}

TEST_F(TestMatrix4x4, equation4x4)
{

    matrix.set(values);
    std::vector<double> results;
    ASSERT_NO_THROW(results = matrix.solveEquation({6, 2, 7, 8}));
    EXPECT_EQ(results[0], 18);
    EXPECT_EQ(results[1], 6);
    EXPECT_EQ(results[2], 15);
    EXPECT_EQ(results[3], -20.5);
    EXPECT_ANY_THROW(matrix.solveEquation({8, 3, 4, 5, 6}));
    EXPECT_ANY_THROW(matrix.solveEquation({2, 4, 4}));
    values = {{1, 2, 3, 4}, {2, 4, 6, 8}, {4, 8, 12, 16}, {8, 16, 24, 32}};
    matrix.set(values);
    EXPECT_ANY_THROW(matrix.solveEquation({6, 2, 7}));

}

TEST_F(TestMatrix5x7, equation5x7)
{

    std::vector<double> vals = {8, 3, 4, 5, 6, 7, 8};
    EXPECT_ANY_THROW(matrix.solveEquation(vals));

}

TEST_F(TestMatrix7x5, equation7x5)
{

    std::vector<double> vals = {8, 3, 4, 5, 6};
    EXPECT_ANY_THROW(matrix.solveEquation(vals));

}
