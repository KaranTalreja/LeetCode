/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 //capacity  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/
class LRUCache {
  public:
    list<pair<int,int>> dQ;
    map<int,list<pair<int,int>>::iterator> hash;
    map<int,list<pair<int,int>>::iterator>::iterator itr;
    int m_capacity;
    LRUCache(int capacity) {
      m_capacity = capacity;
    }

    int get(int key) {
      // cout << "get " << key <<endl;
      itr = hash.find(key);
      int retval = -1;
      if (itr != hash.end()) {
        retval = itr->second->second;
        dQ.push_front(*(itr->second));
        dQ.erase(itr->second);
        hash[key] = dQ.begin();
      }
      //assert(dQ.size() == hash.size());
      return retval;
    }

    void put(int key, int value) {
      // cout << "put " << key << " "<< value;
      itr = hash.find(key);
      if (itr != hash.end()) {
        // cout << " found" << endl;
        itr->second->second = value;
        dQ.push_front(*(itr->second));
        dQ.erase((itr->second));
        hash[key] = dQ.begin();
      } else {
        pair <int,int> curr(key, value);
        if (dQ.size() == m_capacity) {
          // cout << " not found, evicted " << dQ.size() << " ";
          int LRUkey = dQ.back().first;
          itr = hash.find(LRUkey);
          // cout << LRUkey << endl;
          hash.erase(itr);
          // cout << dQ.size() << endl;
          dQ.pop_back();
          dQ.push_front(curr);
          hash[key] = dQ.begin();
        } else {
          // cout << " not found, not evicted" << endl;
          dQ.push_front(curr);
          hash[key] = dQ.begin();
        }
      }
      //assert(dQ.size() == hash.size());
    }
};
