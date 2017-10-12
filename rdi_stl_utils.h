#ifndef RDI_STL_UTILS_H
#define RDI_STL_UTILS_H

#include <vector>
#include <string>

namespace RDI
{

extern "C++"
{
	std::vector<std::string> split(const std::string &input, const char delimiter = ' ');

	template<typename T>
	std::vector<T> concat_vectors(std::vector<T> a, std::vector<T> b)
	{
		a.insert(a.end(), b.begin(), b.end());
		return a;
	}
}

}

#endif // RDI_STL_UTILS_H
