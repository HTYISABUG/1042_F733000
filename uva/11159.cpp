#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int a[200] , b[200] , ll[200] , rl[200];
bool used[200];
vector<int> link[200];
int n , m;

bool dfs(int);
int bip();

int main(){

	int t;

	while(cin >> t){

		for(int i = 0 ; i < t ; ++i){

			fill(a , a + 200 , 0);
			fill(b , b + 200 , 0);
			fill(ll , ll + 200 , -1);
			fill(rl , rl + 200 , -1);
			fill(used , used + 200 , false);
			for(int i = 0 ; i < 200 ; ++i) link[i].clear();

			cin >> n;

			for(int j = 0 ; j < n ; ++j) cin >> a[j];

			cin >> m;

			for(int j = 0 ; j < m ; ++j) cin >> b[j];

			for(int j = 0 ; j < n ; ++j){

				for(int k = 0 ; k < m ; ++k){

					if(!a[j]){

						if(!b[k]) link[j].push_back(k);
						else continue;

					}
					else if(b[k] % a[j] == 0) link[j].push_back(k);

				}

			}

			cout << "Case " << i + 1 << ": " << bip() << endl;

		}

	}

	return 0;

}

bool dfs(int cur){

	for(int i : link[cur]){

		if(!used[i]){

			used[i] = true;

			if(rl[i] == -1 || dfs(rl[i])){

				rl[i] = cur;
				ll[cur] = i;
				return true;

			}

		}

	}

	return false;

}

int bip(){

	int ret = 0;

	for(int i = 0 ; i < n ; ++i){

		fill(used , used + 200 , false);

		if(dfs(i)) ++ret;

	}

	return ret;

}
