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

const int  N = 5e3 + 5;
ll  oo = 1e18;
ll const MOD = 1e9 + 7;


/*

int dx [] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
*/

int dx[] = { 0, 1, -1,0 };
int dy[] = { 1,0 , 0,-1 };

vl prefix ;
vi v ;
int n , m , k  ;
ll dp[N][N];
ll max_value(int index , int rem){
    if(index > n )return 0 ;

    ll &sol = dp[index][rem] ;
    if(~sol )return sol ;
    sol = 0 ;
    ll summation = 0 ;
    if(index+m-1 <= n ){
        summation = prefix[index+m-1] - prefix[index-1];

        if(rem>0) sol = max(sol , max_value(index+m , rem-1) + summation);
        sol = max(sol , max_value(index+1 , rem));
    }

    return sol ;
}


void solve(){

    ::memset(dp , -1 , sizeof dp );
    cin >> n >> m >> k ;
    v.resize(n+1);
    prefix.resize(n+1);

    for(int i = 1 ; i <= n ; i ++ )cin>> v[i];
    prefix[1] = v[1];
    for (int i = 1 ; i <= n ; i ++ )prefix[i] = prefix[i-1]+v[i];

    cout <<max_value(1,k);



}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("jenga.in", "r", stdin);

    int t = 1 ;
    //cin >> t;
    while(t--){

        solve();
        cout << endl;
    }



    return 0;


}