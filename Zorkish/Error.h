#pragma once
#include "stdafx.h"

/// Error class.
/// Displays message and exits program
///	Error returns 1

class Error
{
public:
	Error() {};

	static void Display(std::string aMsg)
	{
		std::cout << aMsg << std::endl;
		exit(1);
	}
};