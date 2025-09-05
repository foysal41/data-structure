#include<bits/stdc++.h>
using namespace std;



int main(){
    int n, e; 
    cin >> n >> e;  //01) এগুলো ইউজারের ইনপুট থেকে নেয়া হচ্ছে।


        //02) যদি int ব্যবহার করি, তাহলে সহজেই overflow হয়ে যাবে।
    long long int adj_mat[n+5][n+5];


    //03) Adj-matrix এর সব কয়টি ঘরে infinete করে দিব . আমরা জানি memset ফাংশন int_max এ প্রপারলি কাজ করতে পারে না তাই আমরা for loop ব্যবহার করব
    for(int i=1; i<=n; i++)
    {
        for(int j = 1; j<=n; j++)
        {
            if(i==j)
            {
                adj_mat[i][j] = 0;
            }else{
                adj_mat[i][j]  = LLONG_MAX;
            }
        }
    }


    //04) 👉 যেহেতু গ্রাফ ডিরেক্টেড আর একই a->b এ একাধিক এজ থাকতে পারে, তাই আমরা সর্বনিম্ন কস্ট রাখি।
    while(e--)
    {
        long long  a , b, c;
        cin >> a >> b >> c;

        adj_mat[a][b] = min(adj_mat[a][b], c);

        /* 05 ) লজিক: যদি i -> k এবং k -> j দুটো পথই থাকে, আর i -> k -> j এর কস্ট i -> j এর চেয়ে ছোট হয়, 
        তাহলে adj_mat[i][j] আপডেট করি। 👉 মানে প্রতিটি নোডকে "মধ্যবর্তী স্টেশন" ধরে ছোট রাস্তাগুলো বের করা। 
        
        সবায় k <= n ছোট বা সমান দিতে হবে
        */
        for(int k=1; k<=n; k++)
        {
            for(int i =1; i<=n; i++)
            {
                for(int j=1; j<=n; j++ ){
                    if(adj_mat[i][k] != LLONG_MAX && adj_mat[k][j]  != LLONG_MAX && adj_mat[i][k] + adj_mat[k][j] < adj_mat[i][j])
                    {
                        adj_mat[i][j] = adj_mat[i][k] + adj_mat[k][j];
                    }
                }
            }
        }
    }



    /* 
  👉  q সংখ্যক কুয়েরি আসবে।
👉 প্রতিটি কুয়েরিতে সোর্স s আর ডেস্টিনেশন d দেওয়া থাকবে।
👉 যদি s -> d এর জন্য কোনো পথ না থাকে, তাহলে -1 প্রিন্ট করবে।
👉 অন্যথায় সর্বনিম্ন কস্ট প্রিন্ট করবে।

    */
    int q;
    cin >> q;
    while(q--)
    {
        int s, d;
        cin >> s >> d;

        if(adj_mat[s][d] == LLONG_MAX)
        {
            cout << -1 << endl;
        }else{
            cout << adj_mat[s][d] << endl;
        }
    }





    return 0;
}

//https://www.hackerrank.com/contests/assignment-02-a-introduction-to-algorithms-a-batch-07/challenges/shortest-distance-2
//https://docs.google.com/document/d/1zY_gWiZghgxgD6T_tc1ma-m5RQvk8urO5AbfDDPVkmo/edit?usp=sharing