#pragma once

#include <iostream>
#include <string>

class IntegerArray
{
	private:
		int _length {};
		int* _data {};
		
	public:
		IntegerArray() = default;
		IntegerArray(int length);
		IntegerArray(const IntegerArray& other);
		~IntegerArray();
		
		void erase();
		void reallocate(int newLength);
		void resize(int newLength);
		void insertBefore(int value, int index);
		void remove(int index);
		void insertAtBeginning(int value);
		void insertAtEnd(int value);
		int getLength() const;
		
		int& operator[] (int index);
		IntegerArray& operator= (const IntegerArray& other);
		
};

class bad_range : public std::exception
{
	virtual const char* what() const noexcept;
};

class bad_length : public std::exception
{
	virtual const char* what() const noexcept;
};

class bad_value : public std::exception
{
	virtual const char* what() const noexcept;
};
