#pragma once
#include"Reader.h"

template<typename T> class Console_reader : public Reader<T>
{
public:
	T read() override
	{
		T data{};
		std::cin >> data;
		return data;
	}
};