#include <stdio.h>

int main(){
	int m,n;
	int cut=0;
	int sum = 0;
	scanf("%d %d",&m,&n);
	if(m>=1 && n<=500){
		int l = m;
		for(m=m;m<=n;m++){
			int p = 0;
			for(int i = 1;i<=m;i++){
				if(m%i==0){
					p+=1;
				}
			}
			if(p==2){
				cut++;
				sum+=m;
			}
		}
		printf("\n%d-%d֮���������%d��,�ܺ�Ϊ%d",l,n,cut,sum);
	}else{
		printf("���벻�淶��");
	}
	return 0;
}
