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
    ListNode* oddEvenList(ListNode* head) {
      if (NULL == head) return NULL;
      ListNode* headO = head;
      ListNode* headE = head->next;
      ListNode* currO = headO;
      ListNode* currE = headE;
      while (currE && currE->next) {
        currO->next = currE->next;
        currO = currO->next;
        currE->next = currE->next->next;
        currE = currE->next;
      }
      currO->next = headE;
      return headO;
    }
};
