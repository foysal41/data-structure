#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string str;
        cin >> str;

        stack<char> st; // এই stack খালি কিনা ওইটা check করে কাজ করছি।

         for(char eachchar : str){
    if(st.empty()){
        st.push(eachchar); // যদি stack খালি হয়, তাহলে push করবো

    }else if((st.top() == '0' && eachchar == '1') || (st.top() == '1' && eachchar == '0')){
        st.pop(); // যদি 01 বা 10 হয়, তাহলে eliminate
    }else{
        st.push(eachchar);  // অন্যথায় push করবো
    }
   }



        if(st.empty()) { // এই stack যদি খালি থাকে তার মানে stack empty তাই output YES
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}



//https://www.hackerrank.com/contests/assignment-03-a-basic-data-structure-a-batch-07/challenges/is-it-valid-1-1