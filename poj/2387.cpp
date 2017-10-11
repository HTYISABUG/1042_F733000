#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

#define inf 999999999
#define num 1100

int main(){

	int i;
	int t , n , b , e , len;
	int mark[num];
	int road[num][num];
	vector<pair<int , int> > save;
	vector<pair<int , int> >::iterator it , begin , end;

	while(scanf("%d %d" , &t , &n) != EOF){

		save.clear();
		fill(road[0] , road[0] + num * num , inf);

		for(i = 0 ; i < t ; ++i){

			scanf("%d %d" , &b , &e);
			scanf("%d" , &len);
			road[e][b] = road[b][e] = min(road[b][e] , len);
			save.push_back(make_pair(b , e));

		}

		fill(mark , mark + num , inf);
		mark[n] = 0;

		begin = save.begin();
		end = save.end();
		for(i = 0 ; i < n - 1 ; ++i){

			for(it = begin ; it != end ; ++it){

				mark[(*it).first] = min(mark[(*it).first] , mark[(*it).second] + road[(*it).first][(*it).second]);
				mark[(*it).second] = min(mark[(*it).second] , mark[(*it).first] + road[(*it).first][(*it).second]);

			}

		}

		printf("%d\n" , mark[1]);

	}

	return 0;

}
