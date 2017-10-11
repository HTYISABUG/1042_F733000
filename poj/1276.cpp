#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int need , N , n , d , r;
	bool c[100001];
	vector<int> cash;

	while(scanf("%d %d" , &need , &N) != EOF){
		fill(c , c + 100001 , false);
		for(int i = 0 ; i < N ; i++){
			scanf("%d %d" , &n , &d);
			for(int j = 0 ; j <= n ; j++){
				r = cash.size();
				for(int k = 0 ; k < r ; k++){
					if(cash[k] + j * d <= need){
						c[cash[k]+j*d] = true;
						cash.push_back(cash[k] + j * d);
					}
				}
			}
			for(int j = 0 ; j <= n && j * d <= need; j++){
				c[j*d] = true;
				cash.push_back(j * d);
			}
		}

		sort(cash.begin() , cash.end());

		if(cash.empty()){puts("0");}
		else{printf("%d\n" , cash.back());}

		cash.clear();
	}

	return 0;
}
