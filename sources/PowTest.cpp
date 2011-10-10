/*
 * PowTest.cpp
 *
 *  Created on: Sep 19, 2011
 *      Author: TF
 */

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

	size_t exp (2);
	if (argc > 1) {
		exp = static_cast<size_t>(std::atoi(argv[1]));
	}

	RunTimeTimer run_timer;
	CPUTimeTimer cpu_timer;
	double res0;

	std::cout << "calculating x^" << exp << " of values with build-in pow ... " << std::flush;
	run_timer.start();
	cpu_timer.start();
	for (size_t j(0); j<1000; j++) {
		for (size_t k(0); k<n;  k++)
			res0 = pow(a[k],exp);
	}
	cpu_timer.stop();
	run_timer.stop();
	std::cout << "done, time for build-in pow: " << run_timer.elapsed() << ", (cpu time: " << cpu_timer.elapsed() << "), res: " << res0 << std::endl;

	std::cout << "calculating x^" << exp << " of values with fastpow ... " << std::flush;
	run_timer.start();
	cpu_timer.start();
	for (size_t j(0); j<1000; j++) {
		for (size_t k(0); k<n;  k++)
			res0 = fastpow(a[k],exp);
	}
	cpu_timer.stop();
	run_timer.stop();
	std::cout << "done, time for fastpow: " << run_timer.elapsed() << ", (cpu time: " << cpu_timer.elapsed() << "), res: " << res0 << std::endl;

	double t = 1e-4;
	std::cout.precision (18);
	std::cout << t << "^3: " << std::endl << "fastpow: " << fastpow(t, 3) << std::endl << "pow:     " << pow(t,3) << std::endl;
	std::cout << "(" << t << "^3)^{1/3}: " << std::endl << "fastpow: " << pow(fastpow(t, 3), 1.0/3.0) << std::endl << "pow:     " << pow(pow(t,3.0), 1.0/3.0) << std::endl;

	t = 1e-2;
	std::cout.precision (18);
	std::cout << t << "^3: " << std::endl << "fastpow: " << fastpow(t, 3) << std::endl << "pow:     " << pow(t,3) << std::endl;
	std::cout << "(" << t << "^3)^{1/3}: " << std::endl << "fastpow: " << pow(fastpow(t, 3), 1.0/3.0) << std::endl << "pow:     " << pow(pow(t,3.0), 1.0/3.0) << std::endl;

	t = 1e-1;
	std::cout.precision (18);
	std::cout << t << "^3: " << std::endl << "fastpow: " << fastpow(t, 3) << std::endl << "pow:     " << pow(t,3) << std::endl;
	std::cout << "(" << t << "^3)^{1/3}: " << std::endl << "fastpow: " << pow(fastpow(t, 3), 1.0/3.0) << std::endl << "pow:     " << pow(pow(t,3.0), 1.0/3.0) << std::endl;

	t = 0.4;
	std::cout.precision (18);
	std::cout << t << "^3: " << std::endl << "fastpow: " << fastpow(t, 3) << std::endl << "pow:     " << pow(t,3) << std::endl;
	std::cout << "(" << t << "^3)^{1/3}: " << std::endl << "fastpow: " << pow(fastpow(t, 3), 1.0/3.0) << std::endl << "pow:     " << pow(pow(t,3.0), 1.0/3.0) << std::endl;

	t = 1e-3;
	std::cout.precision (18);
	std::cout << t << "^3: " << std::endl << "fastpow: " << fastpow(t, 3) << std::endl << "pow:     " << pow(t,3) << std::endl;
	std::cout << "(" << t << "^3)^{1/3}: " << std::endl << "fastpow: " << pow(fastpow(t, 3), 1.0/3.0) << std::endl << "pow:     " << pow(pow(t,3.0), 1.0/3.0) << std::endl;

	return 0;
}
