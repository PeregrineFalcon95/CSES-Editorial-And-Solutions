/* Editorial:
There are few exceptional case:
N = 1 : Print 1
N = 2 or 3 : Print "No Solution"
N = 4 : Print "2 4 1 3"
For all other values:
Just print all odd values one side and all the even values on the other side.
Iterate from N and decrease N with 2 every step.
Then iterate from N-1 and decrease N with 2 every step.
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
#define mod ( ll  ) 1000000000000//( 1e9 + 7 )  //( 1e9 + 7 )
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
    cin>>n;
    if ( n == 1 )
    {
        cout<<"1";
        return;
    }
    if ( n < 4 )
    {
        cout<<"NO SOLUTION";
        return;
    }
    if ( n == 4 )
    {
        cout<<"2 4 1 3";
        return;
    }
    m = n;
    while( m >= 1 )
    {
        cout<<m<<" ";
        m -= 2;
    }
    m = n-1;
    while( m >= 1 )
    {
        cout<<m<<" ";
        m -= 2;
    }
}
