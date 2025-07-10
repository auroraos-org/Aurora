#include "stdio.h"

// TODO: write code for these functions

int printf(const char* format, ...) {
  
}
int fprintf(FILE* stream, const char* format, ...) {
  
}
int sprintf(char* str, const char* format, ...) {
  
}
int snprintf(char* str, size_t size, const char* format, ...) {
  
}

int scanf(const char* format, ...) {
  
}
int fscanf(FILE* stream, const char* format, ...) {
  
}
int sscanf(const char* str, const char* format, ...) {
  
}

int putchar(int c) {
  
}
int puts(const char* str) {
  
}
int getchar(void) {
  
}
// Deprecated: char* gets(char* str);

FILE* fopen(const char* filename, const char* mode) {
  
}
int fclose(FILE* stream) {
  
}
size_t fread(void* ptr, size_t size, size_t nmemb, FILE* stream) {
  
}
size_t fwrite(const void* ptr, size_t size, size_t nmemb, FILE* stream) {
  
}

int fgetc(FILE* stream) {
  
}
int fputc(int c, FILE* stream) {
  
}
char* fgets(char* str, int n, FILE* stream) {
  
}
int fputs(const char* str, FILE* stream) {

}

int feof(FILE* stream) {
  
}
int ferror(FILE* stream) {
  
}
void clearerr(FILE* stream) {
  
}
int fflush(FILE* stream) {
  
}

long ftell(FILE* stream) {

}
int fseek(FILE* stream, long offset, int whence) {
  
}
void rewind(FILE* stream) {
  
}

int remove(const char* filename) {
  
}
int rename(const char* oldname, const char* newname) {
  
}
FILE* tmpfile(void) {
  
}
char* tmpnam(char* str) {
  
}
