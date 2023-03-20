#ifndef __COMMON__
#define __COMMON__
#include <gmp.h>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;

struct arg {
    char* num;
    int param;
};

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

int decision(char* d1, char* d2, char* num) {
    mpz_t dz1;
    mpz_init(dz1);
    mpz_t dz2;
    mpz_init(dz2);
    mpz_set_str(dz1, d1, 10);
    mpz_set_str(dz2, d2, 10);
    mpz_t res;
    mpz_init(res);
    mpz_mul(res, dz1, dz2);
    mpz_t nz;
    mpz_init(nz);
    mpz_set_str(nz, num, 10);
    if (mpz_cmp(res, nz)  == 0) {
          mpz_clear(dz1);
          mpz_clear(dz2);
          mpz_clear(res);
          mpz_clear(nz);
          return 0;
    } else {
          mpz_clear(dz1);
          mpz_clear(dz2);
          mpz_clear(res);
          mpz_clear(nz);
          return 1;
    }
}

char* interpret(std::string result, int param, int p, char* num, int& is_prime) {
    if (param == 1) {
       std::reverse(result.begin(), result.end());
    }
    char* ret = (char*) calloc(result.size() + 1, sizeof(char));
    for (int i = 0; i < result.size(); ++i) {
          if (p == 1) {
               if (result[i] == 'A') {
                     ret[i] = '1';
               } else {
                     ret[i] = '0';
               }
          } else {
               if (result[i] == 'A') {
                     ret[i] = '0';
               } else {
                     ret[i] = '1';
               }
          }
    }
    char* dec = _int_(ret);
    mpz_t dz;
    mpz_init(dz);
    mpz_set_str(dz, dec, 10);
    mpz_t nz;
    mpz_init(nz);
    mpz_set_str(nz, num, 10);
    if (mpz_cmp(nz, dz) >= 0) {
         is_prime = 1;
    } else {
         is_prime = 0;
    }
    mpz_clear(dz);
    mpz_clear(nz);
    return dec;
}

char* _modulo_(char* num, char* x) {
   mpz_t nz;
   mpz_init(nz);
   mpz_set_str(nz, num, 10);
   mpz_t xz;
   mpz_init(xz);
   mpz_set_str(xz, x, 10);
   mpz_t remainder;
   mpz_init(remainder);
   char* r = 0;
   if (mpz_cmp_si(xz, 0) <= 0) {
	   r = strdup("-1");
   } else {
	   mpz_mod(remainder, nz, xz);
	   r =  strdup(mpz_get_str(0, 10, remainder));
   }
   mpz_clear(nz);
   mpz_clear(xz);
   mpz_clear(remainder);
   return r;
}
#endif
