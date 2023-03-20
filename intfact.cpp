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
     arg1.param = 0;
     arg2.param = 1;
     pthread_create(&thread1, NULL, factorize, &arg1);
     pthread_create(&thread2, NULL, factorize, &arg2);
     pthread_join(thread1, (void**) &ret1);
     pthread_join(thread2, (void**) &ret2);
     char* dec1 = _int_(ret1);
     char* dec2 = _int_(ret2);
     int is_prime = decision(dec1, dec2, num);
     if (is_prime) {
           printf(" %s is a prime number. \n", num);
     } else {
           printf("%s = %s X %s\n", num, dec1, dec2);
     }
     return 0;
}
