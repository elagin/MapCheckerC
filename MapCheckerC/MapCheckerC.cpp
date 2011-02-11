// MapCheckerC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	ifstream ifs ( "D:\\Projects\\!Personal\\MapCheckerC\\maps\\200k--n39-01.map" , ifstream::in );

	while (ifs.good())
	{
		string line;//= ifs.get();
//		getline( line, ifs);
//		getline( ifs, &line );
//		getline(line );
		line = getline( &ifs);
//		ifs.getline(&line, 20);
	}

	ifs.close();


	return 0;
}

