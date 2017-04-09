#include<stdlib.h>
#include"main.h"
int error(char*msg)
{
 puts(msg);
 exit(-1);
}
int countChar(char ch,char*string)
{
int tmp=0;
while(*string)
{
 if(*string==ch) tmp++;
 *string++;
}
return tmp;
}

char ** devideString(char * string,int * c,char ch)
{
*c = countChar(ch, string);
char ** list= (char**) calloc(sizeof(char*) , *c+1);
for(int i = 0; i != *c+1; i++)
 list[i] = (char*) calloc(SIZEBUFFER,sizeof(char));
//
int tmp=0;
int tmp_1=0;
char tmpb[SIZEBUFFER];
//
while(*string)
{
 while(*string!=ch && *string) tmpb[tmp_1++]=*string++;
 tmpb[tmp_1++]='\0';
 memcpy(list[tmp++],tmpb,tmp_1);
 tmp_1=0; // for array
 if(*string) *string++;
}
return list;
}

