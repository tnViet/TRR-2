// https://code.ptit.edu.vn/student/question/TRR1011

#include <bits/stdc++.h>
using namespace std;
int n, t, m , w, a[100][100];
ifstream fin("DT.INP");
ofstream fout("DT.OUT");
void solve1(){
	for(int i=1; i<=n; i++){
		int cnt = 0;
		for(int j=1; j<=n; j++)
			if(a[i][j] <=50 && a[i][j] > 0)
				cnt++;
		fout << cnt <<" ";
	}
}
void solve2(){
	fout << n <<endl;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
			fout << a[i][j] <<" ";
		fout << endl;
	}

}
int main(){
	fin >> t >> n >> m;
	int tmp1, tmp2;
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
			if(j != i)
				a[i][j] = 10000;
	}

	for(int i=1; i<=m; i++){
		fin >> tmp1 >> tmp2 >> w ;
		a[tmp1][tmp2] = w;
		a[tmp2][tmp1] = w;			
	}

	if(t==1)
		solve1();
	else
		solve2();

	fin.close();
	fout.close();
	return 0;
}