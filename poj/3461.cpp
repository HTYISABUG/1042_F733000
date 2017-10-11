#include <cstdio>
#include <algorithm>
#include <new>
#include <cstring>
using namespace std;

#define ll long long

ll ff[20000];

void fail(char* , ll);

int main(){

	ll CASE , wlen , tlen , pos , count , i , j;
	char* w = new char[20000];
	char* t = new char[2000000];

	while(scanf("%lld" , &CASE) != EOF){

		for(i = 0 ; i < CASE ; i++){

			scanf("%s" , w);
			scanf("%s" , t);
			wlen = strlen(w);
			tlen = strlen(t);

			fail(w , wlen);

			for(j = 0 , pos = -1 , count = 0 ; j < tlen ; j++){

				while(t[j] != w[pos+1] && pos >= 0) pos = ff[pos];
				if(t[j] == w[pos+1]) pos++;
				if(pos + 1 == wlen){

					count++;
					pos = ff[pos];

				}

			}

			printf("%lld\n" , count);

			memset(w , 0 , 20000 * sizeof(char));
			memset(t , 0 , 2000000 * sizeof(char));

		}

	}

}

void fail(char* w , ll wlen){

	fill(ff , ff + 20000 , -1);

	for(ll i = 1 , pos = -1 ; i < wlen ; i++){

		while(pos >= 0 && w[i] != w[pos+1]) pos = ff[pos];
		if(w[i] == w[pos+1]) pos++;
		ff[i] = pos;

	}

}
