/* 
 * File:   statistic.h
 * Author: elagin
 *
 * Created on 11 Февраль 2011 г., 18:57
 */

#ifndef STATISTIC_H
#define	STATISTIC_H

#include <map>

typedef map<string, string> times;
typedef pair<string,string> timesPair;
typedef map<string, string>::iterator itTimes;


class CStatistic {
public:
    CStatistic();
    ~CStatistic();

    void appendNotFound(const string & mapName, const string & imgName);
    void printResults();
    
private:
    times _notfound;
};

#endif	/* STATISTIC_H */

