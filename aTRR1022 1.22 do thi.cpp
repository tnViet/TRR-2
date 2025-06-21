// https://code.ptit.edu.vn/beta/problems/TRR1022

#include <bits/stdc++.h>
using namespace std;
ifstream fin("DT.INP");
ofstream fout("DT.OUT");
int t, n, m, w;
int a[100][100];
int degp[100], degn[100];
void solve1(){
	for(int i=1; i<=n; i++)
		fout << degn[i] <<" "<<degp[i] <<endl;
}
void solve2(){
	fout<< n <<endl;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
			fout << a[i][j] <<" ";
		fout <<endl;
	} 
}
int main(){
	fin >> t >> n >> m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
			a[i][j] = 10000;
		a[i][i] = 0;
	}
	int tmp1, tmp2, tmp3;
	for(int i=1; i<=m; i++){
		fin >> tmp1 >> tmp2 >> tmp3 ;
		a[tmp1][tmp2] = tmp3;

		degp[tmp1] ++;
		degn[tmp2] ++;
	}
	if(t==1)
		solve1();
	else
		solve2();
	return 0;
}