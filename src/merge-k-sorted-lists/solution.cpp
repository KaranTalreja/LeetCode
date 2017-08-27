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
