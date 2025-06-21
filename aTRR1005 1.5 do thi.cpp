// https://code.ptit.edu.vn/student/question/TRR1005
#include <bits/stdc++.h>
using namespace std;
ifstream fin ("DT.INP");
ofstream fout ("DT.OUT");

int n, t, m;
int a[100][100], edgelist[100][2];
map <int,int> mp;
vector <vector<int>> v;
void solve1(){
	for(auto x : mp)
		fout << x.second <<" ";
}
void solve2(){
	fout << n <<endl;
	for(int i=1; i<=n; i++){

		fout << mp[i] <<" ";
		for(int j=0; j<v[i].size(); j++){
			fout << v[i][j]<<" ";
		}
		fout <<endl;
	}
}
int main(){
	fin >> t >> n >> m;
	v.resize(n+1);
		
	for(int i=1; i<=m; i++){
		fin >> edgelist[i][0] >> edgelist[i][1];
		mp[edgelist[i][0]] ++;
		mp[edgelist[i][1]] ++;
	
		v[edgelist[i][0]].push_back(edgelist[i][1]);
		v[edgelist[i][1]].push_back(edgelist[i][0]);
	}

	if(t==1)
		solve1();
	else
		solve2();
	return 0;
}