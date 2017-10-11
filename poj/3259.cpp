#include <algorithm>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

#define inf 999999999
#define num 1100

int main(){

	int i , j;
	int f , n , m , w , s , e , t;
	int point[num];
	int time[num][num];
	vector<pair<int , int> > save;
	vector<pair<int , int> >::iterator it , begin , end;

	while(scanf("%d" , &f) != EOF){

		for(i = 0 ; i < f ; ++i){

			save.clear();
			fill(time[0] , time[0] + num * num , inf);

			scanf("%d %d %d" , &n , &m , &w);

			for(j = 0 ; j < m ; ++j){

				scanf("%d %d %d" , &s , &e , &t);
				time[e][s] = time[s][e] = min(time[s][e] , t);
				save.push_back(make_pair(s , e));
			
			}

			for(j = 0 ; j < w ; ++j){

				scanf("%d %d %d" , &s , &e , &t);
				time[s][e] = min(time[s][e] , -t);
				save.push_back(make_pair(s , e));

			}

			fill(point , point + num , inf);
			point[n] = 0;

			begin = save.begin();
			end = save.end();
			for(j = 0 ; j < n - 1 ; ++j){

				for(it = begin ; it != end ; ++it){

					point[(*it).first] = min(point[(*it).first] , point[(*it).second] + time[(*it).first][(*it).second]);
					point[(*it).second] = min(point[(*it).second] , point[(*it).first] + time[(*it).second][(*it).first]);

				}

			}

			for(it = begin ; it != end ; ++it){

				if(point[(*it).first] > point[(*it).second] + time[(*it).first][(*it).second]){

					j = inf;
					break;

				}
				else if(point[(*it).second] > point[(*it).first] + time[(*it).second][(*it).first]){

					j = inf;
					break;

				}
				else continue;

			}

			j == inf ? puts("YES") : puts("NO");

		}

	}

	return 0;

}
