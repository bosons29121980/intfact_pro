#ifndef __FACTORIZE__
#define __FACTORIZE__
#include "common.h"
#include <string>
using namespace std;
void* factorize(void* arg) {
    struct func_arg* a = (struct func_arg*) arg;
    char* num = a->num;
    int param = a->param;
    FILE* fp = 0, *fe = 0;
    if (param) {
       fp = fopen("./pi.dat", "r");
       fe = fopen("./e.dat", "r");
    } else {
       fp = fopen("./e.dat", "r");
       fe = fopen("./pi.dat", "r");
    }
    std::string factor = "";
    while (1) {
    }
    char* ret = strdup((char*) factor.c_str());
    return ret;
}
#endif
