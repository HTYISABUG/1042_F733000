#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

#define amount 300
//the quantity of point

#define inf 1e8
//a very large number


int n , p;
bool visited[amount]; //check the point has been visited or not
int cap[amount][amount];//the capacity of a->b
int flow[amount][amount];//the current flow of a->b
int past[amount];//the past point of this point
struct path{int s , t , len;}length[50000];

void init(){
	fill(visited , visited + amount , false);
	fill(cap[0] , cap[0] + amount * amount , 0);
	fill(flow[0] , flow[0] + amount * amount , 0);
	fill(past , past + amount , -1);
}

int FindFlow(int s , int t){
	int f = inf;

	for(int i = t ; i != s ; i = past[i]){
		int pre = past[i];

		if(cap[pre][i] - flow[pre][i] > 0)
			f = min(f, cap[pre][i] - flow[pre][i]);	
		else f = min(f , flow[i][pre]);
	}

	for(int i = t ; i != s ; i = past[i]){
		int pre = past[i];

		if(cap[pre][i] - flow[pre][i] > 0) flow[pre][i] += f;
		else flow[i][pre] -= f;
	}

	return f;
}

bool DFS(int cur , int t){
	visited[cur] = true;
	if(cur == t) return true;

	for(int i = 1 ; i <= t ; ++i){
		if(visited[i]) continue;

		if(cap[cur][i] - flow[cur][i] > 0 || flow[i][cur] > 0){
			past[i] = cur;
			if(DFS(i , t)) return true;
		}
	}

	return false;
}

int MaximumFlow(int s , int t , int maxlen){
	int ret = 0;

	init();

	for(int i = 0 ; i < p ; ++i){
		if(length[i].len <= maxlen){
			cap[length[i].s][length[i].t] += 1;
			cap[length[i].t][length[i].s] += 1;
		}
	}

	while(1){
		fill(visited , visited + amount , false);
		if(!DFS(s , t)) break;
		ret += FindFlow(s , t);
	}

	return ret;
}

int main(){
	int t , maxlen , l , r , m;

	while(scanf("%d %d %d" , &n , &p , &t) != EOF){

		init();
		maxlen = 0;

		for(int i = 0 ; i < p ; ++i){
			scanf("%d %d" , &length[i].s , &length[i].t);
			scanf("%d" , &length[i].len);
			maxlen = max(maxlen , length[i].len);
		}

		l = 0 , r = maxlen;

		while(l != r){
			m = (l + r) / 2;

			if(MaximumFlow(1 , n , m) >= t) r = m;
			else l = m + 1;
		}

		cout << l << endl;
	}

	return 0;
}
