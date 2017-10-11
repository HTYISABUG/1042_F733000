#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n1 , n2 , i , j , in , count = 0;
	vector<int>  t1 , t2;
	int lcs[101][101];

	while(cin >> n1 >> n2){
		if(n1 == 0 && n2 == 0){return 0;}

		t1.clear();
		t2.clear();
		fill(lcs[0] , lcs[0] + 10201 , 0);
		t1.push_back(0);
		t2.push_back(0);
		count++;

		for(i = 0 ; i < n1 ; i++){
			cin >> in;
			t1.push_back(in);
		}
		for(i = 0 ; i < n2 ; i++){
			cin >> in;
			t2.push_back(in);
		}

		for(i = 1 ; i <= n1 ; i++){
			for(j = 1 ; j <= n2 ; j++){
				if(t1.at(i) == t2.at(j)){lcs[i][j] = lcs[i-1][j-1] + 1;}
				else{lcs[i][j] = max(lcs[i-1][j] , lcs[i][j-1]);}
			}
		}

		cout << "Twin Towers #" << count << endl;
		cout << "Number of Tiles : " << lcs[n1][n2] << endl << endl;
	}
}
