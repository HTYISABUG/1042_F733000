#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int to[200];
int from[200];
bool used[200];
vector<int> link[2000];

bool dfs(int);
int bip(int);

int main(){

	int n , m , k , pro , x , y;

	while(cin >> n){

		if(!n) return 0;

		fill(from , from + 200 , 0);
		fill(to , to + 200 , 0);
		fill(used , used + 200 , 0);
		for(int i = 0 ; i < 2000 ; ++i) link[i].clear();

		cin >> m >> k;

		for(int i = 0 ; i < k ; ++i){

			cin >> pro >> x >> y;

			link[x].push_back(y);

		}

		cout << bip(n) << endl;

	}

}

bool dfs(int cur){

	for(int i = 0 ; i < (int)link[cur].size ; ++i){

		if(!link[cur][i]) continue;

		if(!used[link[cur][i]]){

			used[link[cur][i]] = true;

			if(!from[link[cur][i]] || dfs(from[link[cur][i]])){

				from[link[cur][i]] = cur;
				to[cur] = link[cur][i];

				return true;

			}

		}

	}

	return false;

}

int bip(int n){

	int ret = 0;

	fill(from , from + 200 , 0);
	fill(to , to + 200 , 0);

	for(int i = 1 ; i < n ; ++i){

		fill(used , used + 200 , false);

		if(dfs(i)) ++ret;

	}

	return ret;

}

