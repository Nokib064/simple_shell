#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/**
 * struct list -  environmental variables list
 * @var: string
 * @next: points to next node
 */
typedef struct list
{
	char *var;
	struct list *next;

} list_s;

/* function prototypes */
int prompt(char **env_var);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
char **_strtok(char *str, char *delm);
char *custom_strcat(char *dest, char *src);
char *custom_strdup(char *str, int bytes_excl);
int custom_t_size(char *str, char delim);
char **custom_strtok(char *str, char *delim);
int _prog_exit(char **str, list_s *env, int num, char **command);
void custom_exit(char **str, list_s *env);
int built_in(char **tok, list_s *env_list, int num, char **cmd);
int _execve(char **s, list_s *env, int num);
int env_list_finder(list_s *env_lst, char *str);
int envar_print(char **str, list_s *env_var);
char *get_env(char *var_name, list_s *env_total);
int set_env(list_s **env, char **str);
int un_set_env(list_s **env, char **str);
void simple_cd(list_s *update_env, char *workdir_current);
int currentdir_executor(list_s *update_env, char *workdir_current,
		char *path_update, char *first_arg, int line_num);
int custom_setenv(list_s **envar_list, char  *envar_name, char *dir_pth);
int _cd(char **user_cmd, list_s *update_env, int num);
char *_which(char *first_cmd, list_s *env);
list_s *environ_list(char *env_var);
size_t LinkedList(list_s *Head);
list_s *Add_NodeToEnd(list_s **Head, char *str);
int Delete_NodeAtIndex(list_s **Head, int index);
void not_available(char *str, int c_n, list_s *env);
void cd_to_impossible(char *str, int c_n, list_s *env);
void illegal_num(char *str, int c_n, list_s *env);
char *_memcpy(char *dest, char *src, int n);
void freeLinkedList(list_s *head);
void db_ptr_free(char **arr_str);
int _strlen(char *s);
void *custom_malloc(void *prev_mem_ptr, unsigned int prev_size,
		unsigned int new_size);
char *ignore_space(char *str);
char *skipSpacesAndNewlines(char *str);
char *ignore_delimet(char *str, char delm);
char *int_to_str(int  arr_str);
int _atoi(char *s);
int t_strlen(char *str, int pos, char delim);
int t_size(char *str, char delim);
int Digit_counts(int i);
void NonInteractive(list_s *env);
void ctrl_c(int n);
void ctrl_d(int a, char *command, list_s *env);
size_t get_line(char **input_str);
int main(int ac, char **av, char **env);

#endif
