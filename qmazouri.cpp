#include <iostream>
#include <ctime>

using namespace std;



struct point
{
	point* father;
	int ind;
	int x;
	int y;
	// int de;

};


int list[16] = {1,2,2,1,2,-1,1,-2,-1,-2,-2,-1,-2,1,-1,2};


int draw(int* a,int x,int y) {

	int d = 2;
	point queue[64];
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			queue[i*8+j].x = i;
			queue[i*8+j].y = j;
			queue[i*8+j].ind = 0;
			queue[i*8+j].father = NULL;

		}
	}

	// queue[x*8+y].father = NULL;
	a[x*8+y] = 1;

	while (true) {
		if (d > 64) {
			return 0;
		}

		for (int i = queue[x*8+y].ind ; i < 9; ++i) {
			if (i==8) {
				int pos = x*8+y;
				
				queue[pos].ind = 0;
				x = queue[pos].father->x;
				y = queue[pos].father->y;
				queue[pos].father = NULL;
				a[pos] = 0;
				d -= 2;

				break;
			}
			
			int nx = x+list[2*i], ny = y+list[2*i+1];

			int pos = x*8+y;
			int newpos = nx*8+ny;
			
			if (nx<8 && ny<8 && nx>=0 && ny>=0) {
				
				// if (queue[newpos].father != NULL){continue;}
				if (a[newpos] != 0){continue;}

				queue[pos].ind = i+1;
				queue[newpos].father = &queue[pos];
				// queue[newpos].de = d;
				a[newpos] = d;
				x = nx;
				y = ny;
				break;

			}
		}
		d += 1;

	}

	return -1;
}


int	main() {

	clock_t start,end;
	start = clock();
	int a[64];
	memset(a,0,sizeof(a));
	
	int beginx = 7,beginy = 0;
	// cin >> beginx >> beginy;
	a[beginx*8+beginy] = 1;

	cout << a << '\n';

	draw(a,beginx,beginy);

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			cout << a[i*8+j] << ' ';
		}
		cout << '\n';
	}
	


	end = clock();
	// double endtime = end-start;
	double endtime=(double)(end-start)/CLOCKS_PER_SEC;
	cout << endtime << '\n' ;
	return 0;

}
