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
    int getLength (ListNode* head) {
      int retval = 0;
      while (head) {
        retval++;
        head = head->next;
      }
      return retval;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      int lenA = getLength(headA);
      int lenB = getLength(headB);
      if (lenA > lenB) {
        for (int i = 0; i < lenA-lenB; i++) {
          headA=headA->next;
        }
      } else {
        for (int i = 0; i < lenB-lenA; i++) {
          headB=headB->next;
        }
      }
      ListNode* retval = NULL;
      if (headA == headB) { retval = headA; return retval;} 
      while (NULL != headA && NULL != headB) {
        if (headA->next == headB->next) {
          retval = headA->next;
          break;
        }
        headA = headA->next;
        headB = headB->next;
      }
      return retval;
    }
};
