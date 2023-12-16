
vector<int> mod_pol(int p, vector<int> pols) {
	for (int i = 0; i < pols.size() - 1; i++)
		if (pols[i] >= p)
			pols[i] %= p;
	return pols;
}
