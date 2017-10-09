#include "stl_utils.h"

using namespace std;

namespace RDI
{

std::vector<std::string> split(const std::string& input, const char delimiter)
{
	string buff{""};
	vector<string> output;

	for(auto c : input)
	{
		if(c != delimiter)
		{
			buff += c;
		}
		else
		{
			if(c == delimiter && buff != "")
			{
				output.push_back(buff);
				buff = "";
			}
		}
	}

	if(buff != "")
	{
		output.push_back(buff);
	}

	return output;
}

}
