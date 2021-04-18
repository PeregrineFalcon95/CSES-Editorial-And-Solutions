/* Editorial:
let's count the number of appearance of each character.
Only one character can appear odd times, We will put those character in the middle of the string.
Let's follow a simple algorithm: For each character with even appearance, we will put one in the front of the string, one at the end of the string.
We can use deque of char for this operation
*/




#include<bits/stdc++.h>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/assoc_container.hpp>
//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")
//#pragma GCC optimization ("unroll-loops")
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>pbds;
//#pragma comment(linker, "/stack:200000000")
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);
#define ll long long int
#define mod ( ll  )( 1e9 + 7 )  //( 1e9 + 7 )
#define inf ( int  )( 1e9 + 10 )
#define mxs (int)(1e6+100)
#define CHECK_BIT(var,pos) ((var) & (1LL<<(pos)))
//#define md  int mid = ( l + r )>>1;
//int dx[]={+1,-1,+0,+0};///Four Directions
//int dy[]={+0,+0,+1,-1};///Four directions
//int dx [] = {+1,-1,+0,+0,-1,-1,+1,+1};///Eight Directions
//int dy [] = {+0,+0,+1,-1,+1,-1,-1,+1};///Eight Directions
//int dx[]={-2,-2,-1,1,-1,1,2,2};///Knight moves
//int dy[]={1,-1,-2,-2,2,2,-1,1};///Knight moves

ll n , m, t, ans, cases ;
ll ar [ mxs ] ;
string s , s2;
void brainfuck();
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    fast
    //cin>>t;
    t = 1;
    //scanf("%d",&t);
    while( t-- )brainfuck();
    return 0;
}
void brainfuck()
{
    cin>>s;
    deque < char > dq;
    n = s.size();
    for ( int i = 0 ; i < n; i++ )
    {
        ar [ s [ i ] - 'A' ]++;
    }
    int counter = 0;
    int idx;
    for ( int i = 0 ; i < 26; i++ )
        if ( ar [ i ]&1 )
        {
            counter++;
            idx = i;
        }
    if ( counter > 1 )
    {
        cout<<"NO SOLUTION";
        return;
    }
    if ( counter )
    {
        for ( int i = 0; i < ar [ idx ]; i++ )
        dq.push_back( idx + 'A' );
        ar [ idx ] = 0;
    }
    for ( int i = 0 ; i < 26; i++ )
    {
        while( ar [ i ] )
        {
            ar [ i ] -= 2;
            dq.push_back( i + 'A' );
            dq.push_front( i + 'A' );
        }
    }
    while( !dq.empty() )
    {
        cout<<dq.front();
        dq.pop_front();
    }
}
