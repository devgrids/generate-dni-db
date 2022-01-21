#include "pch.h"
#include "Algorithms.h"
#include "Log.h"

namespace Bflex
{
	
    inline std::vector<std::string> Algorithms::split_iterator(const std::string& str, const char& c)
	{
        std::vector<std::string> resultado;

        std::string::const_iterator itBegin = str.begin();
        std::string::const_iterator itEnd = str.end();

        int numItems = 1;
        for (std::string::const_iterator it = itBegin; it != itEnd; ++it)
            numItems += *it == c;

        resultado.reserve(numItems);

        for (std::string::const_iterator it = itBegin; it != itEnd; ++it)
        {
            if (*it == c)
            {
                resultado.push_back(std::string(itBegin, it - 7));
                //FX_CORE_INFO("function split_iterator: {0}", resultado.back());
                itBegin = it + 1;
            }
        }

        if (itBegin != itEnd)
        {
            resultado.push_back(std::string(itBegin, itEnd));
            //FX_CORE_INFO("function split_iterator: {0}", resultado.back());
        }

        return resultado;
	}

    inline std::string Algorithms::change_iterator(std::string& str, const char& c_comparation)
    {
        std::string r = "";
        for (size_t i = 0; i < str.size(); i++)
        {
            if (str[i] == c_comparation)
            {
                r += "'\'";
            }
            else
            {
                r += str[i];
            }
        }
        return r;
    }

    inline std::string Algorithms::find_data_position(const std::string& str, const int& position)
    {
        std::string::const_iterator itBegin = str.begin();
        std::string::const_iterator itEnd = str.end();

        unsigned i = 0;

        for (std::string::const_iterator it = itBegin; it != itEnd; ++it)
        {
            if (*it == '|')
            {
                if (i == position)
                    return std::string(itBegin, it);
                else
                    i++;
            }
        }
        return "";
    }



}