#pragma once
#include<string>

template<typename T> class Reader
{
public:
	virtual ~Reader(){}
	virtual T read() = 0;
};