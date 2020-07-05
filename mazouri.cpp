
#include <iostream>
#include <ctime>

using namespace std;

int list[16] = {1,2,2,1,2,-1,1,-2,-1,-2,-2,-1,-2,1,-1,2};
int draw(int* a,int x,int y,int d) {
	if (d==65) {return 1;}
	// if (d==64) {cout << 1 << '\n';}

	for (int i = 0; i < 8; ++i) {
		
		int nx = x+list[2*i], ny = y+list[2*i+1];
		int pos = nx*8+ny;
		if (nx<8 && ny<8 && nx>=0 && ny>=0){
			if(a[pos]==0){
				a[pos] = d;
				int ix = draw(a,nx,ny,d+1);
				if (ix==1){return 1;}
				a[pos] = 0;
			}
		}
	}

	return -1;
}


int	main() {

	clock_t start,end;
	start = clock();
	int a[64];
	memset(a,0,sizeof(a));
	int beginx = 7,beginy = 7;
	cin >> beginx >> beginy;
	a[beginx*8+beginy] = 1;
	cout << a << '\n';
	draw(a,beginx,beginy,2);

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
