// https://code.ptit.edu.vn/student/question/TRR1006
#include <bits/stdc++.h>
using namespace std;
ifstream fin("DT.INP");
ofstream fout("DT.OUT");
int t, n, m;
int a[100][100], edgelist[100][2];
map<int,int> mp;
void solve1(){
	for(auto x : mp)
		fout << x.second <<" ";
}
void solve2(){
	fout << n<<" "<< m <<endl;
	for(int i=1; i<=m; i++){
		a[edgelist[i][0]][i] = 1;
		a[edgelist[i][1]][i] = 1;
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			fout << a[i][j] <<" "; 
		}
		fout <<endl;
	}
}
int main(){
	fin >> t >> n >> m;
	for(int i=1; i<=m; i++){
		fin >> edgelist[i][0] >> edgelist[i][1];
		mp[edgelist[i][0]] ++;
		mp[edgelist[i][1]] ++;
	}
	if(t==1)
		solve1();
	else
		solve2();
	return 0;
}