#ifndef RDI_STL_UTILS_H
#define RDI_STL_UTILS_H

#include <vector>
#include <string>

namespace RDI
{

extern "C++"
{

template<typename T>
std::vector<std::basic_string<T>> split(const std::basic_string<T> &input, const T delimiter = ' ')
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

#endif // RDI_STL_UTILS_H
