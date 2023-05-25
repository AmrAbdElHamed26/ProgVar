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




void solve(){


    int n , x ; cin >> n >> x ;

    vi v(n);
    for (int i = 0 ; i < n ; i ++ )cin>>v[i];

    int dp[x+1];
    for (int i = 0 ; i <= x ;i++)dp[i]=0;
    dp[0] = 1;

    for (auto j : v){
        for (int i = 1 ; i <= x ; i ++ ){
            if(i-j >= 0 ){
                dp[i] += dp[i-j];
                dp[i]%=MOD;
            }
        }
    }
    cout << dp[x];







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

