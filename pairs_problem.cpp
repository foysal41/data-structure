#include <bits/stdc++.h>
using namespace std;

// cmp ফাংশন: দুইটা pair<string, int> এর মধ্যে তুলনা করার নিয়ম
bool cmp(pair<string, int> left, pair<string, int> right)
{
    // যদি নাম ভিন্ন হয়, তাহলে নাম alphabetically ছোট যেটা সেটা আগে আসবে
    if (left.first != right.first)  
        return left.first < right.first;

    // যদি নাম একই হয়, তাহলে roll বড় যেটা সেটা আগে আসবে
    return left.second > right.second;
}

int main()
{
    vector<pair<string, int>> v;
    int n;
    cin >> n; // কতগুলো pair ইনপুট আসবে

    // ইনপুট নেওয়া
    for (int i = 0; i < n; i++) {
        string name;
        int roll;
        cin >> name >> roll;
        v.push_back({name, roll});
    }
    
    // custom compare function দিয়ে sort করা
    sort(v.begin(), v.end(), cmp);
    
    // sorted result প্রিন্ট করা
    for (int i = 0; i < n; i++) {
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}

/* 
left → sorting এর সময় প্রথম এলিমেন্ট (যেটা compare করা হচ্ছে)

right → দ্বিতীয় এলিমেন্ট (যেটার সাথে compare করা হচ্ছে)

if (left.first != right.first) → প্রথমে নাম মিলছে কি না চেক করি

নাম আলাদা হলে left.first < right.first মানে alphabetically ছোট নাম আগে যাবে

নাম এক হলে left.second > right.second মানে roll বড় হলে আগে যাবে

এভাবে second test case টাও ঠিকভাবে pass করবে।
*/



//https://www.hackerrank.com/contests/final-exam-a-basic-data-structure-a-batch-07/challenges/pairs-17

//https://docs.google.com/document/d/1fXzKJAiB3somZ-hGDPaIMzUv4IIbZAIba1fziqJWtb4/edit?usp=sharing