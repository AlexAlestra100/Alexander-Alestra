/*
Alexander Alestra
CISP 400 - TTH 10:30 am
Project 1
September 5, 2019
*/

#include <iostream>
#include <ctime>
#include <sys/timeb.h>

using namespace std;

bool IsPrime(unsigned long long n);

unsigned long long pow2(unsigned n);

unsigned long long Mersenne(unsigned n);

unsigned long long Sqrt(unsigned long long n);

double TIME ( void );

bool LucasLehmer(unsigned long long n);

int main()
{
	double s = TIME();

	for (unsigned long long i = 1; i <= 61; i++)
	{
		cout << "#: " << i  << " Prime: " << IsPrime(Mersenne(i)) << " Mersenne Number: " << Mersenne(i) << endl;
	}
	double e = TIME();

	cout << "Time: " <<  (e - s) << " milliseconds" << endl;

	double a = TIME();

	for (unsigned long long i = 1; i <= 61; i++)
        {
                cout << "#: " << i << " Lucas Lehmer Method: " << LucasLehmer(i) << " Mersenne Number: " << Mersenne(i) << endl;
        }
        double b = TIME();

	cout << "Time: " <<  (b - a) << " milliseconds" << endl;

	return 0;
}

bool IsPrime(unsigned long long n)
{
	if (n <= 2) return n == 2;

	if (n % 2 == 0) return false;

	unsigned long long  max =  Sqrt(n);

	for (unsigned long long  i = 3; i <= max; i+=2)
	{
		if (n % i == 0)
		return false;
	}
	return true;
}

unsigned long long pow2(unsigned n)
{
	return static_cast<unsigned long long>(1) << n;
}

unsigned long long Mersenne(unsigned n)
{
	return pow2(n) - 1;
}

unsigned long long Sqrt(unsigned long long n)
{
	if (n < 4) return 1;

	if (n < 9) return 2;

	unsigned long long ret = 3;

	while (ret * ret <= n)
	{
		++ret;
	}
	return ret - 1;
}

double TIME ( void )
{
   struct timeb t;
   ftime(&t);
   return ( ( (1000.0 * t.time) + t.millitm ) );
}

bool LucasLehmer ( unsigned long long n )
{
	unsigned long long s = 4;

	unsigned long long M = Mersenne(n);

	for (unsigned long long i = 0; i < n - 2; ++i)
	{
		s = ((s * s) - 2) % M;
		if (s == 0)
		return true;
	}

	return false;
}
