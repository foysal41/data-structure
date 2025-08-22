#include<bits/stdc++.h>   // সব স্ট্যান্ডার্ড হেডার একসাথে ইনক্লুড
using namespace std;

int main(){
    int node, edge;       // node = নোড সংখ্যা, edge = এজ সংখ্যা
    cin >> node >> edge;  // ইনপুট থেকে নোড আর এজ সংখ্যা পড়া

    vector<int> adj_list[node]; // অ্যারে অব ভেক্টর → প্রতিটি নোডের জন্য প্রতিবেশী লিস্ট

    // সব এজ ইনপুট নেওয়া (undirected বলে দুই দিকেই push করতে হবে)
    while (edge--)
    {
        int a,b;
        cin >> a >> b;            // এক এজ: a ↔ b
        adj_list[a].push_back(b); // a থেকে b কানেক্টেড
        adj_list[b].push_back(a); // b থেকে a কানেক্টেড
    }
    
    // প্রতিটি নোডের লিস্টকে descending order এ সাজানো
    for(int i=0; i<node; i++){
        sort(adj_list[i].begin(), adj_list[i].end(), greater<int>());
    }

    int q; 
    cin >> q;  // query সংখ্যা পড়া

    // প্রতিটি query প্রসেস করা
    while(q--){
        int u;
        cin >> u;  // query তে দেওয়া নোড u

        if(adj_list[u].empty()){   // যদি u–এর সাথে কোনো নোড কানেক্টেড না থাকে
            cout << -1 << endl;    // তাহলে -1 প্রিন্ট
        }else{
            // নাহলে u–এর সব কানেক্টেড নোড প্রিন্ট করা
            for(int x: adj_list[u]){
                cout << x << " ";  // প্রতিটি প্রতিবেশী নোড স্পেস দিয়ে প্রিন্ট
            }
            cout << endl;          // প্রতিটি query শেষে newline
        }
    }

    return 0;   // প্রোগ্রাম শেষ
}
