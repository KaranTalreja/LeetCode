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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
      ListNode* prevM = NULL;
      ListNode* currM = head;
      int i = 1;
      ListNode* retval = head;
      for (i = 1; i < m; i++) {
        prevM = currM;
        currM = currM->next;
      }
      ListNode* prev = NULL, *curr = currM, *next = NULL;
      for (i; i <= n ; i++) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }
      currM->next = next;
      if (NULL != prevM) prevM->next = prev;
      else retval = prev;
      return retval;
    }
};
