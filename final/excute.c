#include "shell.h"
/**
 * 
 * 
 * 
 * 
*/
void excute(char **argv)
{
char *cmd = NULL;
char *realcmd = NULL;
if(argv)
{
cmd = argv[0];
realcmd = locate(cmd);
if (realcmd == NULL)
{
printf("error");
return;
}
if (execve(realcmd, argv, NULL) == -1)
perror("error");
}
}
