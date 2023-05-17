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

const int  N = 1e4  + 5;
ll  oo = 10000000;
ll const MOD = 1e9 + 7;


/*

int dx [] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
*/

int dx[] = { 0, 1, -1,0 };
int dy[] = { 1,0 , 0,-1 };

int n ;
vi v;
ll dp[N];
ll rec(int index ){
    if(index >= n  )return 0 ;

    ll &ans = dp[index];
    if(ans !=-1 )return ans ;
    ans = 0 ;

    ans = max(rec(index+2 ) + v[index] , rec(index+1));

    return ans ;
}
void solve(int t ){


    cin >> n ;
    for (int i = 0 ; i < n+3 ; i ++ )dp[i] = -1 ;
    v.resize(n);
    for (int i = 0 ; i < n ; i ++)cin>>v[i];

    cout << "Case "<< t << ": ";
    cout << rec(0);
}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    //freopen("jenga.in", "r", stdin);

    int t = 1 ;
    cin >> t;
    int number = 1 ;
    while(t--){

        solve(number++);

        cout << endl;
    }



    return 0;


}

