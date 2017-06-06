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
    ListNode* rotateRight(ListNode* head, int k) {
      if (NULL == head) return NULL;
      if (0 == k) return head;
      int n = 1;
      ListNode* curr = head;
      while (curr->next) {
        curr = curr->next;
        n++;
      }
      // curr will be the last node. Make it a circular list now.
      curr->next = head;
      // Start again from head.
      curr = head;
      // The following loop depends on k being smaller than n. So modulo operation.
      k %= n;
      /* To find the kth node from end
         From start it would be n-k th node.
         Since to go to 2nd node it takes one iteration.
         to go to n-kth node it'll take n-k-1 iterations.
         Since we require the set the n-k-1 th node next to NULL,we run the loop n-k-2 times.
         >= implies a-b iteration for (i = a; i >= b)
         > implies a -b -1 iterations
         we need n-k -2 iterations since a = n; a-b-1 = n-k-2; k+2 = b+1; b = k + 1
       */
      for (int i = n; i > k + 1; i--) {
        curr = curr->next;
      }
      head = curr->next;
      curr->next = NULL;
      return head;
    }
};
