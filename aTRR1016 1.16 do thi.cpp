// https://code.ptit.edu.vn/beta/problems/TRR1016

#include <bits/stdc++.h>
using namespace std;
int t, n , m;
int a[100][100];
int edge[100];
ifstream fin ("DT.INP");
ofstream fout("DT.OUT");
void solve1(){
	int i = 1;
	while(i <=n ){
		int degp = 0, degn = 0;
		for(int j=1; j<=n; j++){
			degp += a[i][j];
			degn += a[j][i];
		}
		fout << degn <<" "<< degp <<endl;
		i++;
	}
}
void solve2(){
	fout << n <<endl;
	for(int i=1; i<=n; i++){
		fout << edge[i] <<" ";
		for(int j=1; j<=n; j++)
			if(a[i][j] == 1)
				fout << j <<" ";
		fout <<endl;
	}
}
int main(){
	fin >> t >> n >> m;
	for(int i=1; i<=m; i++){
		int tmp1, tmp2;
		fin >> tmp1 >> tmp2;
		a[tmp1][tmp2] = 1;
		edge[tmp1] ++;
	}
	if(t==1)
		solve1();
	else
		solve2();
	return 0;
}