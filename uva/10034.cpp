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
bool connect[200];
vector<line> save;
vector<pair<double , double> > point;

void link();
bool cmp(line , line);

int main(){

	int i , j , k;
	int c , n;
	double x , y , len;
	vector<int> lp;

	while(cin >> c){

		for(i = 0 ; i < c ; ++i){

			if(i) puts("");

			fill(connect , connect + 200 , false);
			save.clear();
			point.clear();
			lp.clear();

			cin >> n;

			for(j = 0 ; j < n ; ++j){

				cin >> x >> y;
				point.push_back(make_pair(x , y));
				if(point.size() > 1) link();

			}

			sort(save.begin() , save.end() , cmp);

			connect[0] = true;
			len = 0;
			lp.push_back(0);

			while((int)lp.size() != n){

				for(j = 0 ; j < (int)save.size() ; ++j){

					for(k = 0 ; k < (int)lp.size() ; ++k){

						if(save[j].s == lp[k] && !connect[save[j].t]){

							connect[save[j].t] = true;
							len += save[j].l;
							lp.push_back(save[j].t);
							j = (int)save.size();
							break;

						}
						if(save[j].t == lp[k] && !connect[save[j].s]){

							connect[save[j].s] = true;
							len += save[j].l;
							lp.push_back(save[j].s);
							j = (int)save.size();
							break;

						}

					}

				}

			}

			printf("%.2lf\n" , len);

		}

	}

	return 0;

}

void link(){

	line *n;

	for(int i = 0 ; i < (int)point.size() - 1 ; ++i){

		n = new line;
		n->s = i;
		n->t = point.size() - 1;
		n->l = sqrt(pow(point[i].first - point.back().first , 2) + pow(point[i].second - point.back().second , 2));
		save.push_back(*n);

	}

}

bool cmp(line a , line b){

	return a.l < b.l;

}
