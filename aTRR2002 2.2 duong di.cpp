// https://code.ptit.edu.vn/student/question/TRR2002
#include <bits/stdc++.h>
using namespace std;
ifstream fin ("TK.INP");
ofstream fout ("TK.OUT");
int t, n , u ,v;
int visit[200], a[200][200], parent[200];

void BFS(){
	queue <int> q;
	q.push(u);
	visit[u] = 0;
	while(!q.empty()){
		int s = q.front();
		q.pop();
		for(int i=1; i<=n; i++){
			if(a[s][i] == 1 && visit[i] == 1){
				q.push(i);
				visit[i] = 0;
				parent[i] = s;
			}
		}
	}
}
void solve1(){
	int ans[200][200];
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++)
				ans[i][j] += a[i][k] * a[k][j];
		}
	}
	fout << ans[u][v];
}
void solve2(){
	BFS();
	if(parent[v] == 0)
		fout << 0;
	else{
		vector<int> vt;
		int s = v;
		while(s != u){
			vt.push_back(s);
			s = parent[s];
		}
		vt.push_back(s);
		for(int i=vt.size() - 1; i >=0; i--)
			fout << vt[i] <<" ";
	}
}
int main(){
	fill(visit, visit + 200, 1);
	fin >>  t >> n >> u >> v;
	for( int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
				fin >> a[i][j];
	if(t==1)
		solve1();
	else	
		solve2();
	return 0;
}