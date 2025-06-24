#include "main.h"
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

void PrintWelcomeMessage() {
    cout << "Калькулятор обратной польской записи" << endl;
    cout << "Введите выражение в постфиксной форме (например, '3 4 + 5 *')." << endl;
    cout << "Поддерживаемые операторы: +, -, *, /" << endl;
    cout << "Введите 'exit', для завершения" << endl << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);


    CalculatorRPN Calculator;
    string Input;
    
    PrintWelcomeMessage();
    
    while (true) {
        cout << "-->  ";
        getline(cin, Input);
        
        if (Input == "exit") {
            break;
        }
        
        if (Input.empty()) {
            continue;
        }
        
        try {
            double Res = Calculator.evaluate(Input);
            cout << "Результат: " << Res << endl;
        } catch (const exception& e) {
            cerr << "Ошибка: " << e.what() << endl;
        }
    }
    
    return 0;
}