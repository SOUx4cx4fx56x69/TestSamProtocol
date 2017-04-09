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
char**list;
int c;
buffer = (char*)malloc(sizeof(char) * SIZEBUFFER*10);
int msocket = InitClient(args[1],atoi(args[2]));
printf("Connect succefully\n");
TestConnection(&msocket);
printf("VERSION: %d\n",VERSION);
GenerateDest(&msocket);
//printf("PUBLIC: %s\nPRIVATE: %s\n",PUBDEST,PRIVDEST);
CreateSession("STREAM","TEst666",PRIVDEST,&msocket);
//...
printf("Test Accept\n");
int csocket = InitClient(args[1],atoi(args[2]));
TestConnection(&csocket);
_SamAccept("TEst666",&csocket);
//^^^ SHITCODE ^^^
printf("\n\nSTOP\n");
stopClient(&csocket);
stopClient(&msocket);
free(PRIVDEST);
free(PUBDEST);
//free(list);
free(buffer);
}
