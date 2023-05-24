#include "main.h"
/**
 * create_pipes - create a pipe
 * @pip: array of pipes
 * @pipnum: number of pipes
*/
void create_pipes(int pip[][2], int pipnum)
{
int i;
for (i = 0; i < pipnum - 1; i++)
{
if (pipe(pip[i]) < 0)
{
perror("pipe error");
exit(EXIT_FAILURE);
}
}
}