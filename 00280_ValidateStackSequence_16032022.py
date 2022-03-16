from collections import deque

class Solution: 
  def validateStackSequences(self, pushed, popped):
    stack, i, n = deque(), 0, len(pushed);

    for p in pushed:
      stack.append(p);

      while stack and stack[-1] == popped[i]:
        stack.pop();
        i += 1;

    return not stack;

#https://leetcode.com/problems/validate-stack-sequences/

