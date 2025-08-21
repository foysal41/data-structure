#include <bits/stdc++.h>
using namespace std;

char grid[105][105]; 
bool vis[105][105];
int level[105] [105]; //21) আমরা জানি ডিসটেন্সটা বের করতে হলে bsf function এর সাথে লেভেল কে ট্রাক রাখতে হয় 


vector<pair<int, int>> movee = {{-1,0}, {1, 0}, {0, -1}, {0, 1}}; 
int n,m;

bool valid(int i, int j){
  if(i<0 || i>=n ||j<0 ||j>=m){
    return false;
  }else{
    return true;
  }
}
//এবং এখানে আমরা BFS  লিখব 
void bfs(int si, int sj){ //8) source দুইটা প্যারামিটার রিসিভ করলাম 
  queue<pair<int, int>> q; //1) আমরা একটা queue নিতাম তার ভেতরে src কে push করে দিতাম  //9) Queue তে ইনডেক্স হিসেবে row এবং কলাম কে নিতে হবে 

  q.push({si,sj}); //10) source এর দুইটাই ইনডেক্স pari হিসেবে পুশ করে দিলাম 
  vis[si][sj] = true; //২) visit কে true করে দিলাম; //11) ভিজিট row কলাম অনুযায়ী true করব 
  level[si][sj] = 0; // 23) Source row and column লেভেলও 0
  
   while(!q.empty()){ //3) পুরা queue  এর উপর looop চালাবো 
     //int par = q.front(); //4) সেই queue থেকে  তার front কে বার করে নিয়ে আসব এবং popকরে দিব
    pair<int, int> par = q.front(); //12) queue এর front থেকে এবার pair আসবে 
    q.pop();
    
//13) আমরা চাইলে সেই pair ফার্স্ট এবং সেকেন্ড ভ্যালুটাকে আলাদা করে রাখতে পারি ভেরিয়েবল এর ভিতরে 
      int par_i = par.first;
      int par_j = par.second;
      
      cout << par_i << " " << par_j << endl; //19) print korta pari 
      
      //for(int child: adj_list[par]) //5) child এর  উপর loop চালাবো।  একটা  একটা করে  child বার করে আনতাম।
      //{
        //if(!vis[child]){ //6) jodi child visit না হয় টা হলে অই child  কে queue তে push হবে। এবং  child এর ভিসিত কে true করে দিলাম।
          //q.push(child);
          //vis[child] = true;
        //}
      //}
      
       for(int i=0; i<4; i++)// 14) এবার এখানে loop অন্যভাবে চালাবো.  আমরা জানি আমাদের 2d grid 4 দিকে move করা যায় 
        {
            int ci = par_i + movee[i].first; //15) এবার আমাদের চাইল্ড বের করতে হবে Movee নামে যে ভেক্টর নিয়েছে সেখান থেকে কন্ট্রোল হচ্ছে 
            int cj = par_j + movee[i].second;
            if(valid(ci,cj) && !vis[ci][cj]){ // 16 valid হতে হবে  and not visited হতে হবে . 
             q.push({ci, cj});   //17) তাই যদি হয় তাহলে simply কিনতে pair কে পুশ করে দিব 
              vis[ci][cj] = true;// 18) visit কে true kore দিলাম। 
              level[ci][cj] = level[par_i][par_j]; //24) এবার এখানে চিল্ড্রেনে লেভেল দিতে হবে. চিল্ড্রেনের লেভেল হচ্ছে প্যারেন্টের লেভেলের থেকে এক বেশি 
            }
        }
      
      
   }
  
}

int main() 
{
  
    cin >>n >> m; 
     for(int i=0; i<n; i++)  {
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
     int di, dj; // 20) এখন যদি প্রশ্নে বলে শর্টেস্ট node বের করতে. এর জন্য আমরা ডিসটেন্স তাকে ইনপুট নিয়ে দিলাম 


     cin >> si >> sj ; 
     cin >> di >> dj; 
    memset(vis, false, sizeof(vis)); 
    memset(level, -1, sizeof(level)); // 22) শুরুতে সবার লেভেলের মান -1  করে দিলাম 
     bfs(si, sj); //7) ebar 2d array জন্য bsf চালাবো। এই জন্য source থাকে হবে ২ টা source er row and coumn এর index.
    
     cout << level[di][dj] << endl; // 25)  19 number line er pring off okre dite pari 
    return 0;

}



/* 

shortst distence
3 4 
. . . . 
. . . . 
. . . . 
1 2
2 0

output: 3


*/