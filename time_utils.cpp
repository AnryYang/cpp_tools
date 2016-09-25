/*************************************************************************
    > File Name: time_utils.cpp
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Sun 25 Sep 2016 08:22:52 PM
 ************************************************************************/

#include<iostream>
#include<string.h>
#include <sys/resource.h>
#include <string>
using namespace std;


//取当前日期   
string getCurDate(){  
    time_t nowtime;  
    time(&nowtime);    //取当前时间值   
    struct tm *tPtr;      
    tPtr = localtime(&nowtime);  
  
    char dateStamp[32];  
    ACE_OS::sprintf(dateStamp, "%04d%02d%02d", tPtr->tm_year+1900 ,tPtr->tm_mon+1,tPtr->tm_mday);  
          
    return dateStamp;  
}

//取得当前时间   
string getCurTime(){  
    time_t nowtime;  
    time(&nowtime);     
    struct tm *tPtr;      
    tPtr = localtime(&nowtime);   
  
    char timeStamp[15];  
    memset(timeStamp, 0x00, 15);  
    ACE_OS::sprintf(timeStamp, "%02d%02d%02d", tPtr->tm_hour,tPtr->tm_min,tPtr->tm_sec);  
          
    return timeStamp;  
}

string getProcMemory(){
    struct rusage r_usage;
    getrusage(RUSAGE_SELF,&r_usage);
    string strMemUsage = to_string(r_usage.ru_maxrss);
    return strMemUsage;
}

int main(){

    return 0;
}