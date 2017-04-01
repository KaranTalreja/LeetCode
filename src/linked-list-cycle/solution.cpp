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
    bool hasCycle(ListNode *head) {
      if (!head) return false;
      ListNode* fast = head->next, *slow = head;
      while (NULL != fast && NULL != slow) {
        if (slow == fast) return true;
        fast = fast->next;
        if (fast != NULL) fast = fast->next;
        slow = slow->next;
      }
      return false;
    }
};
