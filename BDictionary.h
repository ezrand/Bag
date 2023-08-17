#pragma once

#include "dictionaryADT.h"
#include "ABag.h"
#include "kvpair.h"

template <typename Key, typename E>
class  BDictionary : public Dictionary<Key, E>
{
private:
	ABag <KVpair<Key, E>>* aDictionary;

public:
	BDictionary() {} // Default constructor
	BDictionary(int bagPosition) 
	{
		aDictionary = new ABag<KVpair<Key, E>>(bagPosition);
	}
	~BDictionary() { delete aDictionary; } // Base destructor

	// Reinitialize dictionary
	void clear() //calls the emptyBag function in ABag to clear, so will reset the bagposition to 0
	{
		aDictionary->emptyBag();
	}

	// Insert a record
	// k: The key for the record being inserted.
	// e: The record being inserted.
	// Return true if insert is successful and false otherwise
	bool insert(const Key& k, const E& e)
	{
		std::shared_ptr<KVpair<Key, E>> item = std::make_shared<KVpair<Key, E>>(k, e); //sets the Key value pair to the class and name item
		return aDictionary->addItem(*item); //reads the KVpair into aBag addItem, and inserts the record
	}

	// Looks for a record using the key and if found does the following:
	// - updates the E& rtnVal
	// - removes the record from the dictionary
	// - returns true
	// If the record is not found the function returns false.
	bool remove(const Key& k, E& rtnVal)
	{
		KVpair<Key, E> item(k, rtnVal);
		//sets the Key value pair to the class and name item
		if (aDictionary->remove(item)) //searching for the KVpair item, and if found will execute the statment
		{
			rtnVal = item.value();
			return true; //removes the item when found, calls ABag function
		}
		else
			return false;
	}

	// Takes an arbitrary record from the dictionary and does the following:
	// - updates the E& returnValue
	// - removes the record from the dictionary
	// - returns true
	// If the dictionary is empty the function returns false.
	bool removeAny(E& returnValue)
	{
		KVpair<Key, E> item;

		if (aDictionary->removeTop(item))
		{
			returnValue = item.value();
			return true;
		}
		else
			return false;
	}

	// Looks for a record using the key and if found does the following:
	// - updates the E& returnValue
	// - returns true
	// If the record is not found the function returns false.
	bool find(const Key& k, E& returnValue) const
	{
		KVpair<Key, E> item(k, returnValue);//sets the Key value pair to the class and name item
		aDictionary->find(item);
		if (aDictionary->find(item) == true)
		{
			returnValue = item.value();
			return true;
		}
		else
			return false;
	}

	// Return the number of records in the dictionary.
	int size() const
	{
		return aDictionary->numItems();
	}

};
