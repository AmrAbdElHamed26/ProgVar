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

const int  N = 10000  + 5;
ll  oo = 10000000;
ll const MOD = 1e9 + 7;


/*
int dx[] = { 0, 1, -1,0 };
int dy[] = { 1,0 , 0,-1 };
int dx [] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
*/

map<int,int> getPrimeFactors(ll n ){
    map<int,int>mp;
    for (int i = 2 ; i*i <= n ; i ++ ){
        while(n % i == 0){
            mp[i]++;
            n/=i;
        }

    }
    if(n > 1 )mp[n]++;

    return mp;
}


void solve(){


    ll n ;cin>> n ;


    map<int,int>all;
    for (int i = 2 ; i <= n ; i ++ ){
        map<int,int> mp = getPrimeFactors(i);

        for (auto j : mp){
            int number = j.first , occ = j.second ;
            all[number]+=occ;
        }
    }

    ll sol = 1;

    for (auto i : all  ) sol = ((sol)%MOD * (i.second+1)%MOD)%MOD ;

    cout << sol ;

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

