#include <limits>
#include <gtest/gtest.h>
#include "math_lib.cpp"


//when there is error function returns DBL_MAX
//----------------------------------------------
//----------------------------------------------

//test function "addition"  for positive results
TEST(addition, positive_result)
{
  EXPECT_DOUBLE_EQ(409.798, addition(25.0,384.798));
  EXPECT_DOUBLE_EQ(59.88, addition(25.1,34.78));
  EXPECT_DOUBLE_EQ(33.0, addition(25.0,8.0));
  EXPECT_DOUBLE_EQ(17.0, addition(25.0,-8.0));
  EXPECT_DOUBLE_EQ(0.0, addition(8.01,-8.01));
}

//test function "addition" for negative results
TEST(addition, negative_result)
{
  EXPECT_DOUBLE_EQ(-359.798, addition(25.0,-384.798));
  EXPECT_DOUBLE_EQ(-9.68, addition(25.1,-34.78));
  EXPECT_DOUBLE_EQ(-17, addition(-25.0,8.0));
  EXPECT_DOUBLE_EQ(-16.01, addition(-8.0,-8.01));
  EXPECT_DOUBLE_EQ(-8.0, addition(-8.0,-0.0));
}

//test function "addition" for operations with limits
TEST(addition, limits)
{
  double maxminus = DBL_MAX -1.0;

  EXPECT_DOUBLE_EQ(DBL_MAX,addition(DBL_MAX,10.0));
  EXPECT_DOUBLE_EQ(DBL_MAX,addition(-DBL_MAX,-100.0));

  EXPECT_DOUBLE_EQ(DBL_MAX, addition(maxminus,10.0));
}

//----------------------------------------------
//----------------------------------------------

//test function "difference"  for positive results
TEST(difference, positive_result)
{
  EXPECT_DOUBLE_EQ(409.798, difference(25.0,-384.798));
  EXPECT_DOUBLE_EQ(59.88, difference(25.1,-34.78));
  EXPECT_DOUBLE_EQ(33.0, difference(25.0,-8.0));
  EXPECT_DOUBLE_EQ(17.0, difference(25.0,8.0));
  EXPECT_DOUBLE_EQ(0.0, difference(8.01,8.01));
  EXPECT_DOUBLE_EQ(2.0, difference(-8.01,-10.01));
}

//test function "difference" for negative results
TEST(difference, negative_result)
{
  EXPECT_DOUBLE_EQ(-359.798, difference(25.0,384.798));
  EXPECT_DOUBLE_EQ(-9.68, difference(25.1,34.78));
  EXPECT_DOUBLE_EQ(-17, difference(-25.0,-8.0));
  EXPECT_DOUBLE_EQ(-16.01, difference(-8.0,8.01));
  EXPECT_DOUBLE_EQ(-8.0, difference(-8.0,-0.0));
}

//test function "difference" for operations with limits
TEST(difference, limits)
{
  double maxminus = DBL_MAX -1.0;

  EXPECT_DOUBLE_EQ(DBL_MAX,difference(DBL_MAX,-2.0));
  EXPECT_DOUBLE_EQ(DBL_MAX,difference(-DBL_MAX,10.0));

  EXPECT_DOUBLE_EQ(DBL_MAX, difference(maxminus,-1.0));
}

//----------------------------------------------
//----------------------------------------------

//test function "multiplication"  for positive results
TEST(multiplication, positive_result)
{
	EXPECT_DOUBLE_EQ(4.0, multiplication(16.0,0.25));
	EXPECT_DOUBLE_EQ(42.0, multiplication(21.0,2.0));
	EXPECT_DOUBLE_EQ(42.0, multiplication(-21.0,-2.0));
	EXPECT_DOUBLE_EQ(58.718, multiplication(21.352,2.75));
	EXPECT_DOUBLE_EQ(16.291576, multiplication(21.352,0.763));
	EXPECT_DOUBLE_EQ(16.291576, multiplication(-21.352,-0.763));
}

//test function "multiplication" for negative results
TEST(multiplication, negative_result)
{
	EXPECT_DOUBLE_EQ(-4.0, multiplication(-16.0,0.25));
	EXPECT_DOUBLE_EQ(-42.0, multiplication(21.0,-2.0));
	EXPECT_DOUBLE_EQ(-42.0, multiplication(-21.0,2.0));
	EXPECT_DOUBLE_EQ(-58.718, multiplication(21.352,-2.75));
	EXPECT_DOUBLE_EQ(-16.291576, multiplication(-21.352,0.763));
	EXPECT_DOUBLE_EQ(-16.291576, multiplication(-21.352,0.763));
}

//test function "multiplication" for operations with limits
TEST(multiplication, limits)
{
  double maxhalf = DBL_MAX /2.0;

  EXPECT_DOUBLE_EQ(DBL_MAX,multiplication(DBL_MAX,1.000001));
  EXPECT_DOUBLE_EQ(DBL_MAX,multiplication(DBL_MAX,1.0));
  EXPECT_DOUBLE_EQ(DBL_MAX,multiplication(-DBL_MAX,1.002));

  EXPECT_DOUBLE_EQ(DBL_MAX, multiplication(maxhalf,2.0));
}

//----------------------------------------------
//----------------------------------------------

//test function "division"  for positive results
TEST(division, positive_result)
{
	EXPECT_DOUBLE_EQ(3.2653061224489792, division(16.0,4.9));
	EXPECT_DOUBLE_EQ(42.0, division(21.0,0.5));
	EXPECT_DOUBLE_EQ(42.0, division(-21.0,-0.5));
	EXPECT_DOUBLE_EQ(7.7643636363636368, division(21.352,2.75));
	EXPECT_DOUBLE_EQ(27.984272608125821, division(21.352,0.763));
	EXPECT_DOUBLE_EQ(27.984272608125821, division(-21.352,-0.763));
}

//test function "division" for negative results
TEST(division, negative_result)
{
	EXPECT_DOUBLE_EQ(-3.2653061224489792, division(16.0,-4.9));
	EXPECT_DOUBLE_EQ(-42.0, division(-21.0,0.5));
	EXPECT_DOUBLE_EQ(-42.0, division(21.0,-0.5));
	EXPECT_DOUBLE_EQ(-7.7643636363636368, division(-21.352,2.75));
	EXPECT_DOUBLE_EQ(-27.984272608125821, division(21.352,-0.763));
	EXPECT_DOUBLE_EQ(-27.984272608125821, division(-21.352,0.763));
}

//test function "division" for operations with limits
TEST(division, limits)
{
  double maxhalf = DBL_MAX /2.0;

  EXPECT_DOUBLE_EQ(DBL_MAX,division(DBL_MAX,0.99));
  EXPECT_DOUBLE_EQ(DBL_MAX,division(-DBL_MAX,0.99));

  EXPECT_DOUBLE_EQ(DBL_MAX, division(maxhalf,0.5));

}

//----------------------------------------------
//----------------------------------------------

//test function "factorial"  for positive results
TEST(factorial, positive_result)
{
  EXPECT_DOUBLE_EQ(120.0, factorial(5.0));
  EXPECT_DOUBLE_EQ(6227020800.0, factorial(13));
  EXPECT_DOUBLE_EQ(1.0, factorial(1.0));
}

//----------------------------------------------
//----------------------------------------------

//test function "powering"  for positive results
TEST(powering, positive_result)
{
  EXPECT_DOUBLE_EQ(25.0, powering(5.0,2.0));
  EXPECT_DOUBLE_EQ(0.012345679012345678, powering(3.0,-4.0));
  EXPECT_DOUBLE_EQ(0.020333466491280209, powering(4.0,-2.81));
  EXPECT_DOUBLE_EQ(28561.0, powering(-13.0,4.0));
}

//test function "powering" for negative results
TEST(powering, negative_result)
{
  EXPECT_DOUBLE_EQ(-125.0, powering(-5.0,3.0));
  EXPECT_DOUBLE_EQ(-0.037037037037037035, powering(-3.0,-3.0));
  EXPECT_DOUBLE_EQ(-371293, powering(-13.0,5.0));
}

//----------------------------------------------
//----------------------------------------------

//test function "sqrt" for operations with positive numbers
TEST(sqrt, positive_numbers)
{
  EXPECT_DOUBLE_EQ(5.0, sqrt(25.0));
  EXPECT_DOUBLE_EQ(9.0, sqrt(81.0));
  EXPECT_DOUBLE_EQ(25.4, sqrt(645.16));
  EXPECT_DOUBLE_EQ(0.0, sqrt(0.0));
  EXPECT_DOUBLE_EQ(1.0, sqrt(1.0));
}



//----------------------------------------------
//----------------------------------------------

//test function "sine" for operations with positive numbers
TEST(sine, positive_numbers)
{
  EXPECT_DOUBLE_EQ(0.70710678118654746,sine(45));
  EXPECT_DOUBLE_EQ(-0.5,sine(930));
  EXPECT_DOUBLE_EQ(0.59622487496561583,sine(36.6));
  EXPECT_DOUBLE_EQ(0.015707317311820675,sine(0.9));
}

//----------------------------------------------
//----------------------------------------------

//test function "sine" for operations with positive numbers
TEST(sine, negative_numbers)
{
    EXPECT_DOUBLE_EQ(-0.015707317311820276,sine(-360.9));
    EXPECT_DOUBLE_EQ(-0.60042022532588402,sine(-36.9));
    EXPECT_DOUBLE_EQ(-0.5028690945602079,sine(-30.19));
    EXPECT_DOUBLE_EQ(0.98328669868730434,sine(-1360.49));
    EXPECT_DOUBLE_EQ(0.86854502735789818,sine(-960.29));
    EXPECT_DOUBLE_EQ(0.0,sine(-360));
}

//----------------------------------------------
//----------------------------------------------

//test function "cosine" for operations with positive numbers
TEST(cosine, positive_numbers)
{
  EXPECT_DOUBLE_EQ(0.70710678118654757,cosine(45));
  EXPECT_DOUBLE_EQ(-0.8660254037844386,cosine(930));
  EXPECT_DOUBLE_EQ(0.80281747519111457,cosine(36.6));
  EXPECT_DOUBLE_EQ(0.99987663248166059,cosine(0.9));
}

//----------------------------------------------
//----------------------------------------------

//test function "cosine" for operations with positive numbers
TEST(cosine, negative_numbers)
{
    EXPECT_DOUBLE_EQ(1.0,cosine(-360.0));
    EXPECT_DOUBLE_EQ(0.79968465848709058,cosine(-36.9));
    EXPECT_DOUBLE_EQ(0.86436258233232,cosine(-30.19));
    EXPECT_DOUBLE_EQ(0.18206391236217909,cosine(-1360.49));
    EXPECT_DOUBLE_EQ(-0.49561026568450678,cosine(-960.29));
}

//----------------------------------------------
//----------------------------------------------

//test function "isValidInput" for operations with positive numbers
TEST(isValidInput, easy_Valid)
{
    EXPECT_DOUBLE_EQ(0,isValidInput("3+4"));
    EXPECT_DOUBLE_EQ(0,isValidInput("3.12+4.3438439-123"));
    EXPECT_DOUBLE_EQ(0,isValidInput("3.12+4.3438439-123*345"));
    EXPECT_DOUBLE_EQ(0,isValidInput("3.12+4.3438439-123*345/23"));
    EXPECT_DOUBLE_EQ(0,isValidInput("-3.12+4.3438439-123*345/23"));
    EXPECT_DOUBLE_EQ(0,isValidInput("3.12+4-123*345/23"));
    EXPECT_DOUBLE_EQ(0,isValidInput("-3.12+4.3439-123*34/23"));
    EXPECT_DOUBLE_EQ(0,isValidInput("3.12+4.34439-123*345/287*0"));
    EXPECT_DOUBLE_EQ(0,isValidInput("3.12+4.3438439%2-123*345/23"));
    EXPECT_DOUBLE_EQ(0,isValidInput("-21343.12+4.3438439-123*345/23"));
    EXPECT_DOUBLE_EQ(0,isValidInput("213.12+4.3438439-123^2*345/23"));
    EXPECT_DOUBLE_EQ(0,isValidInput("3.12+4.3438439^3^3^3-123*345/23"));
    EXPECT_DOUBLE_EQ(0,isValidInput("3.12+4.3438439-1-1-1-1-1-1-1-123*345/23"));
    EXPECT_DOUBLE_EQ(0,isValidInput("4.0987+4.3438439-123*345/23"));
    EXPECT_DOUBLE_EQ(0,isValidInput("10000+4.3438439-123*345/23"));
    EXPECT_DOUBLE_EQ(0,isValidInput("0.765+4.3438439-123*345/23"));
    EXPECT_DOUBLE_EQ(0,isValidInput("1-1-1-11-1-1-1-1/1-1-1-11-1^1-11*1-1-11-1-1-11-11-1-1-1-11-1-1-1-11-1-1-11-1-11-1-11-1-11-1-11-1-11-1-1-11-11-2-21-1-21-212-1212-1-2-12-1-21-2-12"));
}

TEST(isValidInput, hard_Valid)
{
    EXPECT_DOUBLE_EQ(roundf(0),isValidInput("3+(-4)"));
    EXPECT_DOUBLE_EQ(roundf(0),isValidInput("(3.12+4.3438439)-123"));
    EXPECT_DOUBLE_EQ(roundf(0),isValidInput("3.12+4.3438439-123*345"));
    EXPECT_DOUBLE_EQ(roundf(0),isValidInput("(3.12+4.3438439-123*345/23)"));
    EXPECT_DOUBLE_EQ(roundf(0),isValidInput("(-3.12+(4.3438439-123*345/23))"));
    EXPECT_DOUBLE_EQ(roundf(0),isValidInput("(3.12+4)-123*345/23"));
    EXPECT_DOUBLE_EQ(roundf(0),isValidInput("sqrt(-3.12+4.3439)-123*34/23"));
    EXPECT_DOUBLE_EQ(roundf(0),isValidInput("3.12+4.34439-123*345/287*0"));
    EXPECT_DOUBLE_EQ(roundf(0),isValidInput("3.12+4.3438439%2-123*345/23"));
    EXPECT_DOUBLE_EQ(roundf(0),isValidInput("-21343.12+4.3438439-123*345/23"));
    EXPECT_DOUBLE_EQ(roundf(0),isValidInput("213.12+4.3438439-123^2*345/23"));
    EXPECT_DOUBLE_EQ(roundf(0),isValidInput("3.12+4.3438439^3^3^3-123*345/23"));
    EXPECT_DOUBLE_EQ(roundf(0),isValidInput("3.12+4.3438439-1-1-1-1-1-1-1-123*345/23"));
    EXPECT_DOUBLE_EQ(roundf(0),isValidInput("(((((4.0987+4.3438439)-123*345/23))))"));
    EXPECT_DOUBLE_EQ(roundf(0),isValidInput("10000+(4.3438439-123*345)/23"));
    EXPECT_DOUBLE_EQ(roundf(0),isValidInput("0.765+4.3438439-(123*345/23)"));
    EXPECT_DOUBLE_EQ(roundf(0),isValidInput("(1-1-1-11-1)-1-(1-(1)/1-1-1)-11-(1^1-11)*1-1"));
}

TEST(isValidInput, hard_inValid)
{
    EXPECT_DOUBLE_EQ(roundf(-1),isValidInput("3+(--4)"));
    EXPECT_DOUBLE_EQ(roundf(-1),isValidInput("(3.12+4.34.38439)-123"));
    EXPECT_DOUBLE_EQ(roundf(-1),isValidInput("3.12+4..3438439-123*345"));
    EXPECT_DOUBLE_EQ(roundf(-1),isValidInput("(3.12+4.3438439-.123*345/23)"));
    EXPECT_DOUBLE_EQ(roundf(-1),isValidInput("(-3.12+.(4.3438439-123*345/23))"));
    EXPECT_DOUBLE_EQ(roundf(-1),isValidInput("(3.12+4.)-123*345/23"));
    EXPECT_DOUBLE_EQ(roundf(-1),isValidInput("3.12+4.3443.9-123*345/287*0"));
    EXPECT_DOUBLE_EQ(roundf(-1),isValidInput("3.12+4.3438439%2-123*3OOO45/23"));
    EXPECT_DOUBLE_EQ(roundf(-1),isValidInput("-21343.12+4.3438439..-123*345/23"));
    EXPECT_DOUBLE_EQ(roundf(-1),isValidInput("213.12+4.3438439-123^2*34O5/23"));
    EXPECT_DOUBLE_EQ(roundf(-1),isValidInput("3.12+4.3438439^3^3^3-.-123*345/23"));
    EXPECT_DOUBLE_EQ(roundf(-1),isValidInput("3.12+4.3438439-1-1-1-1-.1-1-1-123*345/23"));
    EXPECT_DOUBLE_EQ(roundf(-1),isValidInput("(((((4.0987+4.343843k9)-123*345/23))))"));
    EXPECT_DOUBLE_EQ(roundf(-1),isValidInput("10000+(4.3438439I-123*345)/23"));
    EXPECT_DOUBLE_EQ(roundf(-1),isValidInput("0.765+4.3438439-u(123*345/23)"));
    EXPECT_DOUBLE_EQ(roundf(-1),isValidInput("(1-1-1-11-1)r-1-(1-(1)/1-1co to kontrolujee vzdyt to je fajn-1)-11-(1^1-11)*1-1"));
}

TEST(result, result)
{
    EXPECT_DOUBLE_EQ(roundf(-1),result("3-4"));  //tento riadok sposobuje stoi error
    EXPECT_DOUBLE_EQ(roundf(-115.53615600000001*100000)/100000,result("(3.12+4.3438439)-123"));
    EXPECT_DOUBLE_EQ(roundf(-1837.5361559999999*100000)/100000,result("(3.12+4.3438439-123*345/23)"));
    EXPECT_DOUBLE_EQ(roundf(-1843.7761559999999*100000)/100000,result("(-3.12+(4.3438439-123*345/23))"));
    EXPECT_DOUBLE_EQ(roundf(-1837.88*100000)/100000,result("(3.12+4)-123*345/23"));
    EXPECT_DOUBLE_EQ(roundf(-180.719787*100000)/100000,result("sqrt(-3.12+4.3439)-123*34/23"));
    EXPECT_DOUBLE_EQ(roundf(7.46439*100000)/100000,result("3.12+4.34439-123*345/287*0"));
    EXPECT_DOUBLE_EQ(roundf(-1841.5361559999999*100000)/100000,result("3.12+4.3438439%2-123*345/23"));
    EXPECT_DOUBLE_EQ(roundf(-23183.776156*100000)/100000,result("-21343.12+4.3438439-123*345/23"));
    EXPECT_DOUBLE_EQ(roundf(-226717.53615900001*100000)/100000,result("213.12+4.3438439-123^2*345/23"));
    EXPECT_DOUBLE_EQ(roundf(-1827.950195*100000)/100000,result("3.12+1.34^3^3-123*345/23"));
    EXPECT_DOUBLE_EQ(roundf(-1844.5361559999999*100000)/100000,result("3.12+4.3438439-1-1-1-1-1-1-1-123*345/23"));
    EXPECT_DOUBLE_EQ(roundf(-1836.5574561*100000)/100000,result("(((((4.0987+4.3438439)-123*345/23))))"));
    EXPECT_DOUBLE_EQ(roundf(8155.18886278*100000)/100000,result("10000+(4.3438439-123*345)/23"));
    EXPECT_DOUBLE_EQ(roundf(-1839.8911561*100000)/100000,result("0.765+4.3438439-(123*345/23)"));
    EXPECT_DOUBLE_EQ(roundf(-14*100000)/100000,result("(1-1-1-11-1)-1-(1-(1)/1-1-1)-11-(1^1-11)*1-1"));
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
