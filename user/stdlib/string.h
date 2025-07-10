#ifndef STRING_H
#define STRING_H

size_t strlen(const char* str);
int strcmp(const char* s1, const char* s2);
int strncmp(const char* s1, const char* s2, size_t n);

char* strcpy(char* dest, const char* src);
char* strncpy(char* dest, const char* src, size_t n);

char* strcat(char* dest, const char* src);
char* strncat(char* dest, const char* src, size_t n);

char* strchr(const char* str, int c);
char* strrchr(const char* str, int c);

char* strstr(const char* haystack, const char* needle);
char* strpbrk(const char* str, const char* accept);

char* strtok(char* str, const char* delim);

void* memcpy(void* dest, const void* src, size_t n);
void* memmove(void* dest, const void* src, size_t n);
int memcmp(const void* s1, const void* s2, size_t n);
void* memset(void* s, int c, size_t n);

char* strerror(int errnum);

#endif // STRING_H
