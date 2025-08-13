#include<bits/stdc++.h>
using namespace std;

// 👉 Singly Linked List-এর নোড
class ListNode
{
    public:
    int val; // নোডে রাখা মান
    ListNode* next; // পরের নোডের পয়েন্টার
    
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
};

// 👉 দুটি Sorted Linked List merge করার সমাধান (Recursive)
class Solution
{
    public:
    // list1 এবং list2 উভয়ই ascending sorted ধরে নেওয়া
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {

        if(!list1) return list2;// Base case-1: list1 ফাঁকা হলে list2-ই ফলাফল
        if(!list2) return list1;// Base case-2: list2 ফাঁকা হলে list1-ই ফলাফল

        if(list1->val <= list2->val){ // ছোট মান যেটার, সেটাকেই head হিসাবে নেবো

            // list1 ছোট ⇒ list1 নিয়ে নিলাম, এবার list1->next আর পুরো list2 merge করবো
            list1->next = mergeTwoLists(list1->next, list2); 
            return list1; // list1 এখন merged লিস্টের নতুন head
        }else{

            // list2 ছোট ⇒ list2 নিয়ে নিলাম, এবার পুরো list1 আর list2->next merge করবো
            list2->next = mergeTwoLists(list1, list2->next);
            return list2; // list2 এখন merged লিস্টের নতুন head
        }
    }
};


// 👉 Tail-এ নতুন নোড যোগ করা (Insert at Tail)
void insertAtTail(ListNode* &head, int val)
{
    ListNode* NewNode = new ListNode(val); // নতুন নোড তৈরি

    // লিস্ট ফাঁকা হলে head-এই সেট করো
    if(head == NULL){
        head = NewNode;
        return;
    }
    // নইলে শেষ নোড পর্যন্ত যেতে হবে।
    ListNode* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    // শেষে নতুন নোড অ্যাটাচ করা
    temp->next= NewNode;

}

// 👉 n সংখ্যক ইনপুট পড়ে একটি Linked List বানানো
ListNode* create_list_from_input(int n){
    ListNode* head = NULL;  // শুরুতে লিস্ট ফাঁকা
    for(int i=0; i<n; i++){
        int val;
        cin >> val; // প্রতিটি ভ্যালু ইনপুট
        insertAtTail(head,val); // টেইলে বসিয়ে দাও

    }
    return head; // লিস্টের head রিটার্ন

}

// 👉 Linked List প্রিন্ট করা (স্পেস-সেপারেটেড)
void printList(ListNode* head)
{
    ListNode* temp = head; // ট্রাভার্সের জন্য কার্সর

    while(temp != NULL){
        cout << temp->val << " "; // বর্তমান নোডের মান
       if(temp->next){
        cout << "-> "; // শেষ আইটেম না হলে স্পেস দাও
       }
        temp = temp->next; // পরের নোডে যাব
    }
    

    
}

// 👉 মেইন ফাংশন: ইনপুট নাও, দুই লিস্ট বানাও, merge করো, আউটপুট দাও
int main(){
    int n1, n2;

    // প্রথম লিস্টের সাইজ ও এলিমেন্টস
    cin >> n1;
    ListNode* list1 = create_list_from_input(n1);

     // দ্বিতীয় লিস্টের সাইজ ও এলিমেন্টস
    cin >> n2;
    ListNode* list2 = create_list_from_input(n2);

    // Merge চালানো
    Solution sol;
    ListNode* merged = sol.mergeTwoLists(list1, list2);

    printList(merged);

    return 0;
}



//https://leetcode.com/problems/merge-two-sorted-lists/description/