#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>

using namespace std;
const int length = 100;

void menu() {
    cout << "1) Создание целочисленного массива размерности " << length << " c случайными значениями в диапазоне от -99 до 99" << '\n';
    cout << "2) Сортировка массива из 1 пункта (от меньшего к большему). Определение затраченного времени на сортировку" << '\n';
    cout << "3) Нахождение максимального и минимального элемента массива. Подсчёт время поиска этих элементов в отсортированном массиве и неотсортированном массиве " << '\n';
    cout << "4) Вывод среднего значения максимального и минимального в отсортированном и неотсортированном массиве. Вывод индексов элементов, которые равны этому значению, и их количество. Подсчёт времени поиска" << '\n';
    cout << "5) Вывод количества элементов в отсортированном массиве, которые меньше числа, введённого пользователем" << '\n';
    cout << "6) Вывод количества элементов в отсортированном массиве, которые больше числа, введённого пользователем" << '\n';
    cout << "7) Вывод информации о том, есть ли введенное пользователем число в отсортированном массиве" << '\n';
    cout << "8) Замена местами элементов массива, индексы которых вводит пользователь. Вывод скорости обмена" << '\n';
    cout << "9) IDZ 9" << '\n';
    cout << "0) Выход из программы" << '\n';
}

void RandomArray(int arr[], int sortedarr[]) {
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        arr[i] = rand() % 199 - 99;
        sortedarr[i] = arr[i];
    }

}

void boubleSort(int arr[], int n) {
    int count;
    auto ClockStart = chrono::high_resolution_clock::now();
    for (int i = 0; i < n - 1; i++)
    {
        count = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
            else
                count += 1;
        }
        if (count == n - 1 - i) {
            break;
        }
    }
    auto ClockEnd = chrono::high_resolution_clock::now();
    cout << "Отсортированный массив:" << '\n';
    for (int i = 0; i < length; i++)
    {
        cout << '[' << arr[i] << ']';

    }
    cout << '\n';
    cout << "Время сортировки: ";
    cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << " мс\n";
    cout << '\n';
}

void shakerSort(int b[])
{
    auto ClockStart = chrono::high_resolution_clock::now();
    for (int i = 0; i < length / 2; i++)
    {
        for (int с = i; с < length - i - 1; с++)
        {
            if (b[с] > b[с + 1])
            {
                swap(b[с], b[с + 1]);
            }

        }
        for (int с = length - 2 - i; с >= i; с--)
        {
            if (b[с] > b[с + 1])
            {
                swap(b[с], b[с + 1]);
            }
        }
    }
    auto ClockEnd = chrono::high_resolution_clock::now();
    cout << '\n';
    cout << "Отсортированный массив:" << '\n';
    cout << '\n';
    for (int i = 0; i < length; i++)
    {
        cout << '[' << b[i] << ']';

    }
    cout << '\n' << '\n';
    cout << "Время сортировки: ";
    cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << " мс\n";
    cout << '\n';
}



void combSort(int b[])
{
    int kef;
    kef = length / 1.247;
    auto ClockStart = chrono::high_resolution_clock::now();
    while (kef >= 1)
    {
        for (int i = 0; i < length - kef; i++)
        {
            if (b[i] > b[i + kef])
                swap(b[i], b[i + kef]);
        }
        kef = kef / 1.247;
    }
    auto ClockEnd = chrono::high_resolution_clock::now();
    for (int i = 0; i < length; i++)
    {
        cout << '[' << b[i] << ']';
    }
    cout << '\n' << '\n';
    cout << "Время сортировки: ";
    cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << " мс\n";
    cout << '\n';
}

void insertSort(int b[])
{
    auto ClockStart = chrono::high_resolution_clock::now();
    for (int i = 1; i < length; i++)
    {
        for (int j = i; j > 0 && b[j - 1] > b[j]; j--)
        {
            swap(b[j - 1], b[j]);
        }
    }
    auto ClockEnd = chrono::high_resolution_clock::now();
    for (int i = 0; i < length; i++)
    {
        cout << '[' << b[i] << ']';
    }
    cout << '\n' << '\n';
    cout << "Время сортировки: ";
    cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << " мс\n";
    cout << '\n';
}



void quickSort(int sortedarr[], int begin, int end)

{
    int i = begin;
    int j = end;
    int mid = sortedarr[(i + j) / 2];
    while (i < j)
    {
        while (sortedarr[i] < mid) i++;
        while (sortedarr[j] > mid) j--;
        if (i <= j)
        {
            swap(sortedarr[i], sortedarr[j]);
            i++;
            j--;
        }
    }
    if (i < end)
        quickSort(sortedarr, i, end);
    if (j > begin)
        quickSort(sortedarr, begin, j);

}



void sort(int sortedarr[]) {
    int a;
    cout << "Выберите сортировку:" << '\n';
    cout << '\n';
    cout << "1) Bubble Sort (сортировка пузырьком)" << '\n';
    cout << "2) Shaker sort (шейкер-сортировка)" << '\n';
    cout << "3) Comb sort (сортировка расчёской)" << '\n';
    cout << "4) Insert sort (сортировка вставками)" << '\n';
    cout << "5) Quick sort (быстрая сортировка)" << '\n';
    cin >> a;
    switch (a) {
    case 1:
        boubleSort(sortedarr, length);
        break;
    case 2:
        shakerSort(sortedarr);
        break;
    case 3:
        combSort(sortedarr);
        break;
    case 4:
        insertSort(sortedarr);
        break;

    case 5:
        auto ClockStart = chrono::high_resolution_clock::now();
        quickSort(sortedarr, 0, length - 1);
        auto ClockEnd = chrono::high_resolution_clock::now();
        for (int i = 0; i < length; i++)
            cout << '[' << sortedarr[i] << ']';
        cout << '\n' << '\n';

        cout << "Время сортировки: ";
        cout << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << " мс\n";
        cout << '\n';
        break;

    }
}

void findmaxmin(int a[], int sorteda[])
{
    for (int i = 0; i < length; i++)
        cout << '[' << sorteda[i] << ']';
    cout << "\n" << "\n";


    int maxelem = a[0], minelem = a[0];
    auto ClockStart = chrono::high_resolution_clock::now();
    for (int i = 1; i < length - 1; i++)
    {
        if (a[i] < minelem)
            minelem = a[i];
        if (a[i] > maxelem)
            maxelem = a[i];
    }
    auto ClockEnd = chrono::high_resolution_clock::now();
    cout << "Максимальный элемент массива: " << maxelem << '\n' << "Минимальный элемент массива: " << minelem;
    cout << '\n';
    cout << "Время поиска в неотсортирванном массиве: " << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << " мс\n";
    cout << "\n" << "\n";

    auto ClockStart1 = chrono::high_resolution_clock::now();
    int maxelem1 = sorteda[length - 1];
    int minelem1 = sorteda[0];
    auto ClockEnd1 = chrono::high_resolution_clock::now();
    cout << "Максимальный элемент массива: " << maxelem1 << '\n' << "Минимальный элемент массива: " << minelem1;
    cout << '\n';
    cout << "Время поиска в отсортирванном массиве:   " << (chrono::duration_cast<chrono::microseconds>(ClockEnd1 - ClockStart1).count()) << " мс\n";
}


void srznach(int a[])
{
    boubleSort(a, length);
    int mid = (a[0] + a[length - 1]) / 2;
    int count = 0;
    cout << "Cреднее значение максимального и минимального: " << mid << "\n";
    cout << "Индексы всех элементов, которые равны среднему значению максимального и минимального: ";
    auto ClockStart = chrono::high_resolution_clock::now();
    for (int i = 0; i < length; i++)
    {
        if (a[i] == mid)
        {
            count += 1;
            cout << i << " ";
        }
    }
    auto ClockEnd = chrono::high_resolution_clock::now();
    cout << "Время поиска элементов, равных среднему значению максимального и минимального элемента массива: " << (chrono::duration_cast<chrono::microseconds>(ClockEnd - ClockStart).count()) << " мс\n";
    cout << '\n';
    if (count == 0)
        cout << "Такие значения отсутствуют в массиве";
    else
        cout << "Количество элементов, равных среднему значению максимального и минимального: " << count;
    cout << '\n';
}
void upp(int arr[])
{
    boubleSort(arr, length);
    cout << "Введите значение ";
    int a;
    cin >> a;
    int i = length - 1;
    while (arr[i] > a)
    {
        i = i / 2;
    }
    while (arr[i] < a)
    {
        i++;
    }
    cout << "В массиве есть " << i << " элемент(а/ов), значение(я) которых меньше " << a << '\n';
}

void low(int arr[])
{
    boubleSort(arr, length);
    cout << "Введите значение ";
    int a;
    cin >> a;
    int i = length - 1;
    while (arr[i] > a)
    {
        i = i / 2;
    }
    while (arr[i] <= a)
    {
        i++;
    }
    cout << "В массиве есть " << length - i << " элемент(а/ов), значение(я) которых превышают " << a << '\n';

}

int binarySearch(int arr[], int value, int start, int end)
{
    if (end >= start)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == value)
        {
            return mid;
        }

        if (arr[mid] > value)
        {
            return binarySearch(arr, value, start, mid - 1);
        }

        return binarySearch(arr, value, mid + 1, end);
    }

    return -1;
}
void poiskelem(int arr[])
{
    cout << "Отсортированный массив:" << '\n';
    for (int i = 0; i < length; i++)
    {
        cout << '[' << arr[i] << ']';

    }
    cout << '\n';
    int value, count = 1;
    cout << "Введите значение: ";
    cin >> value;

    int i = binarySearch(arr, value, 0, length - 1);
    while (arr[i - 1] == value)
        i--;
    while (arr[i + 1] == value)
    {
        count++;
        i++;
    }
    cout << "В массиве есть " << count << " элемент(а/ов), значение(я) которых равны " << value << '\n';

}
void replacement(int arr[])
{
    boubleSort(arr, length);
    int a, b;
    cout << "Введите значение элемента для замены: ";
    cin >> a;
    cout << "Введите значение второго элемента для замены: ";
    cin >> b;
    swap(arr[a], arr[b]);
    for (int i = 0; i < length; i++)
    {
        cout << '[' << arr[i] << ']';
    }
}


void idz9(int arr[])
{
 
        boubleSort(arr, length);
    srand(time(NULL));
    int value, countnechet = 0;
    cout << "Введите значение, на которое нужно уменьшить каждый нечетный элемент: ";
    cin >> value;
    for (int i = 0; i < length; i += 2)
        arr[i] = arr[i] - value;
    int randomvalue = rand() % 9 + 1;
    for (int i = 0; i < length; i += 2)
        arr[i] = arr[i] * randomvalue;
    for (int i = 1; i < length; i += 2)
        if (arr[i] % 2 != 0) countnechet++;
    int i = 0;
    while (countnechet > 0)
        if (arr[i] % 2 == 0)
            cout << arr[i] << " ";
    cout << "\n";
    int coun1 = 0;
    int coun2 = 0;
    int coun3 = 0;
    int coun4 = 0;
    int coun5 = 0;
    int coun6 = 0;
    int coun7 = 0;
    int coun8 = 0;
    int coun9 = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] % 1 == 0)
            coun1++;
        if (arr[i] % 2 == 0)
            coun2++;
        if (arr[i] % 3 == 0)
            coun3++;
        if (arr[i] % 4 == 0)
            coun4++;
        if (arr[i] % 5 == 0)
            coun5++;
        if (arr[i] % 6 == 0)
            coun6++;
        if (arr[i] % 7 == 0)
            coun7++;
        if (arr[i] % 8 == 0)
            coun8++;
        if (arr[i] % 9 == 0)
            coun9++;
    }
    cout << "Кол-во эл-ов, кратных 1: " << coun1 << "\n";
    cout << "Кол-во эл-ов, кратных 2: " << coun2 << "\n";
    cout << "Кол-во эл-ов, кратных 3: " << coun3 << "\n";
    cout << "Кол-во эл-ов, кратных 4: " << coun4 << "\n";
    cout << "Кол-во эл-ов, кратных 5: " << coun5 << "\n";
    cout << "Кол-во эл-ов, кратных 6: " << coun6 << "\n";
    cout << "Кол-во эл-ов, кратных 7: " << coun7 << "\n";
    cout << "Кол-во эл-ов, кратных 8: " << coun8 << "\n";
    cout << "Кол-во эл-ов, кратных 9: " << coun9 << "\n";



}

int main()
{

    int arr[length], sortedarr[length];
    setlocale(0, "");
    short int choice;

    bool m = true;
    RandomArray(arr, sortedarr);
    quickSort(sortedarr, 0, length - 1);
    while (m)
    {
        menu();
        cout << "\nВыберите пункт меню: ";
        cin >> choice;
        system("cls");
        switch (choice)
        {
        case 0:
            exit(0);
            break;
        case 1:
            RandomArray(arr, sortedarr);
            system("cls");
            cout << "Создание целочисленного массива размерности " << length << " c случайными значениями в диапазоне от - 99 до 99\n\n";
            for (int i = 0; i < length; i++)
            {
                cout << "[" << arr[i] << "]" << " ";
                if ((i + 1) % 10 == 0)
                    cout << "\n";

            }
            break;
        case 2:
            system("cls");
            sort(sortedarr);
            break;
        case 3:
            system("cls");
            findmaxmin(arr, sortedarr);
            break;
        case 4:
            system("cls");
            srznach(arr);
            break;
        case 5:
            system("cls");
            upp(sortedarr);
            break;
        case 6:
            system("cls");
            low(sortedarr);
            break;
        case 7:
            system("cls");
            poiskelem(sortedarr);
            break;
        case 8:
            system("cls");
            replacement(arr);
            break;
        case 9:
            system("cls");
            idz9(arr);
            break;
        }
        system("pause");
        system("cls");

    }
    return 0;


}
