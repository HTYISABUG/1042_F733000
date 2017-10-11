#include <iostream>
#include <algorithm>
#include <new>
using namespace std;
int main(){
	int Case , i;
	int* a;
	while(cin >> Case){
		a = new int[Case];
		for(i = 0 ; i < Case ; i++){cin >> a[i];}
		sort(a , a+Case);
		cout << a[(Case-1)/2] << endl;
	}
	return 0;
}
