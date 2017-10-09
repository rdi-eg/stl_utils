#ifndef STL_UTILS_H
#define STL_UTILS_H

#include <vector>
#include <string>

namespace RDI
{

extern "C++"
{
	std::vector<std::string> split(const std::string &input, const char delimiter);
}

}

#endif // STL_UTILS_H
