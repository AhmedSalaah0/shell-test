 #include <libgen.h>
 #include <limits.h>
 #include "main.h"
/**
  *execute - function that execute a command
  *@comm: the command will executed
  *@argv:2D array of argvs
  *Return: 0 if success
  */
int execute(char **comm, char **argv)
{
if (!comm)
return (0);

if (strcmp(comm[0], "cd") == 0)
{
if (comm[1])
{
if (execute_cd(comm[1]) == -1)
printf("cd: No directory specified\n");
}
else
{
printf("cd: No directory specified\n");
}
}
if (strcmp(comm[0], "exit") == 0)
{
exit(-1);
}
else
{
run_command(comm, argv);
}

return (0);
}
