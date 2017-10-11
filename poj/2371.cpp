#include <iostream>
#include <algorithm>
#include <new>
using namespace std;

int main(){
	int i;
	int Case , a , b;
	int* save;
	string trash;

	while(cin >> Case){
		save = new int[Case];
		for(i = 0 ; i < Case ; i++){cin >> save[i];}
		sort(save , save + Case);
		cin >> trash;
		cin >> a;
		for(i = 0 ; i < a ; i++){
			cin >> b;
			cout << save[b-1] << endl;
		}
	}

	return 0;
}
