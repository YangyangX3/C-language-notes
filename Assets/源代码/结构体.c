#include <stdio.h>
#include <string.h>

 struct date {
        int month;
        int day;
        int year;
    };

int main(int argc, const char *argv[])
{

    struct date today = {04,23,2025};
    struct date thismonth = {.month = 04,.year = 2025};
	
	struct date day;
	day = today;
	day.year = 2026;

    printf("today is %i-%i-%i.\n", today.year, today.month, today.day);
    printf("today is %i-%i.\n", thismonth.year, thismonth.month);
	printf("today is %i-%i-%i.\n", day.year, day.month,day.day);
    return 0;
}    
