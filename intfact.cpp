#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include "common.h"
#include "factorize.h"
using namespace std;

int main(int argc, char* argv[]) {
     char* num = strdup(argv[1]);
     free(num);
     return 0;
}
