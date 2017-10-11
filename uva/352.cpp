#include <iostream>
#include <string>

using namespace std;

bool image[27][27];
bool mirroring [27][27];
short near[8] = {-28,-27,-26,-1,1,26,27,28};

inline void DFS(bool* place);

int main() {
	short dimension;
	short row , column , count;
	short C , D;//constant
	string buffer;
	short image_number = 0;

	while (cin >> dimension) {
		image_number++;
		//zero
		for(C = 0 ; C < 27 * 27 ; C++) {
			*(&image[0][0] + C) = false;
			*(&mirroring[0][0] + C) = false;
		}
		count = 0;
		buffer.clear();
		//construst the image
		for(row = 1 ; row <= dimension ; row++) {
			cin >> buffer;
			for(column = 1 ; column <= dimension ; column++) {
				if(buffer[column-1] == '1') {
					image[row][column] = true;
				}
			}
			buffer.clear();
		}
		//scan the image
		for(row = 1 ; row <= dimension ; row++) {
			for(column = 1 ; column <= dimension ; column++) {
				if(image[row][column] == true && mirroring[row][column] == false) {
					DFS(&image[row][column]);
					count++;
				}
			}
		}

		cout << "Image number " << image_number << " contains " << count << " war eagles.\n";
	}

	return 0;
}

inline void DFS(bool* place) {
	short C;//constant
	*(mirroring[0] + (place - image[0])) = true;
	for(C = 0 ; C < 8 ; C++) {
		if(*(place + near[C]) == true && *(mirroring[0] + (place - image[0]) + near[C]) == false) {
			DFS(place + near[C]);
		}
	}
	return;
}
