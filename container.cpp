#include "container.hpp"

#include <iostream>
#include <climits>

const char* bad_range::what() const noexcept
{
	return "ERROR: array borders excursion";
}

const char* bad_length::what() const noexcept
{
	return "ERROR: improper length of the container";
}

const char* bad_value::what() const noexcept
{
	return "ERROR: number is either too small or too big.\nTry again\n";
}

IntegerArray::IntegerArray(int length) : _length(length)
{
	if (_length < 0)
	{
		throw bad_length();
	}
	_data = new int[_length]{};
	
	if (_length == INT_MAX)
	{
		std::cout << "Check your container size. Max size is " << INT_MAX << std::endl;
	}
}

IntegerArray::IntegerArray(const IntegerArray& other)
{
	reallocate(other.getLength());
	for (int i = 0; i < _length; ++i)
	{
		_data[i] = other._data[i];
	}
}

IntegerArray::~IntegerArray()
{
	delete[] _data;
}

void IntegerArray::erase()
{
	delete[] _data;
	_data = nullptr;
	_length = 0;
}

void IntegerArray::reallocate(int newLength)
{

	if (newLength < 0)
	{
		throw bad_length();
	}

	erase();
	
	if (newLength == 0)
	{
		return;
	}
	
	_data = new int[newLength];
	_length = newLength;
}

void IntegerArray::resize(int newLength)
{
	if (_length == newLength)
	{
		std::cout << "The container is already this size" << std::endl;
		return;
	}
	if (newLength <= 0)
	{
		erase();
		return;
	}
	int* tempo = new int[newLength];
	if (_length > 0)
	{
		int elementsToCopy = (newLength > _length) ? _length : newLength;
		for (int i = 0; i < elementsToCopy; ++i)
		{
			tempo[i] = _data[i];
		}
	}
	delete[] _data;
	_data = tempo;
	_length = newLength;
}

void IntegerArray::insertBefore(int value, int index)
{
	if ((index < 0) || (index > _length))
	{
		throw bad_range();
	}

	
	int* tempo = new int[_length + 1];
	for (int before = 0; before < index; ++before)
	{
		tempo[before] = _data[before];
	}
	
	tempo[index] = value;
	
	for(int after = index; after < _length; ++after)
	{
		tempo[after + 1] = _data[after];
	}
	delete[] _data;
	_data = tempo;
	_length += 1;
}

void IntegerArray::remove(int index)
{
	if ((index < 0) || (index > _length))
	{
		throw bad_range();
	}

	if (_length == 1)
	{
		erase();
		return;
	}
	
	int* tempo = new int[_length - 1];
	
	for (int before = 0; before < index; ++before)
	{
		tempo[before] = _data[before];
	}
	
	for (int after = (index + 1); after < _length; ++after)
	{
		tempo[after - 1] = _data[after];
	}
	
	delete[] _data;
	_data = tempo;
	_length -= 1;
}

void IntegerArray::insertAtBeginning(int value)
{
	insertBefore(value, 0);
}

void IntegerArray::insertAtEnd(int value)
{
	insertBefore(value, _length);
}

int IntegerArray::getLength() const
{
	return _length;
}

int& IntegerArray::operator[] (int index)
{
	if ((index < 0) || (index > _length))
	{
		throw bad_range();
	}

	return _data[index];
}

IntegerArray& IntegerArray::operator= (const IntegerArray& other)
{
	if (this == &other)
	{
		return *this;
	}
	
	reallocate(other.getLength());
	
	for (int i = 0; i < _length; ++i)
	{
		_data[i] = other._data[i];
	}
	return *this;
}






