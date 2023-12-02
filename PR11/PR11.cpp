#include <iostream>
using namespace std;

// Базовий клас ПАРА_ЧИСЕЛ
class PAIR {
    // Поля класу
    int first; // Перше число
    int second; // Друге число
public:
    // Конструктори класу
    // Конструктор без параметрів
    PAIR() { 
        first = 0;
        second = 0;
    }
    // Конструктор з параметрами
    PAIR(int a, int b) { 
        first = a;
        second = b;
    }
    // Деструктор класу
    ~PAIR() {
        // Нічого не робити
    }
    // Селектори та модифікатори
    int getFirst() { 
        // Повернути перше число
        return first;
    }
    int getSecond() { 
        // Повернути друге число
        return second;
    }
    void setFirst(int a) { 
        // Встановити перше число
        first = a;
    }
    void setSecond(int b) { 
       // Встановити друге число
        second = b;
    }
    // Перевантажена операція присвоєння
    PAIR& operator=(const PAIR& p) {
        first = p.first;
        second = p.second;
        return *this;
    }
     // Перевантажена операція складання пар
    PAIR operator+(const PAIR& p) {
        PAIR result;
        result.first = first + p.first;
        result.second = second + p.second;
        return result;
    }
    // Перевантажені операції введення та виведення
    friend istream& operator>>(istream& in, PAIR& p);
    friend ostream& operator<<(ostream& out, const PAIR& p);
};

// Перевантажена операція введення для класу ПАРА_ЧИСЕЛ
istream& operator>>(istream& in, PAIR& p) {
    in >> p.first >> p.second;
    return in;
}

// Перевантажена операція виведення для класу ПАРА_ЧИСЕЛ
ostream& operator<<(ostream& out, const PAIR& p) {
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

// Похідний клас КОМПЛЕКСНЕ_ЧИСЛО
class COMPLEX : public PAIR {
    // Поля класу
    int real; // Дійсна частина числа
    int imag; // Уявна частина числа
public:
    // Конструктори класу
    COMPLEX() : PAIR() { 
        // Конструктор без параметрів
        real = 0;
        imag = 0;
    }
    COMPLEX(int a, int b) : PAIR(a, b) { 
        // Конструктор з параметрами
        real = a;
        imag = b;
    }
    // Деструктор класу
    ~COMPLEX() {
        // Нічого не робити
    }
    // Селектори та модифікатори
    int getReal() { 
        // Повернути дійсну частину числа
        return real;
    }
    int getImag() { 
        // Повернути уявну частину числа
        return imag;
    }
    void setReal(int a) { 
        // Встановити дійсну частину числа
        real = a;
    }
    void setImag(int b) { 
        // Встановити уявну частину числа
        imag = b;
    }
    // Перевантажена операція присвоєння
    COMPLEX& operator=(const COMPLEX& c) {
        real = c.real;
        imag = c.imag;
        return *this;
    }
    // Перевантажена операція множення комплексних чисел
    COMPLEX operator*(const COMPLEX& c) {
        COMPLEX result;
        result.real = real * c.real - imag * c.imag;
        result.imag = real * c.imag + imag * c.real;
        return result;
    }
    // Перевантажена операція віднімання комплексних чисел
    COMPLEX operator-(const COMPLEX& c) {
        COMPLEX result;
        result.real = real - c.real;
        result.imag = imag - c.imag;
        return result;
    }
    // Перевантажені операції введення та виведення
    friend istream& operator>>(istream& in, COMPLEX& c);
    friend ostream& operator<<(ostream& out, const COMPLEX& c);
};

// Перевантажена операція введення для класу КОМПЛЕКСНЕ_ЧИСЛО
istream& operator>>(istream& in, COMPLEX& c) {
    in >> c.real >> c.imag;
    return in;
}

// Перевантажена операція виведення для класу КОМПЛЕКСНЕ_ЧИСЛО
ostream& operator<<(ostream& out, const COMPLEX& c) {
    out << c.real << " + " << c.imag << "i";
    return out;
}

// Функція, яка отримує об'єкт базового класу
void printPair(PAIR p) {
    cout << "Ïàðà ÷èñåë: " << p << endl;
}

// Функція, яка повертає об'єкт базового класу
PAIR makePair(int a, int b) {
    PAIR p(a, b);
    return p;
}

// Головна функція програми
int main() {
    system("chcp 1251");
    // Створення об'єктів базового класу
    PAIR p1, p2(3, 4), p3;
    // Введення та виведення об'єктів базового класу
    cout << "Введіть першу пару чисел:";
    cin >> p1;
    cout << "Введіть другу пару чисел: ";
    cin >> p2;
    cout << "Перша пара чисел: " << p1 << endl;
    cout << "Друга пара чисел: " << p2 << endl;
    // Складання пар чисел
    p3 = p1 + p2;
    cout << "Сума пар чисел: " << p3 << endl;
    // Створення об'єктів похідного класу
    COMPLEX c1, c2(5, 6), c3;
    // Введення та виведення об'єктів похідного класу
    cout << "Введіть перше комплексне число: ";
    cin >> c1;
    cout << "Введіть друге комплексне число: ";
    cin >> c2;
    cout << "Перше комплексне число: " << c1 << endl;
    cout << "Друге комплексне число: " << c2 << endl;
    // Множення комплексних чисел
    c3 = c1 * c2;
    cout << "Добуток комплексних чисел: " << c3 << endl;
    // Віднімання комплексних чисел
    c3 = c1 - c2;
    cout << "Різниця комплексних чисел: " << c3 << endl;
    // Виклик функції, яка отримує об'єкт базового класу
    printPair(p1);
    // Виклик функції, яка повертає об'єкт базового класу
    p3 = makePair(7, 8);
    cout << "Пара чисел, створена функцією: " << p3 << endl;
    // Принцип підстановки
    PAIR* ptr; // Вказівник на базовий клас
    ptr = &p1; // Вказує на об'єкт базового класу
    cout << "Вказівник на базовий клас: " << *ptr << endl;
    ptr = &c1; // Вказує на об'єкт похідного класу
    cout << "Вказівник на похідний клас: " << *ptr << endl;
    return 0;
}
