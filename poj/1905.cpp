#include <cstdio>
#include <cmath>
using namespace std;

#define pi 3.14159265

int main(){
	double len , T , C , lenp , r , x;

	while(1){
		scanf("%lf %lf %lf" , &len , &T , &C);
		if(len < 0 && (T < 0 && C < 0)){return 0;}
		lenp = (1 + T * C) * len;
		if(lenp == len){puts("0.000");}
		else{
			x = r * (1 - cos(lenp / 2 / r));
			printf("%.3lf\n" , x);
		}
	}
}
