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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) return nullptr;
        ListNode* node = head;
        int len=0;
        while(node != nullptr)
        {
            len++;
            node = node->next;
        }

        ListNode* root = head;
        bool is_root_col = false;
        int segments = (int)len/k;
        int j =0;
        int i=1;
        ListNode* start = new ListNode(head->val);;
        ListNode* stop = start;
        ListNode* prev = nullptr;
        head = head->next;
        while(head != nullptr && j < segments)
        {
            ListNode* curr = new ListNode(head->val);
            if(i==0)
            {
                prev->next = curr;
                start = curr;
                stop = curr;
            }
            else if(i == k-1)
            {
                i=-1;
                j++;
                curr->next = start;
                if(prev != nullptr) prev->next = curr;
                start = curr;
                prev = stop;
                if(!is_root_col)
                {
                    is_root_col = true;
                    root = start;
                }
            }
            else{
                curr->next = start;
                if(prev != nullptr) prev->next = curr;
                start = curr;
            }
            i++;
            head = head->next;
            
        }
        if(head != nullptr)
        {
            stop->next = head;
        }
        return root;
    }
};
