// double linked list , it always has head and tail , the other element are insert between head and tail
// tail's left element is least frequency element 
// head's right element is most frequency element
// [head]->[a]->...->[z]->[tail] , than the z is the least frequency
// insert new element always head's right element
// insert s => [head]->[s]->[a]->...->[z]->[tail]
class LRUCache {
public:
    class node{
        public:
            int key;
            int value;
            node *next;
            node *prev;
            node (int _key,int _val){
                key = _key;
                value=_val;
            }
    };
    int cap;
        node* head  = new node(-1,-1);
        node* tail  = new node(-1,-1);
    unordered_map<int,node*> mp;
        LRUCache(int capacity) {
        cap=capacity;
        head->next = tail;
        tail->prev = head;    
    }
    void add(node* tmp){
        tmp->next = head->next;
        head->next->prev = tmp;
        tmp->prev = head;
        head->next = tmp;
    }
    void del(node* tmp){
        node* t = tmp;
        tmp->prev->next = t->next;
        tmp->next->prev = t->prev;
    }

int get(int key) {
    if(mp.find(key) != mp.end()){
        node* res = mp[key];
        int value = res->value;  // 保存節點的值
        mp.erase(key);
        del(res);
        // 更新節點的值
        res->value = value;
        add(res);
        mp[key] = head->next;
        return res->value;
    }
    return -1;
}
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            node* res = mp[key];
            mp.erase(key);
            del(res);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            del(tail->prev);
        }
        add(new node(key,value));
        mp[key]=head->next;
    }
};