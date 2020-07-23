#include<bits/stdc++.h>
using namespace std ;

#define F first
#define S second
#define pb push_back
#define vi vector<int>
#define pii pair<int , int>
#define vpii vector< pair<int ,int > >
#define triplet pair<long double , pair <int , int> >
#define ld long double

const int N = 210 ;
vector <triplet> edge_list ;
vi parent (N , -1) ;
vpii g (N) ;
ld ans = 0 ;
int n ;

void read_graph () {
	cin >> n ;
	for (int i = 0 ; i < n ; ++i) {
		cin >> g[i].F >> g[i].S ;
	}
}

ld dis (pii &f , pii &s) {
	ld a = (ld)(f.F - s.F)*(f.F - s.F) ;
	ld b = (ld)(f.S - s.S)*(f.S - s.S) ;
	ld c = sqrt(a+b) ;
	return c ;
}

void make_edges () {
	for (int i = 0 ; i < n-1 ; ++i) {
		for (int j = i + 1 ; j < n ; ++j) {
			ld distance = dis(g[i] , g[j]) ;
			edge_list.pb({distance , {i , j}}) ;
		}
	}
}

int find_parent (int a) {
	if (parent[a] < 0) {
		return a ;
	}
	return parent[a] = find_parent(parent[a]) ;
}


void union_operation (triplet &temp) {
	long double weight = temp.F ;
	int a = temp.S.F ;
	int b = temp.S.S ;
	int p1 = find_parent(a) ;
	int p2 = find_parent(b) ;
	if (p1 == p2) {
		return ;
	}
	ans += weight ;
	if (parent[p2] < parent[p1]) {
		swap(p1 , p2) ;
	}
	parent[p1] += parent[p2] ;
	parent[p2] = p1 ;
}

void kruskal_MST () {
	sort(edge_list.begin() , edge_list.end()) ;
	for (int i = 0 ; i < edge_list.size() ; ++i) {
		union_operation(edge_list[i]) ;
	}
}

int main () {
	read_graph () ;
	make_edges () ;
	kruskal_MST() ;
	cout << fixed << setprecision(10) << ans ;
	return 0 ;
}
