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
ll  oo = 1e18;
ll const MOD = 1e9 + 7;


/*

int dx [] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
*/

int dx[] = { 0, 1, -1,0 };
int dy[] = { 1,0 , 0,-1 };



int n ;
vi cost ;
vector<string> v;
// need to minimize the cost of reversing string , take it if the current string is bigger than previous only
ll dp[N][3];
ll min_cost(int index , int pre){ // 1 pre changed
    if(index == n )return  0 ;

    ll &sol = dp[index][pre] ;
    if(sol!=-1)return sol ;
    sol = oo;
    if(index == 0 ){
        sol = min (sol , min_cost(index+1 ,0 ));
        sol = min (sol , min_cost(index+1 , 1 )+ cost[index]);
    }else{
        string preString = v[index-1];
        string currentString = v[index];
        reverse(currentString);
        reverse(preString);
        if(pre == 1 ){
            if(v[index] >= preString){
                sol = min (sol , min_cost(index+1 , 0));
            }

            if(preString <= currentString) sol = min(sol , min_cost(index+1 , 1 )+ cost[index]);

        }
        else {
            if(v[index] >= v[index-1])sol=min(sol , min_cost(index+1 ,0));

            if(currentString>=v[index-1]) sol = min (sol , min_cost(index+1 , 1) + cost[index]);
        }



    }

    return sol;

}
void solve(){

    cin >> n ;
    v.resize(n);
    cost.resize(n);
    ::memset(dp , -1 , sizeof dp);


    for (int i = 0;i < n ; i ++ )cin >> cost[i];
    for (int i = 0;i < n ; i ++ )cin >> v[i];



    ll sol = min_cost(0,0);
    if(sol == oo)cout << -1 ;
    else cout << sol ;




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