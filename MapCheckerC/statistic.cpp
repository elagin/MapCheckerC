/* 
 * File:   statistic.cpp
 * Author: elagin
 * 
 * Created on 11 Февраль 2011 г., 18:57
 */
#include "stdafx.h"
#include "statistic.h"

CStatistic::CStatistic() {}

void CStatistic::appendNotFound(const string & mapName, const string & imgName)
{
    _notfound.insert(timesPair(mapName, imgName));
}

CStatistic::~CStatistic() {}

void CStatistic::printResults()
{
    if(!_notfound.empty() )
    {
        cout << "Files not found:" << endl;
        itTimes it;
        for ( it = _notfound.begin(); it != _notfound.end(); it++ ){
            cout << "Error: " << it->first << " count: " << it->second << endl;
        }
    }
}

