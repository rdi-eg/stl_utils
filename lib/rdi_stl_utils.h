#ifndef RDI_STL_UTILS_H
#define RDI_STL_UTILS_H

#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <type_traits>

/// Use this macro to create a smart pointer to an array
#define MAKE_UNIQUE_ARRAY(TYPE, NAME, SIZE) \
	std::unique_ptr<TYPE[]> NAME = std::make_unique<TYPE[]>((SIZE))

/// Use this macro when you own an array ptr that you did not create
/// but since you own it, you're responsible of freeing it.
/// Note that the array must be created using the 'new' keyword.
/// malloc may not produce compile error and the program may run normally
/// but it can (and will) silently leak memory in the background
#define MAKE_UNIQUE_ARRAY_PTR(TYPE, NAME, ARRAY) \
	std::unique_ptr<TYPE, void (*)(TYPE*)> NAME = \
	std::unique_ptr<TYPE, void (*)(TYPE*)>((ARRAY), unique_array_ptr_deleter)

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
void unique_array_ptr_deleter(T* object)
{
	delete[] object;
}


template<typename T>
std::vector<T> concat_vectors(std::vector<T> a, std::vector<T> b)
{
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

template<typename T>
T remove_spaces(const T &input)
{
    T result="";
    for(const auto& i :input)
    {
        if(i != ' ')
        {
            result +=i;
        }

    }
    return result;
}
template <typename T>
bool within_vector(const T& element, const std::vector<T>& v)
{
	auto iterator = std::find (begin(v), end(v), element);

	if (iterator != end(v))
		return true;

	return false;
}

}



} // namespace RDI

#endif // RDI_STL_UTILS_H
