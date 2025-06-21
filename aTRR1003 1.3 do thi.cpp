// https://code.ptit.edu.vn/student/question/TRR1003
#include <bits/stdc++.h>
using namespace std;
ifstream fin("DT.INP");
ofstream fout("DT.OUT");
int t, n;
int a[200][200], association[300][300];
int edgecnt ;

void solve1(){
	for(int i=1; i<=n; i++){
		int cnt = 0;
		for(int j=1; j<=n; j++){
			cnt +=a[i][j];
		}
		fout << cnt <<" ";
	}
}
void solve2(){
	fout << n <<" "<<edgecnt /2 <<endl;
	int edge = 1;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(a[i][j] == 1){
				association[i][edge] = 1;
				association[j][edge] = 1;
				edge ++;

				a[i][j] = 0;
				a[j][i] = 0;
			}
		}
	}

	for(int i=1; i<=n; i++){
		for(int j=1; j<=edgecnt /2; j++ ){
			fout << association[i][j] <<" ";
		}
		fout <<endl;
	}

}
int main(){
	fin >> t >> n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
			fin >> a[i][j];
			if(a[i][j] != 0)	edgecnt ++;
		}
	if(t==1)
		solve1();
	else
		solve2();
	return 0;
}