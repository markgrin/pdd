#include <iostream>
#include <cstring>
#include <memory>
#include <thread>

/**
 * Для хранения переменных через указатель, а не на стеке
 */
std::unique_ptr<std::size_t> unique_number(std::size_t number) {
    std::unique_ptr<std::size_t> ptr(new std::size_t);
    *ptr = number;
    return ptr;
}

/**
 * Для разделения массива на два
 **/
std::unique_ptr<char[]> split(const char* input, std::size_t size, bool is_left) {
    std::unique_ptr<char[]> array(new char[size/2 + 1]);
    std::size_t j = 0;
    for (std::size_t i = 0; i < size; i++) {
        if ((is_left && i % 2) || (!is_left && !(i % 2))) {
            array[j] = input[i];
            j++;
        }
    }
    return array;
}

int main (int argc, const char** argv) {
    static_assert(sizeof(std::size_t) == 8);
    if (argc != 3) {
        std::cout << "Checked needs 2 arguments: phone number and control sum\n";
        return 1;
    }
    const char* phone = argv[1];
    std::size_t size = std::strlen(phone);
    if (size < 5) {
        std::cout << "Phone number should be at least 5 digits long\n";
        return 2;
    }

    std::unique_ptr<char[]> inputs[2];
    inputs[0] = split(phone, size, true);
    inputs[1] = split(phone, size, false);

    auto low_point = unique_number(phone[0]);
    auto high_point = unique_number(phone[1]);
    auto koef = unique_number(phone[1]);
    auto addition = unique_number(phone[2]);
    std::size_t next = 4;

    /**
     * К этому моменту
     * 1) Входные данные разбиты в памяти
     * 2) Переменные для расчета не на стеке
     * 3) Выходные данные не на стеке и разбиты в памяти
     * 4) Запуск будем происходить в другом потоке =)
     */
    std::thread main_thread([&]() {
        std::size_t input_index = 0;
        while(next < size) {
            *low_point = ((*low_point) * (*koef) + (*addition));
            *high_point = ((*high_point) * (*addition) + (*koef));
            *addition = (*addition) * inputs[input_index][next/2] + inputs[input_index][next/2];
            next += 1;
            input_index = (input_index + 1) % 2;
        }
        std::size_t result = ((*high_point) << 32) | (*low_point >> 32);
        std::cout << result << "\n";
    });
    main_thread.join();
    return 0;
}

