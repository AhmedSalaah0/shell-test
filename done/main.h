#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <libgen.h>
#include <limits.h>
#include <errno.h>
#include <sys/wait.h>
#define maxin_size 1024
#define max_tkn 64
#define maxtkn_num 64

int execute(char **comm, char **argv);
char *get_location(char *command);
void execute_pipe(char **cmd,int token_count);
int execute_command(char **comm, char **argv);
int execute_cd(const char *dir);
void create_pipes(int pip[][2], int pipnum);
void close_pipes(int pip[][2], int pipnum);
void execute_child(char **args, int i, int pip[][2], int pipnum);
void execute_pipe(char **cmd, int pipnum);
void execute_env();
#endif
