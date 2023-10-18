#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

int my_unset_alias(shell_info_t *shell_info, char *alias_str);
int alphaToInteger(int character, char *stringToConvert);
int my_nov_alias(shell_info_t *shell_infoi);
int my_help(void);
int lets_check_if_exctble(info_t *info, char *path);
char *my_getenv(messg_t *msg, const char *idty);
int my_env_disp(messg_t *msg);
char *unique_chars_extraction(char *pathstr, int start_idx, int end_idx);
char *convert_to_base(long int idty, int radix, int mask);
void the_forking_func(messg_t *messg);
int custom_atoi(const char *str);
int the_env_set_ok(messg_t *msg);
int handle_env_popltn(messg_t *msg);
int checking_If_Interactive(info_t *info);
void _write_strng(char *strng);
int is_it_the_Delimiter(char c, const char *delim);
int write_alias(list_t *node);
int main_shell_loop(messg_t *messg, char **argv);
int freeing_idol_mem(void **ptr);
char *custom_str_chr(char *string, char character);
void find_cmd_in_path(messg_t *messg);
char *custom_str_concat(char *home, const char *org, int longest);
char *get_full_path(messg_t *msg, char *path_str, char *cmd);
int shell_main(int argchar, char **argvi);
char **split_string(char *input_string, char delimiter);
char *custom_string_copier(char *home, const char *orgn, size_t long_);
int my_cs_cd(info_t *info);
int my_exit_key(info_t *info);
char **string_writing(char *str, char *d);
int _write_string_file_annotator(char *str, int file_annotator);

#endif // _SHELL_H_
