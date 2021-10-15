

#include "HiLoDataImp.h"
#include <vector>

#include "StationToolkit.h"
#include "Date.h"
#include "PersistentImp.h"
#include "StringProcessingUtilits.h"

namespace
{
	static const std::vector<std::string> TypesToString = { {"0000000000"},
															{"Temperatur"}};
}

HiLoDataImp::HiLoDataImp(StationToolkit* st, Type type, Date theDate, double init, long initTime)
	: itsPI(nullptr)
	, itsHightTime(0)
	, itsHightValue(0.0)
	, itsLowTime(0)
	, itsLowValue(0.0)
	, itsType(type)
	, itsStorageKey(nullptr)
{
	itsPI = st->getPersistentImp();
	calculateStorageKey(theDate);
	try
	{
		HiLoDataImp t = static_cast<HiLoDataImp>(itsPI->retrieve(*itsStorageKey));
		itsHightTime = t.getHighTime();
		itsHightValue = t.getHighValue();
		itsLowTime = t.getLowTime();
		itsLowValue = t.getLowValue();
	}
	catch (...)
	{
		itsHightValue = itsLowValue = init;
		itsHightTime = itsLowTime = initTime;
	}
}

double HiLoDataImp::getHighValue()
{
	return itsHightValue;
}

long HiLoDataImp::getHighTime()
{
	return itsHightTime;
}

double HiLoDataImp::getLowValue()
{
	return itsLowValue;
}

long HiLoDataImp::getLowTime()
{
	return itsLowTime;
}

void HiLoDataImp::currentReading(double value, long time)
{
	if (value > itsHightValue)
	{
		itsHightValue = value;
		itsHightTime = time;
		store();
	}
	else if (value < itsLowValue)
	{
		itsLowValue = value;
		itsLowTime = time;
		store();
	}
}

void HiLoDataImp::newDay(double initial, long time)
{
	store();

	// reset the value and generate a new key
	itsLowValue = itsHightValue = initial;
	itsLowTime = itsHightTime = time;

	// generate a new key based on the current date and save the new entry
	calculateStorageKey(Date());
	store();
}

void HiLoDataImp::store()
{
	try
	{
		PersistentImp* tempPI = itsPI;
		itsPI = nullptr;
		std::string* tempkey = itsStorageKey;
		itsStorageKey = nullptr;
		
		tempPI->store(*tempkey, this);
		
		itsPI = tempPI;
		itsStorageKey = tempkey;
		
	}
	catch (...)
	{
		// catch registrate error
		throw;
	}
}

void HiLoDataImp::calculateStorageKey(const Date& d)
{
	if (itsStorageKey)
	{
		delete itsStorageKey;
	}
	itsStorageKey = new std::string(TypesToString[static_cast<size_t>(itsType)] + "HiLo"
		+ StringProcessingUtilits::getStringOfGivenLength(std::to_string(d.GetMonth()), 2)
		+ StringProcessingUtilits::getStringOfGivenLength(std::to_string(d.GetDay()), 2)
		+ StringProcessingUtilits::getStringOfGivenLength(std::to_string(d.GetYear()), 4));
}