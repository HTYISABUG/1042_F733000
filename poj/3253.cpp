#include <iostream>
#include <queue>
using namespace std;

int main(){
	long long Case , i , in , buf , ans;
	priority_queue<long long> save;

	while(cin >> Case){
		for(i = 0 ; i < Case ; i++){
			cin >> in;
			save.push(-in);
		}
		ans = 0;
		while(save.size() > 1){
			buf = save.top();
			save.pop();
			buf += save.top();
			save.pop();
			ans += buf;
			save.push(buf);
		}
		cout << -ans << endl;
		save.pop();
	}
}
