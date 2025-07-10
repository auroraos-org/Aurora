#ifndef TIME_H
#define TIME_H

typedef long time_t;
typedef struct tm {
    int tm_sec, tm_min, tm_hour;
    int tm_mday, tm_mon, tm_year;
    int tm_wday, tm_yday, tm_isdst;
} tm;

time_t time(time_t* timer);
double difftime(time_t end, time_t start);
time_t mktime(struct tm* timeptr);

char* asctime(const struct tm* timeptr);
char* ctime(const time_t* timer);
struct tm* gmtime(const time_t* timer);
struct tm* localtime(const time_t* timer);

size_t strftime(char* str, size_t maxsize, const char* format, const struct tm* timeptr);

#endif // TIME_H
