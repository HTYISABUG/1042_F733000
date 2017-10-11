#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define ull unsigned long long
#define max 2147483648

int main(){
	vector<ull> save;
	for(ull i = 1 ; i <= max ; i *= 2){
		for(ull j = 1 ; i * j <= max ; j *= 3){
			save.push_back(i * j);
		}
	}
	sort(save.begin() , save.end());

	ull in;
	ull l , r , mid , end = save.size() - 1;

	while(1){
		scanf("%llu" , &in);
		if(in == 0){return 0;}
		l = 0 , r = end;
		while(l != r){
			mid = (l + r) / 2;
			if(save.at(mid) >= in){r = mid;}
			else{l = mid + 1;}
		}
		printf("%llu\n" , save.at(r));
	}
}
