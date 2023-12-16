int last_1(vector<vector<int>> vec) {
	for (int i = 1; i < vec.size() - 2; i++) {
		vector<int> a = vec[vec.size() - 2];
		if (vec[i] == vec[vec.size() - 2])
			return false;
	}
	return true;
}
