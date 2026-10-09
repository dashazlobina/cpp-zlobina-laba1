Отчет по Лабораторной работе №1
Злобина Дарья , ЛА-3
Задача №1. Методы

№1.
Текст задачи:
Дробная часть.
Дана сигнатура функции: double fraction (double x);
Необходимо реализовать функцию таким образом, чтобы она возвращала
только дробную часть числа х. Подсказка: вещественное число может быть
преобразовано к целому путем отбрасывания дробной части.
Пример:
x=5,25
результат: 0,25
Алгоритм решения: 
1. Преобразовать `x` к целому типу `int` — при этом дробная часть
   отбрасывается. Для этого используется `static_cast<int>(x)`.
2. Вычесть полученное целое из исходного: `x - static_cast<int>(x)`.
3. Вернуть результат.
Тестирование:
<img width="358" height="151" alt="image" src="https://github.com/user-attachments/assets/0724a8ea-66e5-4578-9ef3-70f9ad891899" />
<img width="370" height="161" alt="image" src="https://github.com/user-attachments/assets/5524afb6-1b12-4a61-823d-7ff3ebc66052" />
<img width="280" height="127" alt="image" src="https://github.com/user-attachments/assets/aa209f4c-68a7-48ec-8ee1-c698f30ad5fc" />
<img width="355" height="102" alt="image" src="https://github.com/user-attachments/assets/e34e9e48-86df-4976-b5ff-ca0ba36f9acc" />

№3
Текст задачи: 
Букву в число. Дана сигнатура функции: int charToNum (char x); Функция принимает символ х, который представляет собой один из “0 1 2 3 4 5 6 7 8 9”. Необходимо реализовать функцию таким образом, чтобы она преобразовывала символ в соответствующее число. Подсказка: код символа ‘0’ — это число 48. Пример: x=’3’ результат: 3 
Алгоритм решения: 

1. Символы `'0'..'9'` идут подряд: коды 48, 49, ..., 57.
2. Чтобы получить числовое значение символа-цифры, нужно вычесть
   из него код символа `'0'`:  return x - '0';
3. Например, `'3' - '0' = 51 - 48 = 3
Тестирование:
<img width="269" height="120" alt="image" src="https://github.com/user-attachments/assets/1e254e20-333c-4423-b5b9-6ed9bef0bd50" />
<img width="510" height="190" alt="image" src="https://github.com/user-attachments/assets/33c5d531-bc54-4259-8cac-e6c78b46e7d3" />

№5
Текст задачи: 
Двузначное. Дана сигнатура функции: bool is2Digits (int x); Необходимо реализовать функцию таким образом, чтобы она принимала число x и возвращала true, если оно двузначное. Пример 1: x=32 результат: true Пример 2: x=516 результат: false 
Алгоритм решения: 
1. Взять модуль числа `x`, чтобы работать с отрицательными числами: int abs_x = x < 0 ? -x : x;
2. Проверить, что модуль лежит в диапазоне `[10, 99]` включительно: return abs_x >= 10 && abs_x <= 99;
3. Если да — вернуть `true`, иначе — `false`.
Тестирование: 
<img width="276" height="120" alt="image" src="https://github.com/user-attachments/assets/095602d8-f2b8-4172-a4c9-a5ed2fb30e80" />
<img width="338" height="134" alt="image" src="https://github.com/user-attachments/assets/6e841148-f7b8-4e79-9cf2-00351d4654cf" />
<img width="304" height="120" alt="image" src="https://github.com/user-attachments/assets/078371fa-3a45-4cb6-a9b1-641514fe0e5b" />

№7
Текст задачи: 
Диапазон. Дана сигнатура функции: bool isInRange (int a, int b, int num); Функция принимает левую и правую границу (a и b) некоторого числового диапазона. Необходимо реализовать функцию таким образом, чтобы она возвращала true, если num входит в указанный диапазон (включая границы). Обратите внимание, что отношение a и b заранее неизвестно (неясно кто из них больше, а кто меньше) Пример 1: a=5 b=1 num=3 результат: true Пример 2: a=2 b=15 num=33 результат: false 
Алгоритм решения: 
1. Если `a > b`, поменять их местами (чтобы `a` была меньшей границей):  
if (a > b) {
    int tmp = a;
    a = b;
    b = tmp;
}
2. Проверить, что `num` больше или равен `a` и меньше или равен `b`:  return num >= a && num <= b;
3. Если да — вернуть `true`, иначе — `false`.
Тестирование:
<img width="311" height="192" alt="image" src="https://github.com/user-attachments/assets/80b0d6af-505f-41bc-b659-2395be520d4a" />
<img width="287" height="181" alt="image" src="https://github.com/user-attachments/assets/00643b5f-3f20-4f6d-a968-8c5b1ba97045" />
<img width="292" height="182" alt="image" src="https://github.com/user-attachments/assets/814f2f9d-037c-46b0-9392-e692fb1370b1" />
<img width="278" height="189" alt="image" src="https://github.com/user-attachments/assets/5c57b54c-7c5f-481b-b905-521587c7ca41" />

№9
Текст задачи: 
Равенство. Дана сигнатура функции: bool isEqual(int a, int b, int c); Необходимо реализовать функцию таким образом, чтобы она возвращала true, если все три полученных функцией числа равны Пример 1: a=3 b=3 с=3 результат: true Пример 2: a=2 b=15 с=2 результат: false 
Алгоритм решения: 
1. Проверить, что `a == b`.
2. Проверить, что `b == c`.
3. Если оба условия истинны, значит `a == c` автоматически —
   возвращаем `true`. Иначе — `false`.
 bool IsEqual(int a, int b, int c) {
   return a == b && b == c;
Тестирование: 
<img width="260" height="176" alt="image" src="https://github.com/user-attachments/assets/eb8d8e1b-8660-4708-9260-a04e55d5d431" />
<img width="248" height="184" alt="image" src="https://github.com/user-attachments/assets/910d710b-e5d3-4ed9-9f17-8c11186d6861" />

Задача №2. Условия
№2
Текст задачи: 
Модуль числа. Дана сигнатура функции: int abs (int x); Необходимо реализовать функцию таким образом, чтобы она возвращала модуль числа х (если оно было положительным, то таким и остается, если он было отрицательным – то необходимо вернуть его без знака минус). Пример 1: x=5 результат: 5 Пример 2: x=-3 результат: 3 
Алгоритм решения: 
1. Проверить, меньше ли `x` нуля (`x < 0`).
2. Если да — вернуть `-x`.
3. Если нет — вернуть сам `x`.
4. Реализация через оператор: `x < 0 ? -x : x`.
Тестирование: 
<img width="438" height="142" alt="image" src="https://github.com/user-attachments/assets/fa7382d8-6021-4ed3-9f67-ae016499e505" />
<img width="241" height="117" alt="image" src="https://github.com/user-attachments/assets/839fc1ed-d0fd-4b77-96c0-07eb30b48239" />
<img width="207" height="108" alt="image" src="https://github.com/user-attachments/assets/a9a05376-0b74-4809-bb94-62ca2fd60dc3" />
<img width="228" height="100" alt="image" src="https://github.com/user-attachments/assets/aef7abf8-72e8-4637-a7eb-85c6291bc97a" />

№3
Текст задачи: 
Тридцать пять.
Дана сигнатура функции: bool is35 (int x);
Необходимо реализовать функцию таким образом, чтобы она возвращала true,
если число x делится нацело на 3 или 5. При этом, если оно делится и на 3, и на
5, то вернуть надо false. Подсказка: оператор % позволяет получить остаток от
деления.
Пример 1:
x=5
результат: true
Пример 2:
x=8
результат: false
Пример 3:
x=15
результат: false
Алгоритм решения: 
1. Проверить, делится ли `x` на 3: `x % 3 == 0`.
2. Проверить, делится ли `x` на 5: `x % 5 == 0`.
3. Вернуть `true`, если ровно одно из условий истинно.
4. XOR для `bool` — это оператор `!=`: `div3 != div5`.
Тестирование: 
<img width="670" height="108" alt="image" src="https://github.com/user-attachments/assets/1079ab89-a44b-4e9a-a9e4-ee72cda2fc42" />
<img width="641" height="105" alt="image" src="https://github.com/user-attachments/assets/80734fad-3668-40a1-a55b-9e4bee9ed14b" />
<img width="637" height="109" alt="image" src="https://github.com/user-attachments/assets/cff374e2-6cd3-46f3-95e8-91beb9159f76" />
<img width="646" height="121" alt="image" src="https://github.com/user-attachments/assets/737dbb0a-7282-40f4-a09c-c0318fc5c320" />

№5
Текст задачи: 
Тройной максимум. Дана сигнатура функции: int max3 (int x, int y, int z); Необходимо реализовать функцию таким образом, чтобы она возвращала максимальное из трех полученных функцией чисел. Подсказка: идеальное решение включает всего две инструкции if и не содержит вложенных if. Пример 1: x=5 y=7 z=7 результат: 7 Пример 2: x=8 y=-1 z=4 результат: 8 

Алгоритм решения: 
1. Предположить, что максимум — это `x`. Записать в переменную `result`.
2. Если `y > result` — обновить `result = y`.
3. Если `z > result` — обновить `result = z`.
4. Вернуть `result`.
int Max3(int x, int y, int z) {
  int result = x;
  if (y > result) result = y;
  if (z > result) result = z;
  return result;
}
Тестирование: 
<img width="220" height="186" alt="image" src="https://github.com/user-attachments/assets/6c6bad2d-791c-4fb9-a682-69d694b68b7f" />
<img width="209" height="188" alt="image" src="https://github.com/user-attachments/assets/18eedc50-594b-4d66-a2af-7bb95a0a9927" />
<img width="207" height="215" alt="image" src="https://github.com/user-attachments/assets/843bf46f-ceed-4251-80a4-a8f602e59a26" />

№7
Текст задачи: 
Двойная сумма. Дана сигнатура функции: int sum2 (int x, int y); Необходимо реализовать функцию таким образом, чтобы она возвращала сумму чисел x и y. Однако, если сумма попадает в диапазон от 10 до 19, то надо вернуть число 20. Пример 1: x=5 y=7 результат: 20 Пример 2: x=8 y=-1 результат: 7 
Алгоритм решения: 
1. Посчитать сумму: `int sum = x + y;`.
2. Проверить, что `sum` в диапазоне `[10, 19]`:
   `sum >= 10 && sum <= 19`.
3. Если да — вернуть `20`.
4. Если нет — вернуть саму сумму `sum`.

Тестирование: 
<img width="236" height="168" alt="image" src="https://github.com/user-attachments/assets/e7883591-73c3-4161-b1a1-74bdb2e83887" />
<img width="227" height="152" alt="image" src="https://github.com/user-attachments/assets/2af1ed46-c222-45b7-868d-2210768e9492" />

№9
Текст задачи: 
День недели. Дана сигнатура функции: String day (int x); Функция принимает число x, обозначающее день недели. Необходимо реализовать функцию таким образом, чтобы она возвращала строку, которая будет обозначать текущий день недели, где 1 — это понедельник, а 7 – воскресенье. Если число не от 1 до 7 то верните текст “это не день недели”. Вместо if в данной задаче используйте switch. Пример: x=5 результат: “пятница” 
Алгоритм решения: 
1. Использовать конструкцию `switch (x)`.
2. Для каждого значения `x` от 1 до 7 вернуть соответствующую строку.
3. Для всех остальных значений (ветка `default`) вернуть
   `"это не день недели"`.
Тестирование: 
<img width="465" height="117" alt="image" src="https://github.com/user-attachments/assets/1d639933-6f03-4ad3-b9b1-fe23531b211c" />
<img width="447" height="121" alt="image" src="https://github.com/user-attachments/assets/6e26459c-f863-4363-8daf-b0b4f40fdd49" />

Задача №3. Циклы
№1
Текст задачи: 
Числа подряд. Дана сигнатура функции: String listNums (int x); Необходимо реализовать функцию таким образом, чтобы она возвращала строку, в которой будут записаны все числа от 0 до x (включительно). Пример: x=5 результат: “0 1 2 3 4 5” 
Алгоритм решения: 
1. Создать пустой поток `std::ostringstream oss` для сборки строки.
2. Пройти циклом `for` от `i = 0` до `i <= x`.
3. Перед каждым числом, кроме первого, добавить пробел: if (i > 0) oss << " ";
4. Дописать число `i` в поток: oss << i;
5. Вернуть `oss.str()` — готовую строку.
Тестирование: 
<img width="433" height="183" alt="image" src="https://github.com/user-attachments/assets/417c8f18-6b53-4421-b750-611f7e3713d9" />
<img width="246" height="135" alt="image" src="https://github.com/user-attachments/assets/972acff9-cff5-4aed-84f8-d81b64a54685" />
<img width="214" height="117" alt="image" src="https://github.com/user-attachments/assets/eaa5a235-2d7c-461f-b607-58391b75311e" />

№3
Текст задачи: 
Четные числа. Дана сигнатура функции: String chet (int x); Необходимо реализовать функцию таким образом, чтобы она возвращала строку, в которой будут записаны все четные числа от 0 до x (включительно). Подсказа для обеспечения качества кода: инструкцию if использовать не следует. Пример: x=9 результат: “0 2 4 6 8” 
Алгоритм решения: 
1. Создать пустой поток `std::ostringstream oss`.
2. Пройти циклом `for` с шагом 2: for (int i = 0; i <= x; i += 2) 
3. Перед каждым числом, кроме первого, добавить пробел:  
if (!first) oss << " ";
    oss << i;
    first = false;
4. Вернуть готовую строку.
Тестирование: 
<img width="331" height="118" alt="image" src="https://github.com/user-attachments/assets/71c2bb66-25d3-4f87-bd88-746d838cd940" />
<img width="376" height="118" alt="image" src="https://github.com/user-attachments/assets/137801b0-4929-4ec3-90e1-1b02490a7490" />

№5 
Текст задачи: 
Длина числа. Дана сигнатура функции: int numLen (long x); Необходимо реализовать функцию таким образом, чтобы она возвращала количество знаков в числе x. Подсказка: Int у=123/10; // у будет иметь значение 12 Пример: x=12567 результат: 5 
Алгоритм решения: 
1. Если `x == 0` — вернуть `1`.
2. Если `x < 0` — заменить на модуль `x = -x`.
3. Инициализировать счётчик `count = 0`.
4. Пока `x > 0`:
   - Разделить `x` на 10 (отбросить последнюю цифру): `x /= 10`.
   - Увеличить счётчик: `++count`.
5. Вернуть `count`.
Тестирование: 
<img width="339" height="124" alt="image" src="https://github.com/user-attachments/assets/5c2ab071-78f4-4054-bdef-3dd22206cce2" />
<img width="328" height="108" alt="image" src="https://github.com/user-attachments/assets/10b80015-2938-419e-aaed-2225fe3ee0e0" />
<img width="330" height="93" alt="image" src="https://github.com/user-attachments/assets/5e1bc0c1-330d-46f6-8309-2aa77acd9cfe" />
<img width="331" height="112" alt="image" src="https://github.com/user-attachments/assets/c99e6d43-e746-4c65-9637-55afbd8ca371" />

№7
Текст задачи: 
Квадрат. Дана сигнатура функции: void square (int x); Необходимо реализовать функцию таким образом, чтобы она выводила на экран квадрат из символов ‘*’ размером х, у которого х символов в ряд и х символов в высоту. Пример 1: x=2 результат: ** ** Пример 2: x=4 результат: **** **** **** **** 
Алгоритм решения: 
1. Внешний цикл `for` от `i = 0` до `x` — по строкам.
2. Внутренний цикл `for` от `j = 0` до `x` — по столбцам.
3. В каждой итерации внутреннего цикла печатать `'*'`.
4. После внутреннего цикла — переход на новую строку: `'\n'`.
Тестирование: 
<img width="406" height="116" alt="image" src="https://github.com/user-attachments/assets/cd80bf4e-7a67-429f-af4e-61fa57145f5a" />
<img width="422" height="277" alt="image" src="https://github.com/user-attachments/assets/dc9fbaae-a9ec-4b47-bd0f-e4ecf9948848" />

№9
Текст задачи: 
Правый треугольник. Дана сигнатура функции: void rightTriangle (int x); Необходимо реализовать функцию таким образом, чтобы она выводила на экран треугольник из символов ‘*’ у которого х символов в высоту, а количество символов в ряду совпадает с номером строки, при этом треугольник выровнен по правому краю. Подсказка: перед символами ‘*’ следует выводить необходимое количество пробелов. Пример 1: x=3 результат: * ** *** Пример 2: x=4 результат: * ** *** **** 
Алгоритм решения: 
1. Внешний цикл `for` от `i = 1` до `x` — по строкам.
2. Печатаем `(x - i)` пробелов (отступ слева).
3. Печатаем `i` звёздочек.
4. Переход на новую строку.
Тестирование: 
<img width="469" height="152" alt="image" src="https://github.com/user-attachments/assets/1b5c6670-b16a-4c35-978b-e7714cf44d18" />
<img width="510" height="290" alt="image" src="https://github.com/user-attachments/assets/72315725-3904-48c9-9d07-e51eec2547ce" />

Задача №4. Массивы
№1
Текст задачи: 
Поиск первого значения. Дана сигнатура функции: int findFirst (int arr[], int x); Необходимо реализовать функцию таким образом, чтобы она возвращала индекс первого вхождения числа x в массив arr. Если число не входит в массив – возвращается -1. Пример: arr=[1,2,3,4,2,2,5] x=2 результат: 1 
Алгоритм решения: 
1. Пройти циклом `for` по всем индексам `i` от 0 до `size - 1`.
2. Если `arr[i] == x` — вернуть `i` (первое вхождение найдено).
3. Если цикл дошёл до конца и ничего не нашёл — вернуть `-1`.
Тестирование: 
<img width="448" height="273" alt="image" src="https://github.com/user-attachments/assets/752ccf81-0832-4ee0-ae6f-6103a0db4783" />
<img width="446" height="329" alt="image" src="https://github.com/user-attachments/assets/052da113-7950-43ea-abf2-0b0988300adc" />

№3
Текст задачи: 
Поиск максимального. Дана сигнатура функции: int maxAbs (int arr[]); Необходимо реализовать функцию таким образом, чтобы она возвращала наибольшее по модулю (то есть без учета знака) значение массива arr. Пример: arr=[1,-2,-7,4,2,2,5] результат: -7 
Алгоритм решения: 
1. Если размер массива равен 0 — вернуть 0.
2. Предположить, что первый элемент — максимум: `best = arr[0]`.
3. Пройти циклом по остальным элементам начиная с индекса 1.
4. Если `|arr[i]| > |best|` — обновить `best = arr[i]`.
5. Вернуть `best`.
Тестирование: 
<img width="398" height="263" alt="image" src="https://github.com/user-attachments/assets/827b078c-36b3-4b37-b833-ea5945597dae" />
<img width="427" height="256" alt="image" src="https://github.com/user-attachments/assets/3655d0cb-de07-4099-b977-5a90c5798a6b" />

№5
Текст задачи: 
Добавление массива в массив. Дана сигнатура функции: int * add (int arr[], int ins[], int pos); Необходимо реализовать функцию таким образом, чтобы она возвращала новый массив, который будет содержать все элементы массива arr, однако в позицию pos будут вставлены значения массива ins. Пример: arr=[1,2,3,4,5] ins=[7,8,9] pos=3 результат: [1,2,3,7,8,9,4,5] 
Алгоритм решения: 
1. Выделить память под новый массив размера `arr_size + ins_size`
   через `new int[...]`: int* Add(int arr[], int arr_size, int ins[], int ins_size, int pos)
2. Скопировать первые `pos` элементов из `arr`:
 for (int i = 0; i < pos; ++i) {
    result[i] = arr[i];
3. Скопировать все элементы `ins`, начиная с позиции `pos`.
 for (int i = 0; i < ins_size; ++i) {
    result[pos + i] = ins[i];
4. Скопировать остаток `arr` (элементы с `pos` до конца) со сдвигом
   на `ins_size`.
for (int i = pos; i < arr_size; ++i) {
    result[i + ins_size] = arr[i];
5. Вернуть указатель на новый массив.
Тестирование:
<img width="455" height="440" alt="image" src="https://github.com/user-attachments/assets/19594576-2bcb-41d9-ba44-21239833737a" />
<img width="516" height="431" alt="image" src="https://github.com/user-attachments/assets/d994d7e8-9713-4b6b-9ffd-74decc7bc1cb" />

№7
Текст задачи: 
Возвратный реверс. Дана сигнатура функции: int * reverseBack (int arr[]); Необходимо реализовать функцию таким образом, чтобы она возвращала новый массив, в котором значения массива arr записаны задом наперед. Пример: arr=[1,2,3,4,5] результат: [5,4,3,2,1] 
Алгоритм решения: 
1. Выделить память под новый массив того же размера через
   `new int[size]`.
2. Пройти циклом `for` от `i = 0` до `size - 1`.
3. В ячейку `result[i]` записать `arr[size - 1 - i]` —
   то есть элемент с противоположного конца исходного массива.
4. Вернуть указатель на новый массив.
Тестирование: 
<img width="460" height="321" alt="image" src="https://github.com/user-attachments/assets/c25ea220-fc7e-4df7-bac0-d9a0f50b363a" />
<img width="397" height="307" alt="image" src="https://github.com/user-attachments/assets/6a5d7d74-092d-413d-acb5-bdedf8c9b289" />

№9 
Текст задачи: 
Все вхождения. Дана сигнатура функции: int * findAll (int arr[], int x); Необходимо реализовать функцию таким образом, чтобы она возвращала новый массив, в котором записаны индексы всех вхождений числа x в массив arr. Пример: arr=[1,2,3,8,2,2,9] x=2 результат: [1,4,5] 
Алгоритм решения: 
1. Первый проход. Посчитать количество вхождений `x` в массив —
   переменная `count`.
2. Выделить память под массив размера `count + 1`.
3. В ячейку `result[0]` записать `count` (сколько всего вхождений).
4. Второй проход. Пройти по массиву и в ячейки
   `result[1..count]` записать индексы всех вхождений `x`.
5. Вернуть указатель на новый массив.



Тестирование:
<img width="432" height="215" alt="image" src="https://github.com/user-attachments/assets/43016dc0-832a-45a2-a656-aca54a9c3678" />
<img width="401" height="369" alt="image" src="https://github.com/user-attachments/assets/755a287a-dad5-48a5-8e69-a9094484ee61" />
<img width="386" height="292" alt="image" src="https://github.com/user-attachments/assets/3432076e-3701-4766-9a55-7eb67dc2c562" />


