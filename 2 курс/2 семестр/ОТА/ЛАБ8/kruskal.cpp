// QBMST on SPOJ
#include <bits/stdc++.h>
using namespace std;

#define FOR(i,x,y) for(int i = (x); i<=(y); ++i)
#define REP(i,r) for(int i = 0; i < (r); ++i)
#define DFOR(i,x,y) for(int i = (x); i>=(y); --i)
#define db(x) cout << #x << " = " << x << endl;
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it!=var.end(); ++it)
#define forrit(it, var) for(__typeof(var.rbegin()) it = var.rbegin(); it!=var.rend(); ++it)
#define pb push_back
#define pf push_front
#define mp make_pair
#define F first
#define S second
#define II pair<int,int>
#define LL long long
#define lb lower_bound
#define ub upper_bound
#define LAST(x) (int)x.size()-1
#define ld long double
#define maximize(x,y) x=max(x,(y))
#define minimize(x,y) x=min(x,(y))


const int N = 100002;
const int oo = 1000000007;
int pset[N], m, n;
vector< pair<int, II> > edge;
void init() {
    FOR(i,1,n) pset[i] = i;
}
int findSet(int u) {
    return pset[u] == u ? u : pset[u] = findSet(pset[u]);
}
int isSameSet(int u, int v) {
    return findSet(u) == findSet(v);
}
void unionSet(int u, int v) {
    pset[findSet(u)] = findSet(v);
}
int main() {
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.out", "w", stdout);
	#endif // ONLINE_JUDGE
	scanf("%d%d", &n, &m);
	FOR(i,1,m) {
	    int u,v,w; scanf("%d%d%d", &u, &v, &w);
	    edge.pb(mp(w,mp(u,v)));
	}
	sort(edge.begin(), edge.end());
	init();
	LL ans = 0;
    forit(it, edge) {
        II e = it->S;
        if (isSameSet(e.F, e.S)) continue;
        unionSet(e.F, e.S);
        ans += it->F;
    }
    printf("%I64d\n", ans);
}
