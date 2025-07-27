#include<bits/stdc++.h>
using namespace std;



int main(){

    //steak and que এর মধ্যে input রাখার জন্য আমরা এটা নিলাম 
    stack<int> steak;
    queue<int> que;

     int n, m;
     cin >> n>> m;
     
     // এবার শুধুমাত্র steak  এর মধ্যে loop চালিয়ে ইনপুট  দিয়ে দিব 
    for(int i=0; i<n; i++){
        int value;
        cin >> value;
        steak.push(value);
    }

    // এবার শুধুমাত্র queue  এর মধ্যে loop চালিয়ে ইনপুট  দিয়ে দিব 
    for(int i=0; i<m; i++){
        int value;
        cin >> value;
        que.push(value);
    }


    /* 
চাইলে output করে দেখতে পারি ঠিকঠাক মতো সবকিছু ইনপুট হয়েছে কিনা 

    while(!steak.empty()){
        cout << steak.top() << " ";
        steak.pop();
    }

    cout << endl;

    while(!que.empty()){
        cout << que.front() << " ";
        que.pop();
    }
*/

//প্রথমে আমরা চেক করছি stack (5).  queue(5) একই কিনা যদি একই না হয় তাহলে তো তারা same না 
    if(steak.size() != que.size()){
        cout << "NO" << endl;
        return 0;
    }else{
        bool flag = true;


        while(!steak.empty() && !que.empty()){ // যতক্ষণ না পর্যন্ত সাইজ  zero না হচ্ছে ততক্ষণ পর্যন্ত এই loop চলবে 

            if(steak.top() != que.front()){  //এবং steak and que এর ভ্যালু এক্সেস করছি same কিনা সেম না হলে false
                flag=false;
                break;
            }
            steak.pop();
            que.pop();
        }

        if(flag){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

    return 0;
}