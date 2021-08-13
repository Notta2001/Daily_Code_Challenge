#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(NULL) {};
    ListNode(int x) : val(x), next(NULL) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
            ListNode* result = new ListNode(0, NULL);
            ListNode* head = result;

            while (l1 != nullptr && l2 != nullptr) {
                if (l1->val < l2->val) {
                    head->next = l1;
                    l1 = l1->next;
                }
                else {
                    head->next = l2;
                    l2 = l2->next;
                }

                head = head->next;
            }

            if (l1) {
                head->next = l1;
            }
            else if (l2) {
                head->next = l2;
            }

            return result->next;
        }

        void printListNode(ListNode* head, string name) {
            cout << name << " : ";
            ListNode* cur = head;
            while(cur != NULL) {
                if(cur->next != NULL)
                    cout << cur->val << " -> ";
                else 
                    cout << cur->val << endl;
                cur = cur->next;
            }
        }
};

int main () {
    ListNode* a1 = new ListNode(4, NULL);
    ListNode* a2 = new ListNode(2, a1);
    ListNode* a3 = new ListNode(1, a2);

    ListNode* a4 = new ListNode(4, NULL);
    ListNode* a5 = new ListNode(3, a4);
    ListNode* a6 = new ListNode(1, a5);

    Solution obj;
    obj.printListNode(a3, "First  ");
    obj.printListNode(a6, "Second");
    ListNode* res = obj.mergeTwoLists(a3, a6);
    obj.printListNode(res, "Result");

    return 1; 
}

//https://leetcode.com/problems/merge-two-sorted-lists/