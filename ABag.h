#pragma once

//include bagADT to overwrite the abstract data types
#include "bagADT.h"
#include <memory>

template <typename E>
class ABag : public Bag<E>
{
private: //private data members to be used in the code
	int bagPosition = 0;
	int maxSize = 10;
	E* newBag;
	

public:
	ABag() {} //default constructor
	ABag(int size) //zero argument constructor
	{
		maxSize = size;
		bagPosition = 0;
		newBag = new E[size];
	}   
	
	~ABag() //default destructor
	{
		delete [] newBag;
	}  //include the [] to ensure the whole thing is deleted rather than just the first data member

	 bool addItem(const E& item) 
	// Insert a new item into the bag -- return false if fails and true if
	// successful
	{
		
		 if (bagPosition < maxSize) //if the bag is not full
		 {
			 //then set the position of the bag equal to the item it read in, then it gets incremented one spot
			 newBag[bagPosition++] = item; 
			 return true; //return true when done
		 }
		 else
		 {
			 return false; //this allows the function to return false if it does not work
		 }
	}

	
	 bool remove(E& item)
	// Looks for 'item' in the bag and if found updates 'item' with the 
	// bag value and returns true.  Otherwise 'item' is left unchanged
	// and the method returns false.
	{
		 int currentPos = 0;
		 for (int i = 0; i < bagPosition; i++) //for loop, allows the entire bag to be searched for the item
		 {
			 if (newBag[i] == item) //if the item being searched for is found, this part of the code will run
			 {
				 item = newBag[i];
				 currentPos = i; //sets the item read in to the position of the bag
				 for (int i = currentPos; i <= bagPosition; i++) //while loop to reset the rest of the data positions back so there is not a missing member in the data
				 {
					 newBag[i] = newBag[i + 1];
				 }
			 }
			 bagPosition--;
			 //increments the bag down
			 return true;
			 break;
		 }
		
	
		 return false;
		
	}

	 bool removeTop(E& returnValue)
	// Removes the top record from the bag, puts it in returnValue, and
	// returns true if the bag is not empty.  If the bag is empty the 
	// function returns false and returnValue remains unchanged.
	{

		 if (bagPosition != 0) //check to make sure the bag is not empty
		 {
			 returnValue = newBag[--bagPosition]; //if bag is not empty, will set the returnValue, and remove the record
			 return true;
		 }
		 else //if bag is empty just returns true
		 {
			 return false;
		 }
	}

	 bool find(E& returnValue) const
	// Finds the record using returnValue and if the record is found updates
	// returnValue based on the contents of the bag and returns true.  If the
	// record is not found the function returns false.  Works just like remove()
	// except that the found record is not removed from the bag.
	{
		 for (int i = 0; i < bagPosition; i++) //For loop, very similar to the remove function, look for the record be looping through the bag
		 {
			 if (newBag[i] == returnValue) //if the record that was read into the function is found, will execute this if statement
			 {
				 returnValue = newBag[i]; //set the returnValue to the bagposition
				 return true;
			 }
		 }
		 return false; //return statement on the outside of for loop, so if the record is not found, return false
	}

	bool inspectTop(E& item) const
	// Inspect the top of the bag.  If the bag is empty return
	// false and leave 'item' unchanged; otherwise, return true and update 
	// 'item' with the contents of the bag.
	{
		if (bagPosition != 0) //check to make sure bag is not empty
		{
			item = newBag[bagPosition]; //set the item read into the function to the value of the current bag position
			return true;
		}
		else //if bag is empty return false
			return false;
	}

	 void emptyBag() //resets the position of the bag, rest of array is deleted by the destructor when function terminates
	{
		 bagPosition = 0;
	}

	 bool operator+=(const E& addend) //overloaded function to add an item to the bag
	{
		 return addItem(addend); //calls addItem to add an item to the bag
	}

	 int numItems() const //returns the number of items in the
	{
		 return (bagPosition); //returns the current position in the bag
	}

	 int bagCapacity() const //returns the capacity, realistically it is 10, as that is the hard code we have set the capacity to
	{
		 return maxSize;
	}
	
};