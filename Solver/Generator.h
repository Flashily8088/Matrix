#pragma once
namespace miit::algebra {
	/**
	* @brief
	*/
	class Generator
	{
	public:
		/**
		* @brief
		*/
		virtual ~Generator() = default;
		/**
		* @brief
		*/
		virtual int generate() const = 0;
	};
}


