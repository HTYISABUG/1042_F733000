#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

int g;
int no;
int dfn[20000];
int low[20000];
int in_sk[20000];
int group[20000];
vector<int> link[20000];
vector<pair<int , int> > save;
stack<int> sk;
int n , m , x , y;

void init();
void dfs(int , int);
bool cmp(pair<int , int> , pair<int , int>);

int main(){

	vector<int> pigeon;

	while(scanf("%d %d" , &n , &m)){

		if(!n && !m) return 0;

		init();

		while(scanf("%d %d" , &x , &y)){

			if(x < 0 && y < 0) break;

			link[x].push_back(y);
			link[y].push_back(x);

		}

		dfs(-1 , 0);

		for(int i = 0 ; i < n ; ++i){

			pigeon.clear();

			for(int &j : link[i]){

				if(find(pigeon.begin() , pigeon.end() , group[j]) != pigeon.end())
					continue;
				else pigeon.push_back(group[j]);

			}

			save.push_back(make_pair(i , (int)pigeon.size()));

		}

		sort(save.begin() , save.end() , cmp);

		for(int i = 0 ; i < m ;++i)
			printf("%d %d\n" , save[i].first , save[i].second);

		puts("");

	}

}

void init(){

	g = 0;
	no = 0;
	fill(dfn , dfn + n , 0);
	fill(low , low + n , 0);
	fill(in_sk , in_sk + n , 0);
	fill(group , group + n , 0);
	for(int i = 0 ; i < n ; ++i) link[i].clear();
	save.clear();
	while(!sk.empty()) sk.pop();

}

void dfs(int pre , int cur){

	low[cur] = dfn[cur] = ++no;
	sk.push(cur);
	in_sk[cur] = true;

	for(int &i : link[cur]){

		if(!dfn[i]){

			dfs(cur , i);
			low[cur] = min(low[cur] , low[i]);

		}
		else if(in_sk[i] && i != pre)
			low[cur] = min(low[cur] , dfn[i]);

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

bool cmp(pair<int , int> a , pair<int , int> b){

	if(a.second < b.second) return false;
	else if (a.second > b.second) return true;
	else{

		if(a.first < b.first) return true;
		else return false;

	}

}
