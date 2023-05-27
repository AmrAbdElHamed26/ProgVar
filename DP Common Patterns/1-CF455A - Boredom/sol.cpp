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


map<int,int>fre;
ll dp[N];
ll max_Points(int number ){
    if(number > fre.rbegin()->first) return 0 ;

    ll &sol = dp[number];
    if(~sol) return sol ;
    sol = 0 ;
    sol = max(sol  , max_Points(number+2) + (ll)fre[number] * (ll)number );
    sol = max(sol , max_Points(number+1));

    return sol ;
}
void solve(){

    ::memset(dp , -1 , sizeof dp);
    int n ; cin >> n ;
    vi v(n);
    for (int i = 0 ; i <n ; i ++ ){
        cin >> v[i];
        fre[v[i]]++;
    }

    cout <<max_Points(fre.begin()->first);








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

