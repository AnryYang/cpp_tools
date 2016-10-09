/*************************************************************************
    > File Name: naming_rules.cc
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Sun 09 Oct 2016 12:22:02 PM
 ************************************************************************/

#include<iostream>
using namespace std;

//namespace names should be basede on project name and directory structure
namespace cpp_tools_google_style

//macro names should be uppercase
#define PI_ROUND 3.14
#define DISALLOW_COPY_AND_ASSIGN(TypeName)\
    TypeName(const TypeName&);            \
    void operator=(const TypeName&)
 

//variable names
int num_dns_connections;

string table_name;

//constant names, begining with k
const int kDaysInAWeek = 7;

const string kFileName = "url_table.conf"

//type names
class UrlTable{...}

struct UrlTableProperties{...};

enum UrlTableErrors {
    //enumerator values should be uppercase
    ERROR_NETWORK,
    ERROR_OUT_OF_MEMORY,
    ERROR_MALFORMED_INPUT,
};

typedef hash_map<string, UrlTable> UrlTableMap;

//function names
void AddTableEntry(){}

void DelUrl(){}

class UrlTable{
    public:
        //getter and settr should be lowercase
        int get_num_entries() const {return num_entries;}
        void set_num_entries(int num_entries) {num_entries = num_entries;}
    private:
        int num_entries;
    private:
        DISALLOW_COPY_AND_ASSIGN(UrlTable);
};

#undef PI_ROUND
#undef DISALLOW_COPY_AND_ASSIGN
