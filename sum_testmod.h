vector<int> sum_testmod(vector<int> poly, vector<int> chlen, int p) {
    vector <int> temp = {};
    for (int i = 0; i < chlen.size(); i++)
        temp.push_back((chlen[i] + poly[i]) % p);
    return temp;
    
}
