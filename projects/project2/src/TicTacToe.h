#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>
#include "TicTacNode.h"

class TicTacToe {

public:

    TicTacToe();
    TicTacToe(string);
    ~TicTacToe();

    void ReadGame(string);
    bool GetResults(string, char);
    bool GetIsOver();

    bool Empty() const;
    bool Push(string value);
    bool Clear();
    int Size() const;
    void Print();


private:

    TicTacNode *m_head, *m_tail;
    // int m_size;
    bool m_isOver;
    int m_results;

};

#endif