#include<bits/stdc++.h>
using namespace std;
int main(){
    int tc;
    cin >> tc;

    while(tc--){
        int a, b, c;
        cin >> a >> b >> c;

        int lift_1_time = a-1;
         int lift_2_time = abs(b-c) + c-1;
         if(lift_1_time < lift_2_time) cout << 1 << endl;
         else if(lift_1_time >lift_2_time) cout << 2 << endl;
         else cout << 3 << endl;
    }
    return 0;
}


//https://codeforces.com/problemset/problem/1729/A