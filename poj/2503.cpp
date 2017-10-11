#include <iostream>
#include <string>
#include <map>
#include <utility>
using namespace std;

int main(){
	string input;
	int judge , len;
	map<string , string> dic;

	while(getline(cin , input)){
		if(input.empty()){continue;}
		judge = (int)input.find(" ");
		len = input.length();
		if(judge != -1){
			dic.insert(pair<string , string>(input.substr(judge + 1 , len - judge - 1) , input.substr(0 , judge)));
		}
		else if(dic[input] == ""){cout << "eh\n";}
		else{cout << dic[input] << endl;}
	}

	return 0;
}
