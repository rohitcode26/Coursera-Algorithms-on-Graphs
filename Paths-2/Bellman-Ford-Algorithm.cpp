#include<bits/stdc++.h>
using namespace std ;

#define F first
#define S second
#define inf INT_MAX
#define pb push_back
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int , int>
#define vpii vector< pii >
#define edge pair< pair <int , int> , int >

const int N = 1e4 + 1 ;
vector<edge> ed (N) ;
vi dis(N , inf) , p(N , -1) ;
vb isneg(N , false) ;
bool chk = false ;
int n , m ;

bool negative_cycle (int s) {
	dis[s] = 0 ;
	int x ;
	for (int i = 0 ; i < n ; ++i) {
		x = -1 ;
		for (int j = 0 ; j < m ; ++j) {
			if (dis[ed[j].F.F] < inf) {
				if (dis[ed[j].F.S] > dis[ed[j].F.F] + ed[j].S) {
					dis[ed[j].F.S] = dis[ed[j].F.F] + ed[j].S ;
					p[ed[j].F.S] = ed[j].F.F ;
					x = ed[j].F.S ;
				}
			}
		}
	}
	if (x != -1) {
		for (int i = 1 ; i <= n ; ++i) {
			x = p[x] ;
		}
		int cnt = 0 ;
		for (int i = x ; ; i = p[i]) {
			isneg[i] = true ;
			++cnt ;
			if (i == x && cnt > 1) {
				break ;
			}
		}
	}
}

int main () {
	cin >> n >> m ;
	for (int i = 0 ; i < m ; ++i) {
		cin >> ed[i].F.F >> ed[i].F.S >> ed[i].S ;
	}
	int s ;
	cin >> s ;
	negative_cycle(s) ;
	for (int i = 1 ; i <= n ; ++i) {
		if (isneg[i]) {
			cout << "-\n" ;
			continue ;
		}
		if (dis[i] == inf) {
			cout << "*\n" ;
			continue ;
		}
		cout << dis[i] << '\n' ;
	}
	return 0 ;
}
