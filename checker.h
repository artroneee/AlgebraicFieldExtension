int checker(vector<int> last) {
	int sum = 0;
	for (auto i : last)
		sum += i;
	if (sum == 1 and last[last.size() - 2] == 1)
		return 1;
	else
		return 0;
}
