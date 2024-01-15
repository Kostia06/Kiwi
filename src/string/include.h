#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#define LINE_BREAK printf("-----------------------------------------------------------------------\n");

#define     RESET   "\033[0m"
#define     WHITE   "\033[1m\033[37m"
#define     MAGENTA "\033[1m\033[35m"
#define     RED     "\033[1m\033[31m"
#define     GREEN   "\033[1m\033[32m"
#define     YELLOW  "\033[1m\033[33m"
#define     BLUE    "\033[1m\033[34m"
#define     CYAN    "\033[1m\033[36m"

#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

char* str_snprintf(const char* format, ...);
void str_to_upper(char** str);
void str_to_lower(char** str);
int str_find_char(const char* str, char c);
int str_find_char_reverse(const char* str, char c);
int str_find_str(const char* str, const char* sub);
static char* _str_strrstr(const char* str, const char* sub) ;
int str_find_str_reverse(const char* str, const char* sub) ;
char* str_add_str(char** str, const char* add);
char* str_add_char(char** str, char add);
char* str_int(const double num);
