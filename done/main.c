#include "main.h"
/**
 * main - entry point
 * @ac: Num of argu.
 * @argv: array of arguments
 * Return: returned 0, or -1 if fail
 */
int main(int ac, char **argv)
{
char *line = NULL;
size_t n = 0;

while (1)
{
printf("$ ");
if (getline(&line, &n, stdin) == -1)
{
perror("getline error");
return (-1);
}
char **args = read_input(line, &n);
if (args == NULL)
{
fprintf(stderr, "Failed to read input\n");
continue;
}
if (strcmp(args[0], "env") == 0)
{
execute_env();
}
else
{
execute(args, argv);
}

free (args);

}

return (0);
}