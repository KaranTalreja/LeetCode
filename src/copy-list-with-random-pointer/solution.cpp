#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
  public:
    RandomListNode* deepCopy (RandomListNode*& node, map<RandomListNode*, RandomListNode*>& mappings) {
      if (node == NULL) return NULL;
      map<RandomListNode*, RandomListNode*>::iterator itr;
      itr = mappings.find(node);
      RandomListNode* retval;
      if (itr == mappings.end()) {
        retval = new RandomListNode(*node);
        mappings[node] = retval;
      } else {
        retval = mappings[node];
      }
      return retval;
    }

    RandomListNode *copyRandomList(RandomListNode *head) {
      if (NULL == head) return NULL;
      map<RandomListNode*, RandomListNode*> mappings;
      RandomListNode* currNode = head;
      RandomListNode* currNodeCpy = NULL;
      while (NULL != currNode) {
        currNodeCpy = deepCopy(currNode, mappings);
        currNodeCpy->next = deepCopy(currNode->next, mappings);
        currNodeCpy->random = deepCopy(currNode->random, mappings);
        currNode = currNode->next;
      }
      return mappings[head];
    }
};

int main() {
  Solution s;
  RandomListNode* head = new RandomListNode(1);
  s.copyRandomList(head);
}
