class Solution {
  public:
    int length(ListNode* l) {
      int count = 0;
      while(l) {
        count++;
        l = l->next;
      }
      return count;
    }

    ListNode *getIntersectionNode(ListNode *l1, ListNode *l2) {
      int sizeA = length(l1);
      int sizeB = length(l2);
      if (!sizeA || !sizeB) return NULL;

      ListNode* smaller, *larger;
      smaller = sizeA < sizeB ? l1 : l2;
      larger = sizeA < sizeB ? l2 : l1;
      int smSize = sizeA < sizeB ? sizeA : sizeB;
      int lgSize = sizeA < sizeB ? sizeB : sizeA;
      for (int i = 0; i < lgSize - smSize; i++) {
        larger = larger->next;
      }
      while (smaller && larger && smaller != larger) {
        smaller = smaller->next;
        larger = larger->next;
      }
      return smaller;
    }
};
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
