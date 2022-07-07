#include "pch.h"

#include "MyMYSQL.h"

SQL::MyMYSQL::MyMYSQL(USER* user)
{
	mysql = new MYSQL();
	this->user = user;
	mysql_err = NULL;
}
SQL::MyMYSQL::MyMYSQL(const char* host, const char* user, const char* password, const char* dbName,
	int port, const char* unix_socket, long client_flag)
{
	mysql = new MYSQL();
	this->user = new SQL::USER{ host, user, password, dbName,
									port, unix_socket, client_flag };
	mysql_err = NULL;
}
SQL::MyMYSQL::~MyMYSQL()
{
	mysql_close(mysql);
}
void SQL::MyMYSQL::setUserData(const char* host, const char* user, const char* password, const char* dbName,
	int port, const char* unix_socket, long client_flag)
{
	//使用者設定
	this->user->host = host;
	this->user->user = user;
	this->user->password = password;
	this->user->dbName = dbName;
	//可用預設
	this->user->port = port;
	this->user->unix_socket = unix_socket;
	this->user->client_flag = client_flag;
}
// load connect
bool SQL::MyMYSQL::loadConnect()
{
	if (mysql_init(mysql) == 0)
	{
		mysql_err = mysql_error(mysql);
	}
	else if (mysql_real_connect(mysql, user->host, user->user, user->password, user->dbName,
		user->port, user->unix_socket, user->client_flag) == 0)
	{
		mysql_err =  mysql_error(mysql);
	}
	else
	{
		mysql_set_character_set(mysql, "utf8");
		if (mysql_err) mysql_err = NULL;
		return 1;
	}
	return 0;
}
//查詢
MYSQL_RES* SQL::MyMYSQL::query(const char* sql)
{
	// sql is OK == 0 
	if (mysql_real_query(mysql, sql, (unsigned int)strlen(sql)))
	{
		mysql_err = mysql_error(mysql);
		return NULL;
	}
	else
	{
		mysql_err = NULL;
		return mysql_store_result(mysql);
	}
}
// 將結果用string另外儲存
std::vector<std::vector<std::string>*>* SQL::MyMYSQL::resToTable(MYSQL_RES* res) {
	if (res == NULL) return NULL;
	// create table
	std::vector<std::vector<std::string>*>* table = new std::vector<std::vector<std::string>*>();
	std::vector<std::string>* tmp;
	size_t column = mysql_num_fields(res), index;
	//標題
	tmp = new std::vector<std::string>();
	table->push_back(tmp);
	for (index = 0; index < column; index++)
	{
		tmp->push_back(mysql_fetch_field(res)->name);
	}
	//內容
	MYSQL_ROW row;
	unsigned long* values_length;
	while (row = mysql_fetch_row(res))
	{
		tmp = new std::vector<std::string>();
		table->push_back(tmp);
		values_length = mysql_fetch_lengths(res);
		for (index = 0; index < column; index++) {
			//row[index] = NULL時，會跳出ERROR無法取出
			//利用值的長度來排除空值(NULL) https://dev.mysql.com/doc/c-api/8.0/en/mysql-fetch-row.html
			if (values_length[index])
			{
				tmp->push_back(row[index]);
			}
			else
			{
				tmp->push_back("NULL");
			}
		}
	}
	//clear
	mysql_free_result(res);
	return table;
}