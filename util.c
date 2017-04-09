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

void
removeNewLine(char*array)
{
while(*array)
 {
  if(*array=='\n')*array='\0';
  *array++;
 }
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
 while(*string!=ch && *string)tmpb[tmp_1++]=*string++;
 tmpb[tmp_1++]='\0';
 removeNewLine(tmpb);
 memcpy(list[tmp++],tmpb,tmp_1);
 tmp_1=0; // for array
 if(*string) *string++;
}
return list;
}

void
devideFromChar(char*array,char*string,char ch)
{
while(*string)
{
if(*string==ch) break;
*string++;
}
if(*string) *string++;
strcpy(array,string);
}

void GenerateDest(int * socket)
{
char buffer[SIZEBUFFER];
int c;
writeTo(*socket,"DEST GENERATE");
readFrom(*socket,buffer);
char ** list = devideString(buffer,&c,' ');
if( strstr(list[3],"PRIV=") == 0 || strstr(list[2],"PUB=") == 0  ) error("Result not okey\n");
//... get Priv key and Public key and copy this to memory
devideFromChar(buffer,list[3],'=');
PRIVDEST = (char*)calloc(sizeof(char),strlen(buffer));
strcpy(PRIVDEST,buffer);
devideFromChar(buffer,list[2],'=');
PUBDEST = (char*)calloc(sizeof(char),strlen(buffer));
strcpy(PUBDEST,buffer);
//...
free(list);
}

void
GetVersion(char*buffer)
{
int c;
char ** list = devideString(buffer,&c,' ');
devideFromChar(buffer,list[c],'=');
VERSION=atoi(buffer);
free(list);
}

void
CreateSession(char*style,char*ID,char*privKey,int * socket)
{
char buffer[SIZEBUFFER];
int c;
//
sprintf(buffer,"SESSION CREATE STYLE=%s ID=%s DESTINATION=%s", style , ID, privKey);
writeTo(*socket,buffer);
//
readFrom(*socket,buffer);
printf("(ADDING): %s\n",buffer);
writeTo(*socket,buffer);
readFrom(*socket,buffer);
char**list = devideString(buffer,&c,' ');
printf("RESULT: %s\n",list[2]);
if(strcmp(list[2],"RESULT=OK") != 0) error("Result not okey");
devideFromChar(buffer,list[3],'=');
printf("DEBUG(PRIVKEY): %s\n",buffer);
free(list);
}

void
_SamAccept(char*ID,int * socket)
{
char buffer[SIZEBUFFER];
writeTo(*socket,"STREAM ACCEPT");
sprintf(buffer,"ID=%s", ID);
writeTo(*socket,buffer);
}
