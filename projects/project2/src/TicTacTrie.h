#ifndef TICTACTRIE_H
#define TICTACTRIE_H


#include "TicTacNode.h"

class TicTacTrie {

public:

    TicTacTrie();
    ~TicTacTrie();
    void addWord(string s);
    bool searchWord(string s);
    // void deleteWord(string s);

private:

    TicTacNode* root;

};

#endif