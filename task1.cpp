// Задачи: 1.1, 1.3, 1.5, 1.7, 1.9.

#include <windows.h>
#include <iostream>
#include <limits>
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

double ReadDouble(const std::string& prompt) {
  double value;
  while (true) {
    std::cout << prompt;
    if (std::cin >> value) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return value;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ошибка: введите число.\n";
  }
}

char ReadDigit(const std::string& prompt) {
  char value;
  while (true) {
    std::cout << prompt;
    std::cin >> value;
    if (std::cin.fail()) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Ошибка: введите цифру от 0 до 9.\n";
      continue;
    }
    if (value >= '0' && value <= '9') {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      return value;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Ошибка: введите цифру от 0 до 9.\n";
  }
}

// 1.1. Возвращает дробную часть числа x.
double Fraction(double x) {
  return x - static_cast<int>(x);
}

// 1.3. Преобразует символ в число.
int CharToNum(char x) {
  return x - '0';
}

// 1.5. Возвращает true, если x — двузначное число.
bool Is2Digits(int x) {
  int abs_x = x < 0 ? -x : x;
  return abs_x >= 10 && abs_x <= 99;
}

// 1.7. Возвращает true, если num входит в [a, b].
bool IsInRange(int a, int b, int num) {
  if (a > b) {
    int tmp = a;
    a = b;
    b = tmp;
  }
  return num >= a && num <= b;
}

// 1.9. Возвращает true, если a, b, c равны.
bool IsEqual(int a, int b, int c) {
  return a == b && b == c;
}

}  

int main() {
  SetConsoleOutputCP(65001);
  SetConsoleCP(65001);

  // 1.1
  std::cout << "Task 1.1\n";
  double x1 = ReadDouble("Введите x: ");
  std::cout << "Дробная часть: " << Fraction(x1) << "\n\n";

  // 1.3
  std::cout << "Task 1.3\n";
  char c1 = ReadDigit("Введите цифру: ");
  std::cout << "Число: " << CharToNum(c1) << "\n\n";

  // 1.5
  std::cout << "Task 1.5\n";
  int n1 = ReadInt("Введите число: ");
  std::cout << "Двузначное: " << (Is2Digits(n1) ? "true" : "false") << "\n\n";

  // 1.7
  std::cout << "Task 1.7\n";
  int a1 = ReadInt("Введите a: ");
  int b1 = ReadInt("Введите b: ");
  int num1 = ReadInt("Введите num: ");
  std::cout << "В диапазоне: "
            << (IsInRange(a1, b1, num1) ? "true" : "false") << "\n\n";

  // 1.9
  std::cout << "Task 1.9\n";
  int e1 = ReadInt("Введите a: ");
  int e2 = ReadInt("Введите b: ");
  int e3 = ReadInt("Введите c: ");
  std::cout << "Все равны: "
            << (IsEqual(e1, e2, e3) ? "true" : "false") << "\n";

  return 0;
}