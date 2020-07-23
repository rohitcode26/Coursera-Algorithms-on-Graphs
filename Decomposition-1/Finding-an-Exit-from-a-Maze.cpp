#include<bits/stdc++.h>
using namespace std ;
#define vi vector<int>
#define pb push_back
#define vb vector<bool>

const int N = 1e3 + 1 ;
vi g[N] ;
vb vis (N , false) ;
int n , m , u , v , a , b ;

void dfs (int node) {
	vis[node] = true ;
	for (int &i : g[node]) {
		if (vis[i]) {
			continue ;
		}
		dfs(i) ;
	}
}

int main () {
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; ++i) {
		g[i].clear() ;
		vis[i] = false ;
	}
	for (int i = 0 ; i < m ; ++i) {
		cin >> a >> b ;
		g[a].pb(b) ;
		g[b].pb(a) ;
	}
	cin >> u >> v ;
	dfs(u) ;
	if (vis[v]) {
		cout << 1 ;
	} else {
		cout << 0 ;
	}
	return 0 ;
}
