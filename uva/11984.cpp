#include <cstdio>

int main(){
	int T , i;
	float C , d;

	while(scanf("%d" , &T) != EOF){
		for(i = 1 ; i <= T ; i++){
			scanf("%f %f" , &C , &d);
			printf("Case %d: %.2f\n" , i , (C * 9 / 5 + d) * 5 / 9);
		}
	}
	
	return 0;
}
