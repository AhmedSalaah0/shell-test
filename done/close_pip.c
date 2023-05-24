#include "main.h"
/**
 * 
 * 
 * 
*/
void close_pipes(int pip[][2], int pipnum) {
    for (int i = 0; i < pipnum - 1; i++) {
        close(pip[i][0]);
        close(pip[i][1]);
    }
}