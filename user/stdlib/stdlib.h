#ifndef STDLIB_H
#define STDLIB_H

void* malloc(size_t size);
void* calloc(size_t num, size_t size);
void* realloc(void* ptr, size_t size);
void  free(void* ptr);

void abort(void);
int  atexit(void (*func)(void));
void exit(int status);
int  system(const char* command);

char* getenv(const char* name);

int   abs(int x);
long  labs(long x);
long long llabs(long long x);

int   rand(void);
void  srand(unsigned int seed);

#endif // STDLIB_H
