#pragma once
#include <string>

using namespace std;

class EmptySetException {

public:
    EmptySetException();
    virtual string what() const;
    virtual ~EmptySetException();
};