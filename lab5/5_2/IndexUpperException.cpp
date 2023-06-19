#include "IndexUpperException.h"

IndexUpperException::IndexUpperException(int index) : IndexOutOfRangeException(index) {}

string IndexUpperException::what() {
    string error = IndexOutOfRangeException::what() + ": ";
    return error + "Индекс не может быть больше размера массива";
}