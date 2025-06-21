// https://code.ptit.edu.vn/student/question/TRR1013

#include <bits/stdc++.h>
using namespace std;

ifstream fin("DT.INP");
ofstream fout("DT.OUT");
int n, t, edgecnt[200] ,a[200][200];

void solve1(){
	int x = 1;	
	while(x <= n){
		int degn = 0, degp = 0;
		for(int i=1; i<=n; i++){
			if(a[x][i] != 0) degp++;
			if(a[i][x] != 0) degn++;
		}
		fout << degn <<" "<< degp <<endl;
		x++;
	}
}
void solve2(){
	fout << n << endl;
	for(int i=1; i<=n; i++){
		fout << edgecnt[i] <<" ";
		for(int j=1; j<=n; j++)
			if(a[i][j])
				fout << j <<" ";
		fout <<endl;
	}

}

int main(){
	fin >> t >> n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
				fin >> a[i][j];
				edgecnt[i] += a[i][j];
		}		
	if(t==1)
		solve1();
	else
		solve2();

	fin.close();
	fout.close();
	return 0;
}