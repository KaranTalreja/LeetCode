/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    bool static comp (ListNode* a, ListNode* b) {
      return a->val > b->val ? true : false;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      int k = lists.size();
      ListNode* retval = NULL;
      if(!k) return retval;
      vector<ListNode*> heap;
      for (int i = 0; i < k; i++) {
        if (lists[i]) heap.push_back(lists[i]);
      }
      if (heap.empty()) return retval;
      std::make_heap(heap.begin(), heap.end(), comp);
      std::pop_heap(heap.begin(), heap.end(), comp);
      ListNode* smallest = heap.back();
      heap.pop_back();
      retval = smallest;
      if (smallest->next) {
        heap.push_back(smallest->next);
        std::push_heap(heap.begin(), heap.end(), comp);
      }
      ListNode* curr = retval;
      while (!heap.empty()) {
        std::pop_heap(heap.begin(), heap.end(), comp);
        smallest = heap.back();
        heap.pop_back();
        curr->next = smallest;
        if (smallest->next) {
          heap.push_back(smallest->next);
          std::push_heap(heap.begin(), heap.end(), comp);
        }
        curr = smallest;
      }
      return retval;
    }
};

class Solution {
  public:
    bool operator() (const pair<int,ListNode*>& a, const pair<int,ListNode*>& b) const {
      if (a.first > b.first) return true;
      return false;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, Solution> heap;
      pair<int, ListNode*> temp;
      for (auto l : lists) {
        if(!l) continue;
        temp.first = l->val;
        temp.second = l;
        heap.push(temp);
      }
      ListNode* head = NULL;
      ListNode* curr = NULL;
      while (!heap.empty()) {
        auto rc = heap.top();
        if (head == NULL) {
          head = rc.second;
          curr = head;
        } else {
          curr->next = rc.second;
          curr = curr->next;
        }
        if (rc.second->next) {
          temp.first = rc.second->next->val;
          temp.second = rc.second->next;
          heap.push(temp);
        }
        heap.pop();
      }
      return head;
    }
};
