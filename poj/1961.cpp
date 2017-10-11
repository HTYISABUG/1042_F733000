#include <cstdio>
#include <cstring>
using namespace std;

#define maxlen 1000100

int main(){

	int i , len , count = 0 , pos;
	char s[maxlen];
	int ff[maxlen];

	while(1){

		scanf("%d" , &len);

		if(len == 0) return 0;

		if(count > 0) puts("");

		printf("Test case #%d\n" , ++count);

		memset(s , 0 , (len + 100) * sizeof(char));
		scanf("%s" , s);

		ff[0] = -1;
		for(i = 1 , pos = -1; i < len ; i++){

			while(pos >= 0 && s[i] != s[pos+1]) pos = ff[pos];
			if(s[i] == s[pos+1]) pos++;
			ff[i] = pos;

			if(pos >-1 && (i + 1) % (i - pos) == 0)
			printf("%d %d\n" , i + 1 , (i + 1) / (i - pos));

		}

	}

}
