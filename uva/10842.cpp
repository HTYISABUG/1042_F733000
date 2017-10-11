#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <new>
#include <utility>
#include <vector>

using namespace std;

struct line{

	int s;
	int t;
	double l;

};
bool connect[20000];
vector<line> save;

void link();
bool cmp(line , line);

int main(){

	int i , j , k;
	int c , n , m;
	double x , y , l;
	vector<int> lp;
	vector<int> len;
	line *cons;

	while(cin >> c){

		for(i = 0 ; i < c ; ++i){

			fill(connect , connect + 20000 , false);
			save.clear();
			lp.clear();
			len.clear();

			cin >> n >> m;

			for(j = 0 ; j < m ; ++j){

				cin >> x >> y >> l;
				cons = new line;
				cons->s = x;
				cons->t = y;
				cons->l = l;
				save.push_back(*cons);

			}

			sort(save.begin() , save.end() , cmp);

			connect[0] = true;
			lp.push_back(0);

			while((int)lp.size() != n){

				for(j = (int)save.size() ; j >= 0  ; --j){

					for(k = 0 ; k < (int)lp.size() ; ++k){

						if(save[j].s == lp[k] && !connect[save[j].t]){

							connect[save[j].t] = true;
							lp.push_back(save[j].t);
							len.push_back(save[j].l);
							j = (int)save.size();
							break;

						}
						if(save[j].t == lp[k] && !connect[save[j].s]){

							connect[save[j].s] = true;
							lp.push_back(save[j].s);
							len.push_back(save[j].l);
							j = (int)save.size();
							break;

						}

					}

				}

			}

			sort(len.begin() , len.end());

			printf("Case #%d: %d\n" , i + 1 , len[0]);

		}

	}

	return 0;

}

bool cmp(line a , line b){

	return a.l < b.l;

}
