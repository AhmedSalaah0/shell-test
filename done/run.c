#include "main.h"
/**
 * run_command - function run a child proccess
 * @comm: a command
 * @argv: array of arguments
 * Return: -1 if error
*/

int run_command(char **comm, char **argv)
{
pid_t pid = fork();
int s;
if (pid == -1)
{
perror("error");
return (-1);
}
else if (pid == 0)
{
execute_command(comm, argv);
exit(EXIT_SUCCESS);
}
else
{
waitpid(pid, &s, 0);
}
return (0);
}