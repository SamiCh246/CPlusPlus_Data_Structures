#include "IntArrayLS.h"
#include <iostream>
using namespace std;

/*
Constructor - initializes the fields.
*/
IntArrayLS::IntArrayLS(int initialCapacity) {
	capacity = initialCapacity;
	elements = new int[capacity]; // allocate contiguous memory for the array - space for up to "capacity" number of elements
	size = 0; // no elements are actually in the array yet
}

/*
Destructor - deletes the memory dynamically allocated for the array.
*/
IntArrayLS::~IntArrayLS() {
	delete [] elements;
}

/*
Return the size (current number of elements) in the array.
(Not the capacity - this number is hidden from the user.)
*/
int IntArrayLS::getSize() {
	return size;
}

int IntArrayLS::get(int index) {
	// ***************************************************************************************************
	// TO DO: Fill in this method to get the element at the given index.
	// This is very easy for an array. Even though elements is an int*, you can treat it like an array and use ordinary [] notation on it.
	// The return -1 is just a placeholder so the code still compiles. You'll need to delete that.
	return elements[index];

	// ***************************************************************************************************
}

/*
Prints the elements in the array. Note the very precise formatting requirements in the assignment description!
*/
void IntArrayLS::printAll() {
	// ***************************************************************************************************
	// TO DO: fill in this method to print the elements of the array exactly as specified in the assignment description.
  cout << "[";
  
  for (int i = 0; i < size-1; i++) {
    cout << elements[i] << ", ";
  }
  cout << elements[size-1] << "]  (size: " << size << ")" << endl;


	// ***************************************************************************************************
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Adding to the structure

/*
Adds the given element to the beginning of the array.
*/
void IntArrayLS::addToStart(int value) {
	addToIndex(value, 0); // just calls the addToIndex method with index 0.
}

/*
Add the given value to the given position (index) in the array.
Allowed indices are from 0 to size, where an index of size means 
adding to the end of the array.
*/
void IntArrayLS::addToIndex(int value, int index) {
	if (index > size)
		cout << "Invalid index " << index << " for array of size " << size << ". Add request ignored." << endl;
	else {
		shiftRight(index);         // To insert value at the index, we have to shift everything from that index to the right to make room.
		elements[index] = value;   // Put the value at the newly-available index.
		size++;                    // This is easy to forget! We have to maintain our size variable.
	}
}

/*
This private method is called by addToIndex to shift everything from the given index to the right.
This opens up a slot for the value we want to add in.
This is a reason that adding is slow for arrays - we may need to shift lots of values!
*/
void IntArrayLS::shiftRight(int lowIndex) {
	if (size == capacity) // If the structure is already full
		expandArray();    // then get more space! (See function definition below.)

	// ***************************************************************************************************
	// TO DO: Shift all elements right one slot so that lowIndex becomes an "open" position.
  for(int i = size-1; i>=lowIndex; i--) {
    elements[i+1] = elements[i];
  }

	// ***************************************************************************************************
}

/*
This private method is called by shiftRight if the user wants to add another element to the structure,
but the structure is already at full capacity for its currently-allocated contiguous memory.
*/
void IntArrayLS::expandArray() {
	int newCapacity = capacity * 2; // We'll allocate a spot in memory that's twice as big as the current spot.
	int* bigger = new int[newCapacity]; // Dynamically allocate the bigger chunk of memory.
	// ***************************************************************************************************
	// TO DO: Copy everything from the array named elements to the array named bigger.
	// This is a reason that adding is slow - we have to copy everything to the new memory location!
  for(int i = 0; i<size; i++) {
    bigger[i] = elements[i];
  }
  
	// ***************************************************************************************************

	// Free up the old, smaller chunk of memory
	delete [] elements;

	// Update the fields to point to the new, bigger chunk of a memory
	elements = bigger;
	capacity = newCapacity;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Removing from the structure

/*
Removes the first element from the structure. Just passes the work on to removeFromIndex.
*/
int IntArrayLS::removeFromStart() {
	return removeFromIndex(0);
}

/*
Removes the element at the given index from the structure.
*/
int IntArrayLS::removeFromIndex(int index) {
	if (index >= size) {
		cout << "Invalid index " << index << " for array of size " << size << ". Remove request ignored." << endl;
		return -1;
	}
	else {
		int retVal = elements[index]; // Save the value to return
		shiftLeft(index);             // Shift all the elements left to make the remaining elements contiguous again.
		size--;                       // Update the size to reflect that an element has been removed.

		return retVal;
	}
}

/*
This private method is called from removeFromIndex, to shift elements left, covering up the value we want to remove.
*/
void IntArrayLS::shiftLeft(int lowIndex){
	// ***************************************************************************************************
	// TO DO: Shift all elements left one slot, starting with lowIndex.
  for (int i = lowIndex; i < size - 1; i++)
    elements[i] = elements[i+1];

	// ***************************************************************************************************
}
