#pragma once
#include <string>

using namespace std;

class IndexOutOfRangeException {
private:
    int index;

public:
    IndexOutOfRangeException(int index);
    virtual string what();
    int getIndex();
    virtual ~IndexOutOfRangeException();
};