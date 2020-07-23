#include<bits/stdc++.h>
using namespace std ;

#define pb push_back
#define vi vector<int>
#define vb vector<bool>

const int N = 1e4 + 1 ;
vi g[N] , order(N) ;
vb vis(N , false) ;
int n , m ;

void dfs_top_sort (int node) {
	vis[node] = true ;
	for (auto &i : g[node]) {
		if (vis[i] == false) {
			dfs_top_sort(i) ;
		}
	}
	order.pb(node) ;
}

void dfs_condensed (int node) {
	vis[node] = true ;
	for (auto &i : g[node]) {
		if (vis[i] == false) {
			dfs_condensed(i) ;
		}
	}
}

int main () {
	cin >> n >> m ;
	for (int i = 0 ; i < m ; ++i) {
		int a , b ;
		cin >> a >> b ;
		g[a].pb(b) ;
	}
	for (int i = 1 ; i <= n ; ++i) {
		if (vis[i] == false) {
			dfs_top_sort (i) ;
		}
	}
	vis.assign(N , false) ;
	int cnt = 0 ;
	for (int i = 1 ; i <= n ; ++i) {
		int node = order[n-1-i] ;
		if (vis[node] == false) {
			++cnt ;
			dfs_condensed(i) ;
		}
	}
	cout << cnt ;
	return 0 ;
}
