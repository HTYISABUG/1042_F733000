#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

bool cmp(pair<string , int> , pair<string , int>);

int main(){
	int i , j;
	int Case;
	char in[100];
	string out;
	bool duplication;
	map<char , char> link;
	link['A'] = '2' ; link['B'] = '2' ; link['C'] = '2';
	link['D'] = '3' ; link['E'] = '3' ; link['F'] = '3';
	link['G'] = '4' ; link['H'] = '4' ; link['I'] = '4';
	link['J'] = '5' ; link['K'] = '5' ; link['L'] = '5';
	link['M'] = '6' ; link['N'] = '6' ; link['O'] = '6';
	link['P'] = '7' ; link['R'] = '7' ; link['S'] = '7';
	link['T'] = '8' ; link['U'] = '8' ; link['V'] = '8';
	link['W'] = '9' ; link['X'] = '9' ; link['Y'] = '9';
	vector<pair<string , int> > save;
	vector<pair<string , int> >::iterator it;

	while(scanf("%d\n" , &Case) != EOF){
		duplication = false;
		for(i = 0 ; i < Case ; i++){
			memset(in , 0 , 100);
			fgets(in , 100 , stdin);
			for(j = 0 ; in[j] != '\0' ; j++){
				if('A' <= in[j] && in[j] <= 'Z'){out += link[in[j]];}
				if('0' <= in[j] && in[j] <= '9'){out += in[j];}
			}
			for(it = save.begin() ; it != save.end() ; it++){
				if((*it).first == out){
					(*it).second++;
					break;
				}
			}
			if(it == save.end()){save.push_back(make_pair(out , 1));}
			out.clear();
		}
		sort(save.begin() , save.end() , cmp);
		for(it = save.begin() ; it != save.end() ; it++){
			if((*it).second != 1){
				duplication = true;
				for(i = 0 ; i < 7 ; i++){
					if(i == 2){printf("%c-" , (*it).first[i]);}
					else{printf("%c" , (*it).first[i]);}
				}
				printf(" %d\n" , (*it).second);
			}
		}
		if(!duplication){puts("No duplicates.");}
		save.clear();
	}
}

bool cmp(pair<string , int> a , pair<string , int> b){
	return a.first < b.first;
}
