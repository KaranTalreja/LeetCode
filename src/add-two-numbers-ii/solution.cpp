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
    int length (ListNode* l1) {
      int retval = 0;
      while (l1) {
        retval++;
        l1 = l1->next;
      }
      return retval;
    }

    void addLists(ListNode* curr1, ListNode* curr2, int& carry) {
      if (NULL != curr1 && NULL != curr2) {
        addLists(curr1->next, curr2->next, carry);
      }
      if (curr1 == NULL || curr2 == NULL) return;
      curr1->val = curr1->val + curr2->val + carry;
      if (curr1->val >= 10) {
        carry = curr1->val / 10;
        curr1->val = curr1->val % 10;
      } else carry = 0;
    }

    void addCarry(ListNode* curr, int at, int& carry) {
      if (at >= 0) addCarry(curr->next, at-1, carry);
      else return;
      curr->val += carry;
      if (curr->val >= 10) {
        carry = curr->val / 10;
        curr->val = curr->val % 10;
      } else carry = 0;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int len1 = length(l1);
      int len2 = length(l2);
      if (len1 < len2) {
        ListNode* temp = l1;
        l1 = l2;
        l2 = temp;
        int tempL = len1;
        len1 = len2;
        len2 = tempL;
      }
      ListNode* curr1 = l1;
      ListNode* curr2 = l2;
      if (len1 > len2) {
        for (int i = len2; i < len1; i++) curr1 = curr1->next;
      } else {
        for (int i = len1; i < len2; i++) curr2 = curr2->next;
      }
      int carry = 0;
      addLists(curr1, curr2, carry);
      if (0 != carry) {
        if (len1 == len2) {
          ListNode* temp = new ListNode(carry);
          temp->next = l1;
          l1 = temp;
        }
        else if (len1 > len2) {
          addCarry(l1, len1-len2-1, carry);
          if (0 != carry) {
            ListNode* temp = new ListNode(carry);
            temp->next = l1;
            l1 = temp;
          }
        } else {
          addCarry(l2, len2-len1-1, carry);
          if (0 != carry) {
            ListNode* temp = new ListNode(carry);
            temp->next = l2;
            l1 = temp;
          }
        }
      }
      return l1;
    }
};
