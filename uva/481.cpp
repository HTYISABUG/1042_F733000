#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main(){
	ll in , lis , scr;
	vector<ll> num , pos , ans;
	vector<ll>::iterator it;

	while(cin >> in){num.push_back(in);}

	ans.push_back(num.at(0));
	pos.push_back(1);
	for(ll i = 1 ; i < (ll)num.size() ; i++){
		if(num.at(i) <= ans.back()){
			it = lower_bound(ans.begin() , ans.end() , num.at(i));
			*it = num.at(i);
			pos.push_back(it - ans.begin() + 1);
		}
		else{
			ans.push_back(num.at(i));
			pos.push_back(ans.size());
		}
	}
	lis = ans.size();
	ans.clear();

	scr = lis;
	for(ll i = pos.size() - 1 ; i >= 0 ; i--){
		if(pos.at(i) == scr){
			ans.push_back(num.at(i));
			scr--;
		}
	}

	cout << lis << endl;
	cout << '-' << endl;
	for(ll i = ans.size() - 1 ; i >= 0 ; i--){cout << ans.at(i) << endl;}

	return 0;
}
