// https://code.ptit.edu.vn/student/question/TRR2001

#include <bits/stdc++.h>
using namespace std;\
ifstream fin ("TK.INP");
ofstream fout ("TK.OUT");
int t, n , v ,u ;
int parent[200], visit[200], a[200][200];

void solve1(){
	int ans[200][200] = {};
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++){
				ans[i][j] += a[i][k] * a[k][j];
			}
		}
	}
	fout << ans[u][v];
}
void DFS(){
	stack <int> st;
	st.push(u);
	visit[u] = 0;
	while(!st.empty()){
		int s = st.top();
		st.pop();
		for(int i=1; i<=n; i++){
			if(a[s][i] == 1 && visit[i] == 1){
				visit[i] = 0;
				st.push(s);
				st.push(i);
				parent[i] = s;
				break;
			}
		}
	}
}
void solve2(){
	DFS();
	vector<int> vt;
	int s = v;
	while(s!=u){
		vt.push_back(s);
		s = parent[s];
	}
	vt.push_back(s);
	for(int i=vt.size() - 1; i>=0; i--)
		fout << vt[i] << " "; 
}

int main(){
	fill(visit, visit + 200, 1);
	fin  >> t >> n >> u >> v;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			fin >> a[i][j];
	if(t==1)
		solve1();
	else
		solve2();
	return 0;
}