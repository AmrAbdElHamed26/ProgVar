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

const int  N = 150000  + 5;
ll  oo = 10000000;
ll const MOD = 1e9 + 7;


/*

int dx [] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
*/

int dx[] = { 0, 1, -1,0 };
int dy[] = { 1,0 , 0,-1 };


vi v , water , parent;
int n ;
int getParent(int node ){
    if(node == parent[node])return node ;
    return parent[node] = getParent(parent[node]);

}

void merge(int node , int rem ){
    if(rem == 0 )return;
    node = getParent(node);
    int used = min(v[node]-water[node] , rem);
    if(node==n){
        water[node]+=used ;
        return;
    }

    water[node]+=used ;
    rem-=used ;
    if(water[node] == v[node])parent[node] = node+1;
    merge(node+1 , rem );

}


void solve(){

    cin >> n ;
    v.resize(n+2);
    water.resize(n+2);
    parent.resize(n+2);
    for (int i = 1 ; i <= n ; i ++ ) {
        cin >> v[i];
        parent[i] = i;
    }

    int q ; cin >> q ;
    while(q--){
        int c;cin >> c;
        if(c == 1 ){
            int x , y ; cin >> x >> y;
            merge(x , y);

        }else{
            int x ; cin >> x ;
            cout << water[x]<<endl;
        }

    }





}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);




    int t = 1 ;
    //cin>>t ;
    while(t--){

        solve();
        //cout << endl;
    }



    return 0;


}

