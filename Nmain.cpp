#include "main.h"
#include <sstream>
#include <vector>
#include <cctype>
using namespace std;

Stack::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

void Stack::push(double Val) {
    Node* NewNode = new Node(Val);
    NewNode->Next = Top;
    Top = NewNode;
}

double Stack::pop() {
    if (isEmpty()) {
        throw runtime_error("Стек пуст");
    }
    Node* Tmp = Top;
    double Val = Tmp->Data;
    Top = Top->Next;
    delete Tmp;
    return Val;
}

bool Stack::isEmpty() const {
    return Top == nullptr;
}

bool CalculatorRPN::Operator(const string& Token) const {
    return Token == "+" || Token == "-" || Token == "*" || Token == "/";
}

double CalculatorRPN::performOperation(const string& Op, double A, double B) const {
    if (Op == "+") return A + B;
    if (Op == "-") return A - B;
    if (Op == "*") return A * B;
    if (Op == "/") {
        if (B == 0) {
            throw runtime_error("Деление на ноль");
        }
        return A / B;
    }
    throw runtime_error("Неизвестный оператор");
}


bool CalculatorRPN::Number(const std::string& Token) const {
    size_t pos;
    try {
        stod(Token, &pos);  
        return pos == Token.length();
    } catch (...) {
        return false;
    }
}


double CalculatorRPN::evaluate(const std::string& Example) {
    istringstream Iss(Example);
    vector<string> Tokens;
    string Token;
    
    while (Iss >> Token) {
        Tokens.push_back(Token);
    }
    
    for (const auto& Token : Tokens) {
        if (Operator(Token)) {
            if (stack.isEmpty()) {
                throw runtime_error("Недостаточно операндов для оператора " + Token);
            }
            double B = stack.pop();
            
            if (stack.isEmpty()) {
                throw runtime_error("Недостаточно операндов для оператора " + Token);
            }
            double A = stack.pop();
            
            double Result = performOperation(Token, A, B);
            stack.push(Result);
        }
        else if (Number(Token)) {
            double Num;
            try {
                Num = stod(Token);
            } catch (...) {
                throw runtime_error("Некорректное число: " + Token);
            }
            stack.push(Num);
        }
        else {
            throw runtime_error("Недопустимый токен: " + Token);
        }
    }
    
    if (stack.isEmpty()) {
        throw runtime_error("Стек пуст после вычислений");
    }
    
    double Result = stack.pop();
    
    if (!stack.isEmpty()) {
        throw runtime_error("В стеке остались лишние значения");
    }
    
    return Result;
}