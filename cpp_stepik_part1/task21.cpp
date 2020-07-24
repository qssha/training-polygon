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
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
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


int main(int argc, char *argv[])
{
    Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Expression * expr = new BinaryOperation(new Number(3), '+', sube);
    
    std::cout << expr->evaluate() << std::endl;
    
    delete expr; 
    return 0;
}
