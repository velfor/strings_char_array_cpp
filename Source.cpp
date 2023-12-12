#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cctype>
#include <windows.h>
using namespace std;
bool isEnglishWord(const char* str) {
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
    char input[100];
    std::cin.getline(input, sizeof(input));

    const size_t maxWordLength = 20;
    const size_t maxWordsNumber = 10;
    char englishWords[maxWordsNumber][maxWordLength] = { '\0', '\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' };
    char otherWords[maxWordsNumber][maxWordLength] = { '\0', '\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' ,'\0' };

    size_t wordIndex = 0;
    

    char* currentWord = strtok(input, " ,.;:-?!");
    while (currentWord != nullptr) {
        if (isEnglishWord(currentWord)) {
            strcpy(englishWords[wordIndex], currentWord);
            
        }
        else {
            strcpy(otherWords[wordIndex], currentWord);
        }
        ++wordIndex;
        currentWord = strtok(nullptr, " ,.;:-?!");
    }
    //сортировка пузырьком массива английских слов
    for (size_t i = 0; i < maxWordsNumber - 1; i++) {
        bool swapped = false;
        for (size_t j = 0; j < maxWordsNumber - i - 1; j++) {
            if (englishWords[j][0] == '\0') { // проверяем, является ли текущий элемент пустой строкой
                continue; // пропускаем пустую строку
            }
            if (strcmp(englishWords[j], englishWords[j + 1]) > 0) {
                char temp[maxWordLength];
                strcpy_s(temp, englishWords[j]);
                strcpy_s(englishWords[j], englishWords[j + 1]);
                strcpy_s(englishWords[j + 1], temp);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    for (int i = 0; i < maxWordsNumber; i++) {
        cout << i << ' ' << englishWords[i] << endl;
    }

    int eIndex = 0;
    int oIndex = 0;
    
    return 0;
}
