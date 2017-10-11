#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Vec2{
	public:
		Vec2(double x , double y){vec = make_pair(x , y);}

		double x(){return vec.first;}

		double y(){return vec.second;}

		double length(){return sqrt(pow(vec.first , 2) + pow(vec.second , 2));}

		double cross(Vec2 v){
			return vec.first * v.y() - vec.second * v.x();
		}

	private:
		pair<double , double> vec;
};

class Point2{
	public:
		Point2(){pos = make_pair(0 , 0);}

		Point2(double x , double y){pos = make_pair(x , y);}

		double x(){return pos.first;}

		double y(){return pos.second;}

		void operator=(Point2 p){pos = make_pair(p.x() , p.y());}

		Point2 operator+(Point2 p){
			return Point2(pos.first + p.x() , pos.second + p.y());
		}

		Vec2 operator-(Point2 p){
			return Vec2(pos.first - p.x() , pos.second - p.y());
		}

		template<class T> Point2 operator*(T t){
			return Point2(pos.first * t , pos.second * t);
		}

		template<class T> Point2 operator/(T t){
			return Point2(pos.first / t , pos.second / t);
		}

		void operator+=(Point2 p){*this = operator+(p);}

		template<class T> void operator/=(T t){*this = operator/(t);}

	private:
		pair<double , double> pos;
};

vector<Point2> save;

bool cmp_origin(Point2 a , Point2 b){
	return (a.y() < b.y()) || (a.y() == b.y() && a.x() < b.x());
}

bool cmp_angle(Point2 a , Point2 b){
	double cro = (a-save[0]).cross(b-save[0]);

	return cro > 0 || (!cro && (a-save[0]).length() < (b-save[0]).length());
}

int main(){
	long n , x , y , p;
	Point2 ans[200];

	while(cin >> n){
		if(n < 3) break;
		save.clear();

		for(int i = 0 ; i < n ; ++i){
			cin >> x >> y;
			save.push_back(Point2(x , y));
		}

/*----------calculation----------*/

		swap(save[0] , *min_element(save.begin() , save.end() , cmp_origin));
		sort(save.begin() + 1 , save.end() , cmp_angle);
		save.push_back(save[0]);

		p = 0;
		for(int i = 0 ; i < (int)save.size() ; ++i){
			while(p >= 2 && (ans[p-1]-ans[p-2]).cross(save[i]-ans[p-2]) <= 0)
				--p;
			ans[p++] = save[i];
		}

/*----------calculation----------*/

		--p;

		double A = 0;
		vector<Point2> triC;

		for(int i = 2 ; i < p ; ++i){
			double area = (ans[i-1] - ans[0]).cross(ans[i] - ans[0]);
			triC.push_back(Point2((ans[0].x() + ans[i-1].x() + ans[i].x()) / 3 , (ans[0].y() + ans[i-1].y() + ans[i].y()) / 3) * area);
			A += area;
		}

		Point2 center;
		for(Point2 &i : triC)
			center += i;
		center /= A;

		printf("%.3lf %.3lf\n" , center.x() , center.y());
	}

	return 0;
}
