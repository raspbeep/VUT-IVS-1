//======== Copyright (c) 2021, FIT VUT Brno, All rights reserved. ============//
//
// Purpose:     White Box - Tests suite
//
// $NoKeywords: $ivs_project_1 $white_box_code.cpp
// $Author:     JMENO PRIJMENI <xlogin00@stud.fit.vutbr.cz>
// $Date:       $2021-01-04
//============================================================================//
/**
 * @file white_box_tests.cpp
 * @author PAVEL KRATOCHVÍL <xkrato61@stud.fit.vutbr.cz>
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

class Matrixx : public ::testing::Test {
protected:
    Matrix m{};
};

TEST_F(Matrixx, ConstructMatrixCheckZeroValue) {
    EXPECT_NO_THROW(Matrix m{});
    Matrix m1x1{};
    EXPECT_EQ(m1x1.get(0, 0), 0);
    EXPECT_ANY_THROW(m1x1.get(3, 4));
}

TEST_F(Matrixx, ValidSizeCheck) {
    EXPECT_ANY_THROW(Matrix m(0,1));
    EXPECT_ANY_THROW(Matrix m(1,0));
    EXPECT_ANY_THROW(Matrix m(1,-42));
    EXPECT_ANY_THROW(Matrix m(-42,0));
}

TEST_F(Matrixx, SetValueCheckPositionExists) {
    Matrix m3{6, 6};

    EXPECT_TRUE(m3.set(3, 3, 42));
    EXPECT_TRUE(m3.set(1, 2, 42));
    EXPECT_TRUE(m3.set(4, 5, 42));
    EXPECT_TRUE(m3.set(0, 0, 42));

    EXPECT_FALSE(m3.set(6, 6, 42));
    EXPECT_FALSE(m3.set(1, 7, 42));
    EXPECT_FALSE(m3.set(7, 11, 42));
    EXPECT_FALSE(m3.set(-2, 3, 42));
    EXPECT_FALSE(m3.set(3, -3, 42));
}

TEST_F(Matrixx, SetMultipleValuesFromVector) {
    std::vector<std::vector<double>> bigger_matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    std::vector<std::vector<double>> smaller_matrix = {{1, 2}, {3, 4}};
    std::vector<std::vector<double>> correct_matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Matrix target_matrix{3, 3};
    EXPECT_FALSE(target_matrix.set(smaller_matrix));
    EXPECT_FALSE(target_matrix.set(bigger_matrix));
    EXPECT_TRUE(target_matrix.set(correct_matrix));
}

TEST_F(Matrixx, CompareMatrices) {
    Matrix  target_matrix{3, 3},
            different_size_matrix{2, 2},
            different_size_matrix1{4, 4},
            diff_values_matrix{3, 3},
            same_matrix{3, 3};

    target_matrix.set(0,0,1);
    target_matrix.set(1,1,2);
    target_matrix.set(2,2,3);

    same_matrix.set(0,0,1);
    same_matrix.set(1,1,2);
    same_matrix.set(2,2,3);

    diff_values_matrix.set(0,0,3);
    diff_values_matrix.set(1,1,2);
    diff_values_matrix.set(2,2,1);

    EXPECT_ANY_THROW(target_matrix == different_size_matrix);
    EXPECT_ANY_THROW(target_matrix == different_size_matrix1);
    EXPECT_FALSE(target_matrix == diff_values_matrix);
    EXPECT_TRUE(target_matrix == same_matrix);
}


TEST_F(Matrixx, MatrixSum) {
    Matrix  target_matrix{3, 3},
            different_size_matrix{2, 2},
            target_matrix1{3, 3},
            correct_sum_matrix{3,3};

    target_matrix.set(0,0,1);
    target_matrix.set(1,0,2);
    target_matrix.set(1,1,-4);
    target_matrix.set(1,2,1);
    target_matrix.set(2,1,2);
    target_matrix.set(2,2,3);

    target_matrix1.set(0,0,2);
    target_matrix1.set(1,0,3);
    target_matrix1.set(1,1,7);
    target_matrix1.set(1,2,23);
    target_matrix1.set(2,0,568);
    target_matrix1.set(2,1,-5);

    //[1, 0,0]   [2,  0 , 0]   [3,  0, 0]
    //|2,-4,1] + |3,  7 ,23| = |5,  3,24]
    //[0, 2,3]   [568,-5, 0]   [568,-3,3]

    correct_sum_matrix.set(0, 0, 3);
    correct_sum_matrix.set(1, 0, 5);
    correct_sum_matrix.set(1, 1, 3);
    correct_sum_matrix.set(1, 2, 24);
    correct_sum_matrix.set(2, 0, 568);
    correct_sum_matrix.set(2, 1, -3);
    correct_sum_matrix.set(2, 2, 3);

    EXPECT_ANY_THROW(target_matrix+different_size_matrix);
    EXPECT_TRUE((target_matrix + target_matrix1) == correct_sum_matrix);
}

TEST_F(Matrixx, MatrixMultiplication) {
    Matrix  target_matrix{3, 3},
            different_size_matrix{2, 3},
            target_matrix1{3, 3},
            correct_mult_matrix{3,3};

    target_matrix.set(0,0,1);
    target_matrix.set(1,0,2);
    target_matrix.set(1,1,-4);
    target_matrix.set(1,2,1);
    target_matrix.set(2,1,2);
    target_matrix.set(2,2,3);

    target_matrix1.set(0,0,2);
    target_matrix1.set(1,0,3);
    target_matrix1.set(1,1,7);
    target_matrix1.set(1,2,23);
    target_matrix1.set(2,0,568);
    target_matrix1.set(2,1,-5);

    //[1, 0,0]   [2,  0 , 0]   [2,   0 , 0 ]
    //|2,-4,1] * |3,  7 ,23| = |560,-33,-92]
    //[0, 2,3]   [568,-5, 0]   [1710,-1, 46]

    correct_mult_matrix.set(0, 0, 2);
    correct_mult_matrix.set(1, 0, 560);
    correct_mult_matrix.set(1, 1, -33);
    correct_mult_matrix.set(1, 2, -92);
    correct_mult_matrix.set(2, 0, 1710);
    correct_mult_matrix.set(2, 1, -1);
    correct_mult_matrix.set(2, 2, 46);

    EXPECT_ANY_THROW(target_matrix*different_size_matrix);
    EXPECT_TRUE((target_matrix * target_matrix1) == correct_mult_matrix);
}

TEST_F(Matrixx, MatrixMultiplicationByConstant) {
    Matrix  target_matrix{3, 3},
            target_matrix1{3, 3},
            correct_mult_matrix{3,3};

    const double mult_value = 32.0;

    target_matrix.set(0,0,1);
    target_matrix.set(1,0,2);
    target_matrix.set(1,1,-4);
    target_matrix.set(1,2,1);
    target_matrix.set(2,1,2);
    target_matrix.set(2,2,3);

    target_matrix1.set(0,0,2);
    target_matrix1.set(1,0,3);
    target_matrix1.set(1,1,7);
    target_matrix1.set(1,2,23);
    target_matrix1.set(2,0,568);
    target_matrix1.set(2,1,-5);

    //[1, 0,0]        [32,   0,   0]
    //|2,-4,1] * 32 = |64,-128,  32]
    //[0, 2,3]        [0,   64,  96]

    correct_mult_matrix.set(0, 0, 32);
    correct_mult_matrix.set(1, 0, 64);
    correct_mult_matrix.set(1, 1, -128);
    correct_mult_matrix.set(1, 2, 32);
    correct_mult_matrix.set(2, 0, 0);
    correct_mult_matrix.set(2, 1, 64);
    correct_mult_matrix.set(2, 2, 96);

    EXPECT_TRUE((target_matrix * mult_value) == correct_mult_matrix);
}

TEST_F(Matrixx, SolveByCramersRule) {
    Matrix  target_matrix{3, 3},
            target_matrix1{3, 3},
            correct_{3, 3};

    target_matrix.set(0,0,2);
    target_matrix.set(0,1,3);
    target_matrix.set(0,2,-1);
    target_matrix.set(1,0,4);
    target_matrix.set(1,1,1);
    target_matrix.set(1,2,-3);
    target_matrix.set(2,0,3);
    target_matrix.set(2,1,-2);
    target_matrix.set(2,2,5);

    std::vector<double> right_side = {1, 11, 21};
    std::vector<double> correct_result = {4, -2, 1};

    //[2, 3,-1|  1]
    //[4, 1,-3| 11]
    //[3,-2, 5| 21]

    auto result = target_matrix.solveEquation(right_side);
    EXPECT_EQ(result, correct_result);

    // TODO matica ktora sa neda vyriesit cramerom
    // taka ktora ma det=0
    // cramer nad maticou 1x1
}

TEST_F(Matrixx, CramerOneByOneMatrix) {
    Matrix m1x1{1, 1};
    m1x1.set(0, 0, 1);
    std::vector<double> right_side = {1};
    std::vector<double> result = {1};
    EXPECT_EQ(m1x1.solveEquation(right_side), result);

}

TEST_F(Matrixx, CramerBiggerRightSide) {
    Matrix m1x1{1, 1};
    m1x1.set(0, 0, 1);
    std::vector<double> right_side = {1,1};
    EXPECT_ANY_THROW(m1x1.solveEquation(right_side));
}
TEST_F(Matrixx, CramerNotSquareMatrix) {
    Matrix m1x1{1, 2};
    m1x1.set(0, 0, 1);
    m1x1.set(0, 1, 2);
    std::vector<double> right_side = {1, 2};
    EXPECT_ANY_THROW(m1x1.solveEquation(right_side));
}

TEST_F(Matrixx, CramerSingularMatrix) {
    Matrix m1x1{2, 2};
    m1x1.set(0, 0, 1);
    m1x1.set(0, 1, 2);
    std::vector<double> right_side = {1, 2};
    EXPECT_ANY_THROW(m1x1.solveEquation(right_side));
}

TEST_F(Matrixx, TransposeMatrix) {
    Matrix  target_matrix{2, 3},
            correct_transposed{3, 2},
            target_matrix2{2, 2},
            correct_transposed2{2, 2};

    target_matrix.set(0,0,1);
    target_matrix.set(0,1,2);
    target_matrix.set(1,0,3);
    target_matrix.set(1,1,4);
    target_matrix.set(2,0,5);
    target_matrix.set(2,1,6);

    correct_transposed.set(0,0,1);
    correct_transposed.set(0,1,3);
    correct_transposed.set(0,2,5);
    correct_transposed.set(1,0,2);
    correct_transposed.set(1,1,4);
    correct_transposed.set(1,2,6);

    // [1, 2]T   [1, 3, 5]
    // |3, 4|  = [2, 4, 6]
    // [5, 6]

    EXPECT_TRUE(target_matrix.transpose() == correct_transposed);
}

TEST_F(Matrixx, InverseMatrix3x3){
    Matrix target_matrix{3, 3},
           inverse_matrix{3, 3};

    target_matrix.set(0, 0, 3);
    target_matrix.set(0, 1, -4);
    target_matrix.set(0, 2, 5);

    target_matrix.set(1, 0, 2);
    target_matrix.set(1, 1, -3);
    target_matrix.set(1, 2, 1);

    target_matrix.set(2, 0, 3);
    target_matrix.set(2, 1, -5);
    target_matrix.set(2, 2, -1);

    inverse_matrix.set(0, 0, -8);
    inverse_matrix.set(0, 1, 29);
    inverse_matrix.set(0, 2, -11);

    inverse_matrix.set(1, 0, -5);
    inverse_matrix.set(1, 1, 18);
    inverse_matrix.set(1, 2, -7);

    inverse_matrix.set(2, 0, 1);
    inverse_matrix.set(2, 1, -3);
    inverse_matrix.set(2, 2, 1);

    EXPECT_EQ(target_matrix.inverse(), inverse_matrix);
}

TEST_F(Matrixx, InverseMatrix2x2) {
    Matrix target_matrix{2, 2},
           inverse_matrix{2, 2};

    target_matrix.set(0, 0, 5);
    target_matrix.set(0, 1, 2);

    target_matrix.set(1, 0, -7);
    target_matrix.set(1, 1, -3);

    inverse_matrix.set(0, 0, 3);
    inverse_matrix.set(0, 1, 2);

    inverse_matrix.set(1, 0, -7);
    inverse_matrix.set(1, 1, -5);

    EXPECT_EQ(target_matrix.inverse(), inverse_matrix);
}

TEST_F(Matrixx, InverseBiggerMatrix){
    Matrix m4x4 = {4, 4};
    EXPECT_ANY_THROW(m4x4.inverse());
}

TEST_F(Matrixx, InverseSingularMatrix) {
    Matrix m2x2 = {2, 2};
    m2x2.set(0, 0, 1);
    m2x2.set(0, 1, 2);

    EXPECT_ANY_THROW(m2x2.inverse());
}

TEST_F(Matrixx, SolveMatrix4x4) {
    Matrix m4x4 = {4, 4};

    std::vector<std::vector<double>> target_template = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    std::vector<double> right_side_and_result = {1, 1, 1, 1};

    EXPECT_NO_THROW(m4x4.set(target_template));
    EXPECT_EQ(m4x4.solveEquation(right_side_and_result), right_side_and_result);
}
/*** Konec souboru white_box_tests.cpp ***/
