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

const int  N = 1e5 + 5;
ll  oo = 10000000;
ll const MOD = 1e9 + 7;


/*

int dx [] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
*/

int dx[] = { 0, 1, -1,0 };
int dy[] = { 1,0 , 0,-1 };

vi price , papers ;
int n , x ;
int dp[1003][N];
void solve(){

    cin >> n >> x;
    price.resize(n+1);
    papers.resize(n+1);
    for (int i = 0 ; i < n ; i ++ )cin >> price[i];
    for (int i = 0 ; i < n ; i ++ )cin >> papers[i];

    // need to maximize the total number of papers using all available coins
   for (int i = 1 ; i <= n ; i ++ ){
       for (int j = 0 ; j <= x ; j ++ ){
            dp[i][j] = dp[i-1][j]; // take the value in the previous row cause this is the max value i can get , then maximize this if can

            if(j - price[i-1] >= 0 ){
                dp[i][j] = max(dp[i-1][j - price[i-1]] + papers[i-1] , dp[i][j] );
            }
       }

   }


   cout << dp[n][x];



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

