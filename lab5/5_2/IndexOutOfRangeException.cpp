#include "IndexOutOfRangeException.h"

IndexOutOfRangeException::IndexOutOfRangeException(int index) { this->index = index; }

string IndexOutOfRangeException::what() { return "��������� � �������� ������� �� ������������� �������"; }

int IndexOutOfRangeException::getIndex() { return index; }

IndexOutOfRangeException::~IndexOutOfRangeException() {}