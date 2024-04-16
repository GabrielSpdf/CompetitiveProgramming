//Accepted

#include <stdio.h>
#include <math.h>
#include <iostream>
#include "stack"

using namespace std;

int main(void){
  int aux=0;
  double num;
  stack<double> mystack;

  while(cin >> num){
    mystack.push(num);
    aux++;
  }

  for(int i=0; i<aux; i++){ printf("%.4lf\n", sqrt(mystack.top())); mystack.pop();}

  return 0;
}