#pragma once
#include <string>
#include <vector>
#include <algorithm>

namespace cfuStr
{
// split the string tosplit by delim.
// With x appearances of delim in tosplit,
// the returned vector
// will have length x + 1 (even if appearances at the start, end, contiguous.
std::vector<std::string> Split(const std::string& tosplit, const std::string& delim)
{
	// vector to return
	std::vector<std::string> spv;
	if (delim.length() > tosplit.length())
	{
		return spv;
	}
	std::vector<size_t> splitposstarts{ 0 };
	std::vector<size_t> splitposends;
	for (size_t x = 0; x < tosplit.length() - delim.length() + 1; x++)
	{
		auto res = std::mismatch(delim.begin(), delim.end(), tosplit.begin() + x);
		if (res.first == delim.end())
		{
			splitposends.push_back(x);
			splitposstarts.push_back(x + delim.length());
		}
	}
	splitposends.push_back(tosplit.length());
	for (unsigned i = 0; i < splitposends.size(); ++i)
	{
		spv.push_back(tosplit.substr(splitposstarts[i], splitposends[i] - splitposstarts[i]));
	}
	return spv;
}
}