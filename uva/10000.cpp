#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define inf 999999999
#define num 1100

int main(){

	int i;
	int n , s , p , q , longest , count = 0 , point;
	int city[num];
	vector<pair<int , int> > save;
	vector<pair<int , int> >::iterator it , begin , end;

	while(1){

		++count;

		cin >> n >> s;

		if(n == 0) break;

		save.clear();

		while(1){

			cin >> p >> q;

			if(p == 0 && q == 0) break;

			save.push_back(make_pair(p , q));

		}

		fill(city , city + num , inf);

		city[s] = 0;
		longest = 0;
		begin = save.begin();
		end = save.end();
		for(i = 0 ; i < n - 1 ; ++i){

			for(it = begin ; it != end ; ++it){

				city[it->second] = min(city[it->second] , city[it->first] - 1);
			}

		}

		for(i = n ; i >= 1 ; --i){

			longest = min(longest , city[i]);
			if(longest == city[i]) point = i;

		}

		cout << "Case " << count << ": The longest path from " << s << " has length " << -longest;
		cout << ", finishing at " << point << '.' << endl << endl;

	}

}
