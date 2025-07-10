#ifndef SIGNAL_H
#define SIGNAL_H

void (*signal(int sig, void (*func)(int)))(int);  // Assign a handler for a signal
int raise(int sig);                               // Send a signal to the current process

#define SIGABRT 0  // Abnormal termination
#define SIGFPE  1 // Floating-point exception
#define SIGILL  2 // Illegal instruction
#define SIGINT  3 // Interrupt (e.g., Ctrl+C)
#define SIGSEGV  4 // Invalid memory access
#define SIGTERM 5 // Termination request


#endif
