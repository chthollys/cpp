#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    string* data;
    int top;
    int capacity;

public:
    Stack(int capacity) {
        this->capacity = capacity;
        this->data = new string[capacity];
        this->top = -1;
    }

    ~Stack() {
        delete[] data;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(string element) {
        if (isFull()) {
            cout << "Stack penuh, tidak bisa menambahkan nama baru" << endl;
            return;
        }
        data[++top] = element;
    }

    void display() {
        cout << "List Nama: " << endl;
        for (int i = top; i >= 0; i--) {
            cout << "-" << data[i] << endl;
        }
        cout << "\n" << endl;
    }
};

int main() {
    int capacity;
    cout << "Masukkan kapasitas stack: ";
    cin >> capacity;

    int maxAttempts;
    cout << "Masukkan maksimal percobaan: ";
    cin >> maxAttempts;

    Stack myStack(capacity);

    string input;
    char choice;
    int attempts = 0;

    do {
        if (attempts >= maxAttempts) {
            cout << "Anda telah mencapai jumlah maksimal percobaan" << endl;
            break;
        }

        cout << "Masukkan nama: ";
        cin >> input;

        if (!myStack.isFull()) {
            myStack.push(input);
        } else {
            cout << "Stack penuh, tidak bisa menambahkan nama baru" << endl;
        }

        attempts++;

        cout << "Apakah ingin memasukkan nama lagi? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    myStack.display();

    return 0;
}