// https://code.ptit.edu.vn/student/question/TRR1010


#include <bits/stdc++.h>
using namespace std;
ifstream fin("DT.INP");
ofstream fout("DT.OUT");
int t, n, a[200][200];
int edgecnt;
void solve1(){
	for(int i=1; i<=n; i++){
		int cnt = 0;
		for(int j=1; j<=n; j++)
			if(a[i][j] <= 50 && a[i][j] > 0)
				cnt ++;
		fout << cnt <<" ";
	}
}
void solve2(){
	fout << n <<" "<<edgecnt / 2 <<endl;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(a[i][j] <= 50 && a[i][j] > 0){
				fout << i <<" "<< j <<" "<< a[i][j] <<endl;
				a[i][j] = 0;
				a[j][i] = 0;
			}
		}
	}
}
int main(){
	fin >> t >> n;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			fin >> a[i][j];
			if(a[i][j] <= 50 && a[i][j] > 0)
				edgecnt++;
		}
	}	
	if(t==1)
		solve1();
	else
		solve2();
	fin.close();
	fout.close();
	return  0;

}