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
ll  oo = 10000000;
ll const MOD = 1e9 + 7;


/*

int dx [] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
*/

int dx[] = { 0, 1, -1,0 };
int dy[] = { 1,0 , 0,-1 };


struct DSU {
    vi size  , parent ;
    DSU(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i = 0 ; i < n ; i ++ )parent[i] = i ;
    }

    int getParent(int node){
        if(node == parent[node]) return node ;
        return parent[node]  = getParent(parent[node]) ;
    }

    void merge(int x , int y ){
        x = getParent(x);
        y = getParent(y);

        if(x == y)return ;

        if(size[x]> size[y])swap(x,y);
        size[y]+= size[x];
        size[x] =  0;
        parent[x] = y ;


    }

    int query(int node ){
        return size[getParent(node)];
    }
};


void solve(){


    


    int n  ; cin >> n  ;

    vector<pair<ll , pair<ll ,ll >>> v(n-1);
    for(int i = 0 ; i <n-1;i++){
        int x , y , w ; cin >> x >> y >> w ;
        pair<ll , pair<ll ,ll >> p ={w ,{x,y}};
        v[i]=p;
    }
    sort(v);
    DSU dsu(n+1);
    ll sol = 0  ;

    for (int i = 0 ; i < n-1 ; i ++ ){
        ll s1 = dsu.query(v[i].second.first);
        ll s2 = dsu.query(v[i].second.second);
        sol+=(s1*s2*v[i].first);
        dsu.merge(v[i].second.first , v[i].second.second);
    }

    cout << sol ;

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

