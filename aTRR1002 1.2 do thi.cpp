//https://code.ptit.edu.vn/student/question/TRR1002
// 1.2 do thi

#include <bits/stdc++.h>
#include <fstream>
using namespace std;
ifstream fin("DT.INP");
ofstream fout("DT.OUT");
int n;
int a[200][200] ;
vector<vector<int>> v_parent;

void solve1(){
	for(int i=1; i<=n; i++){
		int cnt = 0;
		for(int j=1; j<=n; j++)
			if(a[i][j] != 0)
				cnt ++;
		fout << cnt <<" ";
	}
	fout <<endl;
}
void solve2(){
	fout << n <<endl;
//	int vertex = 1;
	
	for(int i=1; i<=n; i++){
		vector<int > v;
		int cnt_edge = 0;
		v.push_back(0);
		for(int j=1; j<=n; j++){
			if(a[i][j] != 0){
				cnt_edge ++;
				if(j <= n)
					v.push_back(j);
			}
		}
		v[0] = cnt_edge;
		v_parent.push_back(v);
	}
	for(int i=0; i<v_parent.size(); i++){
		for(int j=0; j<v_parent[i].size(); j++)
			fout <<  v_parent[i][j] <<" ";
		fout <<endl;
	}
}
int main(){
	
	int t; fin >> t;
	fin >> n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			fin >> a[i][j];
		
	if( t == 1)
		solve1();
	else
		solve2();
		
	return 0;
}