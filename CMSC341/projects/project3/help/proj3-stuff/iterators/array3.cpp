#include <iostream>
#include <iterator>

class ArrayIterator : 
    public std::iterator<std::random_access_iterator_tag, int>
{
private:
    int *_pos;

public:
    ArrayIterator() : _pos(NULL) {}
    ArrayIterator(int *pos) : _pos(pos) {}
    ArrayIterator(const ArrayIterator &other) : _pos(other._pos) {}
    ArrayIterator &operator=(const ArrayIterator &other)
    {
        if (this != &other)
        {
            _pos = other._pos;
        }
    }

    ~ArrayIterator()
    {
        _pos = NULL;
    }

    bool operator==(const ArrayIterator &other) const
    {
        return _pos == other._pos;
    }

    bool operator!=(const ArrayIterator &other) const
    {
        return !(*this == other);
    }

    int operator*() const
    {
        return *_pos;
    }

    ArrayIterator &operator++()
    {
        _pos++;
        return *this;
    }

    ArrayIterator operator++(int unused)
    {
        ArrayIterator temp(*this);
        _pos++;

        return temp;
    }

    ArrayIterator &operator--()
    {
        _pos--;
        return *this;
    }

    ArrayIterator operator--(int unused)
    {
        ArrayIterator temp(*this);
        _pos--;

        return temp;
    }

    ArrayIterator &operator+=(std::ptrdiff_t offset)
    {
        _pos += offset;
        return *this;
    }

    ArrayIterator operator+(std::ptrdiff_t offset) const
    {
        ArrayIterator new_iterator(_pos);
        new_iterator += offset;
        return new_iterator;
    }

    friend ArrayIterator operator+(std::ptrdiff_t offset, 
                                   const ArrayIterator &i)
    {
        ArrayIterator new_iterator(i);
        new_iterator += offset;
        return new_iterator;
    }

    ArrayIterator &operator-=(std::ptrdiff_t offset)
    {
        _pos -= offset;
        return *this;
    }

    ArrayIterator operator-(std::ptrdiff_t offset) const
    {
        ArrayIterator new_iterator(_pos);
        new_iterator -= offset;
        return new_iterator;
    }

    friend ArrayIterator operator-(std::ptrdiff_t offset, 
                                   const ArrayIterator &i)
    {
        ArrayIterator new_iterator(i);
        new_iterator -= offset;
        return new_iterator;
    }

    std::ptrdiff_t operator-(const ArrayIterator &i) const
    {
        return i._pos - this->_pos;
    }

    int &operator[](int i) const
    {
        return _pos[i];
    }

    bool operator<(const ArrayIterator &other) const
    {
        return _pos < other._pos;
    }

    bool operator>(const ArrayIterator &other) const
    {
        return !(*this < other) && !(*this == other);
    }

    bool operator<=(const ArrayIterator &other) const
    {
        return *this < other || *this == other;
    }

    bool operator>=(const ArrayIterator &other) const
    {
        return !(*this < other);
    }
};

int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7};
    ArrayIterator i(a);
    ArrayIterator end(a + 8);

    ArrayIterator j = 3 + i;

    j[2] = 42;

    while (i != end)
    {
        std::cout << *i << std::endl;
        i++;
    }

    std::cout << std::endl;
    std::cout << j - i << std::endl;
    std::cout << std::endl;
    std::cout << j[1] << std::endl;
    std::cout << std::endl;

    while (j != end)
    {
        std::cout << *j << std::endl;
        j++;
    }

    std::cout << std::endl;

    return 0;
}
