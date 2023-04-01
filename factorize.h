#ifndef __FACTORIZE__
#define __FACTORIZE__
#include "common.h"
#include "zeros.h"
#include <string>
using namespace std;
const int MAGIC = 24;
const int PART_MAGIC = 12;
const int START = 2;
const int PART = 8;

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
	++ctr;
	while (1) {
		char pp2 = 0, ee2 = 0;
		fscanf(fp, "%c", &pp2);
		char n2 = num[ctr % l];
		fscanf(fe, "%c", &ee2);
		int sum2 = (pp2 - '0') + (n2 - '0') + (ee2 - '0'); 
		sum += sum2; 
		printf("sum\t%d\tpp %c\tn %c\t e %c  ctr %llu zero %f\n", sum, pp2 , n2, ee2, ctr % l, zeros[ctr]);
		if (sum == MAGIC && sum2 == PART_MAGIC) {
			if ((ctr + 1) % PART == 0) {
				ctr++;
				fseek(fe, START,  SEEK_SET);
				fscanf(fp, "%c", &pp);
				n = num[ctr % l];
				fscanf(fe, "%c", &ee);
				sum = (pp - '0') + (n - '0') + (ee - '0');
				printf("sum\t%d\tpp %c\tn %c\t e %c \t ctr %llu zero %f\n", sum, pp, n, ee, ctr % l, zeros[ctr]);
		                system("a=1;read a");
			} else {
				sum = sum2;
			}
		} else {
			sum = sum2;
		}
		ctr++; 
	}
	fclose(fp);
	fclose(fe);
	return ret;
}
#endif
