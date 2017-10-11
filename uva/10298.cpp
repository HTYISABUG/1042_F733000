#include <cstdio>
#include <cstring>
using namespace std;

#define maxlen 1000100

int main(){

	int i , pos , len;
	char s[maxlen];
	int ff[maxlen];

	while(1){

		memset(s , 0 , maxlen * sizeof(char));
		scanf("%s" , s);

		if(s[0] < 'a' || 'z' < s[0]) return 0;

		len = strlen(s);

		ff[0] = -1;
		for(i = 1 , pos = -1; i < len ; i++){

			while(pos >= 0 && s[i] != s[pos+1]) pos = ff[pos];
			if(s[i] == s[pos+1]) pos++;
			ff[i] = pos;

		}

		if(pos > -1 && len % (len - pos - 1) == 0)
			printf("%d\n" , len / (len - pos - 1));
		else puts("1");

	}

}


