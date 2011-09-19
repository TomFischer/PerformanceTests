#include <cstdlib>
#include <cmath>
#include <iostream>
#include "RunTimeTimer.h"
#include "CPUTimeTimer.h"

template <typename T>
T fastpow (T base, size_t exp)
{
	T result (base);
	if (exp == 0) result = static_cast<T>(1);
	for (size_t k(1); k<exp; k++) {
		result *= base;
	}
	return result;
}

int main(int argc, char *argv[])
{
	const size_t n (100000);
	double a[n];

	std::cout << "initializing vectors ... " << std::flush;
	double rand_max (static_cast<double>(RAND_MAX));
	for (size_t k(0); k<n; k++) {
		a[k] = rand()/rand_max;
	}
	std::cout << "done" << std::endl;

	RunTimeTimer run_timer;
        CPUTimeTimer cpu_timer;
	double res0;

	std::cout << "calculating square root of values with build-in pow ... " << std::flush;
	run_timer.start();
	cpu_timer.start();
	for (size_t j(0); j<1000; j++) {
		for (size_t k(0); k<n;  k++)
			res0 = pow(a[k],2.5);
	}
	cpu_timer.stop();
	run_timer.stop();
	std::cout << "done, res: " << res0 << ", time for build-in pow: " << run_timer.elapsed() << ", (cpu time: " << cpu_timer.elapsed() << ")" << std::endl;

	std::cout << "calculating square root of values with built-in sqrt ... " << std::flush;
	run_timer.start();
	cpu_timer.start();
	for (size_t j(0); j<1000; j++) {
		for (size_t k(0); k<n;  k++)
			res0 = fastpow(sqrt(a[k]), 5);
	}
	cpu_timer.stop();
	run_timer.stop();
	std::cout << "done, res: " << res0 << ", time for sqrt: " << run_timer.elapsed() << ", (cpu time: " << cpu_timer.elapsed() << ")" << std::endl;

	return 0;
}
