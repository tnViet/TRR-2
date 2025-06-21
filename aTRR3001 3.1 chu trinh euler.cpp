// https://code.ptit.edu.vn/student/question/TRR3001

#include <bits/stdc++.h>
using namespace std;
int t, n, u, k;
int a[200][200], visit[200];
ifstream fin("CT.INP");
ofstream fout("CT.OUT");

bool ltBFS(){
	fill(visit, visit + 200, 1);
	queue <int> q;
	q.push(1);
	visit[1] = 0;
	while(!q.empty()){
		int s = q.front();
		q.pop();
		for(int i=1; i<=n; i++){
			if( a[s][i] == 1){
				if(visit[i] == 1){
					visit[i] = 0;
					q.push(i);	
				}
			}
		}
	}
	for(int i=1; i<=n; i++)
		if(visit[i] == 1)	return 0;
	return 1;
	 
}
void solve1(){
	fin >> n;
	for(int i=1; i<= n; i++)
		for(int j=1; j<=n; j++)
			fin >> a[i][j];
			
	if(ltBFS() == 0){
		fout << 0;
		return;
	}
	int cntodd = 0;
	for(int i=1; i<= n; i++){
		int cnt = 0;
		for(int j=1; j<=n; j++){
			if(a[i][j] == 1)	
				cnt ++;
		}
		if(cnt % 2 == 1)
			cntodd ++;
	}
	if (cntodd == 0)
		fout << 1;
	else if(cntodd == 2)
		fout << 2;
	else 
		fout << 0;
}
void solve2(){
	fin >> n >> k;
	for(int i=1; i<= n; i++)
		for(int j=1; j<=n; j++)
			fin >> a[i][j];
			
	stack <int> st;
	vector <int> ce;
	st.push(k);

	while(!st.empty()){
		bool check = 1;
		int s = st.top();
	
		for(int i=1; i<=n+1; i++){
			if(i == n+1){
				check = 0;	
				break;
			}
			if(a[s][i] == 1){
				st.push(i);
				a[s][i] = 0;
				a[i][s] = 0;
				break;
			}
		}
		if(check == 0){
			st.pop();
			ce.push_back(s);
		}
		
	}
	for(int i=ce.size()-1; i >=0; i--)
		fout << ce[i] <<" ";
}
int main(){
	fin >> t;
	if(t == 1)	
		solve1();
	else
		solve2();
	
	return 0;
}