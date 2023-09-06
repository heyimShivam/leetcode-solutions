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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        ListNode *temp = head;
        
        int count = 0;
        while(temp != NULL) {
          count++;
          temp = temp->next;
        }
        
        temp = head;

        if(count / k == 0) {
          int i = 0;

          while(temp != NULL) {
            ans[i] = temp;
            ListNode *box = temp;
            temp = temp->next;
            box->next = NULL;
            i++;
          }
        } else {
          int i = 0;
          
          while(temp != NULL) {
            ans[i] = temp;
            int loop  = count/k;
            if(count%k != 0) loop++;
            
            while(loop - 1) {
              temp = temp->next;
              loop--;
            }

            ListNode *box = temp;
            temp = temp->next;
            box->next = NULL;

            if(count%k != 0)  count--;
            i++;
          }
        }

        return ans;
    }
};