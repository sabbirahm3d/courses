#include <iostream>
#include <iterator>

struct NODE {
    int data;
    NODE *parent;
    NODE *left;
    NODE *right;

    NODE() : data(0), parent(NULL), left(NULL), right(NULL) {

    }

    ~NODE() {
        if (left != NULL) {
            delete left;
            left = NULL;
        }

        if (right != NULL) {
            delete right;
            right = NULL;
        }

        parent = NULL;
    }
};

class BSTIterator : public std::iterator<std::input_iterator_tag, int> {
private:
    NODE *_current;

public:
    BSTIterator()
            : _current(NULL) {

    }

    BSTIterator(NODE *current)
            : _current(current) {

    }

    BSTIterator(const BSTIterator &other)
            : _current(other._current) {

    }

    BSTIterator &operator=(const BSTIterator &other) {
        if (this != &other) {
            _current = other._current;
        }
    }

    bool operator==(const BSTIterator &other) const {
        return _current == other._current;
    }

    bool operator!=(const BSTIterator &other) const {
        return !(*this == other);
    }

    int operator*() const {
        return _current->data;
    }

    BSTIterator &operator++() {
        if (_current == NULL) {
            return *this;
        }
        else if (_current->right != NULL) {
            _current = _current->right;

            while (_current->left != NULL) {
                _current = _current->left;
            }
        }
        else {
            while (_current->parent != NULL
                   && _current->parent->left != _current) {
                _current = _current->parent;
            }

            _current = _current->parent;
        }

        return *this;
    }

    BSTIterator operator++(int unused) {
        BSTIterator temp(*this);
        operator++();
        return temp;
    }
};


class BST {
private:
    NODE *_root;

    void insert(NODE *n, int i) {
        if (i < n->data && n->left != NULL) {
            insert(n->left, i);
        }
        else if (i < n->data) {
            n->left = new NODE;
            n->left->data = i;
            n->left->parent = n;
        }
        else if (n->right != NULL) {
            insert(n->right, i);
        }
        else {
            n->right = new NODE;
            n->right->data = i;
            n->right->parent = n;
        }
    }

public:
    friend class BSTIterator;

    BST()
            : _root(NULL) {

    }

    ~BST() {
        if (_root != NULL) {
            delete _root;
            _root = NULL;
        }
    }

    void insert(int i) {
        if (_root == NULL) {
            _root = new NODE;
            _root->data = i;
        }
        else {
            insert(_root, i);
        }
    }

    BSTIterator begin() {
        if (_root == NULL) {
            return BSTIterator(NULL);
        }

        NODE *current = _root;

        while (current->left != NULL) {
            current = current->left;
        }

        return BSTIterator(current);
    }

    BSTIterator end() {
        return BSTIterator(NULL);
    }
};


int main() {
    int n = 0;
    unsigned long num_numbers = 15;
    BST tree;

    std::cout << "Enter " << num_numbers << " numbers" << std::endl;

    for (unsigned long i = 0; i < num_numbers; i++) {
        std::cin >> n;
        tree.insert(n);
    }

    std::cout << std::endl;
    BSTIterator iter = tree.begin();

    while (iter != tree.end()) {
        std::cout << *iter << std::endl;
        iter++;
    }

    return 0;
}
