#include<stdio.h>
#include<stdlib.h>
#include"main.h"
int main(int countArg,char**args)
{
if(countArg < 2) return error("You need giver host and port SAM\n example: ./prorgramm HOST PORT");
char ** list;
char * buffer;

buffer = (char*)malloc(sizeof(char) * SIZEBUFFER);

int msocket = InitClient(args[1],atoi(args[2]));

writeTo(msocket,"HELLO VERSION\n");

readFrom(msocket,buffer);

printf("DEBUG INFO(ANSWER): %s\n",buffer);
int res = devideString(buffer,list,' ');
printf("RES: %d\n",res);
//printf("%s\n",list[0]);
//PrintList(list);
//free(constBuffer);
//free(buffer);
}
