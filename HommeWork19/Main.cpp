#include <iostream>
#include <cstdlib>
#include <ctime>

int my_common_divider(int num1, int num2) {
    while (num1 > 0 && num2 > 0) {
        if (num1 > num2) {
            num1 %= num2;
        }
        else
            num2 %= num1;
    }
    return num1 + num2;
}

int my_mirror_number(int num) {
    int n{};
    while (num) {
        n *= 10;
        n += num % 10;
        num /= 10;
    }
    return n;
}

template <typename T>
int my_search_index(T arr[], const int length, T key, int begin = 0) {
    for (int k = begin; k < length; k++) {
        if (arr[k] == key) {
            for (int i = length-1; i > 0; i--) {
                for (int j = k+1; j < i; j++) {
                    if (arr[j] > arr[j + 1]) {
                        int tmp;
                        tmp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = tmp;
                    }
                }
            }
            return k;
        }
    }    
    return -1;
}

template<typename T>
void my_fill_arr(T arr[], const int lenght, int left, int right) {
    srand(time(NULL));
    for (int i = 0; i < lenght; i++)
        arr[i] = rand() % (right - left+1) + left;
}

int main() {
	setlocale(LC_ALL, "Russian");

    /*
    Задача 1
    Создайте функцию, которая принимает два числа и возвращает их наибольший общий делитель.
    */

	std::cout << "Задача 1.\nНаибольший общий делитель: " << my_common_divider(10, 20) << "\n\n";

    /*
    Задача 2
    Напишите функцию mirror_number, которая принимает число и возвращает его в отражённом виде.
    */

    std::cout << "Задача 2.\nЗеркальное число: " << my_mirror_number(123456789) << "\n\n";

    /*
    Задача 3
    Создайте функцию, которая принимает массив, его длину и число N. Функция возвращает первую позицию 
    числа N в массиве, а также сортирует все элементы, которые находятся справа от N.
    */

    const int size1 = 10;
    int arr1[size1] = { 1, 2, 10, 8, 9, 6, 7, 4, 5, 3 };
    std::cout << "Задача 3\nИзначальный массив:\n";
    std::cout << "{ ";
    for (int i = 0; i < size1; i++) {
        std::cout << arr1[i] << ", ";
    }
    std::cout << "\b\b }\n";
    std::cout << "Индекс числа: " << my_search_index(arr1, size1, 10) << "\n";
    std::cout << "Изменный массив:\n";
    std::cout << "{ ";
    for (int i = 0; i < size1; i++) {
        std::cout << arr1[i] << ", ";
    }
    std::cout << "\b\b }\n\n";

    /*
    Задача 4
    Создайте функцию, которая принимает пустой массив, его длину и два числа A и B, которые являются 
    началом и концом диапазона. Функция должна заполнять массив случайными числами из указанного диапазона.
    */
    
    std::cout << "Задача 4\nМассив:\n";
    const int size2 = 10;
    int arr2[size2];
    my_fill_arr(arr2, size2, 1, 10);
    std::cout << "{ ";
    for (int i = 0; i < size2; i++) {
        std::cout << arr2[i] << ", ";
    }
    std::cout << "\b\b }\n";

	return 0;
}