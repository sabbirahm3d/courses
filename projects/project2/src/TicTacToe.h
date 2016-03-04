#ifndef TICTACTOE_H
#define TICTACTOE_H


#include "TicTacNode.h"

class TicTacToe {

public:

    TicTacToe();
    TicTacToe(string);
    ~TicTacToe();

    void ReadGame(string);
    bool Empty() const;
    bool Push(string value);
    bool Clear();

private:

    TicTacNode *m_head, *m_tail;
    bool m_isOver;
    int m_results;

};

#endif