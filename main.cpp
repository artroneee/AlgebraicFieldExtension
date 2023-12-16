#include <cmath>
#include "poly.h"
#include "vector"
#include "iostream"
#include "addGF.h"
using namespace std;

void main_func() {
	cout << "Привет! Это функция для построения расширения поля GF(p)^k\n";
	
	int p, k, choice;
	
	cout << "Введите p: "; cin >> p;
	cout << "Введите k: "; cin >> k; cout << endl;
	cout << "Ваше поле GF(" << p << ")^" << k << " с характеристикой " << p << " и размерностью " << k << " имеет порядок " << pow(p, k) << "\n";

	cout << "Выберите:\n1. Сгенерировать полином автоматически [1]\n2. Ввести свой полином [2]\n";
	cin >> choice;
	vector<int> moduls = {};
	vector<int> polynom = {};
	for (int i = 0; i < p; i++)
		moduls.push_back(i);
	if (choice == 1)
		polynom = generator_pol(p, k, moduls);
	else if (choice == 2) {
		cout << "Внимание!!! Если ваш полином будет некорректным, то он будет автоматически сгенерирован!!!\n";
		cout << "Для того, чтобы закончить ввод, введите в консоль любую букву\n";
		int x;
		while (cin >> x)
			polynom.push_back(x);
		cout << "Ваш полином: ";
		for (int i = 0; i < polynom.size() - 1; i++) {
			if (polynom[i] != 0 and polynom[i] == 1)
				cout << "x^" << k - i << " + ";
			else if (polynom[i] != 0)
				cout << polynom[i] << "x^" << k - i << " + ";

		}
		cout << polynom[k] << endl;
		cout << endl;
		
	}

	vector<vector<int>> result = addGF(p, k, polynom, moduls);

	while (true) {
		if (result.size() == 1) {
			polynom = generator_pol(p, k, moduls);
			result = addGF(p, k, polynom, moduls);
			
		}
		else {
			cout << "Подходящий многочлен для данного поля: ";
			for (int i = 0; i < polynom.size() - 1; i++) {
				if (polynom[i] != 0 and polynom[i] == 1)
					cout << "x^" << k - i << " + ";
				else if (polynom[i] != 0)
					cout << polynom[i] << "x^" << k - i << " + ";

			}
			cout << polynom[k] << endl;
			cout << endl;
			for (int i = 0; i < result.size() - 1; i++) {
				for (int j = 1; j < result[i].size() - 1; j++) 
					cout << result[i][j]; // вывод элементов векторов вектора
				cout << endl;
				
			}
			break;
		}
		
	}
	cout << "Произведение элементов альфа^" << 1 << ": ";
		for (int j = 1; j < result[1].size()-1; j++)
			cout << result[1][j] << ",";
		cout << "и альфа^" << 2 << ": ";
		for (int j = 1; j < result[2].size() - 1; j++)
			cout << result[2][j] << ",";
		cout << " равно: ";
		for (int j = 1; j < result[3].size() - 1; j++)
			cout << result[3][j] << ",";
		cout << endl;
		
		
		cout << "Результат сложения альфа^" << 3 << ": ";
		for (int j = 1; j < result[3].size() - 1; j++)
			cout << result[3][j] << ",";
		cout << " и альфа^" << 4 << ": ";
		for (int j = 1; j < result[4].size() - 1; j++)
			cout << result[4][j] << ",";
		cout << " равен ";
		vector<int> summ = {};
		for (int j = 1; j < result[4].size() - 1; j++) {
			int sum = result[3][j] + result[4][j];
			summ.push_back(sum);
		}
		for (auto i : summ) {
			if (i >= p)
				i%= p;
			cout << i << " ";
		}
		cout << endl;


		cout << "Обратный элемент по умножению для альфа^" << 3 << ": ";
		for (int j = 1; j < result[3].size() - 1; j++)
			cout << result[3][j] << ",";
		cout << " - это альфа^" << pow(p, k) - 1 -3 << ": ";
		for (int j = 1; j < result[pow(p, k) - 1 -3 ].size() - 1; j++)
			cout << result[pow(p, k) - 1 -3][j] << ",";
		cout << " поскольку получилась единица: ";
		for (int j = 1; j < result[pow(p,k)-1].size() - 1; j++)
			cout << result[pow(p, k) - 1][j] << ",";
		cout << endl;
		

		cout << "Обратный элемент по сложению для альфа^" << 3 << ": ";
		for (int j = 1; j < result[3].size() - 1; j++)
			cout << result[3][j] << ",";
		cout << " - это ";
		
		vector<int> pustoy = {};
		for (int i = 0; i < result[0].size(); i++) 
			pustoy.push_back(0);
		vector <int> revers = result[3];
		for(auto element : result){
			if (sum_testmod(element, revers, p) == pustoy) {
				for (int i  =1 ; i <  element.size() -1; i ++)
					cout << element[i] << " ";
				break;
			}
		}

		cout << endl;

}
