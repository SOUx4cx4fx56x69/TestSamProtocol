#include<stdlib.h>
#include<stdio.h>
#include<string.h>
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

int devideString(char * string,char ** list,char ch)
{
/*auto*/ int c = countChar(ch, string);
list= (char**) calloc(sizeof(char*) , c+1);
for(int i = 0; i != c+1; i++)
{
 list[i] = (char*) calloc(SIZEBUFFER,sizeof(char));
}
int tmp=0;
int tmp_1=0;
char tmpb[SIZEBUFFER];
while(*string)
{
 while(*string!=ch && *string) tmpb[tmp_1++]=*string++;
 tmpb[tmp_1++]='\0';
 strcpy(list[tmp],tmpb);
 tmp_1=0; // for array
 printf("DEBUG: %s\n",list[tmp++]);
 if(*string) *string++;
}
printf("reversed\n");
for (int zzz=c;zzz--;)
 printf("%s\n",list[zzz]);

printf("end\n");

return c;
}

