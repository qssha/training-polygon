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


struct SharedPtr
{
    explicit SharedPtr(Expression *ptr = 0) : ptr_(ptr) {
        if (ptr_ != 0) count_ = new int(1);
        else count_ = 0;
    }

    ~SharedPtr() {
        if (ptr_ != 0) {
            if (*count_ > 1) *(count_) -= 1;
            else {
                delete ptr_;
                delete count_;
            }
        }
    }
    
    SharedPtr(const SharedPtr & sharedPtr) {
        if (sharedPtr.get() != 0) {
            ptr_ = sharedPtr.get();
            count_ = sharedPtr.getCount();
            *(count_) += 1;
        }
        else {
            ptr_ = 0;
            count_ = 0;
        }
    }

    SharedPtr& operator=(const SharedPtr & sharedPtr) {
        if (ptr_ != sharedPtr.get()) {
            if (ptr_ != 0) {
                if (*count_ > 1) *(count_) -=1;
                else {
                    delete ptr_;
                    delete count_;
                }
            }
            if (sharedPtr.get() != 0) {
                *(sharedPtr.getCount()) += 1;
            }

            ptr_ = sharedPtr.get();
            count_ = sharedPtr.getCount();
        }

        return *this;
    }
    
    Expression* get() const {
        return ptr_;
    }

    void reset(Expression *ptr = 0) {
        if (ptr_ != 0) {
            if (*count_ == 1) {
                delete ptr_;
                delete count_;
            }
            else {
                *(count_) -= 1;
            }
        }

        ptr_ = ptr;
        
        if (ptr_ != 0) {
            count_ = new int(1);
        }
        else count_ = 0;
    }

    Expression& operator*() const {
        return *ptr_;
    }

    Expression* operator->() const {
        return ptr_;
    }
    
    int* getCount() const {
        return count_;
    }
    
private:
    int *count_;
    Expression *ptr_;
};

int main(int argc, char *argv[])
{
    Expression *num1 = new Number(4.5);
    SharedPtr ptr1(0);
    SharedPtr ptr2(ptr1);
    SharedPtr ptr3(num1);

    std::cout << (ptr1.get() == 0) << " " << (ptr1.getCount() == 0) << std::endl;
    std::cout << (ptr2.get() == 0) << " " << (ptr2.getCount() == 0) << std::endl;
    std::cout << (ptr3.get() == 0) << " " << (ptr3.getCount() == 0) << std::endl;

    ptr3.reset();
    std::cout << (ptr3.get() == 0) << " " << (ptr3.getCount() == 0) << std::endl;

  
    return 0;
}
