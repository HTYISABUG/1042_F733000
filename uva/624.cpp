#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> ans;

bool bt(vector<int> , int , int);

int main(){
	int n , t , in;
	int i , j;
	int dp[10000];
	vector<int> num;
	
	while(cin >> n >> t){
		fill(dp , dp + 10000 , 0);
		for(i = 0 ; i < t ; i++){
			cin >> in;
			num.push_back(in);
		}

		for(i = 0 ; i < num.size() ; i++){
			for(j = n ; j - num[i] >= 0 ; j--){
				if(dp[j] < dp[j-num[i]] + num[i]){dp[j] = dp[j-num[i]] + num[i];}
			}
		}

//		sort(num.begin() , num.end());
		bt(num , dp[n] , 0);

		for(i = ans.size() - 1 ; i >= 0 ; i--){cout << ans[i] << ' ';}

		cout << "sum:" << dp[n] << endl;
		num.clear();
		ans.clear();
	}

	return 0;
}

bool bt(vector<int> num , int max , int start){
	for(int i = start ; i < num.size() ; i++){
		if(max - num[i] > 0){
			if(bt(num , max - num[i] , i + 1)){
				ans.push_back(num[i]);
				return true;
			}
		}
		else if(max - num[i] == 0){
			ans.push_back(num[i]);
			return true;
		}
		else{continue;}
	}
	return false;
}
