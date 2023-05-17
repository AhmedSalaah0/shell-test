#include "shell.h"
/**
 * 
 * 
 * 
 * 
 * 
*/
int main(int argc, char **argv)
{
char *line = NULL, *linecp = NULL, *tkn;
size_t len;
ssize_t check;
const char *separat = " \n";
int n1 = 0, i;
(void)argc;
while (1)
{
printf("cinfun $");
check = getline(&line, &len, stdin);
if (check == -1)
{
printf("Error\n");
return (-1);
}
linecp = malloc(check * sizeof(char));
if (linecp == NULL)
{
printf("error");
return (-1);
}
strcpy(linecp, line);
tkn = strtok(line, separat);
while(tkn)
{
n1++;
tkn = strtok(NULL, separat);
}
n1++;
argv = malloc(sizeof(char *) * n1);
tkn = strtok(linecp, separat);

for (i = 0; tkn; i++)
{
argv[i] = malloc(sizeof(char) * strlen(tkn) + 1);
strcpy(argv[i], tkn);
tkn = strtok(NULL, separat);
}
argv[i] = NULL;
excute(argv);


}
free(argv);
free(linecp);
free(line);
return(0);
}
