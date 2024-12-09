// Функция для проверки чередования гласных и согласных
#include "Trie_Tree.h"
// Функция для проверки чередования гласных и согласных
bool is_alternating(const std::string& word) {
    if (word.empty()) return false;

    bool prev_is_vowel = (std::string("aeiou").find(tolower(word[0])) != std::string::npos);

    for (size_t i = 1; i < word.size(); ++i) {
        bool is_vowel = (std::string("aeiou").find(tolower(word[i])) != std::string::npos);

        // Если текущий тип совпадает с предыдущим, не чередуется
        if (prev_is_vowel == is_vowel) {
            return false;
        }

        prev_is_vowel = is_vowel; // Обновляем предыдущий тип
    }

    return true; // Если все символы чередуются
}

// Функция для печати слов с чередующимися гласными и согласными
void print_alternating_words(ttree::ptrNODE t, std::string word) {
    if (t->eow && is_alternating(word)) {
        std::cout << word << std::endl;
    }

    for (int i = 0; i < 26; i++) {
        if (t->ptrs[i]) {
            print_alternating_words(t->ptrs[i], word + char(i + 'a'));
        }
    }
}

void print_alternating_vowels_consonants(ttree::ptrNODE root) {
    print_alternating_words(root, "");
}

// Пример использования
int main() {
    const char* filename = "words.txt"; // Укажите имя файла со словами
    ttree::TTREE trie("data.txt");

    std::cout << "Слова с чередующимися гласными и согласными:\n";
    print_alternating_vowels_consonants(trie.get_root());

    return 0;
}