#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

#define pi 3.14159

using namespace std;

int main(){

	int n , ans;
	double t , x , y , area , v , r , a , b , c , d;
	vector<pair<double , double> > save;

	while(cin >> n){

		if(!n) return 0;

		v = 0;

		for(int i = 0 ; i < n ; ++i){

			save.clear();

			cin >> t;

			while(cin >> x >> y){

				if((int)save.size() && (x == save[0].first && y == save[0].second))
					break;

				save.push_back(make_pair(x , y));

			}

			area = 0;

			for(int j = 1 ; j < (int)save.size() - 1 ; ++j){

				a = save[j].first - save[0].first;
				b = save[j].second - save[0].second;
				c = save[j+1].first - save[0].first;
				d = save[j+1].second - save[0].second;
				area += (a * d - b * c) / 2;

			}

			v += fabs(t * area);

		}

		cin >> r >> t;

		ans = (int)(v / (pi * r * r * t));

		cout << ans << endl;

	}

}
