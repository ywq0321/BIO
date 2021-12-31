#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int rec[100], result[100], n, cnt = 0;
vector<int> output;
string prefix;

int ifValid (vector<int> data) {
	int i, j;
	int len = data.size(), longest;
	vector<int> maxLens;
	maxLens.push_back(1);

	for (i = 1; i < len; i++){
		longest = 1;
		for (j = 0; j < i; j++){
			if ((data[i] > data[j]) and (maxLens[j]+1 > longest)){
				longest = maxLens[j] + 1;
			}
		}
		if (longest == 3) return 0;
		maxLens.push_back(longest);
	}
	return 1;
}

void dfs(int step){
    int i;
    if (step == n+1){
      output.clear();
      for (i = 0; i < prefix.length(); i++)
        output.push_back(prefix[i]-64);
      for (i = 1; i <= n; i++){
        output.push_back(result[i]);
      }
      for (auto i = output.begin(); i != output.end(); i++)
        cout << *i << " ";
      cout << endl;
      if (ifValid(output) == 1) cnt += 1;
      return;
    }

    for (i = 1; i <= n; i++){
        if (rec[i] == 0){
            result[step] = i;
            rec[i] = 1;
            dfs(step + 1);
            rec[i] = 0;
        }
    }
    return;
}

void print(vector<int> ary){
  for (auto j = ary.begin(); j != ary.end(); j++){
    cout << *j << " ";
  }
  cout << endl;
}

int main() {
	cin >> n >> prefix;
  n -= prefix.length();
	dfs(1);
	cout << cnt;
  return 0;
}
