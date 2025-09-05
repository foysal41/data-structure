#include<bits/stdc++.h>
using namespace std;
class Edge
{
    public:
       int a, b, c;
    Edge( int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

int dis[1005]; //04) source থেকে প্রতিটি নোড পর্যন্ত shortest distance রাখবে।
vector<Edge> edge_list; //02 সব এজ জমা থাকবে এখানে।
int n , e; 

int main(){
 
    cin >> n >> e;

    

    while(e--)//01) while থেকে shob লুপ চালিয়ে push back করে। edge_list মদ্দে রাখলাম। 

    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a,b, c));

    }


    int source; //03) Bellman-Ford সব distance হিসাব করবে s থেকে।
    cin >> source;

    int qry; //05 query
    cin >> qry;
    vector<int> query(qry);
    for(int i=0; i< qry; i++)
    {
        cin >> query[i];
    }

    /*  Details in query;
    qry = কয়টা query আসবে। প্রতিটি qry আসলে একটা destination node এর নাম্বার। অর্থাৎ: "source থেকে এই নোডে যাওয়ার shortest path কত?"
    সব query-কে query[] ভেক্টরে রেখে দিলাম। 

    example: ধরি source = 1 আর query list হলো 3 4 5।
        1 থেকে 3 এ shortest distance কত?
        1 থেকে 4 এ shortest distance কত?
        1 থেকে 5 এ shortest distance কত?
    */

    for(int i = 1; i<=n; i++)
    {
        dis[i] = INT_MAX;  //06) শুরুতে সব distance = "অজানা" (INT_MAX) ধরা হলো।   
    }
    dis[source] = 0; //07) source node source থেকে source- এ যাওয়ার distance সবসময় 0 

    for(int i=0; i<n-1; i++){
        for(auto ed : edge_list)
        {
            //08) প্রতিটি edge (a → b, cost = c) চেক করা হয়।
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;

            //09) যদি source থেকে a তে যাওয়ার পথ জানা থাকে (dis[a] != INT_MAX) এবং dis[a] + c এর মান ছোট হয় dis[b] থেকে → তাহলে dis[b] আপডেট করা হয়।
            if(dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }


    bool cycle = false;
    for(auto ed: edge_list){

        //10) আবার একবার সব edge চেক করা হয়।
         int a = ed.a;
         int b = ed.b;
         int c = ed.c; 

         //11)যদি আরও ছোট distance পাওয়া যায়, তাহলে এর মানে negative cycle আছে।
         if(dis[a] != INT_MAX && dis[a] + c < dis[b])
         {
            cycle = true;
            break;
         }
    }

//12) যদি negative cycle থাকে → সরাসরি বলে দেয় "Negative Cycle Detected"।
    if(cycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;

    }

    //13)না হলে প্রতিটি query node এর shortest distance প্রিন্ট করে। যদি কোনো node এ যাওয়া সম্ভব না হয় → "Not Possible"
    for(int d : query)
    {
        if(dis[d] == INT_MAX)
        {
            cout << "Not Possible" << endl;
        }else{
            cout << dis[d] << endl;
        }
    }


 
    return 0;
}


// https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-07/challenges/can-go-again