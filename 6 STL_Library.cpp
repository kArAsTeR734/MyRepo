// 6 STL_Library.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<deque>
#include<algorithm>
#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    deque<int>arr;

    for (int i = 0; i < 21; i++) {
        arr.push_back(rand() % 100);
    }
    char s;
    /*int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (i % 10 == 0)
            cout << endl;
        cout << arr[i] << "   ";
    }*/
    cout << "Введите номер задания" << endl;
    cout << "1.Заменить максимальный элемент минимальным." << endl;
    cout << "2. Удалить все элементы, по значению меньшие среднего арифметического." << endl;
    cout << "3. Отсортировать по убыванию." << endl;
    cout << "4. Найти медиану (элемент в центре отсортированной последовательности)." << endl;
    cout << "5. Изменить знак каждого элемента в контейнере." << endl;
    cin >> s;
    if (s == '1') {
        for (auto iter = arr.begin(); iter < arr.end(); iter++) {
            cout << *iter << "  ";
        }
        auto max_elem = max_element(arr.begin(), arr.end());
        auto min_elem = min_element(arr.begin(), arr.end());

        cout << "\n";

        cout << "Максимальный элемент в деке" << endl;
        cout << *max_elem << endl;

        cout << "Минимальный элемент в деке" << endl;
        cout << *min_elem;

        replace(arr.begin(), arr.end(), *max_elem, *min_elem);
        cout << "\n";
        cout << "Массив после замены элемента" << endl;
        for (auto iter = arr.begin(); iter < arr.end(); iter++) {
            cout << *iter << "  ";
        }
    }
    if (s == '2') {
        double avg = 0;
        auto sum = 0;

        for (auto i = arr.begin(); i < arr.end();i++) {
            std::cout << *i << " ";
        }

        for (auto i = arr.begin(); i < arr.end();i++) {
            sum += *i;
        }

        avg = sum / arr.size();
        cout << "\nСреднее арифметическое = :" << avg << endl;

        arr.erase(std::remove_if(arr.begin(), arr.end(), [avg](int num) { return num < avg; }), arr.end());
        cout << "\n";
        for (int num : arr) {
            std::cout << num << " ";
        }
    }
    if (s == '3') {
        struct Compare {
            bool operator() (const int& a, const int& b) {
                return a > b;
            }
        };
        cout << "Исходная последовательность: " << endl;
        for (int i : arr)
            cout << i << " ";
        sort(arr.begin(), arr.end(),Compare());
        cout << "\n";
        cout << "Отсортированная последовательность" << endl;
        for (int i : arr)
            cout << i << " ";
    }
    if (s == '4') {
        cout << "Исходная последовательность " << endl;
        for (int i : arr) {
            cout << i << " ";
        }
        sort(arr.begin(), arr.end());
        cout << "\nОтсортированная последовательность: " << endl;
        for (int i : arr) {
            cout << i << " ";
        }
        cout << "\nМедиана последовательности : ";
        if (arr.size() % 2 == 0) {
            cout << (arr[arr.size() / 2 - 1] + arr[arr.size() / 2]) / 2;
        }
        else {
            cout << "Медиана последовательности : ";
            cout << arr[arr.size() / 2];
        }
    }
    if (s == '5') {
        cout << "Исходная последовательность " << endl;
        for (int i : arr) {
            cout << i << " ";
        }
        transform(arr.begin(), arr.end(), arr.begin(), [](int num) {return -num; });
        cout << "\n";
        for (int i : arr) {
            cout << i << " ";
        }
    }
}



