#include "IndexOutOfRangeException.h"

class IndexLowerException : public IndexOutOfRangeException {

public:
    IndexLowerException(int index);
    string what();
};
