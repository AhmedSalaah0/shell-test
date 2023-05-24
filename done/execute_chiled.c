#include "main.h"
/**
 * execute_child - run a child excution
 * @args: num of argu.
 * @i:intger
 * @pip: array of pip
 * @pipnum: number of pipes
*/

void execute_child(char **args, int i, int pip[][2], int pipnum)
{
if (i != 0)
{
if (dup2(pip[i - 1][0], STDIN_FILENO) < 0)
{
perror("error");
exit(EXIT_FAILURE);
}
}
if (i != pipnum - 1)
{
if (dup2(pip[i][1], STDOUT_FILENO) < 0)
{
perror("dup2 error");
exit(EXIT_FAILURE);
}
}
close_pipes(pip, pipnum - 1);
if (execvp(args[0], args) == -1)
{
perror("execvp error");
exit(EXIT_FAILURE);
}
exit(EXIT_SUCCESS);
}
