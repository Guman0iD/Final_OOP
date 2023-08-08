#pragma once
#include"Writer.h"

template<typename T> class Console_writer : public Writer<T>
{
public:
	void write(const T& data) override
	{
		std::cout << data;
	}
};
