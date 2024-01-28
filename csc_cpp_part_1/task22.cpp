#include <iostream>

struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() {}
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {}

    virtual double evaluate() const {
        return value;
    }

    virtual ~Number() {}

private:
    double value;
};

struct BinaryOperation : Expression
{
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right)
    { }

    virtual double evaluate() const {
        switch (op) {
            case '+':
                return left->evaluate() + right->evaluate();
            case '-':
                return left->evaluate() - right->evaluate();
            case '*':
                return left->evaluate() * right->evaluate();
            case '/':
                return left->evaluate() / right->evaluate();
            default:
                return 0.0;
        }
    }

    virtual ~BinaryOperation() {
        delete left;
        delete right;
    }

private:
    Expression const * left;
    Expression const * right;
    char op;
};

bool check_equals(Expression const *left, Expression const *right)
{
    //for (int i = 0; i < 5; i = i + 1) {
    //    std::cout << *((int*)(left) + i) << "   ##  ";
    //    std::cout << *((int*)(right) + i) << std::endl;
    //}
    //std::cout << *(int*)(left) << std::endl;
    //std::cout << *(int*)(right) << std::endl;
    return *(int*)(right) == *(int*)(left);
}


int main(int argc, char *argv[])
{
    Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression * expr = new BinaryOperation(new Number(3), '+', sube);
    Expression * num2 = new Number(3.0);
    Expression * num = new Number(2.5);

    std::cout << check_equals(num, num2) << std::endl;
    //std::cout << check_equals(num, expr) << std::endl;

    return 0;
}
