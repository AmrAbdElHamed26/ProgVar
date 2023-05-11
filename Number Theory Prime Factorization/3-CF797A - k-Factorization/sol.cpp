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

const int  N = 200000  + 5;
ll  oo = 10000000;
ll const MOD = 1e9 + 7;


/*

int dx [] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
*/

int dx[] = { 0, 1, -1,0 };
int dy[] = { 1,0 , 0,-1 };



void solve(){

    int n , k ;cin >> n >> k ;
    vi v;
    for (int i = 2 ; i*i <= n ; i ++ ){
        while(n%i == 0){
            v.push_back(i);
            n/=i;
        }
    }

    if(n >1)v.push_back(n);
    if(v.size()>=k){
        ll summation = 1 ;
        int i = 0 ;
        for ( i ; i <= v.size()-k ; i ++ ){
            summation*=v[i];
        }

        cout << summation << ' ';

        for(i ; i < v.size() ; i ++ )cout << v[i]<< ' ';
    }
    else cout << -1 ;


}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);




    int t = 1 ;
    //cin>>t ;
    while(t--){


        solve();
        cout <<endl;
    }



    return 0;


}

