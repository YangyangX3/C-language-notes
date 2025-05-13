#include <stdio.h>
#include "binaury.h"
struct wd{
	unsigned int t1:3;
	unsigned int t2:5;
	int t3:24;
};

int main(){
	struct wd tt;
	tt.t1 = 3;
	tt.t2 = 15;
	tt.t3 = 0;
	printf("%zu\n",sizeof(tt));
	prtBin(*(int*)&tt);
}


