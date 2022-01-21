#pragma once

namespace Bflex
{
	class CORE_API Algorithms
	{
	public:

		inline static std::vector<std::string> split_iterator(const std::string& str, const char& c);
		
		inline static std::string change_iterator(std::string& str, const char& c_comparation);

		inline static std::string find_data_position(const std::string& str, const int& position);
	};
}