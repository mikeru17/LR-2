#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const string TASK1_DESCRIPT = "Задача 1.\nСоздайте функцию, которая организует простейшее сжатие входящей символьной строки произвольного масштаба. Сжатие происходит по следующему принципу: если в строке есть последовательность повторяющихся символов, то она заменяется на пару код символа и количество его повтора в строчке. Обеспечьте возможность ввода строки с клавиатуры.\n\n";
const string TASK2_DESCRIPT = "Задача 2.\nРеализуйте сортировку массива вставками (массив из целых чисел).\n\n";
const string TASK3_DESCRIPT = "Задача 3.\nСоздайте программу, позволяющую находить в строке подстроку и заменять её на другую произвольную подстроку в каждом месте обнаружения.\n\n";

// Задача 1.
void RunTask1() {
    string str, compressStr;
    cout << "Введите вашу строку: ";
    cin >> str;

    char root = str[0];
    int count = 1;
    for (int i = 1; i < str.length() + 1; i++)
    {
        if (str[i] == root)
        {
            // Считаем кол-во одинаковых символов в текущей последовательности.
            count++;
        }
        else
        {
            // Текущий элемент выводим в любом случае.
            compressStr += root;
            // Если текущий элемент повторялся в непрерывной последовательности, выводим также его кол-во.
            if (count > 1)
            {
                compressStr += to_string(count);
            }
            // Переопределяем root.
            root = str[i];
           // Сбрасываем count.
            count = 1;
        }
    }
    cout << "Сжатая строка: " << compressStr;
}

// Метод, реализующий сортировку вставками (для задачи 2).
void InsertSort(int* arr, int count) {
    int root, temp;
    for (int i = 0; i < count - 1; i++)
    {
        // Для каждого i запоминаем i + 1-й элемент.
        root = i + 1;
        temp = arr[root];
        // Пробегаем все элементы от i + 1 до 0.
        for (int j = i + 1; j > 0; j--)
        {
            // Если j-й элемент меньше предыдущего.
            if (temp < arr[j - 1])
            {
                // Кладем в него большее значение.
                arr[j] = arr[j - 1];
                // Запоминаем индекс, на который встанет меньший элемент.
                root = j - 1;
            }
        }
        // Вставляем меньшее значение на запомненное место.
        arr[root] = temp;
    }
}

// Задача 2.
void RunTask2() {
    int count;
    cout << "Введите кол-во элементов в вашем массиве: ";
    cin >> count;

    // Выделяем память под массив.
    int* arr = new int[count];
    cout << "Ввод массива...\n";
    for (int i = 0; i < count; i++)
    {
        cout << "Введите " << i << "-й элемент: ";
        cin >> arr[i];
    }

    // Сортируем массив.
    InsertSort(arr, count);

    cout << "\nВаш массив, отсортированный по возрастанию:\n";
    for (int i = 0; i < count; i++)
    {
        cout << setw(10) << arr[i];
    }
}

// Задача 3.
void RunTask3() {
    string mainStr, entry, newSubstr;
    cout << "Введите главную строку: ";
    cin >> mainStr;
    cout << "Введите заменяемую субстроку: ";
    cin >> entry;

    int startPosForFind = 0, entryStartPos = mainStr.find(entry, startPosForFind);
    if (entryStartPos != -1)
    {
        cout << "Введите новую субстроку, которая заменит заменяемую: ";
        cin >> newSubstr;
        // Пока есть вхождения заменяемой субстроки.
        while (entryStartPos != -1)
        {
            // Заменяем старую субстроку новой.
            mainStr.replace(entryStartPos, entry.size(), newSubstr);
            // Обновляем стартовую позицию для поиска.
            startPosForFind += newSubstr.size();
            // Ищем стартовую позицию нового вхождения, начиная с обновленного startPosForFind.
            entryStartPos = mainStr.find(entry, startPosForFind);
        }
        cout << "\nОбновленная главная строка: " << mainStr << "\n";
    }
    else
    {
        cout << "\nЗаменяемая субстрока в главной строке не найдена!\n";
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "----- ЛР-2 начала выполнение! -----\n\n";
    int userChoice;
    // Главное меню для перехода между задачами.
    do
    {
        cout << "----- Главное меню -----\n";
        cout << "Что вы хотите сделать?\nНа выбор есть 4 варианта:\n";
        cout << "1 - Задача 1\n2 - Задача 2\n3 - Задача 3\n0 - Выход\n\nВведите номер вашего выбора: ";
        cin >> userChoice;
        cout << "\n";

        switch (userChoice)
        {
        case 1:
            cout << TASK1_DESCRIPT;
            RunTask1();
            break;
        case 2:
            cout << TASK2_DESCRIPT;
            RunTask2();
            break;
        case 3:
            cout << TASK3_DESCRIPT;
            RunTask3();
            break;
        case 0:
            cout << "Выбран вариант выхода из программы. Программа завершается...\n\n";
            break;
        default:
            cout << "Введен некорректный номер. Пожалуйста, повторите попытку";
            break;
        }

        if (userChoice != 0)
        {
            cout << "\n\n----------------------------------------------------------------------------------------------------\n\n";
        }
    } while (userChoice != 0);

    system("pause");
    return 0;
}
