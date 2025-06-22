// 
#include <bits/stdc++.h>
using namespace std;
ifstream fin ("CT.INP");
ofstream fout("CT.OUT");
int t, n, m, u;
int a[200][200], visited[200];
vector<int> ans;
//// bai nay loi fin fout, phai dung cin, cout
void DFS(int u){
	visited[u] = 1;
	for(int i=1; i<=n; i++)
		if(a[u][i] ==1 and visited[i] == 0)
			DFS(i);
}
int solve1(){
	DFS(1);
	for(int i=1; i<=n; i++)
		if(visited[i] == 0)
			return 0;
	int deg[200] = {};
	int cnt_odd = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			deg[i] += a[i][j];
		}
	}
	for(int i=1; i<=n; i++){
		if(deg[i] % 2 == 1)
			cnt_odd ++;
	}
	if(cnt_odd == 0)
		return 1;
	if(cnt_odd == 2)
		return 2;
	return 0;
}
void solve2(){
	stack<int> st;
	st.push(u);
	while(!st.empty()){
		int s= st.top();
		bool exist = 0;
		for(int i=1; i<=n; i++){
			if(a[s][i] == 1){
				exist = 1;
				a[s][i] = a[i][s] = 0;
				st.push(i);
				break;
			}
		}
		if(exist == 0){
			st.pop();
			ans.push_back(s);
		}
	}
	for(int i=ans.size()-1; i>=0; i--)
		fout << ans[i] <<" ";
}
int main(){
	fin >> t;
	fin >> n >> m;
	if(t==2)
		fin >> u;
	int tmp1, tmp2;
	for(int i=1; i<=m; i++){
		fin >> tmp1 >> tmp2;
		a[tmp1][tmp2] = 1;
		a[tmp2][tmp1] = 1;
	}
	if(t==1)
		fout << solve1() <<endl;
	else
		solve2();
	return 0;
}