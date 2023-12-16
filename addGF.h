#include <vector>
#include "GFpKElement.h"
#include "multiplyGF.h"
#include "iostream"
#include "sum_mnog.h"
#include "mod_pol.h"
#include "multiplye.h"
#include "checker.h"
#include "last_1.h"
#include "sum_testmod.h"
using namespace std;

vector<vector<int>> addGF(int p, int k, vector<int> poly, vector<int> moduls) {
    poly.push_back(0); 
    vector<vector<int>> pols(pow(p,k)+1, vector<int>(k+2, 0)); // тут +2 лишних, но нужен для того, чтобы не выходить из размера массива. 
    int raznost = k;
    pols[1][k-1] = 1; // образующий элемент x
    
    for (int i = 0; i < pols.size(); i++)
        pols[i][k+1] = 0; 

    
    for (int i = 1; i < pols.size() - 1; i++) {
        std::vector<int> temp = shiftleft(pols[i]);
        pols[i + 1] = temp;
        while (pols[i+1][0] != 0) {
            pols[i+1] = sum_mnog(poly, pols[i+1]);
            for (auto j : pols[i+1]) {
                if (j >= p)  
                    pols[i+1] = mod_pol(p, pols[i+1]);
            }
        }
        
    }
    int sizee = pow(p, k) - 1;
    if (!checker(pols[sizee]) or !last_1(pols)) {
        
        return { {0} };

    }
    else {
        
        return pols;
    }
        
    
}
