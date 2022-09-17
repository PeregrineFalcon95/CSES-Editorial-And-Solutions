#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define inf 10000000000000001
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie( NULL);
int t, cases;

struct node {
    int _node;
    ll cost;
    node(ll _cost, int __node ){
        _node = __node;
        cost = _cost;
    }
    bool operator < (const node& p) const { return cost > p.cost; }
};

class solution{
private:
    void dijkstra(int source, int target, int n, vector < vector < pair < int, int > > >& graph, vector < ll >& cost){
        priority_queue < node > pq;
        vector < bool > vis (n+1, false);
        pq.push(node(0,source));
        cost [ source ] = 0;

        while( !pq.empty() ){
            source = pq.top()._node;
            pq.pop();
            if ( vis [ source ] )continue;
            vis [ source ] = true;

            int sz = graph [ source ].size();
            for ( int i = 0; i < sz; i++ ){
                int child = graph [ source ] [ i ].first;
                ll cc = graph [ source ] [ i ].second;

                if ( cost [ child ] > cost [ source ] + cc ){
                    cost [ child ] = cost [ source ] + cc;
                    pq.push( node(cost [ child ] , child) );
                }
            }
        }
    }
public:
    void inputAndPerform(){
        int n, m;
        cin>>n>>m;
        vector < vector < pair < int, int > > > graph (n+1, vector < pair < int ,int > >() ), revGraph (n+1, vector < pair < int ,int > >() );
        vector < ll > cost (n+1, inf), revCost (n+1, inf);
        while( m-- ){
            int a, b , c;
            cin>>a>>b>>c;
            graph [ a ].push_back( {b,c} );
            revGraph [ b ].push_back( {a,c} );
        }
        dijkstra(1,n,n,graph,cost);
        dijkstra(n,1,n,revGraph,revCost);
        ll ans = inf;
        for ( int i = 1; i <= n; i++ ){
            int sz = graph [ i ].size();
            for ( int j = 0; j < sz; j++ ){
                int child = graph [ i ] [ j ].first;
                int cc = graph [ i ] [ j ].second;
                ans = min(ans, cost [ i ] + revCost [ child ] + cc / 2 ); 
            }
        }
        cout<<ans<<"\n";
    }   
};
int main(){
    fast
    solution obj;
    obj.inputAndPerform();
    return 0;
}