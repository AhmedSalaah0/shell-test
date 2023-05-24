#include "main.h"

/**
 * execute_cd - Function that executes the "cd" command
 * @dir: The directory to change to
 *
 * Return: 0 if success, -1 if error
 */
int execute_cd(const char *dir)
{
if (chdir(dir) != 0)
{
perror("error");
return (-1);
}
return (0);
}