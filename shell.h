#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>

#define END_OF_FILE -2
#define EXIT -3

extern char **environ;
extern char **env;

/**
 * struct info_s - A new struct type defining a linked list.
 * @readfd: A pointer to another struct list_s.
 */
typedef struct info_s
{
	int readfd;
} info_t;

/**
 * struct list_path - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct list_path
{
	char *dir;
	struct list_path *next;
} list_t;

/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @naam: a pointer to a character string.
 * @p: a pointer to a function that takes two arguments.
 */
typedef struct builtin_s
{
	char *naam;
	int (*p)(char **argv, char **prow);
} builtin_t;

/**
 * struct alias_s - A new struct defining aliases.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * @next: A pointer to another struct alias_s.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias *next;
} alias_t;

/* Global aliases linked list */
alias_t *aliases;

/* Main Helpers */
void *_realloc(void *ptr, size_t old_size, size_t new_size);
char **_strtok(char *line, char *delim);
char *my_getline(void);
bool interactive(info_t *info);
int is_delim(char c, const char *delim);
int _isalpha(int c);
int _atoi(char *s);
int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **_strtok(char *line, char *delim);

/*Functions of the shell*/
void execute_line(char **argv, char **commands, int count,
		char **env, int *exit_st, char *line);
char **split_line(char *line);
list_t *list_path(char **env);
int _setenv(const char *name, const char *value, int overwrite);
char *_which(char **commands, char **env);
void shell_exit(char *line, char **arg, int *exit_st, int count);
void shell_env(char **arg, char **env, int *exit_st);
char *_getenv(const char *name, char **env);
void _error(char **argv, char *first, int count, int **exit_st);
int special_case(char *line, ssize_t line_len, int *exit_st);
void print_num(int count);

/*useful functions*/
int _strlen(char *s);
void add_node_end(list_t **head, const char *str);
char *_strcat(char *s1, char *s2);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
void free_loop(char **arr);
void free_list(list_t *head);
char *_strncpy(char *dest, char *src, int n);

#endif
