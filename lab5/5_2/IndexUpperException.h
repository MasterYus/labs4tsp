#include "IndexOutOfRangeException.h"

class IndexUpperException : public IndexOutOfRangeException {

public:
    IndexUpperException(int index);
    string what();
};