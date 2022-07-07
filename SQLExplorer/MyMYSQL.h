#pragma once

#ifndef MYMYSQL
#define MYMYSQL

#include <iostream>
#include <vector>
#include <mysql.h>

namespace SQL
{
	struct USER
	{
		//使用者設定
		const char* host;
		const char* user;
		const char* password;
		const char* dbName;
		//可用預設
		int port;
		const char* unix_socket;
		long client_flag;
	};
	class MyMYSQL
	{
	private:

		MYSQL* mysql;

		USER* user;

	public:
		const char* mysql_err;

		MyMYSQL(USER* user);
		MyMYSQL(const char* host, const char* user, const char* password, const char* dbName, int port = 0, const char* unix_socket = (const char*)0, long client_flag = 0L);
		~MyMYSQL();
		// user data
		void setUserData(const char* host, const char* user, const char* password, const char* dbName, int port = 0, const char* unix_socket = (const char*)0, long client_flag = 0L);
		// load connect
		bool loadConnect();
		//查詢
		MYSQL_RES* query(const char* sql);
		// res to table[row][column]，將結果用string另外儲存
		std::vector<std::vector<std::string>*>* resToTable(MYSQL_RES* res); 
	};
}
#endif // MyMYSQL