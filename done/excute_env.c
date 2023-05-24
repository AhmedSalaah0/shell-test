#include "main.h"
/**
 * execute_env - function handle env case
*/
void execute_env() {
extern char **environ;
int i = 0;

while (environ[i] != NULL) {
printf("%s\n", environ[i]);
i++;
}
}