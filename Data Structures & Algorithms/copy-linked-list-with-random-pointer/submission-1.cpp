/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head ==NULL)return head;
        unordered_map<Node*, Node*> mapa;
        
        Node*node = head->next;//for parsing the og
        Node*head_cp = new Node(head->val);//bc we need a head as a return
        Node*node_cp = head_cp; //this is what will be moving
        mapa[head]=head_cp;
        while(node != nullptr)
        {
            Node* temp = new Node(node->val); //dynamic alloaction so now worries that the temp will die before we want to
            node_cp->next = temp; //link node_cp and temp
            node_cp = node_cp->next; //move the list forward
            mapa[node] = node_cp;
            node=node->next; //move the og forward
        }
        
        node = head;
        node_cp = head_cp;
        Node* ran;
        while(node !=NULL)
        {
            ran = node->random;
            node_cp->random = mapa[ran];
            node=node->next;
            node_cp = node_cp->next;
        }
        return head_cp;
    }
};
