#include <queue>
#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <memory>
#include <functional>
#include <cstring>   
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	string total, s;
	cin >> total >> s;
	vector<int> alpha(26, 0);
	for (int i = 0; i < (int)total.size(); ++i)
		alpha[total[i] - 'a'] = i;
	int prevIndex = -1, cnt = 0;
	for (auto a : s) {
		if (alpha[a-'a'] <= prevIndex)
			cnt++;
		prevIndex = alpha[a - 'a'];
	}
	int res = cnt * 26 + alpha[s.back() - 'a'] + 1;
	cout << res - s.size();
	return 0;
}
