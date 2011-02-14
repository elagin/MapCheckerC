/* 
 * File:   statistic.cpp
 * Author: elagin
 * 
 * Created on 11 Февраль 2011 г., 18:57
 */
#include "stdafx.h"
#include <fstream>
#include "statistic.h"
//#include "file.h"

CStatistic::CStatistic() {}

void CStatistic::appendNotFound(const string & mapName, const string & imgName)
{
    _notfound.insert(timesPair(mapName, imgName));
}

CStatistic::~CStatistic() {}

void CStatistic::procResults()
{
#ifdef WIN32
    string fileName("del.cmd");
#else
    string fileName("del.sh");
#endif
    if(!_notfound.empty() )
    {
//        _deleteFile.open("del.cmd");
        
        ofstream outfile (fileName.c_str(),ofstream::binary);

        cout << "Files not found:" << endl;
        itTimes it;
        for ( it = _notfound.begin(); it != _notfound.end(); it++ ){
             cout << "map: " << it->first << " - img: " << it->second << endl;

#ifdef WIN32
            outfile << "del ";
#else
            outfile << "rm ";
#endif
            outfile << it->first;
//            _deleteFile.write(it->second);
            outfile << endl;
        }
        outfile.close();
        cout << "Found bad files is: " << _notfound.size() << endl << "Please, run " << fileName << endl;
    }
}

