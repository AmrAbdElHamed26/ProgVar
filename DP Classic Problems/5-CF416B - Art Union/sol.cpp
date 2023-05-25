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

int  arr[N][7];
ll dp[N][7];
void solve(){


    int m , n ; cin >> m >> n ;

    // every painter can start after the last min he finished if he late more than the last painter or wait the last painter 
    // then we want to know which one is late 
    for (int i = 1 ; i <= m ; i ++ ){
        for (int j = 1 ; j <= n ; j ++ ){
            cin >> arr[i][j];
            dp[i][j] = dp[i-1][j]+arr[i][j];

            dp[i][j] = max(dp[i][j-1] , dp[i-1][j]) + arr[i][j];
        }

    }


    for (int i = 1; i <= m ; i ++ )cout << dp[i][n]<< " ";





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

