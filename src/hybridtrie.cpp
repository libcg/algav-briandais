#include "hybridtrie.h"
#include <iostream>

HybridTrie::HybridTrie() :
    m_left(NULL),
    m_child(NULL),
    m_right(NULL),
    m_key(false),
    m_char('\0')
{}

HybridTrie::~HybridTrie()
{
    delete m_left;
    delete m_child;
    delete m_right;
}

void HybridTrie::insert(std::string word)
{
    if (word.empty()) {
        return;
    }

    /* If we are inserting the last character, this node is marked as a key */
    m_key = (word.length() == 1);

    if (m_char == '\0') {
        m_char = word.front();
    }

    if (word.front() < m_char) {
        if (m_left == NULL) {
            m_left = new HybridTrie();
        }

        m_left->insert(word);
    }
    else if (word.front() == m_char && !m_key) {
        if (m_child == NULL) {
            m_child = new HybridTrie();
        }

        /* Insert the string minus the first letter */
        m_child->insert(word.erase(0, 1));
    }
    else if (word.front() > m_char) {
        if (m_right == NULL) {
            m_right = new HybridTrie();
        }

        m_right->insert(word);
    }
}

void HybridTrie::print()
{
    if (m_left) {
        m_left->print();
    }

    std::cout << m_char;

    if (m_child) {
        m_child->print();
    }
    else {
        std::cout << std::endl;
    }

    if (m_right) {
        m_right->print();
    }
}

bool HybridTrie::exists(std::string word)
{
    if (word.empty()) {
        return false;
    }

    if (word.length() == 1) {
        return m_char == word.front() && m_key;
    }

    if (word.front() < m_char && m_left) {
        return m_left->exists(word);
    }
    else if (word.front() == m_char && m_child) {
        return m_child->exists(word.erase(0, 1));
    }
    else if (word.front() > m_char && m_right) {
        return m_right->exists(word);
    }

    return false;
}

int HybridTrie::countWords()
{
    /* We count the number of keys (last letter of a word) found in the tree */
    int count = (int)m_key;

    if (m_left) { 
        count += m_left->countWords();
    }
    if (m_child) {
        count += m_child->countWords();
    }
    if (m_right) {
        count += m_right->countWords();
    }

    return count;
}
