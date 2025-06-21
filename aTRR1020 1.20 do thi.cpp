//https://code.ptit.edu.vn/beta/problems/TRR1020

#include <bits/stdc++.h>
using namespace std;
int t, n ,m  = 1;
int degp[100], degn[100];
int a[100][100];
ifstream fin ("DT.INP");
ofstream fout("DT.OUT");
void solve1(){
	for(int i=1; i<=n; i++)
		fout << degn[i] <<" "<<degp[i] <<endl;
}
void solve2(){
	fout << n <<" "<< m-1 <<endl;
	for(int i=1; i<=n; i++){
		for(int j=1; j<m; j++)
			fout << a[i][j] <<" ";
		fout <<endl;
	}
}
int main(){
	fin >> t >> n;
	for(int i=1; i<=n; i++){
		int tmp, cnt;
		fin >> cnt;
		degp[i] = cnt;
		for(int j=1; j<=cnt; j++){
			fin >> tmp;
			degn[tmp] ++;

			a[i][m] = 1;
			a[tmp][m] = -1;
			m++;
		}
	}
	if(t==1)
		solve1();
	else
		solve2();
	return 0;
}