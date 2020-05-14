#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
  vector<int> arguments(argv, argv + argc);

  vector<int> vec{1, 2, 3, 4, 51, 49};
  for (int i = 1; i <= 6; ++i) {
    vec.push_back(arguments.at(i));
  }
  if(vec.size() < 1 || vec.size() > 6){
    cout << "error" << endl;
    exit(1);
  }
  // calculate the greatest number
  int max = vec.at(0);
  for (int i = 0; i < vec.size(); ++i) {
    if (vec.at(i) > max) {
      max = vec.at(i);
    }
  }
  if (max > 50) {
    cout << "max = " << max << " bippity" << endl;
  } else {
    cout << "max = " << max << endl;
  }
  // calculate the sum
  int sum = 0;
  for (int j = 0; j < vec.size(); ++j) {
    sum += vec.at(j);
  }

  if (sum > 10 && sum < 50) {
    cout << "sum = " << sum << endl;
  }
  else if (sum > 50) {
    cout << "sum = " << sum << " bippity" << endl;
  }
//calculate
int last = vec.back();
for (int k = 0; k < vec.size() - 1; ++k) {
  if(last == vec.at(k)){
    cout << "boo" << endl;
  }

}
  return 0;
}
