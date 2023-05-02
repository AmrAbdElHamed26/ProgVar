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

const int  N = 100000  + 5;
ll  oo = 10000000000;
ll const MOD = 1e9 + 7;


/*
int dx[] = { 0, 1, -1,0 };
int dy[] = { 1,0 , 0,-1 };
int dx [] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
*/

void solve(){


    int n ; cin >> n ;

    vi v (n+5);
    for(int i = 1 ; i <= n ; i ++ )cin>>v[i];

    vi maxLeft(n+5) , maxRight(n+5);

    maxLeft[1]=1;
    for (int i =2 ; i <= n ; i ++ ){
        maxLeft[i] =  maxLeft[i-1]+1;
        if(v[i] <= v[i-1])maxLeft[i]=1;
    }

    maxRight[n]=1;
    for (int i = n-1 ; i >= 1 ; i -- ){
        maxRight[i] = maxRight[i+1]+1;

        if(v[i]>= v[i+1])maxRight[i]=1;
    }

    int sol = 0;

    for (int i = 1 ; i <= n ; i ++ ){
        sol = max(sol , 1 + maxLeft[i-1]);
        sol = max(sol, 1 +  maxRight[i+1]);

        if(v[i+1] - v[i-1] > 1 )sol = max(sol , 1+ maxLeft[i-1] + maxRight[i+1]);
    }


    cout << sol ;

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);



    int t = 1 ;// cin>>t ;
    while(t--){

        solve();
        cout <<endl;
    }



    return 0;


}