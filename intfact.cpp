#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "factorize.h"
#include "common.h"
extern void* factorize(void* arg);

int main(int argc, char* argv[]) {
     char* num = strdup(argv[1]);
     int l = strlen(num);
     char* ret1 = 0, *ret2 = 0;
     pthread_t thread_id1, thread_id2;
     struct func_arg arg1;
     struct func_arg arg2;
     arg1.num = num;
     arg1.param = 1;
     arg2.num = num;
     arg2.param = 0;
     pthread_create(&thread_id1, NULL, factorize, &arg1);
     pthread_create(&thread_id2, NULL, factorize, &arg2);
     pthread_join(thread_id1, (void**) &ret1);
     pthread_join(thread_id2, (void**) &ret2);
     if (ret1 && ret2) {
        printf("%s = %s X %s\n", num, ret1, ret2);
        free(ret1);
        free(ret2);
     } else {
        printf("%s is a Prime Number.\n", num);
     }
     free(num);
     return 0;
}
