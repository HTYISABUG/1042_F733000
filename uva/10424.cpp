#include <iostream>
#include <string>
#include <iomanip>
#include <cstdio>

using namespace std;

int main(){
	string name_1;
	string name_2;
	int sum_1 , sum_2 , buffer;
	int i;
	float output;

	while(getline(cin , name_1)){
		//input
		getline(cin , name_2);
		//zero
		sum_1 = 0;
		sum_2 = 0;
		//alphabet to number
		for(i = 0 ; i < name_1.length() ; i++){
			if('a' <= name_1[i] && name_1[i] <= 'z'){
				sum_1 = sum_1 + (int)(name_1[i] - 'a') + 1;
			}
			if('A' <= name_1[i] && name_1[i] <= 'Z'){
				sum_1 = sum_1 + (int)(name_1[i] - 'A') + 1;
			}
		}
		for(i = 0 ; i < name_2.length() ; i++){
			if('a' <= name_2[i] && name_2[i] <= 'z'){
				sum_2 = sum_2 + (int)(name_2[i] - 'a') + 1;
			}
			if('A' <= name_2[i] && name_2[i] <= 'Z'){
				sum_2 = sum_2 + (int)(name_2[i] - 'A') + 1;
			}
		}
		//sum every digit
		while(sum_1 / 10 != 0){
			buffer = 0;
			while(sum_1 != 0){
				buffer += (sum_1 % 10);
				sum_1 /= 10;
			}
			sum_1 = buffer;
		}
		while(sum_2 / 10 != 0){
			buffer = 0;
			while(sum_2 != 0){
				buffer += (sum_2 % 10);
				sum_2 /= 10;
			}
			sum_2 = buffer;
		}
		//filter
		if(sum_1 == 0 && sum_2 == 0){
			cout << '\n';
			//clean the string
			name_1.clear();
			name_2.clear();
			continue;
		}
		//output
		if(sum_1 > sum_2){
			output = (float)sum_2 / (float)sum_1 * 100;
		}
		else{
			output = (float)sum_1 / (float)sum_2 * 100;
		}
		cout << fixed << setprecision(2) << output << " %\n";
		//clean the string
		name_1.clear();
		name_2.clear();
	}
}
