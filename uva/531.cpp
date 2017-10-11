#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main(){
	int checker = 0 , dp[101][101] , i , j;
	string in;
	vector<string> s1 , s2;
	stack<string> ans;

	while(cin >> in){
		s1.clear();
		s2.clear();
		s1.push_back("");
		s2.push_back("");
		fill(dp[0] , dp[0] + 10201 , 0);
		while(!ans.empty()){ans.pop();}

		if(in != "#"){
			s1.push_back(in);
			while(cin >> in){
				if(in == "#"){break;}
				s1.push_back(in);
			}
		}
		while(cin >> in){
			if(in == "#"){break;}
			s2.push_back(in);
		}

		for(i = 1 ; i < s1.size() ; i++){
			for(j = 1 ; j < s2.size() ; j++){
				if(s1[i] == s2[j]){dp[i][j] = dp[i-1][j-1] + 1;}
				else{dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);}
			}
		}

		i = s1.size() - 1;
		j = s2.size() - 1;
		while(i != 0 && j != 0){
			if(s1[i] == s2[j]){
				ans.push(s1[i]);
				i--;
				j--;
			}
			else{dp[i-1][j] >= dp[i][j-1] ? i-- : j--;}
		}

		while(!ans.empty()){
			cout << ans.top();
			ans.size() != 1 ? cout << ' ' : cout << endl;
			ans.pop();
		}
	}

	return 0;
}
