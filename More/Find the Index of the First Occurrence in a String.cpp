#include<bits/stdc++.h>
using namespace std;


int strStr(string haystack, string needle){
    int n = haystack.size();
    int m = needle.size();

    for(int i=0; i +m <= n; i++){ // in doc

        //substr আসলে C++ STL | .substr(pos, len) → সাবস্ট্রিং বের করে ex s.substr(0, 3)
        string sub = haystack.substr(i, m); 

        if(sub == needle){
            return i;
        }
    }

    return -1;

}




int main(){

    string haystack, needle;
    cin >>  haystack >> needle;
    int ans = strStr(haystack, needle);

    cout << ans << endl;


    return 0;
}


//https://docs.google.com/document/d/1VZ-4tZwh64t_eTPMkVvcgxQYDd1eIxKKkuhqfA__9K8/edit?usp=sharing