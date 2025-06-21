//https://code.ptit.edu.vn/student/question/TRR1008

#include <bits/stdc++.h>
using namespace std;
ifstream fin("DT.INP");
ofstream fout("DT.OUT");

int t, n, edgecnt;
int a[100][100];
void solve1(){
	
	for(int i=1; i<=n; i++){
		int cnt = 0;
		for(int j=1; j<=n; j++)
			cnt += a[i][j];
		fout << cnt <<" ";
	}

}
void solve2(){
	fout << n <<" " <<edgecnt /2<<endl;
	for(int i=1 ; i<=n; i++){
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
	fin >> t >> n;
	for(int i=1; i<=n; i++){
		int tmp, x;
		fin >> tmp;
		edgecnt += tmp;
		for(int j=1; j<=tmp; j++){
			fin >> x;
			a[i][x] = 1;
		}
	}
	if(t==1)	
		solve1();
	else 
		solve2();
	return 0;
}