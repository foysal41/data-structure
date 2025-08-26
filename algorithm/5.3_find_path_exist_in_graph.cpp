class Solution {
public:
    vector<int> adj_list[200005];//01) adj list conert করছি 
    bool vis[200005]; // 05) vis array নিয়ে নিলাম। 

    void dfs(int src){
        vis[src] = true;

        for(int child : adj_list[src]){ //07 adj_list থেকে each item বার করে নিব আর দেখব visited কিনা। 
            if(!vis[child]){
                dfs(child); //08 যদি ভিজিটেড না হয় তাহলে  DFS চালিয়ে দিবো 
            }
        }

    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i=0; i<edges.size(); i++){ //02) edge list এর উপর প্রতিটা ইনডেক্সের উপরে loop চালালাম. এই লোক চালালে কি পাব? 
            int a = edges[i][0]; //03) সেই edge মধ্যে দুইটা করে ইনডেক্স আছে. প্রথম element তাকে বের করে নিয়ে আসলাম. i নাম্বার ইনডেক্স একটা ভেক্টর পাবো তার মধ্যে 0 নম্বর index 
            int b = edges[i][1];

            adj_list[a].push_back(b); // 04) যেহেতু এটা আন ডাইরেক্টেড সে তো এখানে আমরা দুইবার দুই দিকে pushback করলাম 
            adj_list[b].push_back(a); 


        }

        memset(vis,false,sizeof(vis));
        dfs(source); // 06 source কে পাঁঠিয়ে দিলাম। 

        //09 এইবার এখান থেকে রিটার্ন করার পালা যদি visited না হয় তাহলে false
        if(vis[destination] == true)
            return true;
        else return false;


        //short curt of 9
        //return vis[destination];
    }
};


//https://docs.google.com/document/d/1m-OCIS35DOH568t-KAo21U7p5FrZKLosP8YXjNW1ocw/edit?usp=sharing















class Solution {
public:

    bool vis[55][55]; //2) vis array niya nilam.  
    vector<pair<int, int>> movee = {{0,1},{0,-1},{1,0},{-1,0}}; 
    int n,m;
    int cnt; //07 আমরা গ্লোবালি  একটা কাউন্ট varialbe নিলাম 


      bool valid(int i, int j){
        if(i<0 || i>=n || j<0 || j>=m){ 
            return false;
        }else{
            return true;
        }
    }

    void dfs(int si, int sj, vector<vector<int>>& grid )
    {
        vis[si][sj] = true;
        cnt++; // 9) প্রতিবার DFS চলার সময় কাউন্ট কে 1 বাড়িয়ে দিলাম 

        for(int i=0; i<4; i++){
            int ci = si + movee[i].first;
            int cj = sj + movee[i].second;
            if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == 1)
                dfs(ci,cj, grid);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
       //int cnt = 0; //উপরে dfs  এর সকল বেসিক কাজগুলো করে ফেললাম. যতবার  dfs চলবে ততবার count++ করবো
        n = grid.size();  //1) Row and column number বের করতে হবে 
        m = grid[0].size();

        memset(vis,false, sizeof(vis));

        //3) এবার এই ভিসিটেড এর উপরেই লুপ চালাবো এখানে যখনই আনভিজিটেড পাবো তখনই DFS চালাবো 
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(!vis[i][j] && grid[i][j] == 1) // grid == 1 or land হতে হবে
                    {
                        dfs(i,j, grid); 
                       // cnt++; 5) component বার kora আমাদের কাজ না। amader কাজ হল each component e যাব যার মাক্স তাকে return করবো. কারন আমাদের জানতে হবে প্রতিটি আইল্যান্ডে কয়টা করে node আছে 
                       cnt = 0; // 8) প্রতিবার DFS চালানোর আগে এটাকে 0 করে নিব 
                       cout << cnt << end; // 10) আমরা এখনো প্রিন্ট করে দেখতে পারি আমাদের কাউন্ট আসছে কিনা সেটা দেখার চেষ্টা করছি. এখান থেকে আমরা ম্যাক্সিমাম টা জাস্ট প্রিন্ট করব 



                    }
                    return cnt; // 4) আমাদের যে ছয়টা কম্পনেন্ট বা ছয়টার ল্যান্ড আছে সেটা বের করতে পারছি কিনা একবার প্রিন্ট করে দেখলাম 

    }
};