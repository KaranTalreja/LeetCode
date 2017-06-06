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
    bool isPalindrome(ListNode* head) {
      // O(N) time and O(1) space
      if (NULL == head || NULL == head->next) return true;
      ListNode* slow = head;
      ListNode* fast = head->next;
      int s = 1,f = 2;
      ListNode* prev = NULL;
      while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
        s++;
        f+=2;
      }
      if (NULL == fast) f--;
      // invariant f/2 <= s
      // invariant slow is pointing to node just before the right image starts
      // if s*2 > f ; Length of list is Odd;
      // If odd, the prev pointer list when reversed should exactly be equal to list starting from slow->next;
      // If even, the slow pointer list when reversed should exactly be equal to list starting from slow->next;
      ListNode* headL = NULL;
      ListNode* headR = slow->next;

      if (s*2 > f) prev->next = NULL;
      else slow->next = NULL;

      ListNode* prevL = NULL,* currL = head, *nextL = NULL;
      while (currL) {
        nextL = currL->next;
        currL->next = prevL;
        prevL = currL;
        currL = nextL;
      }
      headL = prevL;
      for(; headL != NULL && headR != NULL;) {
        if (headL->val == headR->val) {
          headL = headL->next;
          headR = headR->next;
        } else return false;
      }
      if (NULL != headL || NULL != headR) return false;
      return true;
    }
};
