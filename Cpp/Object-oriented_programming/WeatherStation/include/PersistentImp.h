#ifndef __PERSISTENTIMP_H__
#define __PERSISTENTIMP_H__

#include <string>
class HiLoDataImp;

/**
* Class responsible for storing and retrieving data from persistent storage
*/
class PersistentImp
{
public:
	/**
	* @param pathToFile - persistent storage address
	*/
	PersistentImp(std::string pathToFile);


	/**
	* 
	*/
	~PersistentImp();

	/**
	* If this key is not found in the storage,
	* then it makes a new record with the given key and data,
	* otherwise it updates the data in the record with this key. 
	* @param key - key defining the record
	* @param obj - data to be written to storage 
	*/
	void store(const std::string& key, HiLoDataImp* obj);

	/**
	* @param key - key defining the record
	*/
	HiLoDataImp retrieve(std::string key);

private:
	/** Persistent storage address */
	std::string itsPathToFile;
};

#endif // !__PERSISTENTIMP_H__