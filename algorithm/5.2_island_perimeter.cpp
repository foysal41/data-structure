class Solution {
public:

    //main logic: a) water পেলে ++ করবো b)invalid পেলে ++ c) land পেলে dfs চালাবো 

    int cnt; //14) এখানে একাউন্ট ভ্যারিয়েবল নিলাম 
    bool vis[105][105];//02 প্রশ্নে বলেছে 100 size এর একটা 2d array নিচ্ছি 
    vector<pair<int, int>> movee = {{0,1},{0,-1},{1,0},{-1,0}}; 
    int n, m;

    bool valid(int i, int j){
        if(i<0 || i>=n || j<0 || j>=m){ //11) উপরে থেকে n, m কে check করছি। 
            return false;
        }else{
            return true;
        }
    }

    void dfs(int si, int sj, vector<vector<int>>& grid){ //07 i and j কে si sj নামে recived করলাম।  13)dfs এর সঙ্গে  grid তাও প্রয়োজন। 
    //cout << si << " " << sj << endl; // 13) এতগুলো চাইলে আউটপুট দেখতে পারি যে আমারা সব গুলা land cell এ যেতে পারলাম কিনা। সবগুলো ল্যান্ডে যে তার ব্যারিকেড গুলো কাউন্ট করব তাই আগে বুঝতে হবে ব্যারিকেড গুলো কখন থাকে.  যদি পানি থাকে তাহলে এক কাউন্ট হবে. আর যদি গ্রিট শেষ হয়ে যায় তখন ১ count একাউন্ট হবে 



         vis[si][sj]= true; // 08) সব visited কে false করে দিলাম। 
         for(int i=0; i<4; i++){//09) এখানে আমাদের চারটা করে child সেটা ফিক্সড 

                //10) এখান থেকে আমরা চিল্ড্রেনের ইনডেক্স বের করব ci, cj. Child কিভাবে পাবো? Si and sj এর সঙ্গে movee যোগ করে.  সেই movement গুলো আমরা একটা ভেক্টরের ভেতর রেখে সেখান থেকে আনতে পারি 
                int ci = si + movee[i].first;
                int cj = sj + movee[i].second;
                
                //12) এবার recursion দিয়ে DFS চালানোর পালা। এখানে তিনটা জিনিস চেক করতে হবে. ভ্যালিড হতে হবে, নট ভেজিটেট হতে হবে, ল্যান্ড হতে হবে .
            //if(valid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == 1){
                //dfs(ci,cj, grid); ei kaj ta korchi na ei problem er jonno
            //} 

            //15)  যদি valid false হয় count ++ করবো
                if(valid(ci, cj) == false)
                    cnt++;
            //16 যদি grid এর ci, cj একটা ভালুএ ০ হলে পানি পেয়েছি। 
               else if(valid(ci, cj) == true && grid[ci][cj] == 0)
                    cnt++;
                
                else if(valid(ci, cj) == true && !vis[ci][cj] && gird[ci][cj] == 1)
                    dfs(ci, cj, grid);
                


         }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        cnt = 0; // শুরুতে  14 নাম্বার লাইনের কাউন্ট ভ্যারিয়েবল ta 0 করে দিচ্ছি
      n = grid.size();
      m = grid[0].size();
      memset(vis, false, sizeof(vis));//03) Memset দিয়ে সব ভিজিটেড array কে false করে দিব 

//4) এবার কাজ হচ্ছে যে কোন একটি ল্যান্ড cell যাব এবং সেখান থেকে ডিএফএস চালায় বাকি ল্যান্ড cell কাছে যাব. এখন কথা হচ্ছে আমরা ল্যান্ড পাব কোথায়? তাই পুরা grid এর পর loop চালাবো যেখানেই পাবো সেখান থেকে শুরু করব.  

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && grid[i][j] == 1){ //05 I j যদি  1 হয় তারমানে আমি ল্যান্ডে আছি| এবং সেই সাথে সাথে visited টা চেক করব|  আমরা চেক করছি land এর ঘরটা ভিজিটেড হয় এবং এবং সেটা যেন ল্যান্ড হয়.

            // 06) উপরের কন্ডিশন যদি ঠিকঠাক থাকে তাহলে আমরা DFS (i j)চালিয়ে দিব 
            dfs(i,j, grid);
 


            }
        }
    }

return cnt;
    }
};