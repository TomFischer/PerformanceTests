#include <cstdlib>
#include <iostream>
#include <vector>
#include "RunTimeTimer.h"
#include "CPUTimeTimer.h"

double scprOperatorVersion (std::vector<double> const& a, std::vector<double> const& b)
{
	double res (0.0);
	const size_t size (a.size());
	for (size_t k(0); k<size; k++) {
		res += a[k] * b[k];
	}
	return res;	
}

double scprIteratorVersion (std::vector<double> const& a, std::vector<double> const& b)
{
	double res (0.0);
	const size_t size (a.size());
	std::vector<double>::const_iterator ia(a.begin());
	std::vector<double>::const_iterator ib(b.begin());

	for (size_t k(0); k<size; k++) {
		res += ia[k] * ib[k];
	}

	return res;
}

int main(int argc, char *argv[])
{
	std::vector<double> a,b;

	std::cout << "initializing vectors ... " << std::flush;
	double rand_max (static_cast<double>(RAND_MAX));
	for (size_t k(0); k<1048576; k++) {
		a.push_back(rand()/rand_max);
		b.push_back(rand()/rand_max);
	}
	std::cout << "done" << std::endl;

	RunTimeTimer run_timer;
        CPUTimeTimer cpu_timer;
	std::cout << "calculating scalar product (operator version) ... " << std::flush;
	double res0;
	run_timer.start();
	cpu_timer.start();
	for (size_t k(0); k<1000;  k++) 
		res0 = scprOperatorVersion(a,b);
	cpu_timer.stop();
	run_timer.stop();
	std::cout << "done, time for scpr: " << run_timer.elapsed() << ", (cpu time: " << cpu_timer.elapsed() << ")" << std::endl;
	std::cout << "result: " << res0 << std::endl;

/*	
	std::cout << "calculating scalar product (iterator version) ... " << std::flush;
	double res1;
	run_timer.start();
	cpu_timer.start();
	for (size_t k(0); k<1000;  k++) 
		res1 = scprIteratorVersion(a,b);
	cpu_timer.stop();
	run_timer.stop();
	std::cout << "done, time for scpr: " << run_timer.elapsed() << ", (cpu time: " << cpu_timer.elapsed() << ")" << std::endl;
	std::cout << "result: " << res1 << std::endl;
*/

/*
	std::cout << "calculating scalar product (operator version) ... " << std::flush;
	double res0;
	run_timer.start();
	cpu_timer.start();
	for (size_t k(0); k<1000;  k++) 
		res0 = scprOperatorVersion(a,b);
	cpu_timer.stop();
	run_timer.stop();
	
	std::cout << "done, time for scpr: " << run_timer.elapsed() << ", (cpu time: " << cpu_timer.elapsed() << ")" << std::endl;
	std::cout << "result: " << res0 << std::endl;
*/
	return 0;
}
