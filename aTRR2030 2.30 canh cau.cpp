// https://code.ptit.edu.vn/student/question/TRR2030

#include <bits/stdc++.h>
using namespace std;
ifstream fin("TK.INP");
ofstream fout("TK.OUT");
int n, first_cnt = 0, cnt = 0;
int a[200][200], visited[200];
vector<pair<int,int>> ans;
void BFS(int u){
	visited[u] = 1;
	queue<int> q;
	q.push(u);
	while(!q.empty()){
		int s = q.front();
		q.pop();
		for(int i=1; i<=n; i++)
			if(a[s][i] == 1 and visited[i] == 0){
				q.push(i);
				visited[i] = 1;
			}
	}
}
void solve(){
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			if(a[i][j] == 1){
				fill(visited, visited + 200, 0);
				a[i][j] = a[j][i] = 0;
				cnt = 0;

				for(int k=1; k<=n; k++){
					if(visited[k] == 0){
						BFS(k);
						cnt++;
					}
				}
				if(cnt > first_cnt)
					ans.push_back({i,j});

				a[i][j] = a[j][i] = 1;
			}
		}
	}
	fout << ans.size() <<endl;
	for(int i=0; i<ans.size(); i++)
		fout << ans[i].first << " " << ans[i].second <<endl;

}
int main(){
	fin >> n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			fin >> a[i][j];
	for(int i=1; i<=n; i++)
		if(visited[i] == 0){
			BFS(i);
			first_cnt++;
		}
	solve();
	return 0;
}