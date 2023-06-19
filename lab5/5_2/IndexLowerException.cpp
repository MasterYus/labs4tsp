#include "IndexLowerException.h"

IndexLowerException::IndexLowerException(int index) : IndexOutOfRangeException(index) {}

string IndexLowerException::what() {
    string error = IndexOutOfRangeException::what() + ": ";
    return error + "������ �� ����� ���� ������ 0";
}