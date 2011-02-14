#pragma once

class CFile
{
public:
    CFile();
    ~CFile();
    bool open(const string & aStr);
    void write(const string & aStr);

private:
    FILE    *f1;
    string  _fileName;
};
