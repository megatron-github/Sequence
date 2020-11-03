# Sequence
A program to get more familiar with C++ and its data structures: basic control constructs, implementing the methods of an array-based data structure, working with the size_t data type, and testing.

Objects of the sequence class represent ordered sequences of integers. The number of integers in the sequence is between zero and some maximum capacity. A sequence is initially empty. Each sequence has a size. Integers in the sequence can be accessed by their position (0-based). Other than the constructor, which initializes an empty sequence, these are the operations on sequences:

Operations that do not change the sequence:
1. size() returns the number of elements in the sequence
2. empty() return true if there are no elements in the sequence; false otherwise
3. full() return true if the number of elements in the sequence has reached capacity
4. print() Display the sequence on the standard output
5. get(position) return the value of the integer at the given position
6. getLongestRun() return the position of the longest run of two or more identical values in the sequence, or size() if there is no run

Operations that change the sequence:
7. add(item) add a new item to the end of the sequence
8. add(item, position) add a new item at a given position
9. remove(position) remove the item at a given position
10. replace(newitem, position) replace the item at a given position with a new item
11. clear() remove all elements from the sequence
