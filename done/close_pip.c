#include "main.h"
/**
 * close_pipes - function close pipe after finsh
 * @pip: array of pipes
 * @pipnum: number of pipes
*/
void close_pipes(int pip[][2], int pipnum)
{
int i;
for (i = 0; i < pipnum - 1; i++)
{
close(pip[i][0]);
close(pip[i][1]);
}
}