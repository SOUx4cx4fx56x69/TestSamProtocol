#include<stdio.h>
#include<stdlib.h>
#include"main.h"
int main(int countArg,char**args)
{
if(countArg < 2) return error("You need giver host and port SAM\n example: ./prorgramm HOST PORT");
char ** list;
char * buffer;
int c;
buffer = (char*)malloc(sizeof(char) * SIZEBUFFER);

int msocket = InitClient(args[1],atoi(args[2]));

writeTo(msocket,"HELLO VERSION\n");

readFrom(msocket,buffer);

printf("DEBUG INFO(ANSWER): %s\n",buffer);
list = devideString(buffer,&c,' ');
printf("DEBUG(COUNT): %d\n",c);
printf("DEBUG INFO(ANSWER REVERSED)\n");
for(int zzz=c;c--;)
{
 printf("%s\n",list[c]);
}
//PrintList(list);
//free(constBuffer);
//free(buffer);
}
