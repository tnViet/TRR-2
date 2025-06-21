// https://code.ptit.edu.vn/student/question/TRR2001

#include <bits/stdc++.h>
using namespace std;
ifstream fin("TK.INP");
ofstream fout("TK.OUT");

int t, n ,v ,u;
stack <int> st;
int parent[200];
bool visit[200];

struct matrix{
	int x[200][200] = {};
	friend matrix operator * (matrix A, matrix B){
		matrix ans;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				for(int k=1; k<=n; k++){
					ans.x[i][j] += A.x[i][k] * B.x[k][j]; 
				}
			}
		}
		return ans;
	}
};
matrix a;
void DFS(int u){
	fill(visit, visit + 200, 1);
	st.push(u);
	visit[u] = 0;
	while(!st.empty()){
		int s = st.top();
		st.pop();	
		for(int i=1; i<=n; i++){
			if(a.x[s][i] == 1 && visit[i] == 1){
				visit[i] = 0;
				st.push(s);
				st.push(i);
				parent[i] = s ;
				break;
			}
			
		}
	}
	return;
}
void solve1(){
	matrix answer = a * a;
	fout << answer.x[u][v];
}
void solve2(){
	DFS(u);
	vector<int> vt;
	string s;
	int k = v;
	if(k == 0)
		fout << 0 ;
	else{
		while(k != u){
			vt.push_back(k);
			k = parent[k];
		}
		vt.push_back(k);
		for(int i=vt.size()-1 ; i>=0; i--)
			fout << vt[i] <<" ";
	}
}
int main(){
	fin >> t >> n >> u >> v;
	for( int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			fin >> a.x[i][j];
	if(t==1)
		solve1();
	else
		solve2();
	return 0;
}

