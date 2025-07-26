#include<bits/stdc++.h>
using namespace std;

class MyStack
{
    public:
    list<int> l;

    void push(int val){
        l.push_back(val);
    }

    void pop(){
        l.pop_back();
    }

    int top(){
        return l.back();
    }

    int size(){
        return l.size();
    }

    bool empty(){
       return l.empty();
    }
};


int main(){
    MyStack st1, st2;
   
    int n;
    cin >> n; // লুপ কইবার চলবে 
    for(int i=0; i<n; i++){
        int value;
        cin >> value; // সেই লুপ এর মদ্ধে প্রতিটা ভালু কে ইনপুট নিলাম  (১০ ২০ ৩০ ৪০ ৫০ )
        st1.push(value); // সেই ভালুএ গুলা  st1 এর মদ্ধে রেখে দিলাম।
    }



     int m;
    cin >> m; // লুপ কইবার চলবে 
    for(int i=0; i<m; i++){
        int value;
        cin >> value; // সেই লুপ এর মদ্ধে প্রতিটা ভালু কে ইনপুট নিলাম  (১০ ২০ ৩০ ৪০ ৫০ )
        st2.push(value); // সেই ভালুএ গুলা  st2 এর মদ্ধে রেখে দিলাম।
    }

    /* 
    while(!st1.empty()){
        cout << st1.top() << " ";
        st1.pop();
    }
    cout << endl;
    while(!st2.empty()){
        cout <<st2.top() << " ";
        st2.pop();
    }*/


//---- আমাদের দুইটা stack এর ভালু ইনপুট নেয়া হয়ে গেছে। 



    if(st1.size() != st2.size()){ //input এর মদ্ধে  ১০ ২০ ৩০ ৪০ ৫০ (৫)  এই দুইটা সেম সাইজ (৫) কিনা, শুধু ওইটা চেক করছি। সেম না হলে ওই জায়গায় বলে দিবে "Not Same"
        cout <<" Not Same" << endl;
    }else{  // else এর মদ্ধে চেক করবো প্রতিটা value সেম কিনা। তার জন্য

        bool flag = true;
        while(!st1.empty() && !st2.empty()){ //১) stack1 and stack2 ফাকা না হয় থলে 
            if(st1.top() != st2.top()){ //২) condition চেক করবে stack1 and stack2 এর top সেম কিনা। যদি সেম না হয় flag false করেছি
                flag = false;
                break; // ৩) থকন এই জায়গায় কোড অফ করে দিবো।
            }

            st1.pop();
            st2.pop(); // ৪ প্রতিবার একটা একটা করে stack1 and stack2 ফাকা করে দিবো।
        }

        if(flag == true){
            cout << "Same" << endl;
        }else{
            cout <<" Not Same" << endl;
        }
    }




    return 0;
}





/*


Question: Take two stacks of size N and M as input and check if both of them are the same or not. Don’t use STL stack to solve this problem.

Sample Input
5
10 20 30 40 50
5
10 20 30 40 50

Sample Output
YES



Sample Input
5
10 20 30 40 50
4
10 20 30 40

Sample Output
NO

Sample Input
5
10 20 30 40 50
5
50 40 30 20 10

Sample Output
NO


*/