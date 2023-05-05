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

bool prime[N];
vl primes ;
void seive (){

    for (int i = 2 ; i *i <= N ; i ++ ){
        for (int j = i*i ; j <= N ; j +=i ){
            prime[j] = 1 ;
        }
    }
    for (int i = 2 ; i < N ; i ++)if(prime[i] ==0)primes.push_back(i);
}
void solve(){

    /*for(int i = 0 ; i < 20 ; i ++ )cout <<primes[i]<<' ';
    cout <<endl;*/

    ll n ;cin >> n ;

    ll sum = 1 ;


    for (int i = 0 ; i <= 15 ; i ++ ){
        sum*=primes[i];

        if(sum > n){
            cout << i ;
            return;
        }
    }

    cout << 15 ;


}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    seive();
    int t = 1 ;
    cin>>t ;
    while(t--){


        solve();
        cout <<endl;
    }



    return 0;


}