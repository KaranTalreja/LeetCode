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
    void helper(ListNode* l1, ListNode* l2, ListNode*& currSum) {
      if (l1 && l2) {
        int sum = l1->val + l2->val;
        if (l1->next || l2->next || currSum->val + sum >= 10)
          currSum->next = new ListNode(0);
        if (sum + currSum->val< 10) currSum->val += sum;
        else {
          currSum->val += sum;
          currSum->next->val = currSum->val / 10;
          currSum->val %= 10;
        }
        if (l1->next || l2->next)
          helper(l1->next, l2->next, currSum->next);
      } else if (l2 != NULL) {
        int sum = currSum->val;
        if (l2->next || l2->val + sum >= 10) {
          currSum->next = new ListNode(0);
        }
        currSum->val += l2->val;
        if (currSum->next) {
          currSum->next->val = currSum->val/10;
          currSum->val %= 10;
        }
        if (l2->next)   helper(l1, l2->next, currSum->next);

      } else if (l1 != NULL) {
        int sum = currSum->val;
        if (l1->next || l1->val + sum >= 10) {
          currSum->next = new ListNode(0);
        }
        currSum->val += l1->val;
        if (currSum->next) {
          currSum->next->val = currSum->val/10;
          currSum->val %= 10;
        }
        if (l1->next)   helper(l1->next, l2, currSum->next);
      }
      return;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      ListNode* retval = new ListNode(0);
      helper(l1,l2,retval);
      return retval;
    }
};
