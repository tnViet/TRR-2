// https://code.ptit.edu.vn/student/question/TRR2015

#include <bits/stdc++.h>
using namespace std;
ifstream fin("TK.INP");
ofstream fout("TK.OUT");
int n, a[200][200];
int visit[200];
int BFS(int u){
	queue < int > q;
	vector<int> vt;
	q.push(u);
	visit[u] = 0;
	vt.push_back(u);
	while(!q.empty()){
		int s = q.front();
		q.pop();
		for(int i=1; i<=n; i++)
			if(a[s][i] == 1 && visit[i] == 1){
				q.push(i);
				visit[i] = 0;
				vt.push_back(i);
			}
	}
	return vt.size();
}
bool strong_connecting(){
	for(int i=1; i<=n; i++){
		fill(visit, visit + 200, 1);
		if(BFS(i) != n)
			return  0;
	}
	return 1;
}
bool weak_connecting(){
	for(int i=1; i<=n; i++){
		fill(visit, visit + 200, 1);
		if(BFS(i) == n)
			return 1;
	}
	return 0;
}
int main(){
	fin >> n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
				fin >> a[i][j];
	
	if(strong_connecting() == 1)
		fout << 1 ;
	else
		if(weak_connecting() == 1)
			fout << 2;
		else
			fout << 0;

	return 0;
}