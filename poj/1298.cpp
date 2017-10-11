#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
	string input;
	int c;

	while(getline(cin , input)){
		if(input == "START" || input == "END"){
			input.clear();
			continue;
		}
		else if(input == "ENDOFINPUT"){
			return 0;
		}
		else{
			for(c = 0 ; c < input.length() ; c++){
				if('A' <= input[c] && input[c] <= 'Z'){
					input[c] -= 5;
					if(input[c] < 'A'){
						input[c] += 26;
					}
				}
			}
			cout << input << '\n';
		}
	}
}
