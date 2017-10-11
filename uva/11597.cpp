#include <iostream>

using namespace std;

int main(){

	int n;
	int count = 0;

	while(1){

		++count;

		cin >> n;

		if(!n) break;

		cout << "Case " << count << ": " << n / 2 << endl;

	}

	return 0;

}
