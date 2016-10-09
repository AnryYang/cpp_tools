/*************************************************************************
    > File Name: class_rules.cc
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Sun 09 Oct 2016 02:53:27 PM
 ************************************************************************/

#include<iostream>
using namespace std;

//prohibit copy constructors
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(const TypeName&); \
    void operator=(const TypeName&)

class Foo {

    public:
        typedef string FooTypes; 
        enum FooType{
            TYPE_A,
            TYPE_B,
        };
        const string kClassName="Foo";
        explicit Foo(int f); //the constructor with only one parameter should be explicit
        ~Foo();
        void Init(); //use init() to initialize non-trivial data, on the other hand, in constructor, do trivial initialization 
        bool Equals(); //use function instead of operator overloading
        void CopyFrom();
        void set_foo(int f);
        int get_foo();
        int foo_data;
        string foo_str;

    protected:
        typedef long FooAmount;
        enum FooCate{
            CATE_A,
            CATE_B,
        };
        const bool kIsFoo = true;
    private:
        typedef int FooCount;
        enum FooG{
            G_A,
            G_B,
        }; 
        const int kFooConstant=10;
        void Print();
        int foo;
        DISALLOW_COPY_AND_ASSIGN(Foo);
};
