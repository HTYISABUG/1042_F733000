#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int main(){

	int c;
	int xs1 , ys1 , xe1 , ye1;
	int xs2 , ys2 , xe2 , ye2;
	double delta , deltax , deltay;

	while(cin >> c){

		cout << "INTERSECTING LINES OUTPUT\n";

		for(int i = 0 ; i < c ; ++i){

			cin >> xs1 >> ys1 >> xe1 >> ye1;
			cin >> xs2 >> ys2 >> xe2 >> ye2;

			//(ys - ye) * x + (xe - xs) * y = ((ys - ye) * xs + (xe - xs) * ys)

			delta = (ys1 - ye1) * (xe2 - xs2) - (ys2 - ye2) * (xe1 - xs1);
			deltax = ((ys1 - ye1) * xs1 + (xe1 - xs1) * ys1) * (xe2 - xs2) - ((ys2 - ye2) * xs2 + (xe2 - xs2) * ys2) * (xe1 - xs1);
			deltay = (ys1 - ye1) * ((ys2 - ye2) * xs2 + (xe2 - xs2) * ys2) - (ys2 - ye2) * ((ys1 - ye1) * xs1 + (xe1 - xs1) * ys1);

			if(delta == 0){

				if(deltax == 0 && deltay == 0) cout << "LINE\n";
				else cout << "NONE\n";

			}
			else printf("POINT %.2lf %.2lf\n" , deltax / delta , deltay / delta);

		}

		cout << "END OF OUTPUT\n";

	}

	return 0;

}
