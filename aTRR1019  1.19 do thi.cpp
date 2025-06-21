//https://code.ptit.edu.vn/beta/problems/TRR1019

#include <bits/stdc++.h>
using namespace std;
int t, n ,m;
int degp[100], degn[100];
vector <pair<int,int>> v;
ifstream fin ("DT.INP");
ofstream fout("DT.OUT");
void solve1(){
	for(int i=1; i<=n; i++)
		fout << degn[i] <<" "<<degp[i] <<endl;
}
void solve2(){
	fout << n <<" "<< m <<endl;
	for(int i=0; i<v.size(); i++)
		fout << v[i].first <<" " << v[i].second <<endl;	
}
int main(){
	fin >> t >> n;
	for(int i=1; i<=n; i++){
		int tmp, cnt;
		fin >> cnt;
		degp[i] = cnt;
		m += cnt;
		for(int j=1; j<=cnt; j++){
			fin >> tmp;

			pair<int,int> x = make_pair(i, tmp);
			v.push_back(x);

			degn[tmp] ++;
		}
	}
	if(t==1)
		solve1();
	else
		solve2();
	return 0;
}