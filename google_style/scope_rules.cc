/*************************************************************************
    > File Name: scope_rules.cc
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Sun 09 Oct 2016 03:13:56 PM
 ************************************************************************/

#include<iostream>
using namespace std;

//advocate to use unnamed namespaces
//avoid using 'using' to contaminate namespaces
namespace {

namespace fbz = ::foo::bar::baz;

using ::foo::bar;

class Foo(){

}

int f(){return 0;}

int i = f();//initialize variable during its statement

//put object's statement out of loop, to avoid call constructor and destructor every time
Foo f;
for(int i=0;i<10000;i++){
    f.do_soemthing();
}

}
