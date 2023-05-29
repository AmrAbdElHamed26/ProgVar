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



int n ;
vi v ;

int dp[102][4];
int min_days(int index , int state){
    if(index == n )return 0;

    int &sol = dp[index][state] ;
    if(~sol)return sol ;
    sol = 1e6 ;
    if(v[index] == 0 ){
        sol = min (sol , min_days(index+1 , 0)+1);
    }
    else if(v[index] == 1 ){
        if(state != 2 )sol = min (sol , min_days(index+1 , 2));
        sol = min (sol , min_days(index+1 , 0)+1);
    }
    else if(v[index] == 2 ){
        if(state != 1 )sol = min (sol , min_days(index+1 , 1));
        sol = min (sol , min_days(index+1 , 0 )+1);
    }
    else {
        if(state != 2) sol = min (sol , min_days(index+1 , 2));
        if(state != 1 )sol = min (sol , min_days(index+1 , 1));

        sol = min (sol , min_days(index+1 , 0)+1);
    }

    return sol ;

}


void solve(){

    cin >> n ;
    v.resize(n);

    ::memset(dp , -1 , sizeof dp);
    for (auto &i : v )cin >> i ;

    cout <<min_days(0,0);






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