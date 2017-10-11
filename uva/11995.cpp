#include <cstdio>
#include <queue>
#include <stack>
using namespace std;

int main(){
	int i;
	int Case , a , b;
	bool sc , qc , pc;
	stack<int> s;
	queue<int> q;
	priority_queue<int> p;

	while(scanf("%d\n" , &Case) != EOF){
		sc = true ; qc = true ; pc = true;
		for(i = 0 ; i < Case ; i++){
			scanf("%d %d" , &a , &b);
			switch(a){
				case 1 :
					q.push(b);
					s.push(b);
					p.push(b);
					break;
				case 2 :
					if(s.empty()){sc = false ; qc = false ; pc = false ; break;}
					if(q.empty()){sc = false ; qc = false ; pc = false ; break;}
					if(p.empty()){sc = false ; qc = false ; pc = false ; break;}
					if(b != s.top() && sc){sc = false;}
					if(b != q.front() && qc){qc = false;}
					if(b != p.top() && pc){pc = false;}
					s.pop();
					q.pop();
					p.pop();
					break;
				default :
					puts("Error !");
					printf("%d %d %d" , (int)sc , (int)qc , (int)pc);
					return 0;
			}
		}
		if(sc && (!qc && !pc)){puts("stack");}
		if(qc && (!sc && !pc)){puts("queue");}
		if(pc && (!sc && !qc)){puts("priority queue");}
		if(!sc && (qc && pc)){puts("not sure");}
		if(!qc && (sc && pc)){puts("not sure");}
		if(!pc && (sc && qc)){puts("not sure");}
		if(sc && (qc && pc)){puts("not sure");}
		if(!sc && (!qc && !pc)){puts("impossible");}

		while(!s.empty()){s.pop();}
		while(!q.empty()){q.pop();}
		while(!p.empty()){p.pop();}
	}

	return 0;
}
