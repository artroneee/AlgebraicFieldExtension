vector<int> shiftleft(vector<int>& vec) {
    vector<int> shiftedRow = vec;

    // Переносим элементы на 1 влево
    for (size_t i = 0; i < shiftedRow.size() - 1; ++i) { 
        shiftedRow[i] = shiftedRow[i + 1];
    }

    // Заполняем последний элемент нулем
    shiftedRow.back() = 0;

    return shiftedRow;
}
