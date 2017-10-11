#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

#define amount 30
//the quantity of point

#define inf 1e8
//a very large number

int n;
bool visited[amount]; //check the point has been visited or not
int cap[amount][amount];//the capacity of a->b
int flow[amount][amount];//the current flow of a->b
int past[amount];//the past point of this point

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

	for(int i = 0 ; i <= t ; ++i){
		if(visited[i]) continue;

		if(cap[cur][i] - flow[cur][i] > 0 || flow[i][cur] > 0){
			past[i] = cur;
			if(DFS(i , t)) return true;
		}
	}

	return false;
}

int MaximumFlow(int s , int t){
	int ret = 0;

	while(1){
		fill(visited , visited + amount , false);
		if(!DFS(s , t)) break;
		ret += FindFlow(s , t);
	}

	return ret;
}

int translate(char c){
	switch(c){
		case 'S':
			return 1;
			break;
		case 'M':
			return 2;
			break;
		case 'L':
			return 3;
			break;
		case 'X':
			return 4;
			break;
		case 'T':
			return 5;
			break;
	}
}

int main(){
	string s;

	while(cin >> s){
		if(s == "ENDOFINPUT") break;
		init();

		cin >> n;

		for(int i = 1 ; i <= n ; ++i){
			cap[0][i] = 1;

			cin >> s;

			for(int j = translate(s[0]) ; j <= translate(s[1]) ; ++j) cap[i][j+n] = 1;
		}

		for(int i = 1 ; i <= 5 ; ++i) cin >> cap[i+n][n+6];

		cin >> s;

		if(MaximumFlow(0 , n+6) == n) cout << "T-shirts rock!\n";
		else cout << "I'd rather not wear a shirt anyway...\n";
	}

	return 0;
}
