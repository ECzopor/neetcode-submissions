class LRUCache {
public:
//1) with linked list 
//2) with map? 
    struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;
    };

    LRUCache(int cap) {
        capacity = cap;
        size = 0;
        head = new Node(-2, -2, nullptr, nullptr);
        tail = new Node(-3, -3, nullptr, head);
        head->next = tail;
    }
    
    int get(int k) {
        if(mp.contains(k) == false)return -1;
        Node*n = mp[k];
        n->prev->next = n->next;
        n->next->prev = n->prev;
        Node* c = tail->prev;
        c->next = n;
        n->next = tail;
        n->prev = c;
        tail->prev = n;
        return n->val;
    }
    
    void put(int k, int v) {

        if(mp.contains(k) == true)
        {
            Node* n = mp[k];
            mp.erase(k);
            n->prev->next = n->next;
            n->next->prev = n->prev;
            Node* c = tail->prev;
            c->next = n;
            n->next = tail;
            n->prev = c;
            tail->prev = n;
            n->val =v;
            mp[k] = n;
        }
        else
        {
            Node* n = new Node(k,v,nullptr, nullptr);
            mp[k] = n;
            Node* c = tail->prev;
            c->next = n;
            n->next = tail;
            n->prev = c;
            tail->prev = n;
            if(size == capacity)
            {
                Node* temp = head->next;
                head->next = temp->next;
                temp->next->prev = head;
                mp.erase(temp->key);
                delete temp;
            }
            else size++;
        }

    }

private:
    int capacity;
    int size;
    Node* head;
    Node* tail;
    std::unordered_map<int, Node*> mp;
};
