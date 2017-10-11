#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

string mergesort(string , int);
string merge(string , string , int);
bool cmp(pair<string , int> , pair<string , int>);

long long counter;

int main(){
	int i;
	int length , amount;
	string input , manip;
	vector<pair<string , int> > save;
	vector<pair<string , int> >::iterator iter;

	while(cin >> length){
		cin >> amount;

		for(i = 0 ; i < amount ; i++){
			cin >> input;
			counter = 0;
			mergesort(input , length);
			save.push_back(make_pair(input , counter));
		}

		sort(save.begin() , save.end() , cmp);

		for(iter = save.begin() ; iter != save.end() ; iter++){
			cout << (*iter).first << endl;
		}
	}

	return 0;
}

string mergesort(string input , int length){
	if(length == 1){return input;}

	string left = input.substr(0 , length / 2);
	string right = input.substr(length / 2 , length - length / 2);

	return merge(mergesort(left , length / 2) , mergesort(right , length - length / 2) , length);
}

string merge(string left , string right , int length){
	string result;
	int i = 0 , j = 0;

	while(i < length / 2 && j < length - length / 2){
		if(left[i] <= right[j]){result += left[i++];}
		else{result += right[j++];counter += (length / 2 - i);}
	}
	while(i < length / 2){result += left[i++];}
	while(j < length - length / 2){result += right[j++];}

	return result;
}

bool cmp(pair<string , int> a , pair<string , int> b){
	return a.second <= b.second;
}
