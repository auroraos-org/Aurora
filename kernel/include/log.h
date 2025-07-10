#ifndef LOG_H
#define LOG_H

#include "system.h"

#define COM1_PORT 0x3F8


static inline void log_init(void) {
    outportb(COM1_PORT + 1, 0x00); // disable interrupts
    
    outportb(COM1_PORT + 3, 0x80);
    outportb(COM1_PORT + 0, 0x03);
    outportb(COM1_PORT + 1, 0x00);
    outportb(COM1_PORT + 3, 0x03);
    outportb(COM1_PORT + 2, 0xC7);
    
    outportb(COM1_PORT + 4, 0x0B);
}


static inline void log_print(const char* str) {
    if (!str) return;
    
    while (*str) {
        if (*str == '\n') {
            serial_write('\r'); 
        }
        
        serial_write(*str++);
    }
}

static inline void log_print_hex(u32 value) {
    // TODO: THIS IS SOOOO BAD CODE
    char hex_str[11];
    char hex_chars[] = "0123456789ABCDEF";
    int i;
    
    // 0x prefix
    hex_str[0] = '0';
    hex_str[1] = 'x';
    

    for (i = 7; i >= 0; i--) {
        hex_str[2 + (7 - i)] = hex_chars[(value >> (i * 4)) & 0xF];
    }
    
    hex_str[10] = '\0'; 
    log_print(hex_str);
}

#define LOG_ERROR(message) log_print("\033[31m [ERROR] \033[0m " message)
#define LOG_INFO(message) log_print("\033[96m [INFO] \033[0m " message)
#define LOG_WARNING(message) log_print("\033[95m [WARNING] \033[0m " message)


#endif
