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

//ll const MOD = 998244353;

/*
int dx[] = { 0, 1, -1,0 };
int dy[] = { 1,0 , 0,-1 };
int dx [] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
*/

int ask(int x, int y ){
    cout << "? " << x << " "<< y<<endl ;
    int dis  ;cin>>dis;
    return dis ;

}
int distance(int x1 , int y1 , int x2 , int y2){
    return max(abs(x1-x2) , abs(y1-y2));
}
vi primes ;
bool prime[N];
void sieves(){

    for (int i = 2 ; i*i <= N; i ++ ){
        for (int j = i*i ; j <N ; j += i ){
            prime[j] = true ;
        }
    }


}

void solve(){

    sieves();

    int n ; cin >> n ;

    if(n<=2)cout << 1 ;
    else cout << 2 ;
    cout <<endl;
    for (int i = 2 ; i <= n+1 ; i ++ ){
        if(prime[i] == false )cout << 1 << ' ';
        else cout << "2 ";
    }

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1 ; //cin>>t ;
    while(t--){

        solve();
        //cout <<endl;
    }



    return 0;


}