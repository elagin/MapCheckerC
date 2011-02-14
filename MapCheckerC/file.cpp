#include "stdafx.h"
#include "file.h"

CFile::CFile()
{
    f1 = NULL;
}

CFile::~CFile()
{
    if(f1 != NULL)
    {
        fclose(f1);
    }
}

bool CFile::open(const string & aStr)
{
    f1 = fopen(aStr.c_str(), "a");
    return f1 != NULL;
}

void CFile::write(const string & aStr)
{
    string out = aStr + "\n";
    if(f1 != NULL)
    {
        fprintf(f1, "%s", aStr.c_str());
    }
    else
    {
        cout << "Error write to file" << endl;
    }
}