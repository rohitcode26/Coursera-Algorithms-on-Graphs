#include<bits/stdc++.h>
using namespace std ;

#define inf INT_MAX
#define pb push_back
#define vi vector<int>
#define pii pair<int , int>
#define vpii vector< pii >

const int N = 1e4 + 1 ;
vpii g[N] ;
vi dis(N , inf) ;

void dijkstra (int s) {
	dis[s] = 0 ;
	priority_queue < pii , vpii , greater <pii> > q ;
	q.push({0 , s}) ;
	while (q.size()) {
		pii p = q.top() ;
		q.pop() ;
		int node = p.second ;
		int d_node = p.first ;
		if (d_node != dis[node]) {
			continue ;
		}
		for (auto &i : g[node]) {
			int nxt = i.first ;
			int len = i.second ;
			if (dis[nxt] > dis[node] + len) {
				dis[nxt] = dis[node] + len ;
				q.push({dis[nxt] , nxt}) ;
			}
		}
	}
}

int main () {
	int n , m ;
	cin >> n >> m ;
	for (int i = 0 ; i < m ; ++i) {
		int a , b , c ;
		cin >> a >> b >> c ;
		g[a].pb({b , c}) ;
	}
	int u , v ;
	cin >> u >> v ;
	dijkstra(u) ;
	if (dis[v] == inf) {
		cout << -1 ;
	} else {
		cout << dis[v] ;
	}
	return 0 ;
}
