// https://code.ptit.edu.vn/student/question/TRR1007

// de bai testcase t==1 co van de
#include <bits/stdc++.h>
using namespace std;
int t, n ,m;
ifstream fin("DT.INP");
ofstream fout("DT.OUT");
int a[100][100];
void solve1(){
	for(int i=1; i<=n; i++){
		int  cnt = 0 ;
		for(int j=1; j<=n; j++)
			cnt += a[i][j];
		fout << cnt <<" ";
	}
}
void solve2(){
	fout << n <<endl;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			fout << a[i][j] <<" ";
		}
		fout <<endl;
	}

}

int main(){
	fin >> t;
	fin >> n;
	int tmp;
	for(int i=1; i<=n; i++){
		int l; fin >> l;
		for(int j=1; j<=l; j++){
			fin >> tmp;
			a[i][tmp] = 1;
		}
	}
	if(t== 1)
		solve1();
	else 
		solve2();
	return 0;
}