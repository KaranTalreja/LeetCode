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
    ListNode* swapPairs(ListNode* head) {
      ListNode* prev = NULL;
      if (!head) return NULL;
      ListNode* pairA = head, *pairB = head->next;
      if (!pairB) return pairA;
      ListNode* next = NULL;
      ListNode* retval = pairB;
      int i = 0;
      while (NULL != pairA && NULL != pairB) {
        next = pairB->next;
        pairB->next = pairA;
        pairA->next = next;
        if (NULL != prev) prev->next = pairB;
        prev = pairA;
        pairA = next;
        if (NULL != pairA) pairB = pairA->next;
      }
      return retval;
    }
};
