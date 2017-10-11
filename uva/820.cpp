#include <algorithm>
#include <iostream>

using namespace std;

#define limit 200
//amount point

#define inf 999999999
//a very large number

int C;
bool visit[limit]; //check point has been visited or not
int cap[limit][limit]; //the maximum flow from a->b
int flow[limit][limit]; //the current flow from a->b
int past[limit]; //the past point of each point

void init(){

	fill(visit , visit + limit , false);
	fill(cap[0] , cap[0] + limit * limit , 0);
	fill(flow[0] , flow[0] + limit * limit , 0);
	fill(past , past + limit , -1);

}

int FindFlow(int s , int t , int n){

	int f = inf;

	for(int i = t ; i != s ; i = past[i]){

		int pre = past[i];

		f = min(f , cap[pre][i] - flow[pre][i]);

	}

	for(int i = t ; i != s ; i = past[i]){

		int pre = past[i];

		flow[pre][i] += f;
		flow[i][pre] -= f;

	}

	return f;

}

bool DFS(int cur , int t , int n){

	visit[cur] = true;

	if(cur == t) return true;

	for(int i = 1 ; i <= n ; ++i){ //from first point to the target

		if(visit[i]) continue;

		if(cap[cur][i] - flow[cur][i] > 0){

			past[i] = cur;
			if(DFS(i , t , n)) return true;

		}

	}

	return false;

}

int FordFulkerson(int s , int t , int n){

	int ret = 0;

	while(1){

		fill(visit , visit + limit , false);
		if(!DFS(s , t , n)) break;
		ret += FindFlow(s , t , n);

	}

	return ret;

}

int main(){

	int n , s , t , c , a , b , CAP;

	while(cin >> n){

		if(!n) break;

		init();

		cin >> s >> t >> c;

		for(int i = 0 ; i < c ; ++i){

			cin >> a >> b >> CAP;
			cap[a][b] += CAP;
			cap[b][a] += CAP;

		}

		cout << "Network " << ++C << endl;
		cout << "The bandwidth is " << FordFulkerson(s , t , n) << '.';
		cout << endl << endl;

	}

	return 0;

}
