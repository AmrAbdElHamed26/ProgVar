#include<bits/stdc++.h>
using namespace std;

#define endl "\n" ;
#define sort(v) sort(v.begin() , v.end());
#define reverse(v) reverse(v.begin() , v.end());
typedef pair<long long, long long > ii;
typedef vector<long long > vl;
typedef vector<int>vi ;
typedef vector<ii> vii;
typedef long long ll;
typedef  long double ld;

const int  N = 100  + 5;
ll  oo = 10000000;
ll const MOD = 1e9 + 7;


/*
int dx[] = { 0, 1, -1,0 };
int dy[] = { 1,0 , 0,-1 };
int dx [] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
*/
int n , m ;
int a[N] , b[N] , c[N] , d[N];
int dp[15][1005][105];

/*
 * 
 * take c[i] if c[i] <= n , take b[i] if b[i] <= a[i] , in this case add d[i] to the soultion 
 * 
 * like coin change problem take every type until you cant have more from c[i] and a[i] and return max summation 
 * 
 * */

int rec(int index , int rem_dough , int rem_stuff ){
    if(index > m)return 0 ;

    int &sol = dp[index][rem_dough][rem_stuff];
    if(sol!=-1)return sol;
    sol = rec(index+1 , rem_dough ,a[index+1]) ;
    if(rem_dough >= c[index] && b[index] <= rem_stuff)
        sol = max(
            sol ,
            rec(index , rem_dough - c[index] , rem_stuff-b[index]) + d[index]
            );

    return sol ;

}
void solve(){

    ::memset(dp , -1 , sizeof dp );

    cin >> n >> m ;
    cin>>c[0] >> d[0];

    for (int i = 1 ; i <= m ; i ++ )cin >> a[i] >> b[i]>>c[i]>>d[i];

    cout << rec(0 , n , a[0]);




}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    int t = 1 ;
    //cin>>t ;
    while(t--){

        solve();
        cout <<endl;
    }



    return 0;


}