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

vi v1, v2;
int n ;
struct  DSU {

    vector<ll> par , size , Time , summation ;
    DSU(int n){
        par.resize(n); size.resize(n , 1);
        Time.resize(n);
        summation.resize(n);
        for (int i = 0 ; i < n ; i ++ ) {
            par[i] = i;
            summation[i] = v1[i];
        }

    }

    int getParent(int node){
        if(node == par[node])return node ;
        return par[node] = getParent(par[node]);
    }



    void merge (int x , int y ){
        y = getParent(y);

        if (size[x] > size[y])swap(x, y);
        size[y]+= size[x];
        summation[y]+=summation[x];
        par[x] = y ;


    }


    ll getSummation (int node ){
        return summation[getParent(node)];
    }

};

void solve(){


    cin >>n;

    v1.resize(n);v2.resize(n);
    for (int i = 0 ; i < n ; i ++ )cin >> v1[i];
    for (int i = 0 ; i < n ; i ++ ) {
        cin >> v2[i];
        v2[i]--;
    }
    reverse(v2);

    map<int,int>mp;
    for (int i = 0; i < n ; i ++ )mp[i]=-1;
    DSU dsu(n);

    ll summation = 0 ;
    vl sol ;
    for (int i = 0 ; i < n ; i ++ ){
        int left = v2[i]-1 ;
        int right = v2[i]+1;
        mp[v2[i]]=1;
        ll c1= 0 , c2 = 0 ;



        if(left >= 0 && mp[left]==1){
            c1 = dsu.getSummation(left);
        }
        if(right < n && mp[right] == 1 ){
            c2 = dsu.getSummation(right);
        }

        sol.push_back(max(summation , max(c1,c2)));
        summation = max(summation , c1+c2+v1[v2[i]]);


        if(left >= 0 && mp[left]==1){
            dsu.merge(dsu.getParent(v2[i]) , left);
        }
        if(right < n && mp[right] == 1 ){
            dsu.merge(dsu.getParent(v2[i]) , right);
        }


    }


    reverse(sol)
    for (auto i : sol )cout << i <<endl;


}
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);




    int t = 1 ;
    //cin>>t ;
    while(t--){

        solve();
        cout << endl;
    }



    return 0;


}

