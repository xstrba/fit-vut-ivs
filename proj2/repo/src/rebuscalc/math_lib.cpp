#include "float.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <ctype.h>
#include "math_lib.h"
#include "cmath"

using namespace std;
double GetNum2(string getNum, int IndexofOperator, int* indexofNum2){
    int decimalNumber=0;
     (*indexofNum2)=IndexofOperator+1;
    for(;  (unsigned ) (*indexofNum2)< getNum.length();  (*indexofNum2)++){
        if(isdigit(getNum[  (*indexofNum2)])){
            continue;
        }
        else if(getNum[  (*indexofNum2)]=='.'){
            decimalNumber=1;
            continue;
        }
        else if((unsigned)(*indexofNum2)  == getNum.length()-1){
            break;
        }
        else{
            break;
        }
    }


    if(decimalNumber==1){
        decimalNumber=0;
        if( IndexofOperator+1==(*indexofNum2) -1){
        string substr=getNum.substr(IndexofOperator+1,1);
          return std::stod(substr);
        }
        else{
          string substr=getNum.substr(IndexofOperator+1,(*indexofNum2) -1);
             return std::stod(substr);
        }

    }
    else{
        if(IndexofOperator+1==(*indexofNum2) -1){
        string substr=getNum.substr(IndexofOperator+1,1);
         return std::stoi(substr);

        }
        else{
          string substr=getNum.substr(IndexofOperator+1,(*indexofNum2) -1);
            return  std::stoi(substr);
        }

    }// num2=number after '^'

    return DBL_MAX;

   }// End of function GetNum2
double GetNum1(string getNum, int IndexofOperator, int* numofOperands,
               int* indexofNum1, int start){
    int decimalNumber=0;
    double neg = 1;
     (*indexofNum1)=IndexofOperator-1;
    for(;   (*indexofNum1)>=start;  (*indexofNum1)--){
        if(isdigit(getNum[  (*indexofNum1)])){
            continue;
        }
        else if(getNum[  (*indexofNum1)]=='.'){
            decimalNumber=1;
            continue;
        }
        else if(getNum[  (*indexofNum1)] == '-' &&   (*indexofNum1)==0){
            numofOperands--;
            neg = -1;
            break;
        }
        else{
            break;
        }
    }
 if(  (*indexofNum1)<= start){(*indexofNum1)=start;}
 else
 {
       (*indexofNum1)++;
 }
 if(neg==-1){
     (*indexofNum1)++;
 }
 if(decimalNumber==1){
     decimalNumber=0;
     if(  (*indexofNum1) ==IndexofOperator){
        string substr=getNum.substr(  (*indexofNum1),1);
        double tmp = std::stod(substr);
         return neg*tmp;
     }
     else{
       string substr=getNum.substr(  (*indexofNum1),IndexofOperator);
       double tmp = std::stod(substr);
        return neg*tmp;

 }
 }
 else{
     if((*indexofNum1) == IndexofOperator){
        string substr=getNum.substr(  (*indexofNum1),1);
        int tmp = std::stoi(substr);
         return neg*tmp;
     }
     else{
       string substr=getNum.substr(  (*indexofNum1),IndexofOperator);
       int tmp = std::stoi(substr);
        return neg*tmp;
     }

 } // num1=number before '!' or '^'
 return DBL_MAX;
} // End of function GetNum1
void SolveOperands(string & Result, int start){
    double num1;
    double num2;
    int IndexofNum1;
    int IndexofNum2;
    int count = 0;
    for(unsigned int IndexOfOperator=0;IndexOfOperator<Result.length();IndexOfOperator++){
        if(Result[IndexOfOperator]=='+' || Result[IndexOfOperator]=='-'  ){
            if(IndexOfOperator==0){
                count = 2;
                        continue;
            }
            if(Result[IndexOfOperator]=='+' &&Result[IndexOfOperator+1]=='-' ){
                Result[IndexOfOperator]='-';
                Result.erase(IndexOfOperator+1,1);
            }
            if(Result[IndexOfOperator]=='-' &&Result[IndexOfOperator+1]=='-' ){
                Result[IndexOfOperator]='+';
                Result.erase(IndexOfOperator+1,1);
            }
            num1=(GetNum1(Result,IndexOfOperator, 0, &IndexofNum1, start));
            num2=GetNum2( Result,  IndexOfOperator, &IndexofNum2);
            if(IndexofNum1<0) IndexofNum1=0;

            if(count==2 || num1<0){IndexofNum1--;
                count =1 ;
            }

         if(Result[IndexOfOperator]=='+'){
             num1=addition(num1,num2);
             string substr=std::to_string(num1);
             Result.replace(IndexofNum1, (IndexofNum2-IndexofNum1 ),substr);

             IndexOfOperator=IndexofNum1+substr.length() -1;
             continue;
         }
         if(Result[IndexOfOperator]=='-'){

             num1=difference(num1,num2);
             string substr=std::to_string(num1);

             Result.replace(IndexofNum1, (IndexofNum2-IndexofNum1),substr);
             IndexOfOperator=IndexofNum1+substr.length() - 1;
             continue;
         }

        }//end of if loop when we have found position of +,-
    }//end of for loop that searches position of +,-
}
void SolveMultPrecedence(string & Result, int start,  int *numOfOperands){
    double num1;
    double num2;
int IndexofNum1;
int IndexofNum2;
    for(unsigned int IndexOfOperator=0;IndexOfOperator<Result.length();IndexOfOperator++){
        if(Result[IndexOfOperator]=='*' || Result[IndexOfOperator]=='/' || Result[IndexOfOperator]=='%' ){

            num1=(GetNum1(Result,IndexOfOperator, numOfOperands, &IndexofNum1, start));
            num2=GetNum2( Result,  IndexOfOperator, &IndexofNum2);
            if(IndexofNum1<0) IndexofNum1=0;
         if(Result[IndexOfOperator]=='*'){
             num1=multiplication(num1,num2);
             string substr=std::to_string(num1);
             Result.replace(IndexofNum1, (IndexofNum2-IndexofNum1),substr);
             IndexOfOperator=IndexofNum1+substr.length() -1;
             continue;
         }
         if(Result[IndexOfOperator]=='/'){
             if(num2==0){
                 Result="MAXFLOAT";
             }
             num1=division(num1,num2);
             string substr=std::to_string(num1);

             Result.replace(IndexofNum1, (IndexofNum2-IndexofNum1),substr);
             IndexOfOperator=IndexofNum1+substr.length() - 1;
             continue;
         }
         if(Result[IndexOfOperator]=='%'){
             if(num2==0){
                 Result="MAXFLOAT";
             }
             num1=mod(num1,num2);
             string substr=std::to_string(num1);
             Result.replace(IndexofNum1, (IndexofNum2-IndexofNum1)-1,substr);
             IndexOfOperator=IndexofNum1+substr.length() - 1;
             continue;
         }
        }//end of if loop when we have found position of *,/,%
    }//end of for loop that searches position of *,/,%

}
void SolvePowFact(string & Result, int start, int *numOfOperands){
    double num1=0;
    double num2=0;

    int indexOfNum1;
    int indexOfNum2;
    for(unsigned int IndexOfOperator = start; IndexOfOperator < Result.length(); IndexOfOperator++){
        if(Result[IndexOfOperator]=='^' || Result[IndexOfOperator]=='!'){
            num1=(GetNum1(Result,IndexOfOperator, numOfOperands, &indexOfNum1, start));
             if(indexOfNum1<0) indexOfNum1=0;
            if(Result[IndexOfOperator] == '!'){
                 if(fmod(num1,1.0) != 0 || num1<=0){
                       Result="DBL_MAX";
                       return;
                   }
                   num1=factorial(num1);
                   string substr=std::to_string(num1);
                   Result.replace(indexOfNum1, (IndexOfOperator-indexOfNum1)+1,substr);
                  IndexOfOperator = indexOfNum1 + substr.length()-1;
               } // End of if, where operand is '!'
               else{
                num2=GetNum2( Result,  IndexOfOperator, &indexOfNum2);

                  num1= powering(num1,num2);
                  string substr=std::to_string(num1);
                  Result.replace(indexOfNum1, (indexOfNum2 -indexOfNum1),substr);
                  IndexOfOperator=indexOfNum1+substr.length()-1;
               } // end of else, that matches '^'
        }//end of if statement, that matches  '!' or '^' in for loop

    } // end of foor loop, that search for '!' or '^'
}//end of function SolvePowFact
void GetNumOfOperands(const char* expression,int* minAtStart,int* numOfLBracket, int* numOfSin, int* numOfCos, int* numOfSqrt,
                      int* numOfFact, int* numOfMult, int* numOfOperands ){
    for(unsigned int i = 0; i < strlen(expression); i++)
    {
                   if(expression[i]=='(')
                   {
                       (*numOfLBracket)++;
                   }
                   if(expression[i]=='^' || expression[i]=='!'){
                       (*numOfFact)++;
                   }
                   if(expression[i]=='*' || expression[i]=='/' || expression[i]=='%' ){
                       (*numOfMult)++;
                   }
                   if(expression[i]=='+' || expression[i]=='-'){
                       (*numOfOperands)++;
                       if(i==0) (*minAtStart)=1;
                   }
                   if(expression[i]=='c'){
                       i += 3;
                       (*numOfLBracket)++;
                       (*numOfCos)++;
                   }
                   if(expression[i]=='s'){
                       if(expression[i+1] == 'i'){
                           i+=3;
                           (*numOfSin)++;
                       }
                       else{
                           i+=4;
                           (*numOfSqrt)++;
                       }
                       (*numOfLBracket)++;
                   }

             }
}// End of function GetNumOfOpearnds


void GetValueFromSinCosSqrt(string & tmp)
{
    int indexofNum=0;
    double num;
    for(unsigned int i = 0; i < tmp.length(); i++){
        if(tmp[i] == 's' ){
            if(tmp[i+1] == 'i'){
                int j = i+2;
                num=GetNum2(tmp,j, &indexofNum);
                if(tmp[j+1]=='-'){
                    num=-1*num;
                }
                 num=sine(num);
                 string substr=std::to_string(num);
                 tmp.replace(i,indexofNum-i, substr);
                 i=j+substr.length()-1;
                continue;
            }//end of sin
            int j = i+3;
            num = GetNum2(tmp,j, &indexofNum);
            if(tmp[j+1]=='-'){
                num=-1*num;
            }
            if(num<0){
                tmp="DBL_MAX";
                return;
            }
             num=m_sqrt(num);
             string substr=std::to_string(num);
             tmp.replace(i, indexofNum-i,substr);
             i=j+substr.length()-1;
            continue;
        }
        if(tmp[i] == 'c'){
            int j = i+2;
            if(tmp[j+1]=='-'){
                num=-1*num;
            }
            num=GetNum2(tmp,j,&indexofNum);
             num=cosine(num);
             string substr=std::to_string(num);
             tmp.replace(i, indexofNum-i,substr);
             i=j+substr.length()-1;
        }

     }

   }

void BracketEvalvuation(string & evalBracket, int start, int end){

     int min_atStart=0;
     int numofSin=0;
     int numofCos=0;
     int numofStrq=0;
     int numofFact=0; //also for pow
     int numofMultPrecedence=0; // *,/,%
     int numofOperands=0;  //+,-
     string tmp = evalBracket.substr(start+1,end-start);
     const char* expression=tmp.c_str();
     int zero =0;
     GetNumOfOperands(expression, &min_atStart, &zero, &numofSin,
                      &numofCos, &numofStrq, &numofFact, &numofMultPrecedence, &numofOperands);

     int numofTrigonoFunctions=numofCos+numofSin+numofStrq;
     if(numofTrigonoFunctions>0){
         GetValueFromSinCosSqrt(tmp);
     }
     if(numofFact>0){
         SolvePowFact(tmp, 0, &numofOperands);
         if(tmp == "DBL_MAX"){
            evalBracket="DBL_MAX";
            return;
         }
     }//end of if, that matches '!' or '^'

     if(numofMultPrecedence > 0){
         SolveMultPrecedence(tmp, 0, &numofOperands );
         //vysledok v parseResult
         if(tmp == "DBL_MAX"){
             evalBracket="DBL_MAX";
             return;
         }
     }
     if(numofOperands>0){
        SolveOperands(tmp, 0);
      }
    if(numofCos >0|| numofSin > 0) start=start-3;
     if(numofStrq>0)start=start-4;
     evalBracket.replace(start, end-start+1, tmp);
     for(unsigned int i = start; i < evalBracket.length(); i++){
         if(evalBracket[i] == ')')
         {
            evalBracket.erase(i,1);
             break;
         }
     }

        return;
}


int CharisOperand(const char *expression, int position){

    if(expression[position]=='*' ||expression[position]=='/' ||expression[position]=='%' ||expression[position]=='+' ||
            expression[position]=='-' ||expression[position]=='n' ||expression[position]=='t' ||
            expression[position]=='s' ||expression[position]=='('||expression[position]=='!' ||expression[position]==')'){
        return 0;
    }
    return -1;
}
int CharAfterlBracket(const char *expression, int position){
    //When we have operand, we accept digit, -,s for sin, strq and c for cos
    if(expression[position]=='s' || expression[position]=='c' || expression[position]=='-'){
        if(expression[position+1]=='t'){
         return 2;
        }
         return 1;
     }
    if(isdigit(expression[position])  || expression[position]=='('){
        return 0;
    }
    return -1;
 }
int CharAfterOperand(const char *expression, int position){
   //return value 2 for s --strq;
   //return value 1 for s --sin, cos;
   //return value 0 for digit and '('
   //return -1 when fault appears
   if(expression[position]=='s' || expression[position]=='c'){
       if(expression[position+1]=='t'){
        return 2;
       }
        return 1;
    }
   if(isdigit(expression[position])  || expression[position]=='('){
       return 0;
   }
   return -1;
}
int BracketValidation(const char *expression){
  int Bracket=0;
  for (int  i = 0;  i < (signed) strlen(expression);  i++) {
    if (expression[i] == '(') {
      Bracket++;
    }

    if (expression[i] == ')') {
      Bracket--;
    }

    if (Bracket<0) {
      return -1;
    }

  }
  if(Bracket>0){
    return -1;
  }
  return 0;
} // End of function  BracketValidation

int isValidInput(const char *expression)
{
  //Firstly, check bracket, just if left counter justifies with right counter
  if(BracketValidation(expression) == -1){
    return -1;
  }
  int number=0;
  int dot=0;
  int op_minus_start=0;
  for (int  i = 0;  i < (signed) strlen(expression);  i++) {

    //For the first char in expression, we accept chars: '-'-for negative number, 's'-for sin;sqrt,
    //'c'-for cos,'(', or any number

    if(i == 0 ){
        switch (expression[i]) {
          case '(':
            continue;
          case 'c':
            i += 2;
            continue;
          case '-':
             op_minus_start=1;
            continue;
          case 's':
            if(expression[i+1] == 'i'){
              i += 2;
              continue;
            }
            else{
              i += 3;
              continue;
            }
          default:
            if(isdigit(expression[i])){
                number++;
                continue;
            }
              return -1;
        }

    } // End of condition for first char

    //After "minus at the start", we check out what comes and continue in the loop
    if(op_minus_start==1){
        op_minus_start = 0;
        if(CharAfterOperand(expression,i)==-1){
            // throw std::runtime_error("error");
            return -1;
        }
        //char is digit
        if(CharAfterOperand(expression,i)==0){
           number++;
           continue;
        }
        //char is sin,cos
        if(CharAfterOperand(expression,i)==1){
            i+=2;
            continue;
        }
        //char is strq
        if(CharAfterOperand(expression,i)==2){
            i+=3;
            continue;
        }
    }// End of condition when minus is first


    //For the last char
    if(i == (signed) (strlen(expression)-1)){
        if(isdigit(expression[i]) || expression[i] == ')' || expression[i]=='!'){
            return 0;
        }
        return -1;
    } // Last char in expression

    switch (expression[i]) {
    case '*':
    case '/':
    case '+':
    case '-':
    case '%':
    case '^':
    {
        if(number < 0 || CharAfterOperand(expression,i+1)==-1){
            return -1;
        }
        number--;
        dot=0;
        continue;
    }
    case '(':
      if(CharAfterlBracket(expression,i+1)==-1 || CharisOperand(expression,i-1)==-1){
          return -1;
      }
      continue;
    case 'c':
        if( CharisOperand(expression,i-1)==-1){
            return -1;
        }
      i += 2;
      dot=0;
      continue;
    case 's':
        if( CharisOperand(expression,i-1)==-1){
            return -1;
        }
      dot=0;
      if(expression[i+1] == 'i'){
          i += 2;
          continue;
       }
       else{
          i += 3;
          continue;
        }
    case '!':
        if(number < 0 ){
            return -1;
        }
        dot=0;
        number--;
        continue;
     case '.':
        if(number<0 || !isdigit(expression[i+1]) || dot == 1){
            return -1;
        }
        dot=1;
        continue;
     case ')':
        if(isdigit(expression[i-1]) || expression[i-1] == '!' ||CharisOperand(expression,i+1)==0  ){
            continue;
        }
        else{
            return -1;
        }
     default:
        if(isdigit(expression[i])){
            number=1;
            continue;
        }
          return -1;
    } //end of switch statement

  }//end of for loop, where we check all char's in expression

  return 0;

} // End of function isValitInput

 double result(const char *expression)
{
     int count=0;

     string parseResult=(string) expression; // our expression, easier work with string
//     std::cout << parseResult;

     int min_atStart=0;
     int numofLbracket=0;
     int numofSin=0;
     int numofCos=0;
     int numofStrq=0;
     int numofFact=0; //also for pow
     int numofMultPrecedence=0; // *,/,%
     int numofOperands=0;  //+,-




     GetNumOfOperands(expression, &min_atStart, &numofLbracket, &numofSin,
                      &numofCos, &numofStrq, &numofFact, &numofMultPrecedence, &numofOperands);
     if(numofLbracket!=0){
         int  bracket [numofLbracket];
         int IndexLBracket;
         unsigned int IndexRBracket;
         count=0;
        for(IndexRBracket = 0; IndexRBracket  < parseResult.length(); IndexRBracket ++){
            if(parseResult[IndexRBracket ]=='('){
                bracket[count]=IndexRBracket ;
                count++;
            }
            if(parseResult[IndexRBracket ]==')'){
                 IndexLBracket = bracket[count-1]; // j= position of lBracket
                                         //i=posiion of rBracket
                count--;
                BracketEvalvuation(parseResult, IndexLBracket , IndexRBracket );
                IndexRBracket = IndexLBracket + 1;
                if(parseResult=="WRONG"){
                    return DBL_MAX;
                }
                 continue;
            }

        }
        while(count> 0){
            count--;
            int IndexLBracket = bracket[count];
              BracketEvalvuation(parseResult, IndexLBracket , parseResult.length());
        }

     } // end of condition to remove brackets

     int numofTrigonoFunctions=numofCos+numofSin+numofStrq;

     if(numofTrigonoFunctions > 0){
          GetValueFromSinCosSqrt(parseResult);
}


         if(numofFact>0){
             SolvePowFact(parseResult, 0, &numofOperands);
             //zmenim parseResult
             if(parseResult == "DBL_MAX"){
                return DBL_MAX;
             }
         }//end of if, that matches '!' or '^'

         if(numofMultPrecedence > 0){
             SolveMultPrecedence(parseResult, 0, &numofOperands );
             //vysledok v parseResult
             if(parseResult == "DBL_MAX"){
                return DBL_MAX;
             }
         }
         if(numofOperands>0){
            SolveOperands(parseResult, 0);
          }

//     std::cout << "ParseRsult as a string is: " << parseResult << "\n";
	 return roundf(std::stod(parseResult) * 100000) / 100000;
 
}


double addition(double addend1, double addend2)
{
    if(addend1>= DBL_MAX || addend2>= DBL_MAX || addend1<=-(DBL_MAX) || addend2<=-(DBL_MAX)){
        return DBL_MAX;

    }
    double result = addend1+addend2;
    if(result>= DBL_MAX || result<= -DBL_MAX){
        return DBL_MAX;
    }
    return result;
}

double difference(double minuent, double subtrahent)
{
    if( minuent>= DBL_MAX || subtrahent>= DBL_MAX ||  minuent<=-DBL_MAX || subtrahent<=-DBL_MAX){
        return DBL_MAX;

    }
    double result = minuent-subtrahent;
    if(result>= DBL_MAX || result<= -DBL_MAX){
        return DBL_MAX;
    }
    return result;
}

double multiplication(double multiply1, double multiply2)
{
    if( multiply1>= DBL_MAX ||multiply2>= DBL_MAX ||  multiply1<=-DBL_MAX || multiply2<=-DBL_MAX){
        return DBL_MAX;

    }
    double result = multiply1*multiply2;
    if(result>= DBL_MAX || result<= -DBL_MAX){
        return DBL_MAX;
    }
    return result;
}

double division(double divident, double divisor)
{
    if(divident>= DBL_MAX ||divisor>= DBL_MAX ||  divident<=-DBL_MAX || divisor<=-DBL_MAX){
        return DBL_MAX;

    }
    double result = divident/divisor;
    if(result>= DBL_MAX || result<= -DBL_MAX){
        return DBL_MAX;
    }
    return result;
}
double mod(double divident, double divisor)
{
    if(divident>= DBL_MAX ||divisor>= DBL_MAX ||  divident<=-DBL_MAX || divisor<=-DBL_MAX){
        return DBL_MAX;

    }
    double result = divident/divisor;
    if(result>= DBL_MAX || result<= -DBL_MAX){
        return DBL_MAX;
    }
    return fmod(divident,divisor);
}
double factorial(double factor)
{
    if(factor>= DBL_MAX  ||  factor<=-DBL_MAX){
        return DBL_MAX;

    }
        if (factor == 1)
            return 1;
        else
            return factor * factorial(factor - 1);

}

double powering(double base, double exponent)
{
    if(base>= DBL_MAX ||exponent>= DBL_MAX ||  base<=-DBL_MAX || exponent<=-DBL_MAX){
        return DBL_MAX;

    }
    double result = pow(base,exponent);
    if(result>= DBL_MAX || result<= -DBL_MAX){
        return DBL_MAX;
    }
    return result;
}

double m_sqrt(double base)
{
    if(base>= DBL_MAX  ||  base<=-DBL_MAX){
        return DBL_MAX;

    }
    return sqrt(base);
}
double cosine(double base)
{
    int lesser = base/360;
    base = base - (double)(360 * lesser);

    if(base>= DBL_MAX  ||  base<=-DBL_MAX){
        return DBL_MAX;

    }
    return cos(base*M_PI/180);
}
double sine(double base)
{
    int lesser = base/360;
    base = base - (double)(360 * lesser);

    if(base>= DBL_MAX  ||  base<=-DBL_MAX){
        return DBL_MAX;

    }
    return sin(base*M_PI/180);
}
