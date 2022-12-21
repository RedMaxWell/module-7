#include "container.hpp"

#include <iostream>
#include <climits>

int main()
{
	std::cout << "\t\tWellcome to Integer Container test!\n" << std::endl;
	
		//first we test the constructors
	IntegerArray* test_1 = new IntegerArray();
	IntegerArray* test_2 = new IntegerArray(10);

	std::cout << "Length of test_1 container using the default constructor: " << test_1->getLength() << std::endl;
	std::cout << "Length of test_2 container using the custom constructor with argument of 10: " << test_2->getLength() << std::endl;
	
		//now let's fill our container with some values
	for (int i = 0; i < test_2->getLength(); ++i)
	{
		(*test_2)[i] = i + 1;
	}
	
		// we can check that every item in the container is set to a valid value
	std::cout << "test_2 container items after fill from 1 to 10: ";
	for (int i = 0; i < 10; ++i)
	{
		std::cout << (*test_2)[i] << "  ";
	}
	std::cout << std::endl << std::endl;
	
		//time to check whether our copy constructor works correctly
	
	IntegerArray* test_3 = new IntegerArray(*test_2);
	
	std::cout << "length of a new test_3 container, after using copy constructor with test_2 container as an argument: " << test_3->getLength() <<std::endl;
	std::cout << "test_3 container items: ";
	for (int i = 0; i < test_3->getLength(); ++i)
	{
		std::cout << (*test_3)[i] << "  ";
	}
	std::cout << std::endl << std::endl;
		
		//now let's check if overloaded operator= works
		
	*test_1 = *test_3;
	
	std::cout << "length of test_1 container using overloaded operator= with test_3 container: " << test_1->getLength() <<std::endl;
	std::cout << "test_1 container items: ";
	for (int i = 0; i < test_1->getLength(); ++i)
	{
		std::cout << (*test_1)[i] << "  ";
	}
	std::cout << std::endl << std::endl;
		
		//the next step is to check whether we can change size of a container using reallocate() function on test_1 container
	
	test_1->reallocate(15);
	std::cout << "length of test_1 container after reallocate(15): " << test_1->getLength() <<std::endl;
	std::cout << "test_1 container items: ";
	for (int i = 0; i < test_1->getLength(); ++i)
	{
		std::cout << (*test_1)[i] << "  ";
	}
	std::cout << std::endl << std::endl;
	
		
	//trying to use resize() function on test_2 container
	
	//resize to a larger size
	test_2->resize(15);
	std::cout << "length of test_2 container after resize(15): " << test_2->getLength() <<std::endl;
	std::cout << "test_2 container items: ";
	for (int i = 0; i < test_2->getLength(); ++i)
	{
		std::cout << (*test_2)[i] << "  ";
	}
	std::cout << std::endl << std::endl;
	
	//rsize to a smaller size
	test_2->resize(5);
	std::cout << "length of test_2 container after resize(5): " << test_2->getLength() <<std::endl;
	std::cout << "test_2 container items: ";
	for (int i = 0; i < test_2->getLength(); ++i)
	{
		std::cout << (*test_2)[i] << "  ";
	}
	std::cout << std::endl << std::endl;
	
	
	//add 1 item
	
	test_2->insertBefore(100, 3);
	std::cout << "length of test_2 container after insertBefore(100, 3): " << test_2->getLength() <<std::endl;
	std::cout << "test_2 container items after insertBefore(100, 3): ";
	for (int i = 0; i < test_2->getLength(); ++i)
	{
		std::cout << (*test_2)[i] << "  ";
	}
	std::cout << std::endl << std::endl;
	
	
	//remove 1 item
		
	test_2->remove(3);
	std::cout << "length of test_2 container after remove(3): " << test_2->getLength() <<std::endl;
	std::cout << "test_2 container items after remove(3): ";
	for (int i = 0; i < test_2->getLength(); ++i)
	{
		std::cout << (*test_2)[i] << "  ";
	}
	std::cout << std::endl << std::endl;

	//insertAtBeginning
	//insertAtEnd
	
	test_2->insertAtBeginning(100);
	test_2->insertAtEnd(200);
	std::cout << "length of test_2 container after insertAtBeginning(100) and insertAtEnd(200): " << test_2->getLength() <<std::endl;
	std::cout << "test_2 container items after insertAtBeginning(100) and insertAtEnd(200): ";
	for (int i = 0; i < test_2->getLength(); ++i)
	{
		std::cout << (*test_2)[i] << "  ";
	}
	std::cout << std::endl << std::endl;
	

	//now lets try some exceptions
	//first: constructor
	std::cout << "\t\tNow lets try all exceptions" << std::endl << std::endl;
	
	IntegerArray* container = nullptr;
	try
	{
		container = new IntegerArray(-10);
	}
	catch (std::exception &e)
	{
		std::cout <<"Negative value in constructor exception: " << e.what() << std::endl << std::endl;
	}
	
	
	//reallocate() function
	try
	{
		test_1->reallocate(-10);
	}
	catch (std::exception &e)
	{
		std::cout << "Negative index in reallocate() exception: " << e.what() << std::endl << std::endl;
	}
	
	
	//insertBefore() function
	try
	{
		test_1->insertBefore(100, -1);
	}
	catch (std::exception &e)
	{
		std::cout <<"Negative index in insertBefore() exception: " <<  e.what() << std::endl << std::endl;
	}
	
	
	try
	{
		test_1->insertBefore(100, (test_1->getLength() + 1));
	}
	
	catch (std::exception &e)
	{
		std::cout << "Index greater than size of container in insertBefore() exception: " << e.what() << std::endl << std::endl;
	}
	
	
	//remove() function
	try
	{
		test_1->remove(-1);
	}
	catch (std::exception &e)
	{
		std::cout << "Negative index in remove() exception: " << e.what() << std::endl << std::endl;
	}
	
	try
	{
		test_1->remove(test_1->getLength() + 1);
	}
	catch (std::exception &e)
	{
		std::cout << "Index greater than size of container in remove() exception: " << e.what() << std::endl << std::endl;
	}
	
	//trying to accsess element that is out of range
	
	try
	{
		std::cout << (*test_1)[-1] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Trying to access negative index in container test_1[-1] exception: " << e.what() << std::endl << std::endl;
	}
	
	try
	{
		std::cout << (*test_1)[test_1->getLength() + 1] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Trying to access negative index in container test_1[test_1->getLength() + 1] exception: " << e.what() << std::endl << std::endl;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	delete test_1;
	delete test_2;
	delete test_3;
	delete container;
	
	std::cout << "Program finished correctly" << std::endl;
	
	return 0;
}


