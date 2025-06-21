// chu trinh euler 02

#include <bits/stdc++.h>
using namespace std;
int visit[100] ;
queue <int> q;
int a[101][101];
int n, u , s;

bool ltBFS(){
	fill(visit, visit + 100, 1);
	q.push(1);
	visit[1] = 0;
	while(!q.empty()){
		s = q.front();
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
	cin >> n;
	for(int i=1; i<= n; i++)
		for(int j=1; j<=n; j++)
			cin >> a[i][j];
			
	if(ltBFS() == 0){
		cout << 0;
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
		cout << 1;
	else if(cntodd == 2)
		cout << 2;
	else 
		cout << 0;
	return;

}
void solve2(){
	int k;	cin >> n >> k;
	for(int i=1; i<= n; i++)
		for(int j=1; j<=n; j++)
			cin >> a[i][j];
			
	stack <int> st;
	vector <int> ce;
	st.push(k);

	while(!st.empty()){
		bool check = 1;
		int s = st.top();
		int u;
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
		cout << ce[i] <<" ";
	
}
int main(){
	int t; cin >> t;
	if(t == 1)	
		solve1();
	else
		solve2();
	
	return 0;
}

