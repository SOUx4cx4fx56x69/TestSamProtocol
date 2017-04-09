#define SIZEBUFFER 1024
void writeTo(int socket,char*msg);
void readFrom(int socket,char*buffer);
int InitClient(char*host,int portno);
int error(char*msg);
char ** devideString(char * string,int * c,char ch);
int countChar(char ch,char*string);
// 
void *memcpy(void *dest, const void *src, size_t n);
int puts(const char *s);
//

/*
typedef char** LIST;
typedef char* constString;
*/
