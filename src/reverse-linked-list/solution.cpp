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
    ListNode* reverseList(ListNode* head) {
      ListNode* prev = NULL;
      ListNode* current = head;
      ListNode* next = NULL;
      while (NULL != current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;            
      }
      return prev;
    }
};
