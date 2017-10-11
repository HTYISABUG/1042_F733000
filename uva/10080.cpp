#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<double , double> > g , h;
vector<int> line[200];
bool used[200];
int link[200];
int inver[200];

bool DFS(int cur);
int bipartite(int n);

int main(){

	int i , j;
	int n , m , s , v;
	double x , y;

	while(cin >> n){

		g.clear();
		h.clear();
		for(int i = 0 ; i < 200 ; ++i) line[i].clear();
		fill(used , used + 200 , false);
		fill(link , link + 200 , -1);
		fill(inver , inver + 200 , -1);

		cin >> m >> s >> v;

		for(i = 0 ; i < n ; ++i){

			cin >> x >> y;
			g.push_back(make_pair(x , y));

		}

		for(i = 0 ; i < m ; ++i){

			cin >> x >> y;
			h.push_back(make_pair(x , y));

		}

		for(i = 0 ; i < n ; ++i){
			for(j = 0 ; j < m ; ++j){

				if(sqrt(pow(g[i].first - h[j].first , 2) + pow(g[i].second - h[j].second , 2)) <= s * v)
					line[i].push_back(j);

			}
		}

		cout << n - bipartite(n) << endl;

	}

	return 0;

}

bool DFS(int cur){

	for(int i = 0 ; i < (int)line[cur].size() ; ++i){

		int hole = line[cur][i];

		if(!used[hole]){

			used[hole] = true;

			if(inver[hole] < 0 || DFS(inver[hole])){

				link[cur] = hole;
				inver[hole] = cur;
				return true;

			}

		}

	}

	return false;
}

int bipartite(int n){

	int ret = 0;

	fill(link , link + 200 , -1);
	fill(inver , inver + 200 , -1);

	for(int i = 0 ; i < n ; ++i){

		fill(used , used + 200 , false);
		if(DFS(i)) ++ret;

	}

	return ret;

}
