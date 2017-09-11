#ifndef INT_ARRAY_H
#define INT_ARRAY_H
/*
 * File:    IntArray.h
 * Project: CMSC 202 Testing Lab, Spring 2014
 * Author:  Jesse Pinkman
 * Date:    2/30/2014
 * Section: 42
 * Email:   representin_the_abq@umbc.edu
 *
 * This file contains the class declaration for the IntArray class. 
 * IntArrays are dynamically resizing arrays that are capable of holding
 * integers. Various forms of insertion into and deletion from are 
 * IntArrays are supported. IntArrays can also have certain mathematical
 * operations performed on them, such as adding or multiplying a 
 * particular value to all elements. It is also possible to compute
 * element-wise sums and products between two IntArrays. 
 *
 * There are 31 error statements and 8 edge case statments hidden throughout
 * the class' implementation.
 *
 * **************************************
 * THIS FILE IS NOT TO BE MODIFIED!!!!!!!
 * **************************************
 */
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <set>

class IntArray
{
public:
    /*
     * IntArray - Default constructor
     * Preconditions: None.
     * Postconditions: Creates an empty IntArray instance.
     */
    IntArray();

    /*
     * IntArray - Fill constructor
     * Preconditions: Size is non-negative, and it is possible 
     * to allocate size integers (i.e. size is not "too big").
     * Postconditions: Creates an IntArray with size elements 
     * equal to defaultVal.
     * 
     * Contains 2 errors and 1 edge case.
     */
    IntArray(int size, int defaultVal=0);

    /*
     * IntArray - Copy constructor
     * Preconditions: None.
     * Postconditions: Creates a deep copy of the other IntArray.
     */
    IntArray(const IntArray &other);

    /*
     * ~IntArray - Destructor
     * Preconditions: None.
     * Postconditions: Frees memory allocated to this IntArray.
     *
     * Contains 1 edge case.
     * Hint: Does it make sense to free already freed memory?
     */
    ~IntArray();

    /*
     * operator = - Assignment operator
     * Preconditions: None.
     * Postconditions: The contents of the other IntArray are
     * copied into this one. The copy performed is a deep copy.
     */
    void operator=(const IntArray &other);

    /*
     * operator == - Equality operator
     * Preconditions: Size of this IntArray is the same size 
     * of the other one. 
     * Postconditions: Returns true if both arrays contain the
     * same integers in the same order, false otherwise.
     *
     * Contains 1 error and 1 edge case.
     */
    bool operator==(const IntArray &other) const;

    /*
     * operator != - Inequality operator
     * Preconditions: Size of this IntArray is the same size 
     * of the other one. 
     * Postconditions: Returns false if both arrays contain the
     * same integers in the same order, true otherwise.
     *
     * Contains 1 error and 1 edge case.
     */
    bool operator!=(const IntArray &other) const;

    /*
     * operator += - Add-assign operator
     * Preconditions: None, but this makes more sense if the
     * other array is not empty.
     * Postconditions: Appends all elements in the other array
     * to this one.
     *
     * Contains 1 edge case.
     */
    void operator+=(const IntArray &other);

    /*
     * operator + - Add operator
     * Preconditions: None, but this makes more sense if both
     * arrays are not empty.
     * Postconditions: Returns a new IntArray containing the
     * elements from this array and the other IntArray.
     *
     * Contains 2 edge cases.
     */
    const IntArray operator+(const IntArray &other) const;

    /*
     * operator [] - Index operator
     * Preconditions: Index is less than the number of elements
     * in the array.
     * Postconditions: Returns element located at index
     *
     * Contains 1 error.
     */
    int operator[](unsigned int index) const;
    
    /*
     * Append
     * Preconditions: None.
     * Postconditions: Element is added to the end of the array.
     */
    void Append(int element);

    /*
     * Get
     * Preconditions: Index is nonnegative and less than the 
     * number of elements in the array.
     * Postconditions: Returns the element at the index.
     *
     * Contains 2 errors.
     */
    int Get(int index) const;

    /*
     * SetItem
     * Preconditions: Index is nonnegative and less than the
     * number of elements in the array.
     * Postconditions: Sets the element at index to the value of
     * newValue.
     *
     * Contains 2 errors.
     */
    void SetItem(int index, int newValue);

    /*
     * Insert
     * Preconditions: Array is not empty and index is nonnegative and 
     * less than the number of elements in the array. 
     * Postconditions: Inserts the element at the given index and shifts
     * all the old elements starting at index to the right by 1.
     *
     * Contains 3 errors. 
     */
    void Insert(int index, int element);

    /*
     * Del
     * Preconditions: Array is not empty and index is nonnegative and 
     * less than the number of elements in the array.
     * Postconditions: Removes the element at index and shifts everything
     * past the index to the left by 1.
     *
     * Contains 3 errors.
     */
    void Del(int index);

    /*
     * Remove
     * Preconditions: Array is not empty and element is in the array.
     * Postconditions: Removes the first occurrence of the given 
     * element and shifts any elements beyond the removed element 
     * to the left by 1.
     *
     * Contains 2 errors.
     */
    void Remove(int element);

    /*
     * Clear
     * Preconditions: None, but this makes more sense if the 
     * array has elements in it.
     * Postconditions: The array contains no elements.
     *
     * Contains 1 edge case.
     */
    void Clear();

    /*
     * Contains
     * Preconditions: Array is not empty.
     * Postconditions: Returns true if the given element is 
     * in the array, false otherwise.
     * 
     * Contains 1 error.
     */
    bool Contains(int element) const;

    /*
     * Contains
     * Preconditions: Array is not empty and count is positive and 
     * less than or equal to the number of elements.
     * Postconditions: Returns true if the given element is 
     * in the array count times, false otherwise.
     * 
     * Contains 3 errors.
     */
    bool Contains(int element, int count) const;

    /*
     * IndexOf
     * Preconditions: Array is not empty and element is in the array.
     * Postconditions: Returns the index of the first occurrence of the
     * given element. 
     *
     * Contains 2 errors.
     */
    unsigned int IndexOf(int element) const;

    /*
     * GetLength
     * Preconditions: None.
     * Postconditions: Returns number of elements in the array.
     */
    size_t GetLength() const;

    /*
     * AddToAll
     * Preconditions: Array is not empty.
     * Postconditions: Adds n to each element in the array.
     *
     * Contains 1 error.
     */
    void AddToAll(int n);

    /*
     * Scale
     * Preconditions: Array is not empty.
     * Postconditions: Multiplies each element in the array by n.
     *
     * Contains 1 error.
     */
    void Scale(int n);

    /*
     * Sum
     * Preconditions: Neither array is empty and both arrays 
     * are the same size.
     * Postconditions: Adds each element of the other array to
     * the corresponding elements in this array.
     *
     * Contains 3 errors.
     */
    void Sum(const IntArray &other);

    /*
     * Product
     * Preconditions: Neither array is empty and both arrays 
     * are the same size.
     * Postconditions: Multiplies each element of the other array to
     * the corresponding elements in this array.
     *
     * Contains 3 errors.
     */
    void Product(const IntArray &other);

    /*
     * GetProgress
     * Preconditions: None
     * Postconditions: Returns a string displaying the number of 
     * edge cases and errors found.
     */
    static std::string GetProgress();
    
    /*
     * This is a friend function. Friend functions are 
     * functions declared outside of a class, but are 
     * still able to access that class' private and protected
     * data and methods.
     * Friend functions should be used with extreme caution!
     */
    friend std::ostream& operator<<(std::ostream &stream, 
				    const IntArray& intArray);
private:
    int *m_contents;      // The contents of the array
    size_t m_numElements; // The number of elements in the array
    size_t m_currentSize; // Actual size of the array >= m_numElements

    static std::set<int> errorsFound;
    static std::set<int> edgeCasesFound;

    /* 
     * Resize()
     * Doubles the capacity of the array.
     * This method is private -- you can't call it
     */
    void Resize();
};

/*
 * operator << - Left shift operator
 * A handy function that will allow you to easily
 * print the contents of an IntArray using cout. 
 *
 * Using this function is as simple as doing the following,
 * assuming array is an IntArray object:
 *
 * cout << array << endl; 
 */
std::ostream& operator<<(std::ostream &strm, const IntArray& intArray);

#endif
