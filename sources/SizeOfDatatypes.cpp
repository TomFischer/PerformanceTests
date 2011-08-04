#include <iostream>
#include <limits>
#include <vector>
#include <cmath>
#include <string>

int main(int argc, char *argv[])
{
	std::cout << "size of char: " << sizeof (unsigned char) 
		<< "  " << std::flush;
	std::cout << "[" << std::numeric_limits<unsigned char>::min () << "," 
		<< (unsigned int)std::numeric_limits<unsigned char>::max () 
		<< "]" << std::endl;
	std::cout << "size of unsigned short: " << sizeof (unsigned short) 
		<< "  " << std::flush;
	std::cout << "[" << std::numeric_limits<unsigned short>::min () << "," << std::numeric_limits<unsigned short>::max () << "]" << std::endl;
	std::cout << "size of size_t: " << sizeof (size_t) << "  " << std::flush;
	std::cout << "[" << std::numeric_limits<size_t>::min () << "," << std::numeric_limits<size_t>::max () << "]" << std::endl;
	std::cout << "size of int: " << sizeof (int) << "  " << std::flush;
	std::cout << "[" << std::numeric_limits<int>::min () << "," << std::numeric_limits<int>::max () << "]" << std::endl;
	std::cout << "size of unsigned: " << sizeof (unsigned) << "  " << std::flush;
	std::cout << "[" << std::numeric_limits<unsigned>::min () << "," << std::numeric_limits<unsigned>::max () << "]" << std::endl;
	std::cout << "size of long: " << sizeof (long) << "  " << std::flush;
	std::cout << "[" << std::numeric_limits<long>::min () << "," << std::numeric_limits<long>::max () << "]" << std::endl;

	// *** float
	std::cout << "size of float: " << sizeof (float) << "  ";;
	std::cout << "[" << std::numeric_limits<float>::min () << "," 
		<< std::numeric_limits<float>::max () << ", "
		<< "epsilon: " << std::numeric_limits<float>::epsilon () 
		<< "]" << std::endl;

	// *** double
	std::cout << "size of double: " << sizeof (double) << "  ";
	std::cout << "[" << std::numeric_limits<double>::min () << "," 
		<< std::numeric_limits<double>::max () << ", "
		<< "epsilon: " << std::numeric_limits<double>::epsilon () 
		<< "]" << std::endl;

	std::cout << "size of std::string: " << sizeof (std::string) << "  " << std::endl;

	return 0;
}
