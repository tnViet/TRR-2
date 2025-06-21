// https://code.ptit.edu.vn/beta/problems/TRR1017

#include <bits/stdc++.h>
using namespace std;
int t, n , m, edge = 1;
int a[100][100];
int degp[100], degn[100];
ifstream fin ("DT.INP");
ofstream fout("DT.OUT");
void solve1(){
	for(int i=1; i<=n; i++)
		fout << degn[i] <<" "<<degp[i] <<endl;
}
void solve2(){
	fout << n <<" "<< m <<endl;
	for(int i=1; i<=n; i++){
		for(int j=1; j< edge; j++)
			fout << a[i][j] <<" ";
		fout <<endl;
	}
}
int main(){
	fin >> t >> n >> m;
	for(int i=1; i<=m; i++){
		int tmp1, tmp2;
		fin >> tmp1 >> tmp2;
		
		degp[tmp1] ++;
		degn[tmp2] ++;

		a[tmp1][edge] = 1;
		a[tmp2][edge] = -1;
		edge ++;
	}
	if(t==1)
		solve1();
	else
		solve2();
	return 0;
}