#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define num 200

using namespace std;

int c;
int dfn[num];
int low[num];
int visit[num];
vector<int> link[num];

int n , r;
string a , b;
map<string , int> si;
map<int , string> is;
vector<int> ver;
vector<string> ans;

void init();
void dfs(int , int);

int main(){

	int counter = 0;

	while(cin >> n){

		if(!n) return 0;

		++counter;

		if(counter > 1) cout << endl;

		init();

		for(int i = 0 ; i < n ; ++i){

			a.clear();

			cin >> a;

			si.insert(pair<string , int>(a , i));
			is.insert(pair<int , string>(i , a));

		}

		cin >> r;

		for(int i = 0 ; i < r ; ++i){

			a.clear();
			b.clear();

			cin >> a >> b;

			link[si[a]].push_back(si[b]);
			link[si[b]].push_back(si[a]);

		}

		for(int i = 0 ; i < n ; ++i) if(!dfn[i])dfs(-1 , i);

		for(int &i : ver) ans.push_back(is[i]);

		sort(ans.begin() , ans.end());

		cout << "City map #" << counter;
		cout << ": " << (int)ver.size() << " camera(s) found";
		cout << endl;
		for(string &i : ans) cout << i << endl;

	}

}

void init(){

	c = 0;
	fill(dfn , dfn + n , 0);
	fill(low , low + n , 0);
	fill(visit , visit + n , 0);
	for(int i = 0 ; i < n ; ++i) link[i].clear();
	si.clear();
	is.clear();
	ver.clear();
	ans.clear();

}

void dfs(int pre , int cur){

	int child = 0;
	bool vertex = false;

	low[cur] = dfn[cur] = ++c;
	visit[cur] = true;

	for(int &i : link[cur]){

		if(!visit[i]){

			dfs(cur , i);
			low[cur] = min(low[cur] , low[i]);
			++child;
			if(low[i] >= dfn[cur]) vertex = true;

		}
		else if(i != pre) low[cur] = min(low[cur] , dfn[i]);

	}

	if(vertex && (child > 1 || pre != -1)) ver.push_back(cur);

}
