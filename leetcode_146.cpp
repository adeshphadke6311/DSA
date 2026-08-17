#include <iostream>
#include <unordered_map>
using namespace std;


class LRUCache {
    //Time Complexity   :   O(Number of Operations);
    //Space Complexity  :   O(capacity)
public:
    class Node{
        public:

        int key, val;
        Node* prev;
        Node* next;

        Node(int key, int val){
            this->key = key;
            this->val = val;
            prev = next = nullptr;
        }
    };

    //Deletion of Node;

    void delNode(Node* oldNode){ //O(1)
        Node* oldNext = oldNode->next;
        Node* oldPrev = oldNode->prev;

        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
    }

    //Addition of Node at head->next

    void addNode(Node* newNode){ //O(1)
        Node* oldNext = head->next;

        head->next = newNode;
        oldNext->prev = newNode;

        newNode->prev = head;
        newNode->next = oldNext;
    }

    int limit;
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;   
    }
    
    int get(int key) { //O(1)
        if(m.find(key) == m.end()) return -1;

        Node* ansNode = m[key];
        int ans = ansNode->val;
        
        m.erase(key);
        delNode(ansNode);

        addNode(ansNode);
        m[key] = ansNode;

        return ans;

        
    }
    
    void put(int key, int val) { // O(1)
        //Case I : If key already exists

        if(m.find(key) != m.end()){
            Node* oldNode = m[key];
            m.erase(key);
            delNode(oldNode);
        }

        //Case II : If capacity reaches

        if(m.size() == limit){
            m.erase(tail->prev->key);
            delNode(tail->prev);
        }

        //Insertion of Node

        Node* newNode = new Node(key, val);
        addNode(newNode);
        m[key] = newNode;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


 int main(){
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // cache is {1=1}
    lRUCache.put(2, 2); // cache is {1=1, 2=2}
    cout<<lRUCache.get(1)<<endl;    // return 1
    lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.get(2);    // returns -1 (not found)
    lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    lRUCache.get(1);    // return -1 (not found)
    lRUCache.get(3);    // return 3
    lRUCache.get(4);    // return 4
    return 0;
 }