//
// Created by zhangjiayuan on 23-4-25.
//

#ifndef BOOSTGEOMETRY_TRIE_H
#define BOOSTGEOMETRY_TRIE_H
#include "Util.h"
class TrieNode {
public:
    TrieNode(std::map<char, TrieNode *> sonMap, bool isLeaf) : _sonMap(std::move(sonMap)), _isLeaf(isLeaf) {}
    TrieNode() {
        _isLeaf = false;
    }
    std::map<char, TrieNode*> _sonMap;
    bool _isLeaf;
};

class Trie{
public:
    Trie() {
        _root = new TrieNode();
    }
    void insert(const std::string& s) {
        if (s.empty()) return;
        auto tmp = _root;
        for (const auto&c: s) {
            if (tmp->_sonMap.find(c) != tmp->_sonMap.end()) {
                tmp = tmp->_sonMap[c];
                continue;
            }
            tmp->_sonMap[c] = new TrieNode();

            if (c != s.back()) {
                tmp = tmp->_sonMap[c];
            }

            if (c == s.back()) {
                tmp->_sonMap[c]->_isLeaf = true;
            }
        }
    }

    bool find(const std::string& s) {
        if (s.empty()) return true;
        auto tmp = _root;
        for (const auto&c: s) {
            if (c == s.back() && tmp->_sonMap[c]->_isLeaf) {
                return true;
            }
            if (tmp->_sonMap.find(c) != tmp->_sonMap.end()) {
                tmp = tmp->_sonMap[c];
                continue;
            } else {
                return false;
            }
        }
        return false;
    }

private:
    TrieNode* _root;
};

void Trie_Test();

#endif //BOOSTGEOMETRY_TRIE_H
