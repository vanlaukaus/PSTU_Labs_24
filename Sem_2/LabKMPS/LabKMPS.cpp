#include <iostream>
#include <vector>
#include <string>
#include <random>

std::vector<int> clps(const std::string& pattern) {
    int n = pattern.length();
    std::vector<int> lps(n, 0);
    int len = 0;
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}


void kmps(const std::string& text, const std::string& pattern) {
    int m = pattern.length();
    int n = text.length();
    bool found = false;

    std::vector<int> lps = clps(pattern);

    int i = 0;
    int j = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            std::cout << "Pattern found at index " << i - j << std::endl;
            j = lps[j - 1];
            found = true;
        }
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    if (!found) {
        std::cout << "Pattern not found in the text." << std::endl;
    }
}

std::string strgen(int length, const std::string& chars) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, chars.size() - 1);

    std::string result;
    for (int i = 0; i < length; ++i) {
        result += chars[distr(gen)];
    }
    return result;
}

int main() {
    std::string characters = "QWERTYUIOPASDFGHJKLZXCVBNM";
    std::string text = strgen(1000, characters);

    std::cout << "Generated text: " << text << std::endl;

    std::string pattern;
    std::cout << "Enter the pattern to search for: ";
    std::cin >> pattern;

    for (char c : pattern) {
        if (characters.find(c) == std::string::npos) {
            std::cout << "Error: invalid characters found. Only A-Z are allowed." << std::endl;
            return 1;
        }
    }

    std::cout << "Searching for pattern: " << pattern << std::endl;

    kmps(text, pattern);

    return 0;
}