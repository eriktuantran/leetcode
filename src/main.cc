#include <iostream>

#include "0217-contains-duplicate.hh"

using namespace std;

int main() {
  cout << "do stuff" << endl;
  int x = 4;
  cout << x << endl;
  independentMethod(x);
  cout << x << endl;
  vector<int> v = {1, 2, 3, 4, 5};
  Solution s;
  cout << (s.containsDuplicate(v) ? "true" : "false") << endl;
}
