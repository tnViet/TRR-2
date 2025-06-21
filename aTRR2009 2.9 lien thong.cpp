// https://code.ptit.edu.vn/student/question/TRR2009

#include <bits/stdc++.h>
using namespace std;
ifstream fin("TK.INP");
ofstream fout("TK.OUT");
int  visit[200], parent[200], a[200][200];
int n , cnt;
vector<vector<int>> ans;
void DFS(int u){
	vector<int> vt;
	stack <int> st;;	
	st.push(u);
	visit[u] = 0;
	vt.push_back(u);
	while(!st.empty()){
		int s = st.top();
		st.pop();
		for(int i=1; i<=n; i++)
			if(a[s][i] == 1 && visit[i] == 1){
				st.push(s);
				st.push(i);
				visit[i] = 0;
				vt.push_back(i);
				break;
			}
	}
	ans.push_back(vt);
}
void solve(){
	for(int i=1; i<=n; i++){
		if(visit[i] == 1){
			cnt++;
			DFS(i);
		}
	}
	fout << cnt <<endl;
	for(unsigned int i=0; i<ans.size(); i++){
		sort(ans[i].begin(),ans[i].end());				// sap xep lai
		for(unsigned int j=0; j<ans[i].size(); j++)
			fout << ans[i][j] <<" ";
		fout <<endl;
	}
}
int main(){
	fill(visit, visit + 200, 1);
	fin >> n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			fin >> a[i][j];
	solve();

	return 0;
}