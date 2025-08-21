#include <bits/stdc++.h>
using namespace std;
char grid[105][105]; 
bool vis[105][105]; // 4) এটা যেহেতু 2d array সেহেতু ভিজিট কাউন্টটাও দুইটা নিতে হবে 
vector<pair<int, int>> movee = {{-1,0}, {1, 0}, {0, -1}, {0, 1}}; //8) এখানে একটি pair ভেক্টর নিচ্ছি.  যেহেতু আমরা চারদিকে যেতে পারবো. তাই move এর মধ্যে 4 দিচ্ছি | ভিক্টরের ভিতরে আমরা পেয়ার রাখতে পারি একটা একটা পেয়ারে দুইটা করে ভ্যালু. আর move  এর সাইজ লেখার প্রয়োজন নাই ভেক্টর একাই বুঝে নিবে 
int n, m;

//13)এবার আমরা একটা valid ফাংশন বানালাম. i  চেক করবে row এর index. J check করবে কলামের ইনডেক্স 

bool valid(int i, int j){
    //i যদি জিরো থেকে ছোট হয় তাহলে false || ধরি আমাদের row আছে তিনটা  কিন্তু 4 নাম্বার পসিবল না. তখন invalid হয়ে যাবে.এটা কলামের ক্ষেত্রে একই  
    if(i<0 || i >= n || j<0 || j >= m  ){
        return false;
    }else{
        return true;
    }
}


void dfs(int si, int sj){ //5) পেরামেরটা দুইটা রিসিভ করলাম 
  cout << si << sj << endl;
  vis[si][sj] = true; //6) আমাদের visited  array  এখন 2d তাই সেভাবে তাকে true করবো 

//7 আমরা জানি যে একটা নোট থেকে চারদিকে যেতে পারি. Up: row= -1 column=0 | botton: row= 1 column=0 | left: row= 0 column=-1 | right: row= 0 column= 1
//12)তবে এখানে আর একটা কাজ আছে. সেটা হচ্ছে আমরা ধরে নিচ্ছি প্রতিটি নোট এই চারটা চিলড্রেন. বেশি হবে না তবে কম হলে কি করতে হবে? তার জন্য ci and cj  valid কিনা সেটা চেক করতে হবে. 
  for(int i=0; i<4; i++){
    int ci, cj;
    
    //8) এবার উপরে ভেক্টর থেকে প্রত্যেকটা পেয়ারের first and second  কে নিয়ে 7 নাম্বারের লজিকের সাথে কাজ করলাম 
    ci = si + movee[i].first; 
    cj = sj + movee[i].second;
    //cout << ci << " " << cj << endl;  //9) output kore dakah
    
    //if(vis[ci][cj] == false){ // 10  চেক করে দেখব ভিসিটেড এর এর ভেতরে এগুলো অলরেডি ভিজিট করা হয়েছে কিনা তারপর DFS এ recurtion কল করব 
    //14) এখানে আমরা ভিজিটেড ভ্যালুটাই চেক করব না সেই সাথে vlaid কিনা সেটা চেক 
    if(valid(ci, cj) == true && !vis[ci][cj])
      dfs(ci, cj);
    }
  }
  
  
 

int main() 
{
    
    cin >>n >> m; 
     for(int i=0; i<n; i++)  { //1) এইবার এই grid কে inasted loop চালিয়ে input নিব
       for(int j=0; j<m; j++){
          cin >> grid[i][j];
       }
     } 
     
     
    
     //for(int i=0; i<n; i++)  { //) input গুলা প্রিন্ট করে দেখলাম
       //for(int j=0; j<m; j++){
         // cout <<  grid[i][j];
       //}
      // cout << endl;
     //} 
     
     
     int si,sj;
     cin >> si >> sj ; //2) মনে করি source i and source j input থেকে  12  দেয়া হল । 
  memset(vis, false, sizeof(vis)); // 11 DFS function কে কল করার আগে visit সবার ভালো false  করে দিব 
     dfs(si, sj); // 3) DSF  চালিয়ে চেক করব আমাদের সোর্স নোট টা কোথায় 
    
    return 0;
}


/* 
3 4
. . . .
. . . .
. . . .
1  2

Output:

1 2
0 2
2 2
1 1
1 3

------------------
all value travers
1 2
0 2
0 1
1 1
2 1
2 0
1 0
0 0
2 2
2 3
1 3
0 3


*/