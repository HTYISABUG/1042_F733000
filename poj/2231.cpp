#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	long long i , j;
	long long cow , loc;
	long long total;
	long long num[10000000000];

	while(scanf("%lld" , &cow) != EOF){
	memset(num , 0 , )
		for(i = 0 ; i < cow ; i++){
			scanf("%lld" , &loc);
			num[i] = loc;
		}
		sort(num , num + cow);
		total = 0;
		for(i = 0 ; i < cow ; i++){
			for(j = 0 ; j < i ; j++){total += (num[i] - num[j]);}
			for(j = i + 1 ; j < cow ; j++){total += (num[j] - num[i]);}
		}
		printf("%lld\n" , total);
	}

	return 0;
}
