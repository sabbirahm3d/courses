#include "TicTacTrie.h"
#include <cstring>

TicTacTrie::TicTacTrie() {

	root = new TicTacNode();
	m_size = 0;

}


TicTacTrie::~TicTacTrie() {

	delete root;
	root = NULL;

}


void TicTacTrie::AddGame(TicTacToe &game) {

	while (game . Size()) {
		TicTacNode *cursor = game.Pop();
		addWord(cursor->content());
		delete cursor;
		cursor = NULL;
	}

	switch (game.GetResults()) {

		case 1:
			m_xWins++;
			break;

		case 2:
			m_oWins++;
			break;

		case 3:
			m_draws++;
			break;

		default:
			break;

	}


}


void TicTacTrie::addWord(string s) {

    TicTacNode* current = root;
    bool newChild = false;
    int sizeOfTree = 0;

    if ( s.length() == 0 )
    {
        return;
    }

    for ( unsigned int i = 0; i < s.length(); i++ )
    {        
        TicTacNode* child = current->findChild(s[i]);
        if ( child != NULL )
        {
            current = child;
        }
        else
        {
            TicTacNode* tmp = new TicTacNode();
            tmp->setChildContent(s[i]);
            current->appendChild(tmp);
            current = tmp;
            newChild = true;
        }

    }

    if ( newChild ) {
        m_size++;
    }

}


bool TicTacTrie::searchWord(string s)
{
    TicTacNode* current = root;

    while ( current != NULL )
    {
        for ( int i = 0; i < s.length(); i++ )
        {
            TicTacNode* tmp = current->findChild(s[i]);
            if ( tmp == NULL )
                return false;
            current = tmp;
        }

        if ( current )
            return true;
        else
            return false;
    }

    return false;
}


int TicTacTrie::GetXWins() const { return m_xWins; }

int TicTacTrie::GetOWins() const { return m_oWins; }

int TicTacTrie::GetDraws() const { return m_draws; }

int TicTacTrie::Size() const { return m_size; }