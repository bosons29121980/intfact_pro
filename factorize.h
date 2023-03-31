#ifndef __FACTORIZE__
#define __FACTORIZE__
#include "common.h"
#include <string>
using namespace std;
const int MAGIC = 24;
const int START = 2;
const int PART = 3;

void* factorize(void* arg) {
    struct func_arg* a = (struct func_arg*) arg;
    char* num = a->num;
    unsigned long long int l = strlen(num);
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
    unsigned long long int ctr = 0;
    char* ret = 0;
    while (1) {
        char pp = 0, ee = 0;
        fscanf(fp, "%c", &pp);
        char n = num[ctr % l];
        fscanf(fe, "%c", &ee);
        unsigned int pos1 = ftell(fp);
        unsigned int pos2 = ftell(fe);
        int sum = (pp - '0') + (n - '0') + (ee - '0');
        char pp2 = 0, ee2 = 0;
        fscanf(fp, "%c", &pp2);
        char n2 = num[(ctr + 1) % l];
        fscanf(fe, "%c", &ee2);
        sum += (pp2 - '0') + (n2 - '0') + (ee2 - '0');
        if (sum == MAGIC) {
           if (ctr % PART == 0) {
                factor = factor + "1";
                fseek(fp, pos1, SEEK_SET);
                fseek(fe, START, SEEK_SET);
           } else {
                factor = factor + "0";
                fseek(fp, pos1, SEEK_SET);
                fseek(fe, pos2, SEEK_SET);
           }
	   if (ctr % l == 0) {
		   ret = _int_(factor);
		   int is_prime = _divides_(num, ret);
		   if (is_prime == 2) {
			   ret = strdup("");
			   break;
		   } else if (is_prime == 0) {
			   break;
		   } 
	   }
        }
        ctr++; 
    }
    fclose(fp);
    fclose(fe);
    return ret;
}
#endif
