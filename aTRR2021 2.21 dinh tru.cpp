// https://code.ptit.edu.vn/student/question/TRR2021
#include <bits/stdc++.h>
using namespace std;
ifstream fin ("TK.INP");
ofstream fout("TK.OUT");
int a[200][200], visited[200];
int first_count = 0, cnt = 0;
vector<int> ans;
int n; 


void DFS(int u){
	visited[u] = 1;
	stack<int> st;
	st.push(u);
	while(!st.empty()){
		int s = st.top();
		st.pop();
		for(int i=1; i<=n; i++)
			if(a[s][i]==1 and visited[i]==0){
				st.push(s);
				st.push(i);
				visited[i] = 1;
				break;
			}
	}

} 
void solve(){
	for(int i=1; i<=n; i++){
		fill(visited, visited + 200, 0);
		cnt = 0;
		visited[i] = 1;
		for(int j=1; j<=n; j++)
			if(visited[j] == 0){
				DFS(j);
				cnt ++;
			}
		if(cnt != first_count)
			ans.push_back(i);
	}

	fout << ans.size() <<endl;
	for(unsigned int i=0; i<ans.size(); i++)
		fout << ans[i] <<" ";
}
int main(){
	fin >> n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			fin >> a[i][j];
	
	for(int i=1; i<=n; i++)
		if(visited[i] == 0){
			DFS(i);
			first_count ++;
		}
	
	solve();
	
	return 0;
}