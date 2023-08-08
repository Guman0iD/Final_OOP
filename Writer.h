#pragma once
#include<string>

template<typename T>class Writer
{
public:
	virtual ~Writer(){}
	virtual void write(const T& value) = 0;
};