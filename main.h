#define SIZEBUFFER 1024
void writeTo(int socket,char*msg);
void readFrom(int socket,char*buffer);
int InitClient(char*host,int portno);
int error(char*msg);
int devideString(char*string,char**list,char ch);
int countChar(char ch,char*string);
/*
typedef char** LIST;
typedef char* constString;
*/
