#include <iostream>
#include <vector>
#include <ratio>
#include <chrono>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <string>

using namespace std;
using namespace chrono;

#define HM 1024*1024*1000

inline void computation()
{
    double x=3.01;
    for(int i=0;i<1000000;i++)
    {
        x=x*x;
        x+=1;
        x=x/x;
    }         
}

string intToStr(int i) {
      stringstream ss;
      ss << i;
    return ss.str();
}

unsigned long long strToInt(string s) {
      unsigned long long i;
      istringstream myStream(s);

       if (myStream>>i) {
               return i;
            } else {
        cout << "String " << s << " is not a number." << endl;
          return atoi(s.c_str());
       }
    return i;
}

string getProcMemory(){
    struct rusage r_usage;
    getrusage(RUSAGE_SELF,&r_usage);
    string strMemUsage = to_string(r_usage.ru_maxrss);
    return strMemUsage;
}

int main()
{
   while(true)
   {
       char *p=new char[HM*10];
       p[HM-2]='a';
       high_resolution_clock::time_point t1 = high_resolution_clock::now();
       computation();
       high_resolution_clock::time_point t2 = high_resolution_clock::now();
       duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
       cout<<getProcMemory()<<" "<<time_span.count()<<endl;
   }
   return true;
}
