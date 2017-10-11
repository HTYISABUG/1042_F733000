#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmp(string , string);

int main(){
	int amount , counter;
	int i , j;
	string input , trash;
	vector<string> country;
	vector<string>::iterator iter;

	while(cin >> amount){
		for(i = 0 ; i < amount ; i++){
			cin >> input;
			getline(cin , trash);
			country.push_back(input);
		}

		sort(country.begin() , country.end() , cmp);

		counter = 0;
		for(iter = country.begin() ; iter != country.end() ; iter++){
			counter++;
			if(*iter != *(iter + 1) && iter + 1 != country.end()){
				cout << *iter << ' ' << counter << endl;
				counter = 0;
			}
		}
		cout << *(iter - 1) << ' ' << counter << endl;

		country.clear();
	}

	return 0;
}

bool cmp(string a , string b){
	return a < b;
}
