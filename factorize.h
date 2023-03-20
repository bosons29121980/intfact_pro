#ifndef __FACTORIZE__
#define __FACTORIZE__
#include <iostream>
#include <stdio.h>
#include <string>
#include "common.h"
using namespace std;

void* factorize(void* arg1) {
	char* num = ((struct arg*) arg1)->num;
	int param = ((struct arg*) arg1)->param;
	std::string result = "";
	char* ret = 0;
	FILE* fp = fopen("./pi.dat","r");
	FILE* fe = fopen("./e.dat", "r");
	char* buf = (char*) calloc(3, sizeof(char));
	fread(buf, 2, sizeof(char), fp);
	fread(buf, 2, sizeof(char), fe);
	free(buf);
	int state = param;
	unsigned int ctr = 0;
	unsigned int l = strlen(num);
	int state1_cnt = 0, state2_cnt = 0;
	while (1) {
		char pp = 0, ee = 0;
		fscanf(fp, "%c", &pp);
		if (state == param) {
			ee = num[ctr];
			ctr = (ctr + 1) % l;
			state1_cnt++;
		} else {
			fscanf(fe, "%c", &ee);
			state2_cnt++;
		}
		if (ee == pp) {
			state = 1 - state;
			if (state == (1-param)) {
				fseek(fe, 2, SEEK_SET);
			} else {
				if (state1_cnt == state2_cnt) {
					result = result + "";
					//output unknown
				} else if (state1_cnt > state2_cnt) {
					result = result + "A";
				} else if (state1_cnt < state2_cnt) {
					result = result + "S";
				}
				int is_prime1 = 0, is_prime2 = 0;
				char* factor1 = interpret(result, param, 1, num, is_prime1);
				char* factor2 = interpret(result, param, 0, num, is_prime2);
				if (is_prime1 && is_prime2) {
					ret = strdup("Prime");
					break;
				}
				int decision = 0;
				char* remainder = _modulo_(num, factor1, decision);
				if (strcmp(remainder, "0") != 0) {
					decision = 0;
					remainder = _modulo_(num, factor2, decision);
					if (!decision && strcmp(remainder, "0") == 0) {
						ret = factor2;
						break;
					}
				} else {
					if (!decision) {
						ret = factor1;
						break;
					}
				}
				state1_cnt = state2_cnt = 0;
			}
		} 
	}
	fclose(fp);
	fclose(fe);
	return ret;
}
#endif
