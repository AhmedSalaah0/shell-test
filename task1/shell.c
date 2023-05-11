#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <shell.h>
int main(void)
{
char *cmd = NULL, *args[100], *tkn;
size_t len = 0;
ssize_t ch, c = 0;
while (1)
{
printf("#cisfun$ ");
ch = getline(&cmd, &len, stdin);
if (ch == -1)
{
break;
}
cmd[strcspn(cmd, "\n")] = '\0';


tkn = strtok(cmd, " ");

while (tkn != NULL)
{
args[c++] = tkn;
tkn = strtok(NULL, " ");
}
args[c] = NULL;
int ret = execve(args[0], args, NULL);
if (ret == -1)
{
perror("./shell");
}
}
free(cmd);
return 0;
}

