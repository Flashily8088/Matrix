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
		* @brief
		* @param in
		*/
		IstreamGenerator(istream& in = cin);
		/**
		* @brief
		*/
		int generate() override;
	};
}

