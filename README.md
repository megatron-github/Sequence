# Sequence
A program to get more familiar with C++ and its data structures: basic control constructs, implementing the methods of an array-based data structure, working with the size_t data type, and testing.

Objects of the sequence class represent ordered sequences of integers. The number of integers in the sequence is between zero and some maximum capacity. A sequence is initially empty. Each sequence has a size. Integers in the sequence can be accessed by their position (0-based). Other than the constructor, which initializes an empty sequence, these are the operations on sequences:

Operations that do not change the sequence: <br />
size() <br />
empty() <br /> 
full() <br /> 
print() <br />
get(position) <br /> 
getLongestRun() <br />
size()

Operations that change the sequence: 
add(item) <br />
add(item, position) <br /> 
remove(position) <br />
replace(newitem, position) <br />
clear()
