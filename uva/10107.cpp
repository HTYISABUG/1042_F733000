#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	short count = 0;
	long input[10000] = {0};

	while(cin >> input[count++]){
		sort(input , input + count);
		if(count % 2 == 1){
			cout << input[count/2] << '\n';
		}
		else{
			cout << (input[count/2-1] + input[count/2]) / 2 << '\n';
		}
	}

	return 0;
}
