#define _CRT_SECURE_NO_WARNINGS
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
    getline(cin,input);

    const size_t maxWordsNumber = 10;
    string englishWords[maxWordsNumber];
    string otherWords[maxWordsNumber];

    //разбиение на слова
    size_t wordIndex = 0;
    stringstream ss(input);
    string token;
    while (std::getline(ss, token, ' ') || std::getline(ss, token, ',') 
        || std::getline(ss, token, '!') || std::getline(ss, token, '?')) 
    {
        if (isEnglishWord(token)) {
            englishWords[wordIndex] = token;
        }
        else {
            otherWords[wordIndex] = token;
        }
        wordIndex++;
    }
    //сортировка 
    
    
    for (int i = 0; i < maxWordsNumber; i++) {
        cout << i << ' ' << englishWords[i] << endl;
    }
    for (int i = 0; i < maxWordsNumber; i++) {
        cout << i << ' ' << otherWords[i] << endl;
    }


    int eIndex = 0;
    int oIndex = 0;

    return 0;
}