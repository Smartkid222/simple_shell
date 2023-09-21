#ifndef SHELL_H
#define SHELL_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


#define BUFSIZE 256
extern char **environ;

/**
 * struct build_l - struct to build linked list of PATH directories.
 * @dir: name of directory
 * @next: pointer to next node in list.
 **/
typedef struct build_l {
	char *dir;
	struct build_l *next;
} path_list;

/**
 * struct buitin - struct to handle builtin command args.
 * @buitin_cmd: name of built in command
 * @func: pointer to function to execute command
 **/
typedef struct builtin {
	char *builtin_cmd;
	int (*func)(char *, char **);
} builtin;


int exec(char **);
char *_which(char *);
char *_getenv(const char *);
int compare_env(const char *, const char *);
int (*check_builtin(char *))(char *, char **);
int exit_shell(char *, char **);
int _printenv(char *, char **);
void set_env(char *, const char *);
int _setenv(char *, char **);
char *over_write(char *, const char *);


ssize_t _getline(char **, size_t *, FILE *);


/** ASSISTS FUNCTIONS **/
int _strlen(const char *);
char *_strchr(const char *, int);
char *_strcpy(char *, char *);
char *_strtok(char *, const char *);
int _atoi(const char *);
int _isdigit(char);
void _memcpy(void *, const void *, size_t);
char *_strdup(const char *);
int _strcmp(char *, char *);
char *_strcat(char *, const char *);

/** FREE FUNCTIONS **/
void free_str(char **);

/** ALLOC FUNCTIONS **/
char **double_alloc(char **, int, int);

#endif
