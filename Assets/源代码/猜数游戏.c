#include <stdio.h>

int main(){
	int number = 100;
	int guess,n;
	scanf("%d %d",&guess,&n);
	for(int i = 1;i<=n;i++){
		if(guess == number){
			if(i ==1 ){
				printf("Bingo");
			}
			if(i<3){
				printf("Lucky You!");
			}
			if(i>3){
				printf("Good Guess!");
			}
		}else if(guess > number){
			printf("Too big\n");
			scanf("%d",&guess);
		}else{
			printf("Too small\n");
			scanf("%d",&guess);
		}
	}
	return 0;
}
