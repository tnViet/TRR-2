// https://code.ptit.edu.vn/student/question/TRR1009

#include <bits/stdc++.h>
using namespace std;
ifstream fin("DT.INP");
ofstream fout("DT.OUT");
int t, n, edgecnt;
int a[200][200], b[200][200];

void solve1(){
	for(int i=1; i<=n; i++){
		int cnt = 0;
		for(int j=1; j<=n; j++)
			cnt += a[i][j];
		fout << cnt <<" ";
	}	
}		
void solve2(){
	int x = 1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(a[i][j] == 1){
				b[i][x] = 1;
				b[j][x] = 1;
				x++;

				a[i][j] = 0;
				a[j][i] = 0;
			}
		}
	}

	fout << n <<" "<<edgecnt/2 <<endl;
	for(int i=1; i<=n; i++){
		for(int j=1; j<= edgecnt/2; j++)
			fout << b[i][j] <<" ";
		fout <<endl;
	}

}
int main(){
	fin >> t >> n;
	for(int i=1; i<=n; i++){
		int tmp, x;
		fin >> tmp;
		edgecnt += tmp;
		while(tmp!=0){
			fin >> x;
			a[i][x] = 1;
			tmp --;
		}
	}
	if(t==1)
		solve1();
	else 
		solve2();
	
	return 0;
}