#ifndef MAIN_H
#define MAIN_H
#include <string>
#include <stdexcept>

class Stack {
private:
    struct Node {
        double Data;
        Node* Next;
        Node(double Val) : Data(Val), Next(nullptr) {}
    };
    Node* Top;

public:
    Stack() : Top(nullptr) {}
    ~Stack();
    
    void push(double Val);
    double pop();
    bool isEmpty() const;
};

class CalculatorRPN {
private:
    Stack stack;
    
    bool Number(const std::string& Token) const;
    bool Operator(const std::string& Token) const;
    double performOperation(const std::string& Op, double A, double B) const;
    
public:
    double evaluate(const std::string& Expression);
};

#endif