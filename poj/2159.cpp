#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	string encrypt;
	string correct;
	int fre_1[26];
	int fre_2[26];
	int i;

	while(cin >> encrypt){
		cin >> correct;

		for(i = 0 ; i < 26 ; i++){
			fre_1[i] = 0;
			fre_2[i] = 0;
		}

		for(i = 0 ; i < encrypt.length() ; i++){
			fre_1[encrypt[i] - 'A']++;
		}
		for(i = 0 ; i < correct.length() ; i++){
			fre_2[correct[i] - 'A']++;
		}

		sort(fre_1 , fre_1 + 26);
		sort(fre_2 , fre_2 + 26);

		for(i = 0 ; i < 26 ; i++){
			if(fre_1[i] != fre_2[i]){
				cout << "NO\n";
				break;
			}
		}
		if(i == 26){
			cout << "YES\n";
		}
		encrypt.clear();
		correct.clear();
	}

	return 0;
}
