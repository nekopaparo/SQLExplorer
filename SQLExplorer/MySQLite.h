#pragma once

#ifndef MYSQLITE
#define MYSQLITE

#include <iostream>
#include <vector>
#include <sqlite3.h>

namespace SQL
{

	class MySQLite
	{
	public:
		const char* dbPath;
		sqlite3* sqlite;

		MySQLite(const char* dbPath);
		~MySQLite();
		
		void loadConnect();
		// sqlite3_exec
		std::vector<std::vector<std::string>>* query(const char* sql);

	private:
		static int callback_ToTable(void* data, int argc, char** argv, char** azColName);
	};
}
#endif // !MYSQLITE