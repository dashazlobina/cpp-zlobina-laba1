// Задачи: 3.1, 3.3, 3.5, 3.7, 3.9.

#include <windows.h>

#include <iostream>
#include <limits>
#include <sstream>
#include <string>

namespace {

int ReadInt(const std::string& prompt) {
  int value;
  while (true) {
    std::cout << prompt;
    if (std::cin >> value) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return value;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ошибка: введите целое число.\n";
  }
}

// 3.1. Возвращает строку "0 1 2 ... x".
std::string ListNums(int x) {
  std::ostringstream oss;
  for (int i = 0; i <= x; ++i) {
    if (i > 0) oss << " ";
    oss << i;
  }
  return oss.str();
}

// 3.3. Возвращает строку "0 2 4 ... x" без использования if.
std::string Chet(int x) {
  std::ostringstream oss;
  bool first = true;
  for (int i = 0; i <= x; i += 2) {
    if (!first) oss << " ";
    oss << i;
    first = false;
  }
  return oss.str();
}

// 3.5. Возвращает количество знаков в числе x.
int NumLen(long x) {
  if (x == 0) return 1;
  if (x < 0) x = -x;
  int count = 0;
  while (x > 0) {
    x /= 10;
    ++count;
  }
  return count;
}

// 3.7. Печатает квадрат из '*' со стороной x.
void Square(int x) {
  for (int i = 0; i < x; ++i) {
    for (int j = 0; j < x; ++j) {
      std::cout << '*';
    }
    std::cout << '\n';
  }
}

// 3.9. Печатает правый треугольник из '*' высотой x.
void RightTriangle(int x) {
  for (int i = 1; i <= x; ++i) {
    for (int j = 0; j < x - i; ++j) {
      std::cout << ' ';
    }
    for (int j = 0; j < i; ++j) {
      std::cout << '*';
    }
    std::cout << '\n';
  }
}
}  

int main() {
  SetConsoleOutputCP(65001);
  SetConsoleCP(65001);

  std::cout << "Задание 3\n\n";

  // 3.1
  std::cout << "Task 3.1\n";
  int x1 = ReadInt("Введите x: ");
  std::cout << "Числа: " << ListNums(x1) << "\n\n";

  // 3.3
  std::cout << "Task 3.3\n";
  int x3 = ReadInt("Введите x: ");
  std::cout << "Чётные числа: " << Chet(x3) << "\n\n";

  // 3.5
  std::cout << "Task 3.5\n";
  int x5 = ReadInt("Введите число: ");
  std::cout << "Количество знаков: " << NumLen(x5) << "\n\n";

  // 3.7
  std::cout << "Task 3.7\n";
  int sq = ReadInt("Введите размер квадрата: ");
  std::cout << "Квадрат:\n";
  Square(sq);
  std::cout << "\n";

  // 3.9
  std::cout << "Task 3.9\n";
  int rt = ReadInt("Введите высоту треугольника: ");
  std::cout << "Треугольник:\n";
  RightTriangle(rt);

  return 0;
}