#pragma once
namespace miit::algebra {
	/**
	* @brief класс генератор
	*/
	class Generator
	{
	public:
		Generator() = default;
		/**
		* @brief Диструктор по умолчанию
		*/
		virtual ~Generator() = default;
		/**
		* @brief Функция генерации числа
		*/
		virtual int generate() const {
			return 0;
		}
	};
}


