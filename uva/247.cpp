#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int c;
int g;
int dfn[100];
int low[100];
int in_sk[100];
int group[100];
vector<int> link[100];
stack<int> sk;

int n , m;
string a , b;
map<string , int> si;
map<int , string> is;

void init();
void dfs(int , int);

int main(){

	int set = 0;
	bool space = false;

	while(cin >> n >> m){

		if(!n && !m) return 0;

		if(space) cout << endl;

		space = true;

		++set;
		int sc = 0;

		init();

		for(int i = 0 ; i < m ; ++i){

			a.clear();
			b.clear();

			cin >> a >> b;

			if(si.find(a) == si.end()){

				si.insert(pair<string , int>(a , sc));
				is.insert(pair<int , string>(sc++ , a));

			}
			if(si.find(b) == si.end()){

				si.insert(pair<string , int>(b , sc));
				is.insert(pair<int , string>(sc++ , b));

			}

			link[si[a]].push_back(si[b]);

		}

		cout << "Calling circles for data set " << set << ':' << endl;

		for(int i = 0 ; i < n ; ++i) if(!dfn[i]) dfs(-1 , i);

	}

}

void init(){

	c = 0;
	g = 0;
	fill(dfn , dfn + n , 0);
	fill(low , low + n , 0);
	fill(in_sk , in_sk + n , 0);
	fill(group , group + n , 0);
	for(int i = 0 ; i < n ; ++i) link[i].clear();
	while(!sk.empty()) sk.pop();
	si.clear();
	is.clear();

}

void dfs(int pre , int cur){

	low[cur] = dfn[cur] = ++c;
	sk.push(cur);
	in_sk[cur] = true;

	for(int &i : link[cur]){

		if(!dfn[i]){

			dfs(cur , i);
			low[cur] = min(low[cur] , low[i]);

		}
		else if(in_sk[i])
			low[cur] = min(low[cur] , dfn[i]);

	}

	if(dfn[cur] == low[cur]){

		while(sk.top() != cur){

			int top = sk.top();
			group[top] = g;
			in_sk[top] = false;
			cout << is[top] << ", ";
			sk.pop();

		}

		group[cur] = g++;
		in_sk[cur] = false;
		cout << is[cur] << endl;
		sk.pop();

	}

}
