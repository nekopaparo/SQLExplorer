#include "pch.h"

#include "MySQLite.h"


SQL::MySQLite::MySQLite(const char* dbPath)
{
	this->dbPath = dbPath;
	sqlite = nullptr;
}
SQL::MySQLite::~MySQLite()
{
	if (sqlite != nullptr)
		sqlite3_close(sqlite);
}

void SQL::MySQLite::loadConnect()
{
	if (sqlite3_open(dbPath, &sqlite) != SQLITE_OK)
	{
		std::cout << sqlite3_errmsg(sqlite) << std::endl;
	}
}
// sqlite3_exec
std::vector<std::vector<std::string>>* SQL::MySQLite::query(const char* sql)
{
	if (sqlite == nullptr)
		return nullptr;
	std::vector<std::vector<std::string>>* table = new std::vector<std::vector<std::string>>();
	if (sqlite3_exec(sqlite, sql, callback_ToTable, (void*)table, nullptr) != SQLITE_OK)
	{
		std::cout << sqlite3_errmsg(sqlite) << std::endl;
		return nullptr;
	}
	else
	{
		return table;
	}
}

int SQL::MySQLite::callback_ToTable(void* data, int argc, char** argv, char** azColName)
{
	std::vector<std::vector<std::string>>* table = (std::vector<std::vector<std::string>>*)data;
	// column name
	if (table->empty())
	{
		std::vector<std::string>* colName = new std::vector<std::string>();
		for (size_t i = 0; i < argc; ++i)
		{
			colName->push_back(azColName[i]);
		}
		table->push_back(*colName);
	}
	// column value
	std::vector<std::string>* value = new std::vector<std::string>();
	for (size_t i = 0; i < argc; ++i)
	{
		if (argv[i] != NULL)
		{
			value->push_back(argv[i]);
		}
		else
		{
			value->push_back("NULL");
		}
	}
	table->push_back(*value);
	return 0;
}