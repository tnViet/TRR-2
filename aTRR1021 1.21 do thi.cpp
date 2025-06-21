// https://code.ptit.edu.vn/beta/problems/TRR1021
#include <bits/stdc++.h>
using namespace std;
ifstream fin("DT.INP");
ofstream fout("DT.OUT");
int n, t, m;
int a[100][100];
void solve1(){
	for(int i=1; i<=n; i++){
		int	degp = 0, degn = 0;
		for(int j=1; j<=n; j++){
			if(a[i][j] > 0 && a[i][j] <= 50)
				degp ++;
			if(a[j][i] > 0 && a[j][i] <= 50)
				degn ++;
		}
		fout << degn <<" "<< degp <<endl;
		
	}
}
void solve2(){
	fout << n << " "<<m <<endl;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
			if(a[i][j] > 0 && a[i][j] <=50)
				fout << i <<" "<< j <<" "<<a[i][j]<<endl;
	}
}
int main(){
	fin >> t >> n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
			fin >> a[i][j];
			if(a[i][j] > 0 && a[i][j] <=50)
				m++;
		}
	if(t==1)
		solve1();
	else
		solve2();
	return 0;
}