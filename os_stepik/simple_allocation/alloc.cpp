#include <iostream>

struct Memory
{
    Memory *next = NULL;
    Memory *prev = NULL;
    std::size_t size;
};

Memory *HEAD;
std::size_t BufSize;

// Эта функция будет вызвана перед тем как вызывать myalloc и myfree
    // используйте ее чтобы инициализировать ваш аллокатор перед началом
    // работы.
    //
    // buf - указатель на участок логической памяти, который ваш аллокатор
    //       должен распределять, все возвращаемые указатели должны быть
    //       либо равны NULL, либо быть из этого участка памяти
    // size - размер участка памяти, на который указывает buf
void mysetup(void *buf, std::size_t size)
{
    HEAD = (Memory*) buf;
    HEAD->size = size - sizeof(Memory);
}

    // Функция аллокации
void *myalloc(std::size_t size)
{
    // Нужно пробежаться по списку аллоцированной памяти 
    // Уменьшить размер если нашел память
    while (HEAD != NULL) {
        if (HEAD->size < size) {
            HEAD = HEAD->next;
        } else {
            Memory *newMemory = (Memory*) ((char*) HEAD + HEAD->size - size);
            newMemory->size = size;
            HEAD->size = HEAD->size - size - sizeof(Memory);
            return newMemory + 1;
        }
    }

    return NULL;
}

    // Функция освобождения
void myfree(void *p)
{

}

int main(int argc, char *argv[])
{
    std::cout << sizeof(Memory) << std::endl;
    int n = 100;
    char *init_buf = new char[n];

    mysetup(init_buf, n);
    
    std::cout << "All size " << HEAD->size << std::endl;

    char *test = (char*) myalloc(16);
    
    std::cout << "All size " << HEAD->size << std::endl;

    std::cout << (void*) (init_buf + 100 - 16) << std::endl;
    std::cout << (void*) test << std::endl;
    
    return 0;
}
