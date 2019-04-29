/**
 *
 * @file math_lib.h
 * @brief Mathematical library for RebusCalculator
 * @author
 *          Branislav Dubec <xdubec01>\n
 *	    Boris Štrbák <xstrba05>
 * @version 1.8
 * @date 2019/04/13
 *
 * ======== Copyright (c) 2019, Rebus Calc, Inc. , All rights reserved. ============
 */
#ifndef MATH_LIB_H_
#define MATH_LIB_H_
#include <string>
using namespace std;

/**
 * @defgroup String_parse
 * Replacing single expression of inserted string for result of these expressions.
 * @{
 */
/**
   *
   * @author    Branislav Dubec
   *
   * @brief      Return double value of a number in expression.
   *
   * @param      string getNum; inserted expression in gui.
   * @param      int IndexofOperator; index of operator in inserted expression.
   * @param      int* indexofNum1; index of first digit in number before operator in inserted expression.
   * @param      int* numofOperands; number of operands in inserted expression, in case that number
   *             is first and it is negative.
   * @param      int start; index of beginning in string getNum.
   * @return     double value of a number in string getNum.
*/

double GetNum1(string getNum, int IndexofOperator, int* numofOperands,
               int* indexofNum1, int start);
/**
   * @author  Branislav Dubec
   * @brief      Return double value of a number in expression.
   *
   * @param      string getNum; inserted expression in gui.
   * @param      int IndexofOperator; index of operator in inserted expression.
   * @param      int* indexofNum2; index of last digit in number after operator in inserted expression.
   * @return     double value of a number in string getNum
*/

double GetNum2(string getNum, int IndexofOperator, int* indexofNum2);

/**
   * @author  Branislav Dubec
   * @brief   Replace operations addition and subtraction with it's result.
   * <p>
   * Additional information: Solve basic mathematic operations; such as addition & subtraction in inserted expression and replace
   * these operations for it's result.
   * </p>
   *
   * @param      string & Result; inserted expression in gui.
   * @param      int start; index of beginning in string Result.
*/
void SolveOperands(string & Result, int start);
/**

   * @author  Branislav Dubec
   * @brief   Replace operations multiplication , division & modulo with it's result.
   *<p>
   * Additional information: Solve basic mathematic operations; such as multiplication , division & modulo in inserted expression and replace
   * these operations for it's result. In case of mathematical error, such as dividing by 0 or overflowing,
   * replace string Result for "MAXFLOAT".
   * </p>
   *
   *
   * @param      string & Result; inserted expression in gui.
   * @param      int start; index of beginning in string Result.
*/
void SolveMultPrecedence(string & Result, int start,  int *numOfOperands);
/**
   *
   * @author  Branislav Dubec
   *
   * @brief      Replace operations exponentiation & factorial with it's result.
   * <p>
   * Additional information: Solve  mathematic operations; such as exponentiation  & factorial in inserted expression and replace
   * these operations for it's result. In case of mathematical error, such as factorial of negative
   * number or overflowing, replace string Result for "MAXFLOAT".
   * </p>
   * @param      string & Result; inserted expression in gui.
   * @param      int start; index of beginning in string Result.
*/

void SolvePowFact(string & Result, int start, int *numOfOperands);
/**
   *
   * @author  Branislav Dubec
   * @brief   Replace operations sin, cos & sqrt with it's result.
   * <p>
   * Additional information: Solve  mathematic operations; such as sin of a number, cos of a number & sqrt of a number
   * in inserted expression and replace these operations for it's result.
   * </p>
   * @param      const char* value; inserted expression in gui.
   * @param      int start; index of beginning in char* value.
*/
void GetValueFromSinCosSqrt(const char* value, int start);
/**
   *
   * @author  Branislav Dubec
   * @brief Evalvuate operations inside brackets.
   * <p>
   * Additional information: Solve mathematic operations in our expression in brackets on indexes start & end and
   * replace it for it's result.
   * </p>
   * @param char* expression; inserted expression in gui.
   * @param int start; index of left bracket in expression.
   * @param int end; index of right bracket in expression.
*/
char* BracketEvalvuation(char* expression, int start, int end);

/**
 * @}
 */
/**
 * @defgroup Input_validation
 * @{
 */
/**
   * @author  Branislav Dubec
   * @brief Check if char in inserted expression is operand.
   * @param const char *expression; inserted expression in gui.
   * @param int position; index in expression.
   * @return 0 if char is valid, -1 in case of invalid.
*/
int CharisOperand(const char *expression, int position);
/**
   * @author  Branislav Dubec
   * @brief Check if char in inserted expression after left Bracket is valid.
   * @param const char *expression; inserted expression in gui.
   * @param int position; index in expression.
   * @return 0 if char is valid, -1 in case of invalid.
*/
int CharAfterlBracket(const char *expression, int position);
/**
* @author  Branislav Dubec
* @brief Check if char after operand is valid.
* @param const char *expression; inserted expression in gui.
* @param int position; index in expression.
* @return 0 if char is valid, -1 in case of invalid.
*/
int CharAfterOperand(const char *expression, int position);
/**
* @author  Branislav Dubec
* @brief Check if number of left brackets is same as number of right brackets.
* @param const char *expression; inserted expression in gui.
* @return 0 when it is valid, -1 in case of invalid.
*/
int BracketValidation(const char *expression);
/**
*
* @author  Branislav Dubec
* <p>
* Additional information: Check if input is valid. Does not check mathematical errors such as
* divison by 0, sqrt(negative number)...
* </p>
* @brief Check if input is valid.
* @param const char *expression; inserted expression in gui.
* @return 0 when it is valid, -1 in case of invalid.
*/
int isValidInput(const char *expression);
/**
* @author  Branislav Dubec
* @brief Get number of operands in expression.
* @param const char *expression; inserted expression in gui.
* @param int* minAtStart; if minus is at the beginning of expression, sets to 1.
* @param int* numOflBracket; sets to the number of left Bracket in expression.
* @param int* numOfSin; sets to the number of sin appearance in expression.
* @param int* numOfCos; sets to the number of cos appearance in expression.
* @param int* numOfSqrt; sets to the number of sqrt appearance in expression.
* @param int* numOfFact; sets to the number of '!' or '^' appearance in expression.
* @param int* numOfMult; sets to the number of '*', '/' or '%' appearance in expression.
* @param int* numOfOperands; sets to the number of '+' or '-' appearance in expression.
*/
void GetNumOfOperands(const char* expression,int* minAtStart,int* numOfLBracket, int* numOfSin, int* numOfCos, int* numOfSqrt,
                      int* numOfFact, int* numOfMult, int* numOfOperands );

/**
*
* @author  Branislav Dubec
* @brief Calculate operations in expression and return result.
* <p>
* Additional information:Calculate all operations in expression with precedence of bracktets.
* In case of mathematical error; such as division by 0, factorial of negative
* number, function returns DBL_MAX.
* </p>
* @param const char *expression; inserted expression in gui.
* @return result, in case of mathematical error DBL_MAX.
*/
double result(const char *expression);
/**
 * @}
 */

/**
 * @defgroup Calculations
 * @{
 */
/**
* @author  Branislav Dubec
* @brief Adds two double values
* @param double addend1;
* @param double addend2;
* @return addition of 'addend1'+'addend2' or DBL_MAX in case of overflow.
*/
double addition(double addend1, double addend2);


/**
* @author  Branislav Dubec
* @brief Subtracts two double values
* @param double minuent;
* @param double subtrahend;
* @return subtraction of 'minuent'-'subtrahend' or DBL_MAX in case of overflow.
*/
double difference(double minuent, double subtrahent);


/**
* @author  Branislav Dubec
* @brief Adds two double values
* @param double multiply1;
* @param double multiplt2;
* @return multiplication of 'multiply1'*'multiply2' or DBL_MAX in case of overflow.
*/
double multiplication(double multiply1, double multiply2);


/**
*
* @author  Branislav Dubec
* @brief Divides 'divident' with 'divisor'.
* <p>
* Additional information: Check if 'divisor' is 0 before calling this function.
* </p>
* @param double divident;
* @param double divisor;
* @return division of 'divident'/'divisor' or DBL_MAX in case of overflow.
*/
double division(double divident, double divisor);

/**
*
* @author  Branislav Dubec
* <p>
* Additional information: Check if 'factor' is negative or decimal number before calling this function.
* </p>
* @brief Gets factorial of natural number.
* @param double factor;
* @return factorial of 'factor' or DBL_MAX in case of overflow.
*/
double factorial(double factor);


/**
* @author  Branislav Dubec
* @brief Return the power of 'base' to the power of 'exponent'.
* @param double base;
* @param double exponent;
* @return base^exponent, or DBL_MAX in case of overflow.
*/
double powering(double base, double exponent);


/**
*
* @author  Branislav Dubec
* @brief Return square root of 'base'.
* <p>
* Additional information: Check if base is 0 or negative number before calling this function.
* </p>
* @param double base;
* @return sqrt(base), or DBL_MAX in case of overflow.
*/
double m_sqrt(double base);




/**
*
* @author  Branislav Dubec
*
* @brief Gets modulo of 'divident' modulo 'divisor'.
* <p>
* Additional information: Check if 'divisor' is 0 before calling this function.
* </p>
* @param double divident;
* @param double divisor;
* @return modulo of 'divident'%'divisor' or DBL_MAX in case of overflow.
*/
double mod(double divident, double divisor);
/**
* @author  Boris Strbak
* @brief Gets sin of 'base'.
* <p>
*   Additional information: To simplify
*   calculation N*360 is substracted from
*   base (N is integer part of base/360), because value of
*   sine is periodically repeated on interval
*   2kPI. And then library function sin(alfa) is
*   called, where alfa is base converted to radians
* </p>
* @param double base;
* @return sin(base);
*/
double sine(double base);
/**
* @author  Boris Strbak
* @brief Gets cos of 'base'.
* <p>
*   Additional information: To simplify
*   calculation N*360 is substracted from
*   base (N is integer part of base/360), because value of
*   cosine is periodically repeated on interval
*   2kPI. And then library function cos(alfa) is
*   called, where alfa is base converted to radians
* </p>
* @param double base;
* @return cos(base);
*/
double cosine(double base);
/**
 * @}
 */

#endif
/*** End of file math_lib.h ***/
