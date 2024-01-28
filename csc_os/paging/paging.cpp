#include <iostream>
#include <cmath>
#include <unordered_map>

bool checkValid(long unsigned number) {
    return number >> 47 == 0 || number >> 47 == ((1 << 17) - 1);
}

long unsigned getNumber(long unsigned number, int highBit, int lowBit) {
    // 0-7, 7 включительно
    return (number >> lowBit) & ((1 << (highBit - lowBit + 1)) - 1);
}

int main(int argc, char *argv[])
{
    long unsigned  m, q, r, currentRootAddr;
    long unsigned paddr, value, request, currentValue;
    std::unordered_map<long unsigned, long unsigned> phys_memory;
    
    std::cin >> m >> q >> r;

    for (int i = 0; i < m; ++i) {
        std::cin >> paddr >> value;
        phys_memory.insert(std::pair<uint64_t, uint64_t>(paddr, value));
    }

    for (int i = 0; i < q; ++i) {
        currentRootAddr = r;
        std::cin >> request;

        if (!checkValid(request)) {
            std::cout << "fault" << std::endl;
            continue;
        }

        // Прибавляем к первоначальному адресу 39-47 биты запроса
        currentValue = currentRootAddr + 8 * getNumber(request, 47, 39);

        // Ищем такую запись в памяти
        auto it_p4 = phys_memory.find(currentValue);

        // Проверяем бит P (используется ли запись)
        if (it_p4 != phys_memory.end() && (it_p4->second & 1)) {
            // Получаем следующий корневой адрес
            currentRootAddr = getNumber(it_p4->second, 51, 12);
            // Сместим на выравнивание 12 бит
            currentRootAddr = currentRootAddr << 12;

            // Получаем адрес записи страницы на уровне p3
            currentValue = currentRootAddr + 8 * getNumber(request, 38, 30);

            auto it_p3 = phys_memory.find(currentValue);

            if (it_p3 != phys_memory.end() && (it_p3->second & 1)) {
                // Проверяем последний ли уровень
                if (it_p3->second & (1 << 7)) {
                    currentRootAddr = getNumber(it_p3->second, 51, 12);
                    currentRootAddr = currentRootAddr << 12;
                    
                    currentValue = currentRootAddr + getNumber(request, 29, 0);

                    std::cout << currentValue << std::endl;
                } else {
                    // Дальше идем на уровень p2
                    currentRootAddr = getNumber(it_p3->second, 51, 12);
                    currentRootAddr = currentRootAddr << 12;

                    currentValue = currentRootAddr + 8 * getNumber(request, 29, 21);

                    auto it_p2 = phys_memory.find(currentValue);

                    if (it_p2 != phys_memory.end() && (it_p2->second & 1)) {
                        // Проверяем последний ли уровень
                        if (it_p2->second & (1 << 7)) {
                            currentRootAddr = getNumber(it_p2->second, 51, 12);
                            currentRootAddr = currentRootAddr << 12;

                            currentValue = currentRootAddr + getNumber(request, 20, 0);

                            std::cout << currentValue << std::endl;
                        } else {
                           currentRootAddr = getNumber(it_p2->second, 51, 12); 
                           currentRootAddr = currentRootAddr << 12;
                           
                           currentValue = currentRootAddr + 8 * getNumber(request, 20, 12);

                           auto it_p1 = phys_memory.find(currentValue);

                           if (it_p1 != phys_memory.end() && (it_p1->second & 1)) {
                               currentRootAddr = getNumber(it_p1->second, 51, 12);
                               currentRootAddr = currentRootAddr << 12;

                               currentValue = currentRootAddr + getNumber(request, 11, 0);

                               std::cout << currentValue << std::endl;
                           } else {
                               std::cout << "fault" << std::endl;
                               continue;
                           }
                        }
                    } else {
                        std::cout << "fault" << std::endl;
                        continue;
                    }
                }
            } else {
                std::cout << "fault" << std::endl;
                continue;
            }
        } else {
            std::cout << "fault" << std::endl;
            continue;
        }
    }

    return 0;
}
