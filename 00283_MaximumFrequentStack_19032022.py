from collections import defaultdict

from sklearn.cluster import k_means

class FreqStack: 
  def __init__ (self):
    self.stack = [];
    self.freq = defaultdict(int);

  def push(self, val: int) -> None:
    self.freq[val] += 1;
    if self.freq[val] > len(self.stack):
      self.stack.append([val]);
    else:
      self.stack[self.freq[val] - 1].append(val);
  
  def pop(self) -> int:
    while not self.stack[-1]:
      self.stack.pop();
    val = self.stack[-1].pop();
    self.freq[val] -= 1;
    return val;
