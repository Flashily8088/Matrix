#pragma once
#include "Generator.h"

namespace miit::algebra {
    /**
    * @brief Генератор, который всегда возвращает одно фиксированное число (константу)
    */
    class ConstantGenerator : public Generator
    {
    private:
        int constant_value;

    public:
        /**
        * @brief Конструктор генератора констант
        * @param value - число, которое всегда будет возвращать генератор
        */
        ConstantGenerator(int value);

        /**
        * @brief Деструктор
        */
        virtual ~ConstantGenerator() = default;

        /**
        * @brief Возвращает фиксированное значение
        * @return значение константы
        */
        int generate() override;
    };
}


