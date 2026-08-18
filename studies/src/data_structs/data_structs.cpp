#include "data_structs.hpp"
#include <cctype>
#include <iostream>
#include <ranges>
#include <string>

namespace datastructs {

Trie::Trie() {
    root = std::make_shared<TrieNode>();
    root->count++;
}

void Trie::insert(const std::string &_string) {
    auto node = root;
    for (const auto &character : _string) {
        int idx = tolower(character) - 'a';
        if (node->child[idx] == nullptr)
            node->child[idx] = std::make_shared<TrieNode>();

        node = node->child[idx];
        node->count++;
    }

    node->endOfWord = true;
}

void Trie::remove(const std::string &_string) {
    auto node = root;
    for (const auto &character : _string) {
        int idx = tolower(character) - 'a';
        if (node->child[idx] == nullptr)
            return;

        node = node->child[idx];
        node->count--;
    }

    if (node->count == 0)
        node->endOfWord = false;
}

void Trie::printBranch(std::shared_ptr<TrieNode> &node, const std::string &_string) {
    if (node->count == 0)
        return;

    if (node->endOfWord)
        std::cout << _string << "\n";

    for (auto idx : std::views::iota(0, 26)) {
        if (node->child[idx] != nullptr) {
            printBranch(node->child[idx], _string + static_cast<char>('a' + idx));
        }
    }
};

void Trie::printAllStringsInTrie() { printBranch(root, ""); };


void tries() {
    std::cout << "Tries!" << "\n";
    datastructs::Trie trie;

    std::string s1{"helloWorld"};
    std::string s2{"helloRemoved"};

    trie.insert(s1);

    trie.insert(s2);
    trie.remove(s2);

    trie.insert("abc");
    trie.remove("abc");

    trie.insert("Hello");

    trie.printAllStringsInTrie();
}
} // namespace datastructs