#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int cents;
	int coin[5] = {1,5,10,25,50};
	int dp[7490];
	memset(dp , 0 , 7490 * sizeof(int));
	dp[0] = 1;
	for(int i = 0 ; i < 5 ; i++){
		for(int j = 0 ; j < 7490 ; j++){
			if(j - coin[i] >= 0 && dp[j-coin[i]]){
				dp[j] += dp[j-coin[i]];
			}
		}
	}
	while(scanf("%d" , &cents) != EOF){printf("%d\n" , dp[cents]);}
	return 0;
}
