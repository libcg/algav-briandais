#ifndef __TRIE_H
#define __TRIE_H

#include <vector>
#include <string>

class Trie {
public:
    virtual ~Trie() {}
    virtual void insert(std::string word) = 0;
    virtual void print() = 0;

    /* Advanced functions */
    virtual bool exists(std::string word) = 0;
    virtual int countWords() = 0;
    virtual std::vector<std::string> listWords() = 0;
    virtual int countNil() = 0;
    virtual int height() = 0;
    virtual int meanDepth() = 0;
    virtual int prefix(std::string &word) = 0;
    virtual void remove(std::string &word) = 0;
};

#endif /* __TRIE_H */
