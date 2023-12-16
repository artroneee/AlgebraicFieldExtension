
vector<int> sum_mnog(vector<int>poly, vector<int>pols) {
		for (int j = 0; j < pols.size() - 1; j++) {
			pols[j] += poly[j];
		}
		return pols;
}
