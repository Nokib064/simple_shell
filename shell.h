#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
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
 *  * struct list - environ variables linked-list
 *   * @var: environ variable string holder
 *    * @next: points to next node
 *     */
typedef struct list
{
	char *var;
	struct list *next;

} list_s;


void custom_exit(char **user_cmd, list_s *env_list);
int _execve(char **usr_inp, list_s *env_var, int numb);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int custom_atoi(char *str);
int __exit(char **usr_str, list_s *env_var, int num, char **comd);
size_t _getline(char **str_buf);
void ctrl_c(int num);
int built_in(char **usr_cmd, list_s *env_var, int num, char **command);
char *ignore_space(char *str);
void ctrl_D(int char_rd, char *usr_cmd, list_s *env_llst);
int prompt(char **environ_var);
char *_strcat(char *dest, char *src);
int _strcmp(char *str1, char *str2);
char *_strcpy(char *dest, char *src);
char *_which(char *usr_inp, list_s *env_var);
char *_strdup(char *str);
int t_strlen(char *str, int pos, char delm);
int t_size(char *usr_inp, char delimet);
char *ignore_delim(char *str, char delimet);
char **_str_tok(char *usr_inp, char *delimet);
char **custom_strtok(char *usr_inp, char *delim);
int custom_t_size(char *str, char delim);
char *custom_strdup(char *str, int exc);
char *_getenv(char *str, list_s *env_var);
list_s *env_linkedList(char **env_var);
int _env(char **usr_inp, list_s *env_var);
void db_ptr_free(char **str);
size_t printList(list_s *h);
list_s *addNode_atEnd(list_s **h, char *str);
int deleteNode_atIndex(list_s **h, int index);
void free_linkedList(list_s *list);
char *custom_strcat(char *dest, char *src);
int custom_setenv(list_s **env_llst, char *var_name, char *dir_pth);
void just_cd(list_s *env_llst, char *curr_dir);
int cd_executor(list_s *env_llst, char *curr_dir, char *dir, char *arg, int num);
int _cd(char **usr_inp, list_s *env_llst, int num);
int env_finder(list_s *env_llst, char *var_name);
int _unsetenv(list_s **env_llst, char **usr_inp);
int _setenv(list_s **env_llst, char **usr_inp);
int numlen(int num);
void not_available(char *usr_inp, int nput, list_s *env_llst);
void unable_toCd(char *user_inp, int nput, list_s *env_llst);
void invalid_number(char *usr_inp, int nput, list_s *env_llst);
char *int_to_str(int num);
char *custom_ignore(char *env_var);
void NonInteractive(list_s *env_var);
int main(int ac, char **av, char **env);


#endif


