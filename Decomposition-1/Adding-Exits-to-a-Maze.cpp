#include<bits/stdc++.h>
using namespace std ;
#define vi vector<int>
#define pb push_back
#define vb vector<bool>

const int N = 1e3 + 1 ;
vi g[N] ;
vb vis (N , false) ;
int n , m ;

void dfs (int node) {
	vis[node] = 1 ;
	for (int &i : g[node]) {
		if (vis[i]) {
			continue ;
		}
		dfs(i) ;
	}
}

int main () {
	cin >> n >> m ;
	for (int i = 0 ; i < m ; ++i) {
		int a , b ;
		cin >> a >> b ;
		g[a].pb(b) ;
		g[b].pb(a) ;
	}
	int ans = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		if (vis[i] == false) {
			++ans ;
			dfs(i) ;
		}
	}
	cout << ans ;
	return 0 ;
}
