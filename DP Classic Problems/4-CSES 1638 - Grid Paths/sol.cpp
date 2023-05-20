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

const int  N = 1e3 + 5;
ll  oo = 10000000;
ll const MOD = 1e9 + 7;


/*

int dx [] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
*/

int dx[] = { 0, 1, -1,0 };
int dy[] = { 1,0 , 0,-1 };
int n ;
string arr[N];
int dp[N][N];
bool valid(int i , int j ) {
    if(i < n && j < n && arr[i][j] == '.')return  true;
    return false;
}
int number_of_paths(int i , int j ){
    if(i == n -1 && j == n-1 )return 1 ;
    int &sol = dp[i][j];
    if(~sol )return  sol;
    sol = 0 ;
    if(valid(i+1 , j ))
        sol += number_of_paths(i+1 , j);
    if(valid(i,j+1))
        sol+= number_of_paths(i , j+1);

    sol%=MOD;
    return sol ;

}
void solve(){
    // compete with problems ⚔︎⚔︎⚔︎⚔︎⚔︎

    ::memset(dp , -1 , sizeof dp );
    cin >> n;
    for (int i = 0 ; i < n ; i ++ ){
        cin >> arr[i];
    }
    if(arr[0][0] =='*')cout << 0 ;
    else cout << number_of_paths(0,0);

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

