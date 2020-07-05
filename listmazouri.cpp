#include <iostream>
#include <ctime>

using namespace std;



int list[16] = {1,2,2,1,2,-1,1,-2,-1,-2,-2,-1,-2,1,-1,2};


int draw(int* a,int x,int y) {

	int d = 2;
	
	int ind[64];

	int father[64];
	memset(ind,0,sizeof(ind));
	memset(father,-1,sizeof(father));

	// father[x*8+y] = -1;
	a[x*8+y] = 1;

	while (true) {
		if (d > 64) {
			return 0;
		}
		// cout << d << '\n';
		for (int i = ind[x*8+y] ; i < 9; ++i) {
			if (i==8) {
				int pos = x*8+y;
				
				ind[pos] = 0;

				x = x - list[2*father[pos]];
				y = y - list[2*father[pos]+1];

				father[pos] = -1;
				a[pos] = 0;
				d -= 2;

				break;
			}

			int nx = x + list[2*i], ny = y + list[2*i+1];			
			
			if (nx<8 && ny<8 && nx>=0 && ny>=0) {
				
				int newpos = nx*8+ny;
				if (a[newpos] != 0){continue;}

				int pos = x*8+y;
				
				ind[pos] = i+1;
				father[newpos] = i;
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
	
	int beginx = 7,beginy = 7;
	// cin >> beginx >> beginy;
	// a[beginx*8+beginy] = 1;

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
