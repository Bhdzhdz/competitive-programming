#include <bits/stdc++.h>

using namespace std;

#define all(container) begin(container), end(container)

using ull = unsigned long long;
using ll = long long;

const int MAX = 1e6;
const int MOD = 1e9 + 7;

/*
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using orderedSet = tree<ull,null_type,less<ull>,rb_tree_tag, tree_order_statistics_node_update>;
using orderedMultiSet = tree<ull,null_type,less_equal<ull>,rb_tree_tag, tree_order_statistics_node_update>;
*/

/////////////////From KACTL/////////////////
// Source: https://github.com/kth-competitive-programming/kactl

///////////////////////////////////////////////////

void preprocessing(){
    return;
}

void solve(){

    vector<int> numbers(7);

    for(int &x : numbers){ cin >> x;}

    sort(all(numbers));

    int a = numbers[0];
    int b = numbers[1];
    int c = numbers[6] - a - b;

    cout << a << ' ' << b << ' ' << c << '\n';

    return;
}

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin.exceptions(cin.failbit);

    //srand (time(nullptr));

    preprocessing();

    int t=1; 
    //cin>>t;

    while(t--){
        solve();
    }

    return 0;
}

