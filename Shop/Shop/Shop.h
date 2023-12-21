#pragma once
#include "Computer.h"
#include <fstream>
class Tovar
{
public:
    explicit Tovar(Computer v, Tovar* n = nullptr) :value(v), next(n) {};
    Computer getValue() const { return value; }
    void setValue(Computer v) { value = v; }
    Tovar* getNext() const { return next; }
    void setNext(Tovar* n) { next = n; }
    void print() const { cout << value; }
private:
    Computer value;
    Tovar* next;
};

class Shop
{
public:
    Shop() :head(nullptr), tail(nullptr), counter(0) {}
    ~Shop();
    size_t size() const { return counter; }
    void push(Computer v);
    void pop();
    void DeleteAll();
    Tovar* findNode(size_t index) const;
    void print() const;
    void load(string filename);
    void save(string filename) const;
private:
    Tovar* head;
    Tovar* tail;
    size_t counter;
};

Shop::~Shop() { DeleteAll(); }

void Shop::push(Computer v)
{
    Tovar* temp = new Tovar(v);
    if (tail)
        tail->setNext(temp);
    else
        head = temp;
    tail = temp;
    ++counter;
}

void Shop::pop()
{
    if (head) {
        Tovar* temp = head;
        head = head->getNext();
        delete temp;
        --counter;
        if (!head) tail = nullptr;
    }
}

void  Shop::DeleteAll() { while (counter > 0) { pop(); } }

Tovar* Shop::findNode(size_t index) const {
    if (index >= counter) return nullptr;
    size_t n = 0;
    Tovar* cur = head;
    while (cur) {
        if (n == index) break;
        cur = cur->getNext();
        n++;
    }
    return cur;
}

void Shop::print() const {
    Tovar* cur = head;
    while (cur) {
        cur->print();
        cout << string(25, '-') << endl;
        cur = cur->getNext();
    }
    cout << endl;
}

void Shop::load(string filename)
{
    ifstream  fs(filename, ios::binary);
    if (!fs.is_open()) throw exception("file not opened");
    double num;
    char* str;
    Computer computer;
    while (fs.read(reinterpret_cast<char*> (&num), sizeof(num))) {
        computer.setPrice(num);
        fs.read(reinterpret_cast<char*> (&num), sizeof(num));
        str = new char[int(num) + 1];
        fs.read(str, num);
        str[int(num)] = '\0';
        computer.setMotherBoard(str);
        delete[] str;

        fs.read(reinterpret_cast<char*> (&num), sizeof(num));
        str = new char[int(num) + 1];
        fs.read(str, num);
        str[int(num)] = '\0';
        computer.setCPU(str);
        delete[] str;

        fs.read(reinterpret_cast<char*> (&num), sizeof(num));
        str = new char[int(num) + 1];
        fs.read(str, num);
        str[int(num)] = '\0';
        computer.setVideoCard(str);
        delete[] str;

        fs.read(reinterpret_cast<char*> (&num), sizeof(num));
        str = new char[int(num) + 1];
        fs.read(str, num);
        str[int(num)] = '\0';
        computer.setStraightPower(str);
        delete[] str;

        fs.read(reinterpret_cast<char*> (&num), sizeof(num));
        str = new char[int(num) + 1];
        fs.read(str, num);
        str[int(num)] = '\0';
        computer.setRAM(str);
        delete[] str;

        push(computer);
    }
    fs.close();
}

void Shop::save(string filename) const
{
    ofstream  fcout(filename, ios::binary);
    if (!fcout.is_open()) throw exception("file not opened");
    Tovar* cur = head;
    double num;
    char* str;
    while (cur) {
        num = cur->getValue().getPrice();
        fcout.write(reinterpret_cast<const char*> (&num), sizeof(num));

        str = _strdup(cur->getValue().getMotherBoard());
        num = strlen(str);
        fcout.write(reinterpret_cast<const char*> (&num), sizeof(num));
        fcout.write(str, strlen(str));
        delete[] str;

        str = _strdup(cur->getValue().getCPU());
        num = strlen(str);
        fcout.write(reinterpret_cast<const char*> (&num), sizeof(num));
        fcout.write(str, strlen(str));
        delete[] str;

        str = _strdup(cur->getValue().getVideoCard());
        num = strlen(str);
        fcout.write(reinterpret_cast<const char*> (&num), sizeof(num));
        fcout.write(str, strlen(str));
        delete[] str;

        str = _strdup(cur->getValue().getStraightPower());
        num = strlen(str);
        fcout.write(reinterpret_cast<const char*> (&num), sizeof(num));
        fcout.write(str, strlen(str));
        delete[] str;

        str = _strdup(cur->getValue().getRAM());
        num = strlen(str);
        fcout.write(reinterpret_cast<const char*> (&num), sizeof(num));
        fcout.write(str, strlen(str));
        delete[] str;
        cur = cur->getNext();
    }
    fcout.close();
}