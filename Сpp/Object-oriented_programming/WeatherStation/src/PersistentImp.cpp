

#include "PersistentImp.h"
#include "HiLoDataImp.h"
#include <fstream>

namespace
{
	/**
	* 
	*/
	bool findKey(std::fstream& fs,const std::string& key, std::streampos& position = std::streampos(0))
	{
		bool bIsFound = false;
		if (fs.is_open() == false)
		{
			position = 0;
			return bIsFound;
		}

		// key = <type>+HiLo+<mm><dd><yyyy> = 10+4+2+2+4 = 22
		const size_t keyLength = key.size();
		const size_t lengthRecord = keyLength + sizeof(HiLoDataImp);

		// get length of file:
		fs.seekg(0, fs.end);
		size_t lengthFile = fs.tellg();
		fs.seekg(0, fs.beg);

		if (lengthFile % lengthRecord == 0)
		{
			// allocate memory
			char* bufferForKey = new char[keyLength];

			const size_t numberRecords = lengthFile / lengthRecord;
			for (size_t indexRecord = 0; indexRecord < numberRecords && bIsFound == false; indexRecord++)
			{
				bIsFound = true;

				// read key
				fs.seekg(lengthRecord * indexRecord);
				fs.read(bufferForKey, keyLength);

				for (int i = 0; i < keyLength; i++)
				{
					if (bufferForKey[i] != key[i])
					{
						bIsFound = false;
						break;
					}
				}
			}
			delete[] bufferForKey;
		}
		position = fs.tellg();
		return bIsFound;
	}
}

PersistentImp::PersistentImp(std::string pathToFile)
	: itsPathToFile(pathToFile)
{
}

PersistentImp::~PersistentImp()
{
}

void PersistentImp::store(const std::string& key, HiLoDataImp* obj)
{
	std::fstream fs(itsPathToFile, std::ios_base::binary | std::ios_base::in | std::ios_base::out);
	if (fs.is_open())
	{
		std::streampos currentPosition = 0;
		bool bIsFound = findKey(fs,key, currentPosition);
		if (bIsFound)
		{
			fs.write((char*)obj, sizeof(HiLoDataImp));
		}
		else
		{
			fs.seekg(0, fs.end);
			fs.write(key.c_str(), key.size());
			fs.write((char*)obj, sizeof(HiLoDataImp));
		}
	}
	else
	{
		throw("Error: PersistentImp::store(std::string name, HiLoDataImp* obj): file is not open");
	}
	fs.close();
}

HiLoDataImp PersistentImp::retrieve(std::string key)
{
	std::fstream fs(itsPathToFile, std::ios_base::binary | std::ios_base::in);
	std::streampos currentPosition = 0;
	bool bIsFound = findKey(fs, key, currentPosition);
	char* bufferForHiLoDataImp = new char[sizeof(HiLoDataImp)]();
	if (fs.is_open() && bIsFound)
	{
		fs.read(bufferForHiLoDataImp, sizeof(HiLoDataImp));
	}
	HiLoDataImp hldi = *reinterpret_cast<HiLoDataImp*>(bufferForHiLoDataImp);
	delete[] bufferForHiLoDataImp;
	return hldi;
}