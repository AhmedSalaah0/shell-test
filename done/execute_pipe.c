#include "main.h"
/**
 * execute_pipe - execute command which include pipe
 * @cmd: the command
 * @pipnum: number of pipes
*/
void execute_pipe(char **cmd, int pipnum)
{
int pip[pipnum - 1][2];
char *args[maxtkn_num];
char *ccd;
int arg_count;
char *tkn;
pid_t pid;

create_pipes(pip, pipnum);
for (int i = 0; i < pipnum; i++)
{
ccd = cmd[i];
arg_count = 0;
tkn = strtok(ccd, " \t\n");
while (tkn != NULL) {
args[arg_count] = tkn;
arg_count++;
tkn = strtok(NULL, " \t\n");
}
args[arg_count] = NULL;
pid = fork();
if (pid < 0) {
perror("fork error");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execute_child(args, i, pip, pipnum);
}
}
close_pipes(pip, pipnum - 1);
for (int i = 0; i < pipnum; i++)
{
wait(NULL);
}
}