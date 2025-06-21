//https://code.ptit.edu.vn/student/question/DT001
// ma tran ke -  danh sach canh

#include <bits/stdc++.h>
using namespace std;
int n;
int a[100][100];
int edge;
void solve1(){
	for(int i=1; i<=n; i++){
		int cnt = 0;
		for(int j=1; j<=n; j++)
			if(a[i][j] == 1)
				cnt ++;
		cout << cnt <<" ";
	}
}
void solve2(){
	cout << n <<" "<< edge/2 <<endl;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
			if(a[i][j] == 1){
				cout << i <<" "<< j <<endl;
				a[i][j] = 0;
				a[j][i] = 0;
			}
		}
}
int main(){
	int t; cin >> t;
	cin >> n;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++){
			cin >> a[i][j];
			if(a[i][j] == 1)	edge++;
		}
	if( t == 1)
		solve1();
	else
		solve2();
		
	return 0;
}