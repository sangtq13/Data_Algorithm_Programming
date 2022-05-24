#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
public:
    LRUCache(int capacity){
        cp = capacity;
    }
    void set(int key, int value){
        auto it = mp.find(key);        
        if (it != mp.end()){
            it->second->value = value;
            if (head == it->second) return;
            it->second->prev->next = it->second->next;
            if (it->second == tail){
                tail = tail->prev;
            }
            else {
                it->second->next->prev = it->second->prev; 
            }
            it->second->next = head;
            head->prev = it->second;
            it->second->prev = nullptr;
            head = it->second;
            return;
        }

        Node *n;
        if (mp.size() == cp){
            mp.erase(tail->key);
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        if(mp.empty()){
            n = new Node(key, value);
            tail = n;
        }
        else {
            n = new Node(nullptr, head, key, value);
            head->prev = n;
        }
        head = n;
        mp.insert({key, n});
    }
    
    int get (int key){
        if (mp.find(key) != mp.end()) return mp[key]->value;
        return -1;
    }
};

int main() {
