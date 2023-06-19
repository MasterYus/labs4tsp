#include "IndexOutOfRangeException.h"

IndexOutOfRangeException::IndexOutOfRangeException(int index) { this->index = index; }

string IndexOutOfRangeException::what() { return "Обращение к элементу массива по неправильному индексу"; }

int IndexOutOfRangeException::getIndex() { return index; }

IndexOutOfRangeException::~IndexOutOfRangeException() {}