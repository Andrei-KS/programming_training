/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/30/2021 22:18:01
	author														: Andrei-KS
*/

#include "CH5P214EXERC7RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH5P214EXERC7RunExmple();

namespace {
	void get_quadratic_roots(double a, double b, double c)
	{
		double discriminant = b * b - 4.0 * a * c;
		if (discriminant < 0)
		{
			cout << "Roots are not exist.\n";
		}
		else if(discriminant == 0)
		{
			double res = -b / 2.0 / a;
			res = res == -0 ? -res : res;
			cout << "Root is equal " << res << "\n";
		}
		else
		{
			double sqrtDiscriminant = sqrt(discriminant);
			cout << "First root is equal " << (-b + sqrtDiscriminant) / 2.0 / a << "\n";
			cout << "Second root is equal " << (-b - sqrtDiscriminant) / 2.0 / a << "\n";
		}
		cout << "\n";
	}
}

int CH5P214EXERC7RunExmple::excute()
{
	get_quadratic_roots(1, 0, 0);
	get_quadratic_roots(1, 0, -1);
	return 0;
}