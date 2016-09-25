/*************************************************************************
    > File Name: str_utils.cpp
    > Author: anryyang
    > Mail: anryyang@gmail.com 
    > Created Time: Sun 25 Sep 2016 08:22:52 PM
 ************************************************************************/

#include<iostream>
#include<string.h>
using namespace std;

//int型转string 型   
string intToString(int value){  
    char tmpString[15];  
    memset(tmpString, 0x00, 15);  
    sprintf(tmpString, "%d", value);  
    return  tmpString;  
} 

//将字符串处理为小写。   
void toLower(string &strTmp){  
    for (unsigned int i = 0; i < strTmp.length(); i++){  
        strTmp[i] = tolower(strTmp[i]);  
    }  
    return;  
}

///根据分隔标记flag将字符串放入。。。。   
int getItem(string &msg ,  char flag, vector<string> &line){  
    try{  
        if (line.size() != 0)  
        {  
            line.clear();  
        }  
          
        if (msg.length() == 0)  
        {  
            return 0;  
        }  
  
        char *tmpMsg = &msg[0];  
  
        int begin = 0;  
        int end = 0;  
        string tmp;  
        for (unsigned int i = 0; i < msg.length(); i ++)  
        {  
            if (tmpMsg[i] == flag)  
            {  
                end = i;  
            }  
            else  
            {  
                continue;  
            }   
  
            if ((end-begin)> 0)  
            {               
                 tmp = string(&tmpMsg[begin], end-begin);  
            }  
            else  
            {  
                tmp = "";  
            }  
            begin = end+1;                 
            line.push_back(tmp);  
           
        }  
        if ((msg.length()-begin)> 0)  
        {               
            tmp  = string(&tmpMsg[begin], msg.length()-begin);  
            line.push_back(tmp);  
        }       
  
    }  
    catch(...){  
        ACE_DEBUG(( _INFO ACE_TEXT("  getItem execpaction:[%s].\n"), msg.c_str()));  
        return -1;  
    }  
    return 0;  
}

////输出vector的内容。   
void dispVector(const vector<string> &vecTmp){  
    if (vecTmp.size() == 0)  
    {  
        ACE_DEBUG(( _INFO ACE_TEXT( " vector is null\n" )));  
        return;          
    }  
      
    for (unsigned int i = 0 ; i < vecTmp.size(); i++)  
    {  
        ACE_DEBUG(( _INFO ACE_TEXT( "  [%25s]\n" ), vecTmp[i].c_str()));          
    }  
  
    return ;  
}  

////返回num后的字符串   
string lastStr(string &from, int num){  
    if (from.length() <= (unsigned int)num)  
    {  
        return from;  
    }  
    else  
    {  
        return from.substr(from.length()-num, num);  
    }  
}  
  
string leftFullChar(string &from, int count, char flag){  
    if (from.length() > (unsigned int)count)  
    {  
        return from ;  
    }  
  
    int fullCount  = (int)from.length() - count;  
    string strTmp(fullCount, flag);  
    strTmp += from;  
    return strTmp;  
}  
  
string rightFullChar(string &from, int count, char flag){  
    if (from.length() > (unsigned int)count)  
    {  
        return from ;  
    }  
  
    int fullCount  = (int)from.length() - count;  
    string strTmp(fullCount, flag);  
    return from+strTmp;  
}  

///////十六进制转char。。。。   
inthexToChar(string &value, char *buf, int &bufLen){    
//    ACE_DEBUG(( _INFO ACE_TEXT( "value:[%s]\n" ), value.c_str()));   
  
    memset(buf, 0x00, bufLen);      
    if ((unsigned int )bufLen < (value.length()/2))   
    {  
        return -1;  
    }  
  
    if (value.length() == 0)  
    {  
        return -1;  
    }  
    if (value.length() % 2 != 0)  
    {  
        return -1;  
    }  
  
    int bufIndex = 0;  
    for (unsigned int i = 0; i < value.length()/2; i++)  
    {      
        string tmp = value.substr(i*2, 2);    
        ascToHex(tmp.c_str(), &buf[bufIndex], 2);  
        bufIndex++;  
    }  
  
    bufLen = bufIndex;  
      
    //ACE_HEX_DUMP((LM_INFO, (char *)buf, bufLen, "resp message:"));   
      
    return 0;  
}  
  
////asc转十六进制   
intascToHex(const char *Asc, char *Hex, int AscLen){  
    char *HexPtr = Hex;  
    short i;  
      
    for(i = 0; i < AscLen; i++)  
    {  
        *HexPtr = Asc[i] << 4;  
        if (!(Asc[i]>='0' && Asc[i]<='9'))  
            *HexPtr += 0x90;  
        i++;  
        *HexPtr |= (Asc[i] & 0x0F);  
        if (!(Asc[i]>='0' && Asc[i]<='9'))  
            *HexPtr += 0x09;  
        HexPtr++;  
    }  
      
    return 0;  
}  
  
//十六进制转asc   
inthexToAsc(const char *Hex, int HexLen, char *Asc){  
    int i;  
    char *AscPtr;  
    const char *HexPtr;  
    char Temp;  
  
    HexPtr=Hex;  
    AscPtr=Asc;  
  
    for(i = 0; i < HexLen; i++)  
    {  
        Temp = (*HexPtr & 0xf0) >> 4;  
        if (Temp < 10)  
            *AscPtr = 0x30 + Temp; // 数字0－9   
        else  
            *AscPtr = 0x37 + Temp; // 字母A－F   
              
        AscPtr++;  
          
        Temp = *HexPtr & 0x0f;  
        if (Temp < 10)  
            *AscPtr = 0x30 + Temp;  
        else  
            *AscPtr = 0x37 + Temp;  
              
        AscPtr++;  
        HexPtr++;  
    }  
      
    return 0;  
}  

//删除字符串中的空格。   
voiddelAllBlank(string &line){  
    if (line.length() <= 0)          
    {  
        return;  
    }  
  
    string tmp;  
    tmp.clear();  
    try  
    {  
       for(unsigned int i = 0; i < line.length(); i++)  
        {  
            if (line[i] == ' ' ||  line[i] == '\t'   
             || line[i] == '\n' || line[i] == '\r')  
            {  
                continue;  
            }  
            else  
            {  
                tmp += line[i];    
            }  
        }  
        line.clear();  
        line = tmp;  
    }  
    catch(...)  
    {          
        ACE_DEBUG(( _ERROR ACE_TEXT( "  delAllBlank execaption\n" ) ));            
    }  
    return;  
}  
  
///同上。   
voiddelAllBlank(char *pstr){  
    if (NULL == pstr)  
    {  
        return;  
    }  
  
    int strLen = strlen(pstr);  
  
    string tmpStr;  
    try  
    {  
       for(int i = 0; i < strLen; i++)  
        {  
            if (pstr[i] == ' ' ||  pstr[i] == '\t'   
             || pstr[i] == '\n' || pstr[i] == '\r')  
            {  
                continue;  
            }  
            else  
            {  
                tmpStr += pstr[i];    
            }  
        }  
    }  
    catch(...)  
    {          
        ACE_DEBUG(( _ERROR ACE_TEXT( "  delAllBlank execaption\n" ) ));            
    }  
  
    memset(pstr, 0x00, strLen);  
    memcpy(pstr, tmpStr.c_str(), tmpStr.length());  
      
    return;  
}  
  
/////删除最后一个空格   
voiddelLastBlank(char *pstr){  
    if (NULL == pstr)  
    {  
        return;  
    }      
      
    string tmpStr = pstr;  
    memset(pstr, 0x00, strlen(pstr));  
    try  
    {  
        for (;;)  
        {  
            if (tmpStr.length() > 0)  
            {  
                if (tmpStr[tmpStr.length()-1] == ' ' ||  tmpStr[tmpStr.length()-1] == '\t'   
                 || tmpStr[tmpStr.length()-1] == '\n' || tmpStr[tmpStr.length()-1] == '\r')  
                {  
                    tmpStr.erase(tmpStr.length()-1);  
                }  
                else  
                {  
                    break;  
                }  
            }  
            else  
            {  
                break;  
            }              
        }  
    }      
    catch(...)  
    {          
        ACE_DEBUG(( _ERROR ACE_TEXT( "  delLastBlank execaption\n" ) ));            
    }  
    memcpy(pstr, tmpStr.c_str(), tmpStr.length());  
      
    return;  
}  
  
voiddelLastBlank(string &tmpStr ){  
    try  
    {  
        for (;;)  
        {  
            if (tmpStr.length() > 0)  
            {          
                if (tmpStr[tmpStr.length()-1] == ' ' ||  tmpStr[tmpStr.length()-1] == '\t'   
                 || tmpStr[tmpStr.length()-1] == '\n' || tmpStr[tmpStr.length()-1] == '\r')  
                {  
                    tmpStr.erase(tmpStr.length()-1);  
                }  
                else  
                {  
                    break;  
                }  
            }  
            else  
            {  
                break;  
            }  
        }  
    }      
    catch(...)  
    {          
        ACE_DEBUG(( _ERROR ACE_TEXT( "  delLastBlank execaption\n" ) ));            
    }      
    return;  
}  
////删除最前边的空格。   
voiddelHeadBlank(string &tmpStr ){  
    try  
    {  
        for (;;)  
        {  
            if (tmpStr.length() > 0)  
            {          
                if (tmpStr[0] == ' ' || tmpStr[0] == '\t'   
                 || tmpStr[0] == '\n' || tmpStr[0] == '\r')  
                {  
                    tmpStr.erase(0);  
                }  
                else  
                {  
                    break;  
                }  
            }  
            else  
            {  
                break;  
            }  
        }  
    }      
    catch(...)  
    {          
        ACE_DEBUG(( _ERROR ACE_TEXT( "  delLastBlank execaption\n" ) ));            
    }      
    return;  
}

int main(){

    return 0;
}

