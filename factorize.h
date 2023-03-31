#ifndef __FACTORIZE__
#define __FACTORIZE__
#include "common.h"
#include <string>
using namespace std;
const int MAGIC = 24;
const int START = 2;

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
	char* buf = (char*) calloc(3, sizeof(char));
	fread(buf, 2, sizeof(char), fp);
	fread(buf, 2, sizeof(char), fe);
	free(buf);
	std::string factor = "";
	unsigned long long int ctr = 0;
	char* ret = 0;
	char pp = 0, ee = 0;
	fscanf(fp, "%c", &pp);
	char n = num[ctr % l];
	fscanf(fe, "%c", &ee);
	int sum = (pp - '0') + (n - '0') + (ee - '0');
	unsigned long long int nOdd = 0;
	unsigned long long int nEven = 0;
	int last_even = nEven;
	int last_odd = nOdd;
	int last_odd2 = 0;
	int last_even2 = 0;
	if (sum % 2 == 0) {
		nEven++;
	} else {
		nOdd++;
	}
	++ctr;
	while (1) {
		char pp2 = 0, ee2 = 0;
		fscanf(fp, "%c", &pp2);
		char n2 = num[ctr % l];
		fscanf(fe, "%c", &ee2);
		int sum2 = (pp2 - '0') + (n2 - '0') + (ee2 - '0'); 
		last_even2 = nEven;
		last_odd2 = nOdd;
		if (sum2 % 2 == 0) {
			nEven++;
		} else {
			nOdd++;
		}
		sum += sum2; 
		printf("sum\t%d\tpp %c\tn %c\t e %c factor %s\n", sum, pp , n, ee, (char*) factor.c_str());
		system("a=1;read a");
		if (sum == MAGIC) {
			if (last_even == last_odd) {
				factor = factor + "1";
				ctr += 2;
				fseek(fe, START,  SEEK_SET);
				fscanf(fp, "%c", &pp);
				n = num[ctr % l];
				fscanf(fe, "%c", &ee);
				sum = (pp - '0') + (n - '0') + (ee - '0');
				last_odd = last_even = nOdd = nEven = 0;
				if (sum % 2 == 0) {
					nEven++;
				} else {
					nOdd++;
				}
				printf("sum\t%d\tpp %c\tn %c\t e %c odd %llu\t even %llu\n", sum, pp , n, ee, nOdd, nEven);
			} else {
				factor = factor + "0";
				last_odd = last_odd2;
				last_even = last_even2;
				sum = sum2;
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
		} else {
			last_odd = last_odd2;
			last_even = last_even2;
			sum = sum2;
		}
		ctr++; 
	}
	fclose(fp);
	fclose(fe);
	return ret;
}
#endif
