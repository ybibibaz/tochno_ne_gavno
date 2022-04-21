#include "Tests.hpp"
#include <iostream>


using namespace std;


void out1() {
    cout << "1 - создать матрицу" << endl;
    cout << "0 - выход" << endl;
}

void out2() {
    cout << "1 - создать матрицу" << endl;
    cout << "2 - посчитать норму матрицы 1" << endl;
    cout << "3 - умножить матрицу 1 на скаляр" << endl;
    cout << "4 - удалить матрицу 1" << endl;
    cout << "5 - вывести матрицу 1" << endl;
    cout << "0 - выход" << endl;
}

void out3() {
    cout << "1 - создать матрицу" << endl;
    cout << "2 - посчитать норму матрицы 2" << endl;
    cout << "3 - умножить матрицу 2 на скаляр" << endl;
    cout << "4 - удалить матрицу 2" << endl;
    cout << "5 - вывести матрицу 2" << endl;
    cout << "0 - выход" << endl;
}

void out4() {
    cout << "1 - посчитать норму матрицы 1" << endl;
    cout << "2 - посчитать норму матрицы 2" << endl;
    cout << "3 - умножить матрицу 1 на скаляр" << endl;
    cout << "4 - умножить матрицу 2 на скаляр" << endl;
    cout << "5 - сложить матрицы" << endl;
    cout << "6 - удалить матрицу 1" << endl;
    cout << "7 - удалить матрицу 2" << endl;
    cout << "8 - вывести матрицу 1" << endl;
    cout << "9 - вывести матрицу 2" << endl;
    cout << "0 - выход" << endl;
}

int decision(Matrix<int>* a1, Matrix<float>* a2, Matrix<int>* b1, Matrix<float>* b2) {
    if (a1->GetLength() == 0 && a2->GetLength() == 0 && b1->GetLength() == 0 && b2->GetLength() == 0) {
        return 11;
    }
    else if (a1->GetLength() != 0 && a2->GetLength() == 0 && b1->GetLength() == 0 && b2->GetLength() == 0) {
        return 21;
    }
    else if (a1->GetLength() == 0 && a2->GetLength() != 0 && b1->GetLength() == 0 && b2->GetLength() == 0) {
        return 22;
    }
    else if (a1->GetLength() == 0 && a2->GetLength() == 0 && b1->GetLength() != 0 && b2->GetLength() == 0) {
        return 31;
    }
    else if (a1->GetLength() == 0 && a2->GetLength() == 0 && b1->GetLength() == 0 && b2->GetLength() != 0) {
        return 32;
    }
    else if (a1->GetLength() != 0 && a2->GetLength() == 0 && b1->GetLength() != 0 && b2->GetLength() == 0) {
        return 41;
    }
    else if (a1->GetLength() != 0 && a2->GetLength() == 0 && b1->GetLength() == 0 && b2->GetLength() != 0) {
        return 42;
    }
    else if (a1->GetLength() == 0 && a2->GetLength() != 0 && b1->GetLength() != 0 && b2->GetLength() == 0) {
        return 43;
    }
    else if (a1->GetLength() == 0 && a2->GetLength() != 0 && b1->GetLength() == 0 && b2->GetLength() != 0) {
        return 44;
    }
}

void TUI() {
    int command = 10000;
    int n;
    int type;
    int const_int;
    float const_float;
    Matrix<int>* a1 = new Matrix<int>();
    Matrix<float>* a2 = new Matrix<float>();
    Matrix<int>* b1 = new Matrix<int>();
    Matrix<float>* b2 = new Matrix<float>();
    while (command != 0) {
        int k = decision(a1, a2, b1, b2);
        if (k == 11) {
            out1();
            cin >> command;
            switch (command) {
            case 1:
                cout << "1 - int, 2 - float" << endl;
                cin >> type;
                cout << "Введите размер" << endl;
                cin >> n;
                switch (type) {
                case 1:
                    a1->input(n);
                    break;
                case 2:
                    a2->input(n);
                    break;
                default:
                    cout << "Ошибка: неверный ввод типа данных" << endl;
                    break;
                }
                break;
            default:
                cout << "Ошибка: команда не найдена" << endl;
                break;
            }
        }
        else if (k == 21) {
            out2();
            cin >> command;
            switch (command) {
            case 1:
                cout << "1 - int, 2 - float" << endl;
                cin >> type;
                cout << "Введите размер" << endl;
                cin >> n;
                switch (type) {
                case 1:
                    b1->input(n);
                    break;
                case 2:
                    b2->input(n);
                    break;
                default:
                    cout << "Ошибка: неверный ввод типа данных" << endl;
                    break;
                }
                break;
            case 2:
                cout << a1->norm() << endl;
                break;
            case 3:
                cout << "Введите целую константу" << endl;
                cin >> const_int;
                a1 = a1->mult(const_int);
                break;
            case 4:
                a1->fake_delete();
                break;
            case 5:
                a1->print();
                break;
            default:
                cout << "Ошибка: команда не найдена" << endl;
                break;
            }
        }
        else if (k == 22) {
            out2();
            cin >> command;
            switch (command) {
            case 1:
                cout << "1 - int, 2 - float" << endl;
                cin >> type;
                cout << "Введите размер" << endl;
                cin >> n;
                switch (type) {
                case 1:
                    b1->input(n);
                    break;
                case 2:
                    b2->input(n);
                    break;
                default:
                    cout << "Ошибка: неверный ввод типа данных" << endl;
                    break;
                }
                break;
            case 2:
                cout << a2->norm() << endl;
                break;
            case 3:
                cout << "Введите константу" << endl;
                cin >> const_float;
                a2 = a2->mult(const_float);
                break;
            case 4:
                a2->fake_delete();
                break;
            case 5:
                a2->print();
                break;
            default:
                cout << "Ошибка: команда не найдена" << endl;
                break;
            }
        }
        else if (k == 31) {
            out3();
            cin >> command;
            switch (command) {
            case 1:
                cout << "1 - int, 2 - float" << endl;
                cin >> type;
                cout << "Введите размер" << endl;
                cin >> n;
                switch (type) {
                case 1:
                    a1->input(n);
                    break;
                case 2:
                    a2->input(n);
                    break;
                default:
                    cout << "Ошибка: неверный ввод типа данных" << endl;
                    break;
                }
                break;
            case 2:
                cout << b1->norm() << endl;
                break;
            case 3:
                cout << "Введите целую константу" << endl;
                cin >> const_int;
                b1 = b1->mult(const_int);
                break;
            case 4:
                b1->fake_delete();
                break;
            case 5:
                b1->print();
                break;
            default:
                cout << "Ошибка: команда не найдена" << endl;
                break;
            }
        }
        else if (k == 32) {
            out3();
            cin >> command;
            switch (command) {
            case 1:
                cout << "1 - int, 2 - float" << endl;
                cin >> type;
                cout << "Введите размер" << endl;
                cin >> n;
                switch (type) {
                case 1:
                    a1->input(n);
                    break;
                case 2:
                    a2->input(n);
                    break;
                default:
                    cout << "Ошибка: неверный ввод типа данных" << endl;
                    break;
                }
                break;
            case 2:
                cout << b2->norm() << endl;
                break;
            case 3:
                cout << "Введите константу" << endl;
                cin >> const_float;
                b2 = b2->mult(const_float);
                break;
            case 4:
                b2->fake_delete();
                break;
            case 5:
                b2->print();
                break;
            default:
                cout << "Ошибка: команда не найдена" << endl;
                break;
            }
        }
        else if (k == 41) {
            out4();
            cin >> command;
            switch (command) {
            case 1:
                cout << a1->norm() << endl;
                break;
            case 2:
                cout << b1->norm() << endl;
                break;
            case 3:
                cout << "Введите целую константу" << endl;
                cin >> const_int;
                a1 = a1->mult(const_int);
                break;
            case 4:
                cout << "Введите целую константу" << endl;
                cin >> const_int;
                b1 = b1->mult(const_int);
                break;
            case 5:
                (a1->plus(b1))->print();
                break;
            case 6:
                a1->fake_delete();
                break;
            case 7:
                b1->fake_delete();
                break;
            case 8:
                a1->print();
                break;
            case 9:
                b1->print();
                break;
            }    
        }
        else if (k == 42) {
            out4();
            cin >> command;
            switch (command) {
            case 1:
                cout << a1->norm() << endl;
                break;
            case 2:
                cout << b2->norm() << endl;
                break;
            case 3:
                cout << "Введите целую константу" << endl;
                cin >> const_int;
                a1 = a1->mult(const_int);
                break;
            case 4:
                cout << "Введите константу" << endl;
                cin >> const_float;
                b2 = b2->mult(const_float);
                break;
            case 5:
                cout << "Ошибка: разные типы" << endl;
                break;
            case 6:
                a1->fake_delete();
                break;
            case 7:
                b2->fake_delete();
                break;
            case 8:
                a1->print();
                break;
            case 9:
                b2->print();
                break;
            }
        }
        else if (k == 43) {
            out4();
            cin >> command;
            switch (command) {
            case 1:
                cout << a2->norm() << endl;
                break;
            case 2:
                cout << b1->norm() << endl;
                break;
            case 3:
                cout << "Введите константу" << endl;
                cin >> const_float;
                a2 = a2->mult(const_float);
                break;
            case 4:
                cout << "Введите целую константу" << endl;
                cin >> const_int;
                b1 = b1->mult(const_int);
                break;
            case 5:
                cout << "Ошибка: разные типы" << endl;
                break;
            case 6:
                a2->fake_delete();
                break;
            case 7:
                b1->fake_delete();
                break;
            case 8:
                a2->print();
                break;
            case 9:
                b1->print();
                break;
            }
        }
        else if (k == 44) {
            out4();
            cin >> command;
            switch (command) {
            case 1:
                cout << a2->norm() << endl;
                break;
            case 2:
                cout << b2->norm() << endl;
                break;
            case 3:
                cout << "Введите константу" << endl;
                cin >> const_float;
                a2 = a2->mult(const_float);
                break;
            case 4:
                cout << "Введите константу" << endl;
                cin >> const_float;
                b2 = b2->mult(const_float);
                break;
            case 5:
                (a2->plus(b2))->print();
                break;
            case 6:
                a2->fake_delete();
                break;
            case 7:
                b2->fake_delete();
                break;
            case 8:
                a2->print();
                break;
            case 9:
                b2->print();
                break;
            }
        }
    }
}
int main() {
    setlocale(LC_ALL, "Russian");


    construct_test();
    int_mult_test();
    float_mult_test();
    int_plus_test();
    float_plus_test();
    int_norm_test();
    float_norm_test();


    TUI();


    return 0;
 }