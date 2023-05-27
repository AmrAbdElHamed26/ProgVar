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

int totalSummation, n   ;
vi v;
int dp[102][50004];
int min_diff(int index , int summation ){
    if(index == n ){
        int anotherSummation = totalSummation - summation ;
        return abs(summation - anotherSummation);
    }


    int &sol = dp[index][summation] ;
    if(~sol)return sol ;
    sol = 1e6 ;
    sol = min (
            min_diff(index+1 , summation+v[index]),
            min_diff(index+1 , summation)
            );


    return sol ;
}
void solve(){

    cin >> n ;
    v.clear();
    v.resize(n);
    totalSummation = 0 ;
    ::memset(dp , -1 , sizeof dp);
    for (int i = 0 ; i < n ; i ++ ){
        cin >> v[i];
        totalSummation+=v[i];
    }

    cout << min_diff(0,0);






}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("jenga.in", "r", stdin);

    int t = 1 ;
    cin >> t;
    while(t--){

        solve();

        cout << endl;
    }



    return 0;


}

