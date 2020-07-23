#include<bits/stdc++.h>
using namespace std ;

# define pb push_back  
# define vi vector <int>

const int N = 1e5 + 1 ;
vi g[N] ;
int color[N] ;

bool flag = true ;

void dfs(int node) {
	for (int &i : g[node]) {
		if (color[i] == color[node]) {
			cout << 0 ;
			exit(0) ;
		}
		if (color[i] == 0) {
			color[i] = 3 - color[node] ;
			dfs(i) ;
		}
	}
}

int main() {
	int n , m ;
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; ++i) {
		g[i].clear() ;
	}
	for (int i = 0 ; i < m ; ++i) {
		int a , b ;
		cin >> a >> b ;
		g[a].pb(b) ;
		g[b].pb(a) ;
	}
	for (int i = 1 ; i <= n ; ++i) {
		color[i] = 0 ;
	}
	for (int i = 1 ; i <= n ; ++i) {
		if (color[i] == 0) {
			color[i] = 1 ;
			dfs(i) ;
		}
	}
	cout << 1 ;
	return 0 ;
}
