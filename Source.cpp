#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <sstream>

using namespace std;
bool isEnglishWord(string str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
            return false;
        }
    }
    return true;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string input;
    getline(cin, input);

    const size_t maxWordsNumber = 10;
    string englishWords[maxWordsNumber];
    string otherWords[maxWordsNumber];

    //разбиение на слова
    size_t wordIndex = 0;
    stringstream ss(input);
    string token;
    while (getline(ss, token, ' '))
    {
        if (isEnglishWord(token)) {
            englishWords[wordIndex] = token;
        }
        else {
            otherWords[wordIndex] = token;
        }
        wordIndex++;
    }
   
    //сортировка пузырьком по возрастанию
    for (int i = 0; i < maxWordsNumber; i++) { // повторяем для всех слов
        for (int j = 0; j < maxWordsNumber-1-i; j++) { // повторяем для всех слов, кроме отсортированных
            if (englishWords[j].empty()) { // если слово пустое
                continue;//сразу пропускаем, переходим к след слову
            }
            if (!englishWords[j].empty()) { //если слово не пустое
                for (int k = j + 1; k < maxWordsNumber; k++) {//повторяем для всех слов от непустого
                    if (!englishWords[k].empty()) { // ищем еще одно не пустое слово
                        if (englishWords[j] > englishWords[k]) { // если слова стоят неправильно
                            swap(englishWords[j], englishWords[k]); // меняем их местами
                            break;//прерываем цикл по k
                        }
                    }
                }
            }
        }
    }
    /*for (int i = 0; i < wordIndex; i++) {
        cout << englishWords[i] << endl;
    }*/
    //сливаем две строки в одну
    ss.clear();//чистим строковый поток
    for (int i = 0; i < wordIndex; i++) {
        if (englishWords[i].empty())
            ss << otherWords[i] + " ";
        else
            ss << englishWords[i] + " ";
    }
    cout << ss.str();
    return 0;
}