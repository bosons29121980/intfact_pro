#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include "common.h"
#include "factorize.h"
using namespace std;

int main(int argc, char* argv[]) {
     char* num = strdup(argv[1]);
     char* ret1 = 0, *ret2 = 0;
     pthread_t thread1, thread2;
     struct arg arg1;
     struct arg arg2;
     arg1.num = num;
     arg2.num = num;
     arg1.param = 1;
     arg2.param = 0;
     pthread_create(&thread1, NULL, factorize, &arg1);
     pthread_create(&thread2, NULL, factorize, &arg2);
     pthread_join(thread1, (void**) &ret1);
     pthread_join(thread2, (void**) &ret2);
     if (strcmp(ret1, "Prime") == 0 && strcmp(ret2, "Prime") == 0) {
           printf(" %s is a prime number. \n", num);
     } else {
           printf("%s = %s X %s\n", num, ret1, ret2);
     }
     return 0;
}
