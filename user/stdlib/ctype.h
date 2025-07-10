#ifndef CTYPE_H
#define CTYPE_H

int isalnum(int c);  // Alphanumeric (A-Z, a-z, 0-9)
int isalpha(int c);  // Alphabetic (A-Z, a-z)
int isblank(int c);  // Blank (space or tab)
int iscntrl(int c);  // Control character
int isdigit(int c);  // Decimal digit (0-9)
int isgraph(int c);  // Printable (excluding space)
int islower(int c);  // Lowercase letter (a-z)
int isprint(int c);  // Printable character (includes space)
int ispunct(int c);  // Punctuation (!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~)
int isspace(int c);  // Whitespace (space, tab, newline, etc.)
int isupper(int c);  // Uppercase letter (A-Z)
int isxdigit(int c); // Hex digit (0-9, A-F, a-f)

int tolower(int c);  // Converts to lowercase
int toupper(int c);  // Converts to uppercase


#endif
