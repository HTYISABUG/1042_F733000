#include <cstdio>
using namespace std;

int main(){
	int M , N;
	long long counter;
	int i , j;

	while(scanf("%d %d" , &M , &N) != EOF){
		if(M == 0 && N == 0){return 0;}
		counter = M * N *(M + N - 2);
		for(i = 0 ; i < M ; i++){
			for(j = 0 ; j < N ; j++){
				if(i < j){counter += i;}
				else{counter += j;}
				if(i < N - j - 1){counter += i;}
				else{counter += (N - j - 1);}
				if(M - i - 1 < j){counter += (M - i - 1);}
				else{counter += j;}
				if(M - i - 1 < N - j - 1){counter += (M - i - 1);}
				else{counter += (N - j - 1);}
			}
		}
		printf("%lld\n" , counter);
	}
}
