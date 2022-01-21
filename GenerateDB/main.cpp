#include <Log.h>
#include <Algorithms.h>
#include <Service.h>

using namespace Bflex;

std::string formatInsertSQL(const std::string& dni, std::string& name)
{
    name = Algorithms::change_iterator(name, 39);
    return "(default, '" + dni + "', '" + name + "'),";
}

int main()
{    
    try
    {
        Log::Init();
        Service* service = new Service("localhost", "root", "", 3306, "dni");
        std::ifstream file;
        file.open("dat.txt", std::ios::in);

        if (file.fail())
        {
            FX_ERROR("Can't open file");
            return 0;
        }

        FX_INFO("Open file");

        std::string text;
        std::list<std::string>::iterator iterator;

        std::string queryInsert = "INSERT INTO persona VALUES ";
        std::string init_queryInsert = queryInsert;

        std::list<std::string> listQueryInsert;

        unsigned int i = 1;
        unsigned int query_registrados = 10000;

        while (!file.eof())
        {
            getline(file, text);
            FX_INFO("data: {0}", text);
            break;
        }

        while (!file.eof())
        {
            getline(file, text);
            if (text == "") break;

            auto data = Algorithms::split_iterator(text, '|');

            if (i >= query_registrados) {
                i = 1;
                queryInsert.back() = ';';
                listQueryInsert.push_back(queryInsert);
                queryInsert = init_queryInsert;
                FX_INFO("Nro registered: {0}", listQueryInsert.size() * query_registrados);
            }

            queryInsert += formatInsertSQL(data[0], data[1]);
            i++;
        }

        if (queryInsert != init_queryInsert)
        {
            i = 1;
            queryInsert.back() = ';';
            listQueryInsert.push_back(queryInsert);
            queryInsert = init_queryInsert;
        }

        FX_INFO("Registering");

        for (iterator = listQueryInsert.begin(); iterator != listQueryInsert.end(); ++iterator)
        {
            service->executeQuery(*iterator);
        } 

        FX_INFO("Completed");

        file.close();
    }
    catch (sql::SQLException& e)
    {

        FX_ERROR("# ERR: SQLException in {0}", __FILE__);
        FX_ERROR("(EXAMPLE_FUNCTION) on line {0}", __LINE__);

        FX_ERROR("# ERR: {0}", e.what());
        FX_ERROR("# MySQL error code: {0}", e.getErrorCode());
        FX_ERROR("# SQLState: {0}", e.getSQLState());

        return EXIT_FAILURE;
    }
}
