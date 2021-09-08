#include<iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(NULL) {}
    ListNode(int x): val(x), next(NULL) {}
    ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
    public:
        ListNode* reverseList(ListNode* head) {
            ListNode* prev = NULL;
            ListNode* cur = head;
            ListNode* n;
            while(cur != NULL) {
                n = cur -> next;
                cur->next = prev;
                prev = cur;
                cur = n;
            }
            return prev;
        }

        void printListNode(ListNode* head) {
            ListNode* cur = head;
            while(cur != NULL) {
                cout << cur->val;
                if(cur->next != NULL)
                    cout << " -> ";
                cur = cur->next;
            }
        }
};

int main () {
    ListNode* a1 = new ListNode (5);
    ListNode* a2 = new ListNode (4, a1);
    ListNode* a3 = new ListNode (3, a2);
    ListNode* a4 = new ListNode (2, a3);
    ListNode* a5 = new ListNode (1, a4);

    Solution obj;
    obj.printListNode(a5);
    ListNode* newHead = obj.reverseList(a5);
    cout << endl;
    obj.printListNode(newHead);

    return 1;
}

//https://leetcode.com/problems/reverse-linked-list/