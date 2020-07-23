#include<bits/stdc++.h>
using namespace std ;
#define vi vector<int>
#define pb push_back
#define vb vector<bool>

const int N = 1e5 + 1 ;
vi g[N] ;
vi indeg (N , 0) ;
int n , m , a , b ;
vi ans ;

int main () {
	cin >> n >> m ;
	for (int i = 1 ; i <= n ; ++i) {
		g[i].clear() ;
	}
	for (int i = 0 ; i < m ; ++i) {
		cin >> a >> b ;
		g[a].pb(b) ;
		++indeg[b] ;
	}
	queue <int> q ;
	for (int i = 1 ; i <= n ; ++i) {
		if (indeg[i] == 0) {
			q.push(i) ;
		}
	}
	while (q.size()) {
		int node = q.front() ;
		q.pop() ;
		ans.pb(node) ;
		for (int &i : g[node]) {
			--indeg[i] ;
			if (indeg[i] == 0) {
				q.push(i) ;
			}
		}
	}
	for (auto &i : ans) {
		cout << i << " " ;
	}
	return 0 ;
}
