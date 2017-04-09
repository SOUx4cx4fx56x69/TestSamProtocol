#include<stdio.h>
#include<stdlib.h>
#include"main.h"
#include<string.h>
short VERSION=0;
char * PRIVDEST;
char * PUBDEST;
int main(int countArg,char**args)
{
if(countArg < 2) return error("You need giver host and port SAM\n example: ./prorgramm localhost 7656");
char * buffer;
int c;
buffer = (char*)malloc(sizeof(char) * SIZEBUFFER);

int msocket = InitClient(args[1],atoi(args[2]));

writeTo(msocket,"HELLO VERSION");

readFrom(msocket,buffer);

printf("DEBUG INFO(ANSWER): %s\n",buffer);
char ** list = devideString(buffer,&c,' ');
printf("DEBUG(COUNT): %d\n",c);
if( strcmp(list[c-1],"RESULT=OK") != 0 )
 return error("Result not okey\n");
printf("INFO: RESULT OKEY, GET VERSION\n");
devideFromChar(buffer,list[c],'=');

VERSION=atoi(buffer);
printf("VERSION: %d\n",VERSION);
writeTo(msocket,"DEST GENERATE");
readFrom(msocket,buffer);
list = devideString(buffer,&c,' ');
if( strstr(list[3],"PRIV=") == 0 || strstr(list[2],"PUB=") == 0  ) return error("Result not okey\n");
//... get Priv key and Public key and copy this to memory
devideFromChar(buffer,list[3],'=');
PRIVDEST = (char*)calloc(sizeof(char),strlen(buffer));
strcpy(PRIVDEST,buffer);
devideFromChar(buffer,list[2],'=');
PUBDEST = (char*)calloc(sizeof(char),strlen(buffer));
strcpy(PUBDEST,buffer);
//...
//printf("PUBLIC: %s\nPRIVATE: %s\n",PUBDEST,PRIVDEST);
sprintf(buffer,"SESSION CREATE\nSTYLE=STREAM\nID=TESTING\nDESTINATION=%s\n",PRIVDEST);
//if(strstr(buffer,PRIVDEST) == NULL) return error("lOl");
printf("DEBUG: writeTo server:%s\n",buffer);
writeTo(msocket,buffer);
readFrom(msocket,buffer);
printf("DEBUG(ANSWER): %s\n",buffer);
readFrom(msocket,buffer);
printf("DEBUG(ANSWER): %s\n",buffer);
printf("\n\nSTOP\n");
stopClient(&msocket);
free(PRIVDEST);
free(PUBDEST);
free(list);
free(buffer);
}
