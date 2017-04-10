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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
      ListNode* start1 = l1;
      ListNode* start2 = l2;
      if (NULL == start1) return start2;
      else if (NULL == start2) return start1;
      ListNode* retval = NULL;
      if (l1->val < l2->val) {
        retval = l1;
        start1 = l1->next;
      }
      else {
        retval = l2;
        start2 = l2->next;        
      }
      ListNode* currNode = retval;
      while (NULL != start1 && NULL != start2) {
        if (start1->val < start2->val) {
          currNode->next = start1;
          start1 = start1->next;
        }
        else {
          currNode->next = start2;
          start2 = start2->next;
        }
        currNode = currNode->next;
      }
      if (start2 == NULL) currNode->next = start1;
      else if (start1 == NULL) currNode->next = start2;
      return retval;
    }
};
