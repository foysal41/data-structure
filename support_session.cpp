#include<bits/stdc++.h>
using namespace std;
int main() {
    int query;
    cin >> query;
        queue<string> q; // যেহেতু একটা নাম তাই char দিয়ে কাজ করবে না string নিতে হবে
    while(query--){
        string cmd;
        cin >> cmd;
        if(cmd == "JOIN"){ // join বললে ইউজার এর কাছ তেখে তার নাম input নিবো
            string name;
            cin >> name;
            q.push(name); // যত বার নাম আসবে তত বার queue এর মদ্দে পুশ হবে
            
            
        }else if (cmd == "DONE"){ // done বললে দুইতা কাজ করব empty and 
            if(q.empty()){  // q এর মদ্ধে student না থাকলে এই operataion করলাম 
                cout << "No Student" << endl;
            }else{// যেহেতু queue data structur use করছি তাই রিমুভ হবে শুরুর দিক থেকে আর পুশ হবে শেষের দিক থেকে যেহেতু পপ হচ্ছে তাহলে front  থেকে তার এলিমেন্ট টি পাব 
                
                cout << q.front() << endl; //যে ফন্টে আছে তার ভ্যালু টাshow korbo
                q.pop(); // এবং তাকে সাপোর্ট থেকে বের করে দেব 
            }
        }
    }

return 0;
}



/* 
Question
 -Q query
 -0 or "JOIN" name = join "Name" student support
 - 1 or "DONE" = print "NAME" who got support, if no student present then print "NO"

*/