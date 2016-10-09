/*************************************************************************
    > File Name: something_else.cc
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Sun 09 Oct 2016 12:46:30 PM
 ************************************************************************/

#include<iostream>
using namespace std;

//input parameters should be value or const reference
//output parameter should be pointer
void foo(const int &sum, int quantity, int *avg){
    avg = sum/quantity;
}

float x = 1.2;
//do not use :
//int y = (int)x; or int y = int(x);
int y = static_cast<int>(x);

//preincrement/predecrement is more efficient than postincrement/postdecrement 
vector<int> vecData;
std::vector<int>::iterator it = vecData.begin();
++it;

int i = 0;
float f = 0.0;
void *p = NULL;
char c = '\0';

//use sizeof(varname) instead of sizeof(type)
int var[10];
int len = sizeof(var)/sizeof(int);
len = sizeof(var)/sizeof(var[0]);

