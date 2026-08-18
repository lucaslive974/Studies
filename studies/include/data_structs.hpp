#include <array>
#include <memory>
#include <string>

namespace datastructs {

struct TrieNode {
    std::array<std::shared_ptr<TrieNode>, 26> child;
    bool endOfWord = false;
    int count = 0;
};

class Trie {
    std::shared_ptr<TrieNode> root;
    void printBranch(std::shared_ptr<TrieNode> &node, const std::string &_string);

  public:
    Trie();
    void insert(const std::string &_string);
    void remove(const std::string &_string);
    void printAllStringsInTrie();
};

void tries();

} // namespace datastructs