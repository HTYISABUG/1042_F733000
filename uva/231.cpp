#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int in , count = 0;
	vector<int> num , ans;

	while(cin >> in){
		if(in >= 0){num.push_back(-in);}
		else{
			count++;
			ans.push_back(num.at(0));
			for(int i = 1 ; i < (int)num.size()  ; i++){
				if(num.at(i) < ans.back()){*lower_bound(ans.begin() , ans.end() , num.at(i)) = num.at(i);}
				else{ans.push_back(num.at(i));}
			}
			cout << "Test #" << count << ':' << endl;
			cout << "  " << "maximum possible interceptions: " << ans.size() << endl;
			cin >> in;
			if(in >= 0){
				cout << endl;
				num.push_back(-in);
			}
			else{return 0;}
			num.clear();
			ans.clear();
		}
	}
}
