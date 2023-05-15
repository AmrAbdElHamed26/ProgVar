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
    vi size , summation , parent ;
    DSU(int n){
        size.resize(n,1);
        summation.resize(n,1);
        parent.resize(n);
        for(int i = 0 ; i < n ; i ++ )parent[i] = i ;
    }

    int getParent(int node){
        if(node == parent[node])return node ;
        return parent[node] = getParent(parent[node]);
    }

    void merge(int x , int y ){
        x = getParent(x);
        y = getParent(y);

        if(x == y)return ;

        if(summation[x]> summation[y])swap(x,y);
        summation[y]+=summation[x];
        size[y]+= size[x];
        size[x] =  0;
        parent[x] = y ;


    }

    int query(int node ){
        return size[getParent(node)];
    }
};


void solve(){


    int n , m ; cin >> n >> m ;

    DSU dsu(n+1);
    while(m--){
        char c ; cin >> c;

        int x , y ;
        if(c == 'M'){

            cin >> x >> y;
            dsu.merge(x,y);

        }
        else {
            cin >> x ;
            cout << dsu.query(x)<<endl;
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

