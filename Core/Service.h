#pragma once

namespace Bflex
{
	class CORE_API Service
	{
	public:

		Service(const char* m_host_name,
			const char* m_user_name,
			const char* m_password,
			const int m_port,
			const char* m_schema);

		~Service();

		void connection(const char* m_host_name,
			const char* m_user_name,
			const char* m_password,
			const int m_port,
			const char* m_schema);

		void executeQuery(const std::string& query);

	private:

		const char* m_host_name;
		const char* m_user_name;
		const char* m_password;
		const char* m_schema;
		unsigned int m_port;

		sql::mysql::MySQL_Driver* m_driver;
		sql::Connection* m_con;
		sql::ConnectOptionsMap m_connection_properties;

	};
}