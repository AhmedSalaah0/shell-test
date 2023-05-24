#include "main.h"
/**
 * execute_command - Function that executes a command
 * @comm: The command to be executed
 * @argv: 2D array of arguments
 *
 * Return: 0 if success, -1 if error
 */
int execute_command(char **comm, char **argv)
{
char *cmd = comm[0];
char *realcmd = get_location(cmd);

if (realcmd)
{
if (execve(realcmd, comm, NULL) == -1)
{
if (errno == ENOENT)
printf("%s: %s: command not found\n", argv[0], cmd);
else
perror("Execution error");
exit(EXIT_FAILURE);
}
}
else
{
printf("%s: %s: command not found\n", argv[0], cmd);
exit(EXIT_FAILURE);
}

return 0;
}