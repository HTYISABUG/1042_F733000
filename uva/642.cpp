#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main(){
	bool c;
	string input , copy;
	vector<string> key;
	vector<string> scratch;
	vector<string>::iterator it , b , e;
	map<string , string> dic;

	while(cin >> input){
		if(input == "XXXXXX"){input.clear();break;}
		key.push_back(input);
		copy = input;
		sort(copy.begin() , copy.end());
		dic.insert(pair<string , string>(input , copy));
		input.clear();
		copy.clear();
	}
	b = key.begin();
	e = key.end();
	while(cin >> input){
		if(input == "XXXXXX"){return 0;}
		sort(input.begin() , input.end());
		c = false;
		for(it = b ; it != e ; it++){
			if(dic[*it] == input){
				scratch.push_back(*it);
				c = true;
			}
		}
		if(!c){cout << "NOT A VALID WORD" << endl;}
		else{
			sort(scratch.begin() , scratch.end());
			for(it = scratch.begin() ; it != scratch.end() ; it++){cout << *it << endl;}
			scratch.clear();
		}
		cout << "******" << endl;
		input.clear();
	}

}
