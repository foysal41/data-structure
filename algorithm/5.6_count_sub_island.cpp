class Solution {
public:
    bool vis[505][505]; //03) একটা visited array নিয়ে নিলাম। 
    vector<pair<int, int>> movee = {{-1,0} , {1,0}, {0,-1}, {0,1}}; //08 move korar global vector টা নিলাম। 
    int n,m; //09 row and column global e  declear করলাম। 

     bool flag; //11 এই জায়গায় ফ্লাগ ভারিয়েবল নিলাম. 11 number line e  যে flag এর মান প্রতিবার DFS চালানোর আগে true করে নিব 

    void dfs(int si, int sj, vector<vector<int>>& grid1, vector<vector<int>>& grid2){ //06 dsf function কে call করলাম। 
        vis[si][sj] = true;

        if(grid1[si][sj] == 0) //10 এখানে দেখার চেষ্টা করছি grid 1 সেম পজিশনে 0 আছে কিনা. 0 থাকলে গ্রিড flag ke false করে দিবো। 
        {
            flag = false;
        }
        
        for(int i=0; i<4; i++){ // 07 amara জানি চার দিকে মভ করবে। 
            int ci = si + movee[i].first;
            int cj = sj + movee[i].second;
            if(valid(ci,cj) && !vis[ci][cj] && grid2[ci][cj] ==1){
                dfs(ci,cj,grid1,grid2);

            }
        }
    }
    bool valid(int i, int j){  // 08 valid function ও I j কে নিবে আর চেক করবে
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        return true;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int cnt = 0; 
        n = grid1.size(); // 01) row  বের করে ফেললাম 
        m = grid1[0].size(); //02) ১ number grid এ জেয়ে column বার করে ফেললাম
        memset(vis,false, sizeof(vis));

      //04  এইবার আমারা pura  grid er উপর loop  চালাবো যেখান  এ আমারা দেখব কনো land unvisited তখন dfs চালাবো
      for(int i=0; i<n; i++)
      {
        for(int j=0; j<m; j++){

            if(!vis[i][j] && grid2[i][j] == 1)//05 land হয়া যাবে না। এবং আমরা grid2 তে কাজ করছি আর দেকব grid 1 এর মদ্ধে ১  আছে কিনা। তাই grid1 e i&j te == 1 হতে হবে।
            {
                flag  = true; // 12 ei j true korlam. 
                dfs(i,j,grid1,grid2);
                if(flag == true){ //13 যদি flag টুকরো হয় তার মানে সাব আইল্যান্ড. তাই তখন কাউন্ট করব 
                    cnt++;
                }
            }

            // 14 return kore dilam  (❌ আগে ভিতরে ছিল, এখন লুপের বাইরে নিলাম)
        }
      }
      return cnt; // 14 return kore dilam
    }
};