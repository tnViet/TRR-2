// https://code.ptit.edu.vn/student/question/TRR1018
// 1.18 do thi

#include <bits/stdc++.h>
using namespace std;
ifstream fin("DT.INP");
ofstream fout("DT.OUT");
int t, n;
int a[100][100];

void solve1(){
	for(int i=1; i<=n; i++){
		int degp = 0, degn = 0;
		for(int j=1; j<=n; j++){
			degp += a[i][j];
			degn += a[j][i];
		}	
		fout << degn <<" "<< degp <<endl;
	}
}
void solve2(){
	fout << n <<endl;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
			fout << a[i][j] <<" ";
		fout <<endl;
	}
}	
int main(){
	fin >> t >> n;
	for(int i=1; i<=n; i++){
		int x; fin >> x;
		int tmp;
		for(int j=1; j<=x; j++){
			fin >> tmp;
			a[i][tmp] = 1;
		}
	}
	if(t==1)
		solve1();
	else
		solve2();
	return 0;
}