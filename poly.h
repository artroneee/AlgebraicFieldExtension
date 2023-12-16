#include <iostream>
#include <random>
#include <vector>
#include <cmath>
#include <cstdlib>
#include "mnogochlen.h"
using namespace std;

vector<int> generator_pol(int p, int k, vector<int> moduls) {
    srand(time(NULL));
    while (true) {
        std::vector<int> polynom;
        for (int i = 0; i < k + 1; i++) {
            polynom.push_back(rand() % p);
            if (polynom[0] == 0)
                polynom[0] = 1;
        }
        if (!sum_mnogochlen(p, polynom))
            continue;
        else {

            int global_count = 0;
            for (auto i : moduls) {
                int temp = 0;
                int j;

                for (j = 0; j < k; j++) {
                    if (polynom[j] != 0) {
                        temp += i * pow(polynom[j],k);
                        if (temp >= p) {
                            temp %= p;
                        }
                    }
                }
                if (j == k) {
                    temp += pow(polynom[j], k);
                    
                }

                if (temp != 0) {
                    global_count += 1;
                }
                if (global_count == p) {
                    return polynom;
                }

                temp = 0;
            }
        }
    }
}
