#include <iostream>
#include <cstdio>
#include <new>

using namespace std;

int main(){
	int N , i;
	int* num;
	int count , buffer;

	while(cin >> N){
		//zero
		count = 0;
		//set the array
		num = new int[N];
		for(i = 0 ; i < N ; i++){
			cin >> num[i];
		}
		//sort & count
		for(i = 0 ; i < N - 1 ; i++){
			if(num[i] > num[i+1]){
				buffer = num[i];
				num[i] = num[i+1];
				num[i+1] = buffer;
				i = -1;
				count++;
			}
		}
		cout << "Minimum exchange operations : " << count << '\n';
		//clean array
		delete[] num;
	}

	return 0;
}
