#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int m[10][2] = {{0,0},{-1,-1},{0,-1},{1,-1},{-1,0},{0,0},{1,0},{-1,1},{0,1},{1,1}};

int main(){

	int c;
	string s;
	pair<int , int> point , pre;
	long long ans;

	while(cin >> c){

		for(int i = 0 ; i < c ; ++i){

			ans = 0;
			point = pair<int , int>(0 , 0);
			s.clear();

			cin >> s;

			pre = pair<int , int>(m[s[0]-'0'][0] , m[s[0]-'0'][1]);
			point = pair<int , int>(m[s[0]-'0'][0] , m[s[0]-'0'][1]);

			for(int j = 1 ; j < (int)s.length() ; ++j){

				point.first += m[s[j]-'0'][0];
				point.second += m[s[j]-'0'][1];

				ans += pre.first * point.second - pre.second * point.first;

				pre = point;

			}

			ans = ans > 0 ? ans : -ans;

			cout << ans / 2;

			if(ans % 2) cout << ".5\n";
			else cout << '\n';

		}

	}

	return 0;

}
