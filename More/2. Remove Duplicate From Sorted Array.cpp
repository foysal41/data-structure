#include<bits/stdc++.h> 
using namespace std;     


class Solution
{
    public:
        int removeDuplicate(vector<int>& nums){  // 🔹 ফাংশন: sorted array থেকে duplicate মুছবে (in-place)
            int n = (int)nums.size();            // 🔹 nums এর সাইজ বের করলাম
            if(n  == 0) return 0;                 // 🔹 সেফটি চেক: অ্যারে ফাঁকা হলে 0 রিটার্ন করব (constraint এ না থাকলেও ভালো অভ্যাস)

            int i = 0;                            // 🔹 slow pointer (শুরুতে প্রথম উপাদান unique ধরে)
            for(int j = 1; j < n; j++){            // 🔹 fast pointer (১ থেকে শুরু, কারণ ০-তে i আছে)
                if(nums[j] != nums[i]){            // 🔹 নতুন unique element পেলেই...
                    i++;                           //    slow pointer এর অবস্থান ১ ধাপ এগিয়ে দাও
                    nums[i] = nums[j];             //    সেই জায়গায় নতুন unique element বসাও
                    // ⚠ এখানে nums[i] = nums[j] মানে j index এর মান i index এ কপি হয়।
                    //    মানে array-এর শুরুতে unique গুলো জমা হচ্ছে।
                }
            }
            return i + 1;                          // 🔹 unique element সংখ্যা = শেষ unique index + 1
            // ⚠ আগে এখানে return n + 1 লিখেছিলে, যেটা ভুল ছিল।
        }
};

int main(){
    int n;
    cin >> n;                                     // 🔹 অ্যারের সাইজ ইনপুট নিচ্ছি
    vector<int> nums(n);                          // 🔹 সাইজ n দিয়ে ভেক্টর বানালাম

    for(int i = 0; i < n; i++){                   // 🔹 nums এর প্রতিটা ভ্যালু ইনপুট নিচ্ছি
        cin >> nums[i];
    }

    Solution sol;                                 // 🔹 Solution অবজেক্ট তৈরি
    int k = sol.removeDuplicate(nums);            // 🔹 removeDuplicate ফাংশন কল করলাম, unique element count পেতে

    cout << k << "\n";                            // 🔹 unique element সংখ্যা প্রিন্ট করলাম
    for(int i = 0; i < k; i++){                   // 🔹 প্রথম k টা element প্রিন্ট করব (কারণ unique গুলো প্রথম k পজিশনে আছে)
        cout << nums[i] << (i + 1 == k ? '\n' : ' '); // 🔹 শেষের পরে স্পেস না দিয়ে newline দিচ্ছি
    }

    return 0;                                     // 🔹 প্রোগ্রাম শেষ
}


//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
//https://docs.google.com/document/d/1VZ-4tZwh64t_eTPMkVvcgxQYDd1eIxKKkuhqfA__9K8/edit?pli=1&tab=t.0