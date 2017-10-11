#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	string s1 , s2;
	int lcs[200][200] , count = 0 , i , j;

	while(1){
		count++;
		getline(cin , s1);
		if(find(s1.begin() , s1.end() , '#') != s1.end()){break;}
		getline(cin , s2);

		fill(lcs[0] , lcs[0] + 40000 , 0);
		for(i = 0 ; i < (int)s1.size() ; i++){
			for(j = 0 ; j < (int)s2.size() ; j++){
				if(s1[i] == s2[j]){lcs[i+1][j+1] = lcs[i][j] + 1;}
				else{lcs[i+1][j+1] = max(lcs[i][j+1] , lcs[i+1][j]);}
			}
		}

		cout << "Case #" << count << ": you can visit at most " << lcs[i][j] << " cities." << endl;
	}

	return 0;
}
