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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //val, id of the list
        for(int i=0; i <lists.size(); i++)
        {
            pq.push(make_pair(lists[i]->val, i));
        }
        bool is_root_col = false;
        ListNode* root = nullptr;
        ListNode* prev;
        while(!pq.empty())
        {
            auto [val, id]  = pq.top();
            pq.pop();
            ListNode* node = new ListNode(val);
            lists[id] = lists[id]->next;
            if(lists[id] != nullptr)
            {
                pq.push(make_pair(lists[id]->val, id));
            }
            
            if(!is_root_col)
            {
                root = node;
                is_root_col = true;
            }
            else{
                prev->next = node;
            }
            prev = node;
            
        }
        return root;
    }
};
