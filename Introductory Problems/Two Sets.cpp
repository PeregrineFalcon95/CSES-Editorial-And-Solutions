/* Editorial:
Firstly, it's not possible to divide the numbers in two sets if the summation of all numbers are not even.
Suppose we have numbers, 1 2 3 4 5 6 7.
Let's reorder the numbers.
First, take the left and rightmost numbers. 1 7. Now we have 2 3 4 5 6.
Second, take the left and rightmost again, 1 7 2 6. Now we have 3 4 5.
Third, take left-right again, 1 7 2 6 3 5. Now we have 4 only.
Take this 4. Now our final ordering look like this:
1 7 2 6 3 5 4.
Let m be the summation of the numbers. Make m = m/2.
Iterate through the ordering. Take all the numbers one by one, until the summation of taken numbers are less then m.
Let x = m - summationOfTakenNumbers.
Iterate through the rest of the numbers and see if there are any number equal to x. Take this and print two sets.
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
double Ratio [ 110 ] ;
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
    m = ( n * ( n + 1 ) ) / 2;
    if ( m&1 )
    {
        cout<<"NO\n";
        return;
    }
    m /= 2;
    deque < int > dq, temp;
    int le = 1, re = n;
    while( le <= re )
    {
        temp.push_back( le );
        if ( le != re )temp.push_back( re );
        le++;
        re--;
    }
    ll sum = 0;
    while( sum + temp.front() <= m )
    {
        dq.push_back( temp.front() );
        temp.pop_front();
        sum += dq.back();
    }
    ll x = m - sum;
    for ( int i = 0 ; i < temp.size(); i++ )
    {
        if ( temp [ i ] == x )
        {
            sum += x;
            dq.push_back( x );
            temp [ i ] = -1;
            x = -1;
        }
    }
    if ( sum != m )
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n"<<dq.size()<<"\n";
    while( !dq.empty() )
    {
        cout<<dq.front()<<" ";
        dq.pop_front();
    }
    cout<<"\n";

    cout<<temp.size()+x<<"\n";
    while( !temp.empty() )
    {
        if ( temp.front()  != -1)cout<<temp.front()<<" ";
        temp.pop_front();
    }
}
