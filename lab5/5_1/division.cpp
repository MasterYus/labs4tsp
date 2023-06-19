#include <stdexcept>

inline float division(float divisible, float divider) {
	if (divider == 0) {
		throw std::runtime_error("Ошибка: деление на ноль!\n");
	}
	return divisible / divider;
}