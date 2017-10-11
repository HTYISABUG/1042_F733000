#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int dfn[200];
int low[200];
vector<int> link[200];
int counter;
stack<int> sk;
bool in_sk[200];
int ans;

void dfs(int , int);

int main(){

	int i;
	int n , b , t;
	string str;
	stringstream ss;

	while(cin >> n){

		if(!n) return 0;

		fill(dfn , dfn + 200 , 0);
		fill(low , low + 200 , 0);
		for(i = 0 ; i < 200 ; ++i) link[i].clear();
		counter = 0;
		while(!sk.empty()) sk.pop();
		fill(in_sk , in_sk + 200 , false);
		str.clear();
		ss.clear();
		ans = 0;

		while(getline(cin , str)){

			if(str == "") continue;

			ss.clear();
			ss.str(str);
			ss >> b;

			if(!b) break;

			while(ss >> t){

				link[b].push_back(t);
				link[t].push_back(b);

			}

		}

		dfs(0 , 1);

		cout << ans << endl;

	}

}

void dfs(int pre , int cur){

	int child = 0;
	bool isvertex = false;

	low[cur] = dfn[cur] = ++counter;
	sk.push(cur);
	in_sk[cur] = true;

	for(int &i : link[cur]){

		if(!in_sk[i]){

			dfs(cur , i);
			low[cur] = min(low[cur] , low[i]);
			++child;
			if(low[i] >= dfn[cur]) isvertex = true;

		}
		else{

			if(i && i != pre)
				low[cur] = min(low[cur] , dfn[i]);

		}

	}

	if(isvertex && (child > 1 || pre)) ++ans;

}
