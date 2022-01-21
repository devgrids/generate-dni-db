#include "pch.h"
#include "Service.h"

#include "Log.h"

namespace Bflex
{
	Service::Service(const char* m_host_name, const char* m_user_name, const char* m_password, const int m_port, const char* m_schema)
	{
		this->m_host_name = m_host_name;
		this->m_user_name = m_user_name;
		this->m_password = m_password;
		this->m_port = m_port;
		this->m_schema = m_schema;

		connection(m_host_name, m_user_name, m_password, m_port, m_schema);
	}

	Service::~Service()
	{
		m_con->close();
		delete m_con;

		m_driver->threadEnd();
	}

	void Service::connection(const char* m_host_name, const char* m_user_name, const char* m_password, const int m_port, const char* m_schema)
	{
		m_connection_properties[OPT_HOSTNAME] = m_host_name;
		m_connection_properties[OPT_USERNAME] = m_user_name;
		m_connection_properties[OPT_PASSWORD] = m_password;

		m_connection_properties[OPT_PORT] = m_port;
		m_connection_properties[OPT_SCHEMA] = m_schema;

		m_connection_properties["OPT_SSL_MODE"] = sql::SSL_MODE_DISABLED;
		m_connection_properties[OPT_RECONNECT] = true;

		m_driver = sql::mysql::get_driver_instance();

		if (m_driver == NULL)
		{
			FX_SERVICE_ERROR("Failed driver");
			return;
		}

		FX_SERVICE_INFO("Success driver");
		m_driver->threadInit();
		
		m_con = m_driver->connect(m_connection_properties);
		if (m_con == NULL)
		{
			FX_SERVICE_ERROR("Failed connection");
			return;
		}

		FX_SERVICE_INFO("Success connection");
	}

	void Service::executeQuery(const std::string& query)
	{
		//FX_SERVICE_INFO("Service -> Success query: {0}", query);
		std::unique_ptr<sql::PreparedStatement> pstmtInsertar(m_con->prepareStatement(query));
		pstmtInsertar->execute();
		FX_SERVICE_INFO("Success query");
	}
}