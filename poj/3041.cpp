#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int ll[1000] , rl[1000];
bool visit[1000];
vector<int> link[1000];
int n , k;

void init();
int bip();
bool dfs(int);

int main(){

	int x , y;

	while(scanf("%d %d" , &n , &k) != EOF){

		init();

		for(int i = 0 ; i < k ; ++i){

			scanf("%d %d" , &x , &y);

			link[x].push_back(y);

		}

		printf("%d\n" , bip());

	}

}

void init(){

	fill(ll , ll + 1000 , 0);
	fill(rl , rl + 1000 , 0);
	fill(visit , visit + 1000 , false);
	for(int i = 0 ; i < 1000 ; ++i) link[i].clear();

}

int bip(){

	int ret = 0;

	fill(ll , ll + 1000 , 0);
	fill(rl , rl + 1000 , 0);

	for(int i = 1 ; i <= n ; ++i){

		fill(visit , visit + 1000 , false);

		if(dfs(i)) ++ret;

	}

	return ret;

}

bool dfs(int cur){

	for(int i = 0 ; i < (int)link[cur].size() ; ++i){

		if(!visit[link[cur][i]]){

			visit[link[cur][i]] = true;

			if(!rl[link[cur][i]] || dfs(rl[link[cur][i]])){

				rl[link[cur][i]] = cur;
				ll[cur] = link[cur][i];
				return true;

			}

		}

	}

	return false;

}
