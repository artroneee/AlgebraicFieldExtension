#include <vector>


using namespace std;
int sum_mnogochlen(int p, vector<int> vec) {
	int sum = 0;
	for (auto i : vec) {
		sum += i;
	}
	if (p % 2 == 0 and sum % 2 == 0)
		return 0;
	else if (p % 2 == 0 and sum % 2 != 0)
		return 1;
	else if (p % 2 != 0 and sum % 2 != 0)
		return 0;
	else
		return 1;

}
