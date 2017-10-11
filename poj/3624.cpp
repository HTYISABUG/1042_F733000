#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int n , m;
	int w[3402] , d[3402] , v[12881];

	while(scanf("%d %d" , &n , &m) != EOF){
		fill(w , w + 3402 , 0);
		fill(d , d + 3402 , 0);
		fill(v , v + 12881 , 0);
		for(int i = 0 ; i < 3402 ; i++){scanf("%d %d" , w + i , d + i);}
		for(int i = 0 ; i < 3402 ; i++){
			for(int j = m ; j - w[i] >= 0 ; j--){
				if(v[j] < v[j-w[i]] + d[i]){v[j] = v[j-w[i]] + d[i];}
			}
		}
		sort(v , v + 12881);
		printf("%d\n" , v[12880]);
	}

	return 0;
}
