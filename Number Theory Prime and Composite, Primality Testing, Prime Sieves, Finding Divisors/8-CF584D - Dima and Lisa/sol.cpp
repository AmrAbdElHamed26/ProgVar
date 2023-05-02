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

const int  N = 100  + 5;
ll  oo = 10000000;
ll const MOD = 1e9 + 7;


/*
int dx[] = { 0, 1, -1,0 };
int dy[] = { 1,0 , 0,-1 };
int dx [] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
*/
bool isPrime(int number ){
    if(number == 2 || number == 3 )return true;
    if(number == 1 || number %2 == 0)return false ;

    for (int i = 3 ; i*i<= number ; i +=2){
        if(number%i==0)return  false ;

    }

    return true ;
}
void test(int number ){

    int n = number ;
    if(isPrime(number)){
        cout << 1 << endl;
        cout << number ;
        return;
    }

    int arr[]= {2,3,5,7,11,13};
    for (auto i : arr ){

            int x = i ;
            int number2 = n-i;
            for (int j = 2 ; j*j <= number2 ; j ++ ){

                int y = j ;
                if(isPrime(y) && x+y == n ){
                    cout << 2 << endl;
                    cout << x << ' '<< y ;
                    return;
                }

                int z = number2 - j ;

                if(z >= 2 && isPrime(y) && isPrime(z) && x + y + z == n ){
                    cout << 3 << endl;
                    cout << x << ' '<< y << ' '<< z ;
                    return;
                }

            }



        }
}


void solve(){

    int n ; cin >> n;

    test(n);

    /*for (int i = 1000 ; i < 1500 ; i ++ ){
        cout << i << " : ";
        test(i);
        cout<<endl;
    }*/
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