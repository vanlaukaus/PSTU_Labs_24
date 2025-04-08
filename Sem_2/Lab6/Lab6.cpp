//v15
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

bool wordcheck(const char* word) {
    for (int i = 0; word[i] != '\0'; i++) {
        if (!(('a' <= word[i] && word[i] <= 'z') ||
            ('A' <= word[i] && word[i] <= 'Z') ||
            ('0' <= word[i] && word[i] <= '9'))) {
            return false;
        }
    }
    return true;
}

int main() {
    char s[256];
    char result[256] = { 0 }; 
    cout << "Input your line:\n";
    cin.getline(s, 256);

    char* word = strtok(s, " ");
    bool first_word = true;

    while (word != nullptr) {
        char* dot_ptr = strchr(word, '.');
        if (dot_ptr != nullptr) *dot_ptr = '\0';

        if (strlen(word) > 0 && wordcheck(word)) {
            if (!first_word) {
                strcat(result, " ");
            }
            strcat(result, word);
            first_word = false;
        }

        word = strtok(nullptr, " ");
    }

    strcat(result, ".");

    cout << "Output:\n" << result << endl;

    return 0;
}
