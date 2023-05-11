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

const int  N = 1000000  + 5;
ll  oo = 10000000;
ll const MOD = 1e9 + 7;


/*
int dx[] = { 0, 1, -1,0 };
int dy[] = { 1,0 , 0,-1 };
int dx [] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
*/
map<int,int>primes ;
bool prime[N];
void solve(int n ){



    for (auto i : primes ){
        int number = i.first ;
        int num2 = n - number ;
        if(primes.find(num2)!=primes.end()){

            cout << n << " = " << number << " + " << num2 ;
            return;
        }
    }

    cout << "Goldbach's conjecture is wrong.";

}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 2 ; i*i <= N ; i ++ ){
       if(!prime[i]){
           for (int j = i*i ; j < N ; j +=i)prime[j] = 1;
       }
    }

    for (int i = 2 ; i <N ; i ++ ){
        if(prime[i] == 0) primes[i]++;
    }


    int t = 1 ;
    //cin>>t ;
    while(t){


        int n ; cin >> n ;
        if(n == 0 )break;
        solve(n);
        cout <<endl;
    }



    return 0;


}

