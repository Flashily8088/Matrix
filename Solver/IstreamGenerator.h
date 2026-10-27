#pragma once
#include "Generator.h"
#include <iostream>
using namespace std;
namespace miit::algebra {
	/**
	* @brief
	*/
	class IstreamGenerator : public Generator
	{
	private:
		istream& in;
	public:
		/**
		* @brief Конструктор
		* @param in - поток ввода
		*/
		IstreamGenerator(istream& in = cin);
		/**
		* @brief Функция генерации
		*/
		int generate() const override;
	};
}

