#include "rebuscalc/math_lib.cpp"
#include <stdio.h>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <time.h>
const int value = 100000;
void getSmer(double sum,double count,double sum2, double array[]){
    sum=multiplication(division(1,count),sum);
    sum = powering(sum,2);

    sum = multiplication(count,sum);
    for(int i =0;i<count;i++){
        sum2=addition(powering(array[i],2),sum2);
    }
   /* sum2=difference(sum2,sum);
    sum2=multiplication(division(1,difference(count,1)),sum2);
    sum2=m_sqrt(sum2);
    printf("%f\n", sum2);*/
    string p = "sqrt(1/(";
    p += std::to_string(count);
    p+= "-1)*(";
    p+= std::to_string(sum2);
    p+= "-";
    p+= std::to_string(sum);
    p+= "))";
    printf("%f\n", result(p.c_str()));


}
void getRandom10(){
      double number,sum=0,sum2=0;
      double array[value] ;

    srand(time(0));

     int count = 0;
     while(count<10){
         number = rand() % 100 + 1;
         array[count] = number;
         count= addition(count,1);
         sum = addition(sum,number);
     }
      return getSmer(sum,count,sum2,array);
     }
void getRandom100(){
      double number,sum=0,sum2=0;

      double array[value] ;

int count = 10;
    srand(time(0));
     count = 0;
     while(count < 100){
          number = rand() % 100 + 1;
         array[count] = number;
         count= addition(count,1);
         sum = addition(sum,number);
     }
     getSmer(sum,count,sum2,array);
    }
void getRandom1000(){
      double number,sum=0,sum2=0;
      double array[value] ;

    int count = 0;
     while(count<1000){
          number = rand() % 100 + 1;
         array[count] = number;

         count= addition(count,1);
         sum = addition(sum,number);
     }
      getSmer(sum,count,sum2,array);
    }

int main(int argc, char* argv[]){
  	(void) argc;
		(void) argv;  
		double sum=0,sum2=0;
    float number;
    int count = 0;
    double array[value] ;
    while(scanf("%g", &number) == 1){
        array[count] = number;
        count= addition(count,1);
        sum = addition(sum,number);

    }
    if(count == 0){
        getRandom10();
        getRandom100();
        getRandom1000();
        return 0;
    }
    getSmer(sum,count,sum2, array);


    return 0;
}
