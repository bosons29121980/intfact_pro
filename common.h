#ifndef __COMMON__
#define __COMMON__
#include <gmp.h>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

char* _int_(char* r) {
    mpz_t prod;
    mpz_init(prod);
    mpz_t sum;
    mpz_init(sum);
    mpz_t term;
    mpz_init(term);
    mpz_set_si(prod, 1);
    mpz_set_si(sum, 0);
    unsigned int l = strlen(r);
    for (int i = l - 1; i >= 0; --i) {
        int rk = r[i] - '0';
        mpz_mul_ui(term, prod, rk);
        mpz_add(sum, sum, term);
        mpz_mul_ui(prod, prod, 2); 
    }
    char* ret = strdup(mpz_get_str(0, 10, sum));
    mpz_clear(prod);
    mpz_clear(sum);
    mpz_clear(term);
    return ret;
}

#endif
