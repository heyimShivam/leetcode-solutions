/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* cur = head;
        ListNode* lessListHead = new ListNode(0);
        ListNode* lessListTail = lessListHead;
        ListNode* greaterListHead = new ListNode(0);
        ListNode* greaterListTail = greaterListHead;

        while(cur != NULL) {
            if(cur->val < x) {
               lessListTail->next = new ListNode(cur->val);
               lessListTail = lessListTail->next;
            } else {
               greaterListTail->next = new ListNode(cur->val);
               greaterListTail = greaterListTail->next;
            }
            ListNode *temp = cur;
            cur = cur->next;
            delete temp;
        }

        lessListTail->next = greaterListHead->next;

        return lessListHead->next;
    }
};