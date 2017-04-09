#define SIZEBUFFER 2056
void writeTo(int socket,char*msg);
void readFrom(int socket,char*buffer);
int InitClient(char*host,int portno);
int error(char*msg);
char ** devideString(char * string,int * c,char ch);
int countChar(char ch,char*string);
short VERSION;
void devideFromChar(char*array,char*string,char ch);
void TestConnection(int * socket);
void GetVersion(char*buffer);
void GenerateDest(int * socket);
void CreateSession(char*style,char*ID,char*privKey,int * socket);
void _SamAccept(char*ID,int * socket);
// 
extern void free (void *__ptr) __THROW;
void *memcpy(void *dest, const void *src, size_t n);
int puts(const char *s);
void stopClient(int * socket);
char *strcpy(char *dest, const char *src);
int atoi(const char *nptr);
char *strstr(const char *haystack, const char *needle);
size_t strlen(const char *s);
int sprintf(char *str, const char *format, ...);
int strcmp(const char *s1, const char *s2);
int printf ( const char * format, ... );
//
char * PRIVDEST;
char * PUBDEST;
/*
typedef char** LIST;
typedef char* constString;
*/
