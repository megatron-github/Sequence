/************************************************************************
    File: sequence.cc
    Author: Truong Pham
    Date: 2/12/19
    Assignment:  Lab 1 (sequence)

    Implementation of a simple array-based sequence class.

************************************************************************/
#include <iostream>
#include "sequence.h"

/*** Constructor ***/
sequence::sequence(){
  // Initializes this sequence with 0 elements
  _size = 0;
}

/*** const member functions ***/

size_t sequence::size() const{
  // return the number of elements in this sequence
  return _size;
}

bool sequence::empty() const{
  // return true if this sequence has no elements, false otherwise.
  return (_size == 0);
}

bool sequence::full() const{
  // return true if this sequence has _capacity elements, false otherwise.
  return (_size == _capacity);
}

void sequence::print() const{
  // Produce output with std::cout: a single open square bracket, the elements
  // of the sequence, separated by commas and spaces, followed by a single
  // close square bracket.  No newline.
  // Examples of output:
  //  []
  //  [6]
  //  [9, -1, 4]
  std::cout << "[";
  for(size_t i = 0; i < _size; i++){

    // Do not add any comma for the last item on the array when print
    if(i == _size - 1){
      std::cout << _data[i];
    }

    // Add comma for after each item of the array when print
    else{
      std::cout << _data[i] << ", ";
    }
  }
  std::cout << "]";
}

int sequence::get(size_t position) const{
  // Precondition:  position < size()
  // Return the element at the given position.
  if(position < _size){
    return _data[position];
  }
  return 0;
}

size_t sequence::getLongestRun() const{
  // Determine the length of the longest run of two or more identical adjacent
  // elements of this sequence. Return the smallest starting position of a
  // run with this length. If no such run occurs, return size().
  // (This method may use auxiliary stand-alone functions, but, again, you
  // cannot change this file. This means that you cannot define auxiliary
  // methods.)
  size_t count = 0;
  size_t tracker = 0;
  size_t position = _size;

  // Cite: Man Nguyen
  // Desc: The idea that a streak of same numbers occur when the first number
  // and the next number are the same, and so on with the next numbers.

  // For each item, find how many times it repeated itself consecutively.
  for(size_t loc = 0; loc < _size; loc++){

    // If the current item and the next item are the same, a streak is found.
    if((loc + 1 < _size) && (_data[loc + 1] == _data[loc])){
      count++;
    }

    // If a streak is not found, reset the count of streak to zero.
    else{

      // If a new longer streak is found, record the new
      // streak and the location where the streak started.
      if(tracker < count){
        tracker = count;

        // Cite: Man Nguyen
        // Desc: total run = end location - start location
        position = loc - count;
      }
      count = 0;
    }
  }
  return position;
}

/*** non-const member functions ***/

void sequence::add(int item){
  // Preconditions:
  //   The sequence has N elements.
  //   N != _capacity;
  //   Without loss of generality, the sequence contains elements
  //     [V0, V1, V2, ...VN-1]
  // Adds item to the end of the sequence.
  // Postconditions:
  //   The sequence contains elements
  //     [V0, V1, ..., VN-1, item];
  //   size() == N+1.
  _data[_size] = item;
  _size++;
}

void sequence::add(int item, size_t position){
  // Preconditions:
  //   The sequence has N elements.
  //   N != capacity;
  //   Without loss of generality, the sequence contains elements
  //     [V0, V1, V2, ..., Vposition,... VN-1];
  //   position <= size()
  // Inserts item at the given position.  All elements with indices at position
  // or greater are shifted to the right.
  // Postconditions:
  //   The sequence contains elements
  //     [V0, V1, V2, ..., item, Vposition,..., VN-1];
  //   size() == N+1
  size_t substitution;

  // Starting from the position of the new item, save the old item before
  // replacing with the new item. Repeate the process by treating the saved
  // item as a new item for the next position.
  for(size_t i = position; i <= _size; i++){
    substitution = _data[i];
    _data[i] = item;
    item = substitution;
  }
  _size++;
}

void sequence::remove(size_t position){
  // Preconditions:
  //   The sequence has N elements
  //   Without loss of generality, the sequence contains elements
  //     [V0, V1,  ..., Vposition-1, Vposition, Vposition+1, ... VN-1];
  //   0 <= position and position < N
  // The item at the given position is discarded.  All elements with greater
  // indices are shifted to the left.
  // Postconditions:
  //   The sequence contains elements
  //     [V0, V1, ..., Vposition-1, Vposition+1, ..., VN-1]
  //   size() == N-1.

  // Begin from the position where the item is removed, shift all the item
  // from the right to the left one by one.
  for(size_t i = position; i < _size; i++){
      _data[i] = _data[i + 1];
  }
  _size--;
}

void sequence::replace(int newitem, size_t position){
  // Preconditions:
  //   The sequence has N elements.
  //   0 <= position < N
  //   Without loss of generality, the sequence contains elements
  //     [V0, V1, V2, ..., Vposition,... VN-1];
  // Replaces the item at the given position with the given new item.
  // Postcondition:
  //   The sequence contains elements
  //     [V0, V1, V2, ..., newitem,... VN-1];
  //   size() == N  (unchanged)
  _data[position] = newitem;
}

void sequence::clear(){
  // Remove all elements from the sequence.
  // Postcondition:
  //   size() == 0
  _size = 0;
}
