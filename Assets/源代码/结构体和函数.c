#include <stdio.h>
#include <stdbool.h>
struct date {
    int month;
    int day;
    int year;
};

struct date* getStruct(struct date*);

int main(int argc,const char *argv[]){
	
	struct date d = {07,23,2025};
	struct date *p = &d;
		
	printf("%p\n",p);
	printf("%p\n",&d.month);
	
	getStruct(p);
	printf("%i-%i-%i\n",p->month,p->month,p->year);
	return 0;
}

struct date* getStruct(struct date* p){
	scanf("%d",&p->month);
	scanf("%d",&p->day);
	scanf("%d",&p->year);
	return p;
}
