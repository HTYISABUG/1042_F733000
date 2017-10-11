#include <iostream>
#include <algorithm>
#include <map>
#include <new>
#include <vector>
using namespace std;

int main(){
	int n , i , in;
	int* dp;
	map<int , int> cor;
	vector<int> ans;

	cin >> n;
	for(i = 0 ; i < n ; i++){
		cin >> in;
		cor.insert(pair<int , int>(i , in));
	}

	dp = new int[n];
	while(cin >> in){
		fill(dp , dp + n , 0);
		ans.clear();
		dp[in-1] = cor[0];
		for(i = 1 ; i < n ; i++){
			cin >> in;
			dp[in-1] = cor[i];
		}
		ans.push_back(dp[0]);
		for(i = 1 ; i < n ; i++){
			if(dp[i] <= ans.back()){*lower_bound(ans.begin() , ans.end() , dp[i]) = dp[i];}
			else{ans.push_back(dp[i]);}
		}
		cout << ans.size() << endl;
	}

	return 0;
}
