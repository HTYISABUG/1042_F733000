#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
	int times , a , b , n = 1 , i , j , count , num , buf;
	int NOD[1000001];
	vector<int> save;
	vector<int>::iterator l , r;

	memset(NOD , 0 , 1000001 * sizeof(int));
	
	for(i = 1 ; i <= 1000000 ; i++){
		for(j = 1 ; i * j <= 1000000 ; j++){
			NOD[i*j]++;
		}
	}

	while(n <= 1000000){
		save.push_back(n);
		n += NOD[n];
	}

	while(scanf("%d" , &times) != EOF){
		for(i = 1 ; i <= times ; i++){
			scanf("%d %d" , &a , &b);
			l = lower_bound(save.begin() , save.end() , a);
			r = upper_bound(save.begin() , save.end() , b);
			num = r - l;
			printf("Case %d: %d\n" , i , num);
		}
	}

	return 0;
}
