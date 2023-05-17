#include "shell.h"
/**
 * 
 * 
 * 
 * 
 * 
*/
char *locate(char *cmd)
{
char *dir = getenv("PATH");
if (dir)
{
char *dircp = strdup(dir);
int dirlen = strlen(cmd);
char *tknd = strtok(dircp, ":");
while (tknd != NULL)
{
int ddlen = strlen(tknd);
char *file = malloc((dirlen + ddlen + 2) * sizeof(char));
strcpy(file, tknd);
strcat(file, "/");
strcat(file, cmd);
if (access(file, X_OK) == 0)
{
free(dircp);
return file;
}
free(file);
tknd = strtok(NULL, ":");
}
free(dircp);
}
return NULL;
}