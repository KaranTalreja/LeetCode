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
    int length(ListNode* head) {
      int retval = 0;
      while (head) {
        head = head->next;
        retval++;
      }
      return retval;
    }

    void reverseGroup(ListNode*& head, int& k, int size) {
      if (size < k) return;
      ListNode* curr = head;
      ListNode* prev = NULL, *next = NULL;
      for (int i = 0; i < k; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }
      reverseGroup(next, k, size-k);
      head->next = next;
      head = prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
      int size = length(head);
      reverseGroup(head, k, size);
      return head;
    }
};
