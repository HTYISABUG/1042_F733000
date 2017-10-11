#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	int i , j;
	int Case , len;
	string input;
	stack<char> save;

	while(scanf("%d\n" , &Case) != EOF){
		for(i = 0 ; i < Case ; i++){
			getline(cin , input);
			if(input.empty()){puts("Yes"); continue;}
			len = input.length();
			if(len == 1){puts("No"); continue;}
			for(j = 0 ; j < len ; j++){
				if(input[j] == '(' || input[j] == '['){save.push(input[j]);}
				else if(input[j] == ')'){
					if(save.empty()){break;}
					else{
						if(save.top() == '('){save.pop();}
						else{break;}
					}
				}
				else if(input[j] == ']'){
					if(save.empty()){break;}
					else{
						if(save.top() == '['){save.pop();}
						else{break;}
					}
				}
				else{continue;}
			}
			if(j != len){puts("No");}
			else{
				if(save.empty()){puts("Yes");}
				else{puts("No");}
			}
			while(!save.empty()){save.pop();}
			input.clear();
		}
	}
}
