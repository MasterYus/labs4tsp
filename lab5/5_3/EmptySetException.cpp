#include "EmptySetException.h"

EmptySetException::EmptySetException() {}

string EmptySetException::what() const { return "Множество пустое"; }

EmptySetException::~EmptySetException() {}