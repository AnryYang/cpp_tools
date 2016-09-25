/*************************************************************************
    > File Name: file_utils.cpp
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Sun 25 Sep 2016 08:22:52 PM
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

//加载文件。   
intloadFile(string fileName, vector<string> &vecLine){  
    vecLine.clear();  
  
    FILE *m_fp = fopen(fileName.c_str(), "rb");  
    if (NULL == m_fp)  
    {          
        ACE_DEBUG(( _ERROR ACE_TEXT( " getline execpaction:[%s]\n" ), fileName.c_str()));              
        return -1;  
    }  
  
    char fileLine[MAX_FILE_LINE_LEN];  
      
    try  
    {      
        for (;;)  
        {  
            memset(fileLine, 0x00, MAX_FILE_LINE_LEN);  
            if (!feof(m_fp))   
            {                           
                if (NULL == fgets(fileLine, MAX_FILE_LINE_LEN, m_fp))  
                {  
                    break;  
                }  
                vecLine.push_back(fileLine);                     
            }  
            else  
            {  
                break;  
            }          
        }  
    }  
    catch(...)  
    {          
        fclose(m_fp);  
        ACE_DEBUG(( _ERROR ACE_TEXT( " getline execpaction:[%s]\n" ), fileName.c_str()));              
        return -1;  
    }  
    fclose(m_fp);  
    return 0;  
}  
  
////写到文件 
void writeToFile(string fileName, char *format, ...){  
    va_list ap;  
    char date[10240];  
    char msgformat[10240];  
  
    memset(msgformat, 0x00, 10240);  
    memset(date, 0x00, 10240);  
  
    FILE *logfp = NULL;  
    logfp = fopen(fileName.c_str(), "a+");  
  
    if (NULL == logfp)  
    {  
        printf("open log file fail.\n");  
        return ;  
    }  
  
    if (NULL == format)  
    {  
        printf("NULL == format.\n");  
    }  
  
    strcat(msgformat, format);  
  
    int msglen = strlen(msgformat);  
    if ('\n' != msgformat[msglen - 1])  
    {  
        strcat(msgformat, "\n");  
    }  
  
    va_start(ap, format);  
    vfprintf (logfp, msgformat, ap);  
    va_end(ap);  
  
    fflush(logfp);  
  
    fclose(logfp);  
  
    return;  
}

int main(){

    return 0;
}