// Функция для проверки чередования гласных и согласных
#include "Trie_Tree.h"
#include <Windows.h>
#include <string>
// Функция для проверки чередования гласных и согласных

const std::string gl = "eyuioa";

// Функция для печати слов с чередующимися гласными и согласными
bool is_glas(char c) {
    return gl.find(c) != std::string::npos;
}

void print_alternating_words(ttree::ptrNODE t, std::string word) {
    if (t->eow) {
        std::cout << word << std::endl;
    }

    for (int i = 0; i < 26; i++) 
        if (t->ptrs[i] && ( (word.length() < 2) || is_glas(char(i + 'a')) != is_glas(word[word.length() - 1]) ))
            print_alternating_words(t->ptrs[i], word + char(i + 'a'));
}



// Пример использования
int main() {
    SetConsoleOutputCP(1251);

    ttree::TTREE trie("data.txt");

    std::cout << "Слова с чередующимися гласными и согласными:\n";
    print_alternating_words(trie.get_root(), "");

    return 0;
}