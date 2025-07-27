#include <bits/stdc++.h>
using namespace std; 

int main() {
    string str;
    cin >> str;
    
    stack<char> st;
    
    //এভাবে আমরা লুক চালাবো এবং str প্রত্যেকটা ইনডেক্সে যাব 
    for(int i=0; i<str.length(); i++){
      if(st.empty()){
        st.push(str[i]); //string /input থেকে যে ক্যারেক্টারি আসুক প্রথমে তাকে আমাকে push করতে হবে 

      }else if (st.top() == 'B' && str[i] == 'A'){
        st.pop(); //এবার এখানে যেটা করতে হবে যে “A” এর আগে  “B” থাকলে তাদেরকে রিমুভ করে দিতে হবে 

      }else{
        st.push(str[i]);  //এরপরে যা আসুক A A B B A p  push hobe
      }
    }
    
    
    if(st.empty()){
      cout << "Empty" << endl;
    }else{
      cout << "Not Empty" << endl;
    }

    return 0;
}


/*
Question:
'A' will remove/elimination previus 'B' with itself. After elimination, if another elimination possible then remove. Then check "Empty"  or "Not Empty"

string: ABBAABBA 
*/