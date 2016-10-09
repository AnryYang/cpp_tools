/*************************************************************************
    > File Name: func-inl.h
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Sun 09 Oct 2016 12:41:45 PM
 ************************************************************************/

#include<iostream>
#include<string>
using namespace std;

//inline functions should be placed in .h file
//if inline function's code is long, put it in *-inl.h file

inline string GetProjName(){
    return "cpp_tools";
}
