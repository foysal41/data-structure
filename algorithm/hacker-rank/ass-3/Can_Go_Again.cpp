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

int dis[1005]; 
vector<Edge> edge_list; 
int n , e; 

int main(){
 
    cin >> n >> e;

    

    while(e--)

    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a,b, c));

    }


    int source; 
    cin >> source;

    int qry;
    cin >> qry;
    vector<int> query(qry);
    for(int i=0; i< qry; i++)
    {
        cin >> query[i];
    }


    for(int i = 1; i<=n; i++)
    {
        dis[i] = INT_MAX;  
    }
    dis[source] = 0; 

    for(int i=0; i<n-1; i++){
        for(auto ed : edge_list)
        {
            int a = ed.a;
            int b = ed.b;
            int c = ed.c;

            if(dis[a] != INT_MAX && dis[a] + c < dis[b])
            {
                dis[b] = dis[a] + c;
            }
        }
    }


    bool cycle = false;
    for(auto ed: edge_list){

         int a = ed.a;
         int b = ed.b;
         int c = ed.c; 

         if(dis[a] != INT_MAX && dis[a] + c < dis[b])
         {
            cycle = true;
            break;
         }
    }

    if(cycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;

    }

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