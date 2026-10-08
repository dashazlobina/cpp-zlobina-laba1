// Задачи: 4.1, 4.3, 4.5, 4.7, 4.9.

#include <windows.h>
#include <cstdlib>
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

// Заполняет массив arr размера size 
void FillArray(int arr[], int size, const std::string& name) {
  for (int i = 0; i < size; ++i) {
    arr[i] = ReadInt(name + "[" + std::to_string(i) + "] = ");
  }
}

// Печатает массив arr размера size
void PrintArray(int arr[], int size) {
  std::cout << "[";
  for (int i = 0; i < size; ++i) {
    if (i > 0) std::cout << ", ";
    std::cout << arr[i];
  }
  std::cout << "]";
}

// 4.1. Индекс первого вхождения x в arr или -1.
int FindFirst(int arr[], int size, int x) {
  for (int i = 0; i < size; ++i) {
    if (arr[i] == x) return i;
  }
  return -1;
}

// 4.3. Элемент массива с максимальным модулем.
int MaxAbs(int arr[], int size) {
  if (size == 0) return 0;
  int best = arr[0];
  for (int i = 1; i < size; ++i) {
    if (std::abs(arr[i]) > std::abs(best)) {
      best = arr[i];
    }
  }
  return best;
}

// 4.5. Новый массив arr, в который вставлен ins на позицию pos.
int* Add(int arr[], int arr_size, int ins[], int ins_size, int pos) {
  int* result = new int[arr_size + ins_size];
  for (int i = 0; i < pos; ++i) {
    result[i] = arr[i];
  }
  for (int i = 0; i < ins_size; ++i) {
    result[pos + i] = ins[i];
  }
  for (int i = pos; i < arr_size; ++i) {
    result[i + ins_size] = arr[i];
  }
  return result;
}

// 4.7. Новый массив — перевёрнутый arr.
int* ReverseBack(int arr[], int size) {
  int* result = new int[size];
  for (int i = 0; i < size; ++i) {
    result[i] = arr[size - 1 - i];
  }
  return result;
}

// 4.9. Новый массив с индексами всех вхождений x.
int* FindAll(int arr[], int size, int x) {
  int count = 0;
  for (int i = 0; i < size; ++i) {
    if (arr[i] == x) ++count;
  }

  int* result = new int[count + 1];
  result[0] = count;
  int idx = 1;
  for (int i = 0; i < size; ++i) {
    if (arr[i] == x) {
      result[idx++] = i;
    }
  }
  return result;
}

}  

int main() {
  SetConsoleOutputCP(65001);
  SetConsoleCP(65001);

  std::cout << "Задание 4\n\n";

  // 4.1
  std::cout << "Task 4.1\n";
  int size_41 = ReadInt("Введите размер массива: ");
  int* arr_41 = new int[size_41];
  FillArray(arr_41, size_41, "arr");
  int x_41 = ReadInt("Введите x: ");
  std::cout << "Индекс первого вхождения: "
            << FindFirst(arr_41, size_41, x_41) << "\n\n";
  delete[] arr_41;

  // 4.3
  std::cout << "Task 4.3\n";
  int size_43 = ReadInt("Введите размер массива: ");
  int* arr_43 = new int[size_43];
  FillArray(arr_43, size_43, "arr");
  std::cout << "Максимум по модулю: " << MaxAbs(arr_43, size_43) << "\n\n";
  delete[] arr_43;

  // 4.5
  std::cout << "Task 4.5\n";
  int size_arr = ReadInt("Введите размер arr: ");
  int* arr_45 = new int[size_arr];
  FillArray(arr_45, size_arr, "arr");
  int size_ins = ReadInt("Введите размер ins: ");
  int* ins_45 = new int[size_ins];
  FillArray(ins_45, size_ins, "ins");
  int pos_45 = ReadInt("Введите позицию вставки: ");
  if (pos_45 < 0 || pos_45 > size_arr) {
    std::cout << "Ошибка: позиция должна быть в диапазоне [0, "
              << size_arr << "].\n\n";
  } else {
    int* result_45 = Add(arr_45, size_arr, ins_45, size_ins, pos_45);
    std::cout << "Результат: ";
    PrintArray(result_45, size_arr + size_ins);
    std::cout << "\n\n";
    delete[] result_45;
  }
  delete[] arr_45;
  delete[] ins_45;

  // 4.7
  std::cout << "Task 4.7\n";
  int size_47 = ReadInt("Введите размер массива: ");
  int* arr_47 = new int[size_47];
  FillArray(arr_47, size_47, "arr");
  int* rev_47 = ReverseBack(arr_47, size_47);
  std::cout << "Исходный: ";
  PrintArray(arr_47, size_47);
  std::cout << "\nОбратный: ";
  PrintArray(rev_47, size_47);
  std::cout << "\n\n";
  delete[] arr_47;
  delete[] rev_47;

  // 4.9
  std::cout << "Task 4.9\n";
  int size_49 = ReadInt("Введите размер массива: ");
  int* arr_49 = new int[size_49];
  FillArray(arr_49, size_49, "arr");
  int x_49 = ReadInt("Введите x: ");
  int* idx_49 = FindAll(arr_49, size_49, x_49);
  std::cout << "Количество вхождений: " << idx_49[0] << "\n";
  std::cout << "Индексы: ";
  PrintArray(idx_49 + 1, idx_49[0]);
  std::cout << "\n";
  delete[] arr_49;
  delete[] idx_49;

  return 0;
}