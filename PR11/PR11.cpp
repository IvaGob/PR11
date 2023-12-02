#include <iostream>
using namespace std;

// ������� ���� ����_�����
class PAIR {
    // ���� �����
    int first; // ����� �����
    int second; // ����� �����
public:
    // ������������ �����
    // ����������� ��� ���������
    PAIR() { 
        first = 0;
        second = 0;
    }
    // ����������� � �����������
    PAIR(int a, int b) { 
        first = a;
        second = b;
    }
    // ���������� �����
    ~PAIR() {
        // ͳ���� �� ������
    }
    // ��������� �� ������������
    int getFirst() { // ��������� ����� �����
        return first;
    }
    int getSecond() { // ��������� ����� �����
        return second;
    }
    void setFirst(int a) { // ���������� ����� �����
        first = a;
    }
    void setSecond(int b) { // ���������� ����� �����
        second = b;
    }
    // ������������� �������� ���������
    PAIR& operator=(const PAIR& p) {
        first = p.first;
        second = p.second;
        return *this;
    }
    // ������������� �������� ��������� ���
    PAIR operator+(const PAIR& p) {
        PAIR result;
        result.first = first + p.first;
        result.second = second + p.second;
        return result;
    }
    // ������������ �������� �������� �� ���������
    friend istream& operator>>(istream& in, PAIR& p);
    friend ostream& operator<<(ostream& out, const PAIR& p);
};

// ������������� �������� �������� ��� ����� ����_�����
istream& operator>>(istream& in, PAIR& p) {
    in >> p.first >> p.second;
    return in;
}

// ������������� �������� ��������� ��� ����� ����_�����
ostream& operator<<(ostream& out, const PAIR& p) {
    out << "(" << p.first << ", " << p.second << ")";
    return out;
}

// �������� ���� ����������_�����
class COMPLEX : public PAIR {
    // ���� �����
    int real; // ĳ���� ������� �����
    int imag; // ����� ������� �����
public:
    // ������������ �����
    COMPLEX() : PAIR() { // ����������� ��� ���������
        real = 0;
        imag = 0;
    }
    COMPLEX(int a, int b) : PAIR(a, b) { // ����������� � �����������
        real = a;
        imag = b;
    }
    // ���������� �����
    ~COMPLEX() {
        // ͳ���� �� ������
    }
    // ��������� �� ������������
    int getReal() { // ��������� ����� ������� �����
        return real;
    }
    int getImag() { // ��������� ����� ������� �����
        return imag;
    }
    void setReal(int a) { // ���������� ����� ������� �����
        real = a;
    }
    void setImag(int b) { // ���������� ����� ������� �����
        imag = b;
    }
    // ������������� �������� ���������
    COMPLEX& operator=(const COMPLEX& c) {
        real = c.real;
        imag = c.imag;
        return *this;
    }
    // ������������� �������� �������� ����������� �����
    COMPLEX operator*(const COMPLEX& c) {
        COMPLEX result;
        result.real = real * c.real - imag * c.imag;
        result.imag = real * c.imag + imag * c.real;
        return result;
    }
    // ������������� �������� �������� ����������� �����
    COMPLEX operator-(const COMPLEX& c) {
        COMPLEX result;
        result.real = real - c.real;
        result.imag = imag - c.imag;
        return result;
    }
    // ������������ �������� �������� �� ���������
    friend istream& operator>>(istream& in, COMPLEX& c);
    friend ostream& operator<<(ostream& out, const COMPLEX& c);
};

// ������������� �������� �������� ��� ����� ����������_�����
istream& operator>>(istream& in, COMPLEX& c) {
    in >> c.real >> c.imag;
    return in;
}

// ������������� �������� ��������� ��� ����� ����������_�����
ostream& operator<<(ostream& out, const COMPLEX& c) {
    out << c.real << " + " << c.imag << "i";
    return out;
}

// �������, ��� ������ ��'��� �������� �����
void printPair(PAIR p) {
    cout << "���� �����: " << p << endl;
}

// �������, ��� ������� ��'��� �������� �����
PAIR makePair(int a, int b) {
    PAIR p(a, b);
    return p;
}

// ������� ������� ��������
int main() {
    system("chcp 1251");
    // ��������� ��'���� �������� �����
    PAIR p1, p2(3, 4), p3;
    // �������� �� ��������� ��'���� �������� �����
    cout << "������ ����� ���� �����: ";
    cin >> p1;
    cout << "������ ����� ���� �����: ";
    cin >> p2;
    cout << "����� ���� �����: " << p1 << endl;
    cout << "����� ���� �����: " << p2 << endl;
    // ��������� ��� �����
    p3 = p1 + p2;
    cout << "���� ��� �����: " << p3 << endl;
    // ��������� ��'���� ��������� �����
    COMPLEX c1, c2(5, 6), c3;
    // �������� �� ��������� ��'���� ��������� �����
    cout << "������ ����� ���������� �����: ";
    cin >> c1;
    cout << "������ ����� ���������� �����: ";
    cin >> c2;
    cout << "����� ���������� �����: " << c1 << endl;
    cout << "����� ���������� �����: " << c2 << endl;
    // �������� ����������� �����
    c3 = c1 * c2;
    cout << "������� ����������� �����: " << c3 << endl;
    // ³������� ����������� �����
    c3 = c1 - c2;
    cout << "г����� ����������� �����: " << c3 << endl;
    // ������ �������, ��� ������ ��'��� �������� �����
    printPair(p1);
    // ������ �������, ��� ������� ��'��� �������� �����
    p3 = makePair(7, 8);
    cout << "���� �����, �������� ��������: " << p3 << endl;
    // ������� ����������
    PAIR* ptr; // �������� �� ������� ����
    ptr = &p1; // ����� �� ��'��� �������� �����
    cout << "�������� �� ������� ����: " << *ptr << endl;
    ptr = &c1; // ����� �� ��'��� ��������� �����
    cout << "�������� �� �������� ����: " << *ptr << endl;
    return 0;
}