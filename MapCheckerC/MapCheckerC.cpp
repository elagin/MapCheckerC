// MapCheckerC.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <stdlib.h>


#ifdef WIN32
#include <Windows.h>

#else
#include <sys/types.h>
#include <dirent.h>

#endif // WIN32

#include "statistic.h"

CStatistic stat;

// /home/elagin/projects/MapCheckerC/maps

string getImgFilePath(const string & aMapFileName)
{
    string res;
//    cout << "getImgFilePath from file: " << aMapFileName << endl;
    string line;
    ifstream ifs (aMapFileName.c_str(), ifstream::in);
    if(ifs.is_open())
    {
        getline(ifs, line);
        getline(ifs, line);
        if(line.length() > 0)
        {
            int realEnd = line.find_last_of( ".") + 4;
//            cout << "Last " << realEnd << endl;
//            cout << /*"line: " << line << */"size= " << line.length() << endl;
            res.append( line, 0, realEnd );
//            cout << "res: " << res << endl;
            return res;
        }
        ifs.close();
    }
    else
    {
        cout << "Error opening" << endl;
    }
    return res;
}

bool fileIsExist(const string & filename)
{
    FILE * pFile;
    pFile = fopen (filename.c_str(),"r");
    if (pFile!=NULL)
    {
        fclose (pFile);
        return true;
    }
    return false;
}

bool findFiles(const string & aPath)
{
    string path = aPath;

    path.append("/");
    DIR *d = NULL;
    struct dirent *DirEntry = NULL;
    string findFileName = "*.map";
    string fullPathDir = aPath;

    fullPathDir.append("/");
    fullPathDir.append(findFileName);

    d = opendir(aPath.c_str());
    if(d == NULL)
    {
        perror("Couldn't open directory");
        return(false);
    }

    string whildcast = ".map";
    // Loop while not NULL
    while(DirEntry = readdir(d))
    {
//        if(DirEntry->d_type == isFile)
        string fileName = DirEntry->d_name;
        
        if( fileName.find(whildcast) != -1 )
        {
            printf("%s\n",DirEntry->d_name);
            fileName.insert(0, aPath + "/");
            string imgName = getImgFilePath(fileName);
            if( imgName.length() > 0 )
            {
//                cout << "img name: :[" << imgName << "]" << endl;
                imgName.insert(0, path);
                cout << "img name: :[" << imgName << "] ";
                if(fileIsExist(imgName))
                {
                    cout << "Ok" << endl;
                }
                else
                {
                    stat.appendNotFound( filename, imgName );
                    cout << "Not found" << endl;
                }
            }
        }
    }
    closedir(d);
}

#ifdef WIN32
void findFiles(const string & aPath)
{
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	//	argv[3]
	printf ("Target file is %s.\n", argv[1]);

	string findFileName = "*.map";
	string fullPathDir;
	fullPathDir.append(argv[1]);
	fullPathDir.append("\\");
	fullPathDir.append(findFileName);

	cout << fullPathDir << endl;
	hFind = FindFirstFileEx(fullPathDir.c_str(), FindExInfoStandard, &FindFileData, FindExSearchNameMatch, NULL, 0 );

	if (hFind == INVALID_HANDLE_VALUE)
	{
		printf ("Invalid File Handle. GetLastError reports %d\n", GetLastError ());
		return (0);
	}
	else
	{
//		printf ("The first file found is %S\n", FindFileData.cFileName);
//		wcout << "The first file found is " << FindFileData.cFileName << endl;
		wstring mapFileName
                cout << getImgFilePath(mapFileName);

		while (FindNextFile(hFind, &FindFileData) != 0)
		{
//			_tprintf (TEXT("Next file name is: %S\n"), FindFileData.cFileName);
//			 wcout << "Next file found is ";// << FindFileData.cFileName << endl;
		}

		return (1);
	}
	FindClose(hFind);


	string mapFileName = "C:\\Projects\\MapCheckerC\\maps\\200k--n39-01.map";
	cout << getImgFilePath(mapFileName);
}
#endif // WIN32

#ifdef WIN32
int _tmain(int argc, _TCHAR* argv[])
#else
int main ( int argc, char *argv[] )
#endif // WIN32
{
    findFiles(argv[1]);
    stat.printResults();
    return 0;
}

