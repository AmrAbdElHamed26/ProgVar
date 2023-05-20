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
vi v ;
int dp[N];
bool flag ;
int min_coins(int myMoney){
    if(myMoney == 0 ){
        flag = true;
        return 0 ;
    }

    int &sol = dp[myMoney] ;
    if(~sol )return sol ;
    sol = 1e6 ;
    for (auto i : v){
        if(myMoney >= i )
            sol = min (sol , min_coins(myMoney - i )+1  );
        sol = min (sol , min_coins(myMoney));
    }
    return sol ;
}

int min_cost_iterative(int x ){
    for (int i = 1 ; i <=x ; i++)dp[i]= 1e9;
    for (auto i : v)dp[i] = 1 ;


    for (int i = 1 ; i <= x ; i ++ ){
        for (auto j : v){
            if(i >= j )dp[i] = min (dp[i] , dp[i-j]+1);
        }
    }
    if(dp[x] == 1e9 )return -1;


    return dp[x];
}
void solve(){
    // compete with problems ⚔︎⚔︎⚔︎⚔︎⚔︎

    int n , x ; cin >> n >> x ;
    v.resize(n);

    for (int i = 0 ; i < n ; i ++ )cin >> v[i];


    int sol = min_cost_iterative(x);
    cout << sol;



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

