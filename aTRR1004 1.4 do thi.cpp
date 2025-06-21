// https://code.ptit.edu.vn/student/question/TRR1004
// 1.4 do thi

#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[1000][2];
int b[1000][1000];
ifstream fin("DT.INP");
ofstream fout("DT.OUT");
void solve1(){
	for(int i=1; i<=n; i++){
		int cnt = 0;
		for(int j=1; j<=n; j++){
			if(b[i][j] == 1)
				cnt ++;			
		}
		fout << cnt <<" ";
	}
}
void solve2(){
	fout << n <<endl;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
			fout << b[i][j] << " ";
			
		fout <<endl;		
	}
}
int main(){
	int t; fin >> t;
	fin >> n >> m;
	for(int i=1; i<=m; i++){
		fin >> a[i][0] >> a[i][1];
		b[a[i][0]] [a[i][1]] = 1;
		b[a[i][1]] [a[i][0]] = 1;
	}
	
	if(t == 1)	solve1();
	else solve2();
	
	return 0;
}