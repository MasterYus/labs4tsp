#include "EmptySetException.h"

EmptySetException::EmptySetException() {}

string EmptySetException::what() const { return "��������� ������"; }

EmptySetException::~EmptySetException() {}