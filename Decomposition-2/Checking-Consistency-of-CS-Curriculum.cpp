#include<bits/stdc++.h>
using namespace std ;
#define vi vector<int>
#define pb push_back
#define vb vector<bool>

const int N = 1e3 + 1 ;
vi g[N] ;
vi vis (N , 0) ;
int n , m , a , b ;
bool found_cycle ;

void dfs (int node) {
	vis[node] = 1 ;
	for (int &i : g[node]) {
		if (vis[i] == 1) {
			found_cycle = true ;
		} else if (vis[i] == 0) {
			dfs(i) ;
		}
	}
	vis[node] = 2 ;
}

int main () {
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; ++i) {
		g[i].clear() ;
		vis[i] = 0 ;
	}
	for (int i = 0 ; i < m ; ++i) {
		cin >> a >> b ;
		g[a].pb(b) ;
	}
	for (int i = 1 ; i <= n ; ++i) {
		if (vis[i] == 0) {
			found_cycle = false ;
			dfs(i) ;
			if (found_cycle) {
				cout << 1 ;
				return 0 ;
			}
		}
	}
	cout << 0 ;
	return 0 ;
}
