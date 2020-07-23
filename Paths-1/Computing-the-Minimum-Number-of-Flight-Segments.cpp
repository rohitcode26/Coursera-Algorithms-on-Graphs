#include<bits/stdc++.h>
using namespace std ;
#define vi vector<int>
#define pb push_back

const int N = 1e5 + 1 ;
vi g[N] ;
vi dis(N , -1) ;

int main () {
	int n , m ;
	cin >> n >> m ;
	for (int i = 0 ; i < m ; ++i) {
		int a , b ;
		cin >> a >> b ;
		g[a].pb(b) ;
		g[b].pb(a) ;
	}
	int u , v ;
	cin >> u >> v ;
	queue <int> q ;
	q.push(u) ;
	dis[u] = 0 ;
	while (q.size()) {
		int node = q.front() ;
		q.pop() ;
		for (int &i : g[node]) {
			if (dis[i] == -1) {
				dis[i] = dis[node] + 1 ;
				q.push(i) ;
			}
		}
	}
	cout << dis[v] ;
	return 0 ;
}
