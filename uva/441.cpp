#include <cstdio>
#include <new>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	int amount , in;
	int* num;
	bool check = false;

	while(scanf("%d" , &amount) != EOF){
		if(amount==0){return 0;}
		!check ? check = true : puts("");
		num = new int[amount];
		memset(num , 0 , amount * sizeof(int));
		for(int i = 0 ; i < amount ; i++){scanf("%d" , num + i);}
		sort(num , num + amount);
		for(int i = 0 ; i < amount - 5 ; i++){
			for(int j = i + 1 ; j < amount - 4 ; j++){
				for(int k = j + 1 ; k < amount - 3 ; k++){
					for(int l = k + 1 ; l < amount - 2 ; l++){
						for(int m = l + 1 ; m < amount - 1 ; m++){
							for(int n = m + 1 ; n < amount ; n++){
								printf("%d %d %d " , num[i] , num[j] , num[k]);
								printf("%d %d %d\n" , num[l] , num[m] , num[n]);
							}
						}
					}
				}
			}
		}
		delete[] num;
	}
}
