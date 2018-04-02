#ifndef RDI_STL_UTILS_H
#define RDI_STL_UTILS_H

#include <vector>
#include <string>

namespace RDI
{

extern "C++"
{

template<typename T ,typename D>
std::vector<std::basic_string<T>> split(const std::basic_string<T> &input, const D delimiter = ' ')
{
	std::basic_string<T> buff;
	std::vector<std::basic_string<T>> output;

	for(auto c : input)
	{
		if(c != delimiter)
		{
			buff += c;
		}
		else
		{
			if(c == delimiter && !buff.empty())
			{
				output.push_back(buff);
				buff.clear();
			}
		}
	}

	if(!buff.empty())
	{
		output.push_back(buff);
	}

	return output;
}

template<typename T>
	std::vector<T> concat_vectors(std::vector<T> a, std::vector<T> b)
	{
		a.insert(a.end(), b.begin(), b.end());
		return a;
	}
}

}

#endif // RDI_STL_UTILS_H
