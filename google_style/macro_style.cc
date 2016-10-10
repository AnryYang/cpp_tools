/*************************************************************************
    > File Name: macro_style.cc
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Mon 10 Oct 2016 09:33:30 PM
 ************************************************************************/

#include<iostream>
using namespace std;

#define DEBUG_INFO 1

#define PI 3.14

#define MAX(a, b) (a>b)?a:b

#define CHECK_PARAMETER(value)        \
    if(value<=0){                     \
        cout<<"Invalid radius"<<endl; \
    }

float get_area(int r){
    CHECK_PARAMETER(r);
    float area=PI*r*r;
#if DEBUG_INFO
    cout<<"area is "<<area<<endl;
#endif
    return area;
}

int main(){
    get_area(-10);
    return 0;
}

#undef DEBUG_INFO
#undef PI
#undef MAX
#undef CHECK_PARAMETER
