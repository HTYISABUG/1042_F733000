#include <cstdio>

int main(){
	int scenario;
	int m , n;
	int i;
	float sum;

	while(scanf("%d" , &scenario) != EOF){
		for(i = 1 ; i <= scenario ; i++){
			scanf("%d %d" , &m , &n);
			if(m * n % 2 == 1){
				sum = m * n + 0.41;
			}
			else{
				sum = m * n;
			}
			printf("Scenario #%d:\n%.2f\n\n" , i , sum);
		}
	}

	return 0;
}
