#define SIZEBUFFER 1024
void writeTo(int socket,char*msg);
void readFrom(int socket,char*buffer);
int InitClient(char*host,int portno);
int error(char*msg);
char ** devideString(char * string,int * c,char ch);
int countChar(char ch,char*string);
short VERSION;
void devideFromChar(char*array,char*string,char ch);
// 
void *memcpy(void *dest, const void *src, size_t n);
int puts(const char *s);
void stopClient(int * socket);
char *strcpy(char *dest, const char *src);
//

/*
typedef char** LIST;
typedef char* constString;
*/
