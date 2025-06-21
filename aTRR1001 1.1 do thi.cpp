#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int n, edge;
int a[100][100];
ifstream fin("DT.INP");
ofstream fout("DT.OUT");
void solve1(){
	for(int i=1; i<=n; i++){
		int cnt = 0;
		for(int j=1; j<=n; j++){
			cnt += a[i][j];
		}
		fout << cnt <<" ";
	}

}
void solve2(){
	fout << n <<" "<< edge /2 <<endl;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(a[i][j] == 1){
				fout << i <<" "<< j <<endl;
				a[i][j] = 0;
				a[j][i] = 0;
			}
		}
	}
}

int main(){
	int t; fin >> t;
	fin >> n;
	for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++){
				fin >> a[i][j];
				if(a[i][j] == 1)
					edge ++;
			}
	if(t==1)
		solve1();
	else
		solve2();

	return 0;
}