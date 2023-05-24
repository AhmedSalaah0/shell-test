#include "main.h"
#include <limits.h>
/**
 * main - entry point
 * @ac: Num of argu.
 * @argv: array of arguments
 *
 * Return: returned 0, or -1 if fail
 */

int main(int ac, char **argv) 
{
char *line = NULL, *linecp = NULL;
size_t n = 0;
ssize_t num;
const char *del = " \n";
int num_tks = 0;
char *tks;
int i;

(void)ac;

while (1) 
{
printf("$ ");
num = getline(&line, &n, stdin);


if (num == -1) 
{
perror("getline error");
return -1;
}

linecp = malloc(sizeof(char) * num);
if (linecp == NULL) 
{
perror("error");
return -1;
}
strcpy(linecp, line);

tks = strtok(line, del);
while (tks != NULL) 
{
num_tks++;
tks = strtok(NULL, del);
}
num_tks++;
argv = malloc(sizeof(char *) * num_tks);
tks = strtok(linecp, del);

for (i = 0; tks != NULL; i++) 
{
argv[i] = malloc(sizeof(char) * strlen(tks));
strcpy(argv[i], tks);
tks = strtok(NULL, del);
}
argv[i] = NULL;


int pipenum = 1;
for (int j = 0; argv[j] != NULL; j++) 
{
if (strcmp(argv[j], "|") == 0) 
{
pipenum++;
argv[j] = NULL;
}
}
if (strcmp(argv[0], "env") == 0) {
execute_env();
continue;
}

if (pipenum > 1) 
{

execute_pipe(argv, pipenum);
}
else 
{

execute(argv, argv);
}
for (int j = 0; j < i; j++) 
{
free(argv[j]);
}
free(linecp);
}
free(line);

return 0;
}


