#include <algorithm>
#include <iostream>
#include <new>
#include <queue>
#include <vector>

using namespace std;

#define inf 999999999
#define num 60000

struct path{int d , w;};
vector<path> save[num];

int main(){

	int N , n , m , S , T , c = 0 , a , b , w;
	int point[num];
	bool inqueue[num];
	queue<int> q;

	while(cin >> N){

		for(int i = 0 ; i < N ; ++i){

			++c;

			cin >> n >> m >> S >> T;

			for(int j = 0 ; j < num ; ++j)
				if(!save[j].empty()) save[j].clear();
			fill(point , point + n , inf);
			fill(inqueue , inqueue + n , false);

			for(int j = 0 ; j < m ; ++j){

				cin >> a >> b >> w;
				save[a].push_back({b , w});
				save[b].push_back({a , w});

			}

			point[S] = 0;
			inqueue[S] = true;
			q.push(S);

			while(!q.empty()){

				int cur = q.front();
				inqueue[cur] = false;
				q.pop();

				for(path &j : save[cur]){

					if(point[cur] + j.w < point[j.d]){

						point[j.d] = point[cur] + j.w;

						if(!inqueue[j.d]){

							q.push(j.d);
							inqueue[j.d] = true;

						}

					}

				}

			}

			cout << "Case #" << c << ": ";
			if(point[T] != inf) cout << point[T] << endl;
			else cout << "unreachable" << endl;

		}

	}

	return 0;

}
