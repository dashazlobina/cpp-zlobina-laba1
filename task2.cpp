// Задачи: 2.1, 2.3, 2.5, 2.7, 2.9.

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

// 2.1. Возвращает модуль числа x.
int Abs(int x) {
  return x < 0 ? -x : x;
}

// 2.3. Возвращает true, если x делится на 3 или 5, но не на оба сразу.
bool Is35(int x) {
  bool div3 = (x % 3 == 0);
  bool div5 = (x % 5 == 0);
  return div3 != div5;
}

// 2.5. Возвращает максимум из x, y, z.
int Max3(int x, int y, int z) {
  int result = x;
  if (y > result) result = y;
  if (z > result) result = z;
  return result;
}

// 2.7. Возвращает x + y, или 20, если сумма в диапазоне [10, 19].
int Sum2(int x, int y) {
  int sum = x + y;
  if (sum >= 10 && sum <= 19) return 20;
  return sum;
}

// 2.9. Возвращает название дня недели.
std::string Day(int x) {
  switch (x) {
    case 1: return "понедельник";
    case 2: return "вторник";
    case 3: return "среда";
    case 4: return "четверг";
    case 5: return "пятница";
    case 6: return "суббота";
    case 7: return "воскресенье";
    default: return "это не день недели";
  }
}

}  

int main() {
  SetConsoleOutputCP(65001);
  SetConsoleCP(65001);

  std::cout << "Задание 2\n\n";

  // 2.1
  std::cout << "Task 2.1\n";
  int x1 = ReadInt("Введите x: ");
  std::cout << "Модуль: " << Abs(x1) << "\n\n";

  // 2.3
  std::cout << "Task 2.3\n";
  int x3 = ReadInt("Введите x: ");
  std::cout << "Делится на 3 или на 5, но не на оба: "
            << (Is35(x3) ? "true" : "false") << "\n\n";

  // 2.5
  std::cout << "Task 2.5\n";
  int m1 = ReadInt("Введите x: ");
  int m2 = ReadInt("Введите y: ");
  int m3 = ReadInt("Введите z: ");
  std::cout << "Максимум: " << Max3(m1, m2, m3) << "\n\n";

  // 2.7
  std::cout << "Task 2.7\n";
  int s1 = ReadInt("Введите x: ");
  int s2 = ReadInt("Введите y: ");
  std::cout << "Результат: " << Sum2(s1, s2) << "\n\n";

  // 2.9
  std::cout << "Task 2.9\n";
  int d = ReadInt("Введите день недели (1-7): ");
  std::cout << "День: " << Day(d) << "\n";

  return 0;
}