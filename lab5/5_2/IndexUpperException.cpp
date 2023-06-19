#include "IndexUpperException.h"

IndexUpperException::IndexUpperException(int index) : IndexOutOfRangeException(index) {}

string IndexUpperException::what() {
    string error = IndexOutOfRangeException::what() + ": ";
    return error + "������ �� ����� ���� ������ ������� �������";
}