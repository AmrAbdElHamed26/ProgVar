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

const int  N = 1e6 + 5;
ll  oo = 10000000;
ll const MOD = 1e9 + 7;


/*

int dx [] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
*/

int dx[] = { 0, 1, -1,0 };
int dy[] = { 1,0 , 0,-1 };
vi coins ;
int n , x ;
ll dp[N];

ll ways(int summation ){
    if(summation >= x){
        if(summation == x)return 1 ;
        return 0 ;
    }


    ll &sol = dp[summation] ;

    if(sol !=-1)return sol;

    sol = 0 ;

    for (int i = 0 ; i < n ; i ++ ){
        sol = (sol % MOD + (ways(summation + coins[i]) )%MOD)%MOD;
    }

    return sol ;

}


void solve(){

    cin >> n >> x;
    memset(dp , -1 , sizeof dp);
    coins.resize(n);
    for (int i = 0 ; i < n ; i ++ )cin>>coins[i];

    cout << ways(0);




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

