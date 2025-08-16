#include<bits/stdc++.h>
using namespace std;


int removeElement(vector<int> &nums, int val){
    int k = 0;
    int numberSize = nums.size();

    for(int i=0; i < numberSize; i++){
        if(nums[i] != val){

        /*nums[k] হলো array-এর সেই index যেখানে আমরা non-val element রাখব। 
            শুরুতে k = 0, তাই প্রথম non-val element → যাবে nums[0] তে।*/
            nums[k] = nums[i]; 
            k++; 
        }
    }

    return k; //// non-val এলিমেন্ট সংখ্যা রিটার্ন

}



int main(){
    int n, val;
    cin >> n >> val; // প্রথম লাইনে: array এর সাইজ n, আর মুছে ফেলার মান val


    vector<int> nums(n);
    for(int i =0; i< n; i++){
        cin >> nums[i]; // array ইনপুট নিয়ে নিলাম। 
    }

    int k = removeElement(nums,val);

    cout << k << endl;

    for(int i =0; i<k ; i++){
        cout << nums[i] << " ";
    }


    return 0;
}




/*

একটি ছোট উদাহরণ



nums = [3, 2, 2, 3], val = 3


Step by step:
শুরু: k = 0

i = 0 → nums[0] = 3 → এটা val, তাই বাদ।

i = 1 → nums[1] = 2 → এটা val নয় → বাদ নয়। 
    তাই nums[k] = nums[i] → | nums[2] = nums[2] , আর k=1.

i = 2 → nums[2] = 2 → non-val →
    তাই nums[k] = nums[i] → | nums[2, 2] = nums[2] , আর k=2.

i = 3 → nums[k] = nums[i] → এটা val, তাই বাদ।


শেষে k = 2 → মানে ২ টা non-val element রাখা হয়েছে।
Array-এর প্রথম ২ টা জায়গায় [2, 2] আছে।



input : 
2
3 2 2 3

output: 
2
2 2 


or 
input : 
8 2
0 1 2 2 3 0 4 2

output: 
5
0 1 3 0 4


https://leetcode.com/problems/remove-element/description/

*/