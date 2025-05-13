#include <stdio.h>
void prtBin(int number){
	unsigned mask = 1u << 31;
	for(;mask;mask>>=1){
		printf("%d",number&mask ?1:0);
	}
	printf("\n");
}
