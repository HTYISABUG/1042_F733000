#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	string s1 , s2;
	int lcs[1005][1005] , i , j;

	while(getline(cin , s1)){
		getline(cin , s2);

		fill(lcs[0] , lcs[0] + 1005 * 1005 , 0);
		for(i = 0 ; i < s1.size() ; i++){
			for(j = 0 ; j < s2.size() ; j++){
				if(s1[i] == s2[j]){lcs[i+1][j+1] = lcs[i][j] + 1;}
				else{lcs[i+1][j+1] = max(lcs[i][j+1] , lcs[i+1][j]);}
			}
		}

		cout << lcs[i][j] << endl;
	}
}
