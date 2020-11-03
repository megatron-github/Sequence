# Sequence
A program to get more familiar with C++ and its data structures: basic control constructs, implementing the methods of an array-based data structure, working with the size_t data type, and testing.

Objects of the sequence class represent ordered sequences of integers. The number of integers in the sequence is between zero and some maximum capacity. A sequence is initially empty. Each sequence has a size. Integers in the sequence can be accessed by their position (0-based). Other than the constructor, which initializes an empty sequence, these are the operations on sequences:

Operations that do not change the sequence: size(); empty(); full(); print(); get(position); getLongestRun(); size()

Operations that change the sequence: add(item); add(item, position); remove(position); replace(newitem, position); clear()
