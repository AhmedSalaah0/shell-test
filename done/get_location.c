#include "main.h"
/**
 * get_location - get the current location
 * @command: command which need the dir
 * Return: path or NULL
*/
char *get_location(char *command)
{
char *path, *path_cp, *path_tkn, *fpath;
int cmdlen, dirlen;
struct stat buffer;
path = getenv("PATH");
if (path)
{
path_cp = strdup(path);
cmdlen = strlen(command);
path_tkn = strtok(path_cp, ":");
while (path_tkn != NULL)
{
dirlen = strlen(path_tkn);
fpath = malloc(cmdlen + dirlen + 2);
strcpy(fpath, path_tkn);
strcat(fpath, "/");
strcat(fpath, command);
strcat(fpath, "\0");
if (stat(fpath, &buffer) == 0)
{
free(path_cp);
return (fpath);
}
else
{
free(fpath);
path_tkn = strtok(NULL, ":");
}
}
free(path_cp);
}
if (stat(command, &buffer) == 0)
{
return (command);
}
return (NULL);
}