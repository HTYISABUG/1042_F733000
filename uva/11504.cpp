#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int c;
int g;
int ans;
int dfn[200000];
int low[200000];
int group[200000];
bool in_sk[200000];
bool scc_link[200000];
vector<int> link[200000];
stack<int> sk;
int ca , n , m , x , y;

void dfs(int);
void init();

int main(){

	int i , j;

	scanf("%d" , &ca);

		for(i = 0 ; i < ca ; ++i){

			scanf("%d %d" , &n , &m);

			init();

			for(j = 0 ; j < m ; ++j){

				scanf("%d %d" , &x , &y);

				link[x].push_back(y);

			}

			for(j = 1 ; j <= n ; ++j) if(!dfn[j]) dfs(j);

			for(j = 1 ; j <= n ; ++j){

				for(int &k : link[j]){

					if(group[j] != group[k])
						scc_link[group[k]] = true;

				}

			}

			for(j = 1 ; j <= g ; ++j) if(!scc_link[j]) ++ans;

			printf("%d\n" , ans);

		}

}

void dfs(int cur){

	low[cur] = dfn[cur] = ++c;
	sk.push(cur);
	in_sk[cur] = true;

	for(int &i : link[cur]){

		if(!dfn[i]){

			dfs(i);
			low[cur] = min(low[cur] , low[i]);

		}
		else if(in_sk[i]) low[cur] = min(low[cur] , dfn[i]);

	}

	if(dfn[cur] == low[cur]){

		++g;

		while(sk.top() != cur){

			int top = sk.top();
			group[top] = g;
			in_sk[top] = false;
			sk.pop();

		}

		group[cur] = g;
		in_sk[cur] = false;
		sk.pop();

	}

}

void init(){

	c = 0;
	g = 0;
	ans = 0;
	fill(dfn + 1 , dfn + n + 1 , 0);
	fill(in_sk + 1 , in_sk + n + 1 , false);
	fill(scc_link + 1 , scc_link + n + 1 , false);
	for(int i = 1 ; i <= n ; ++i) link[i].clear();
	while(!sk.empty()) sk.pop();

}
