#include "pch.h"

#include "FMySQL.h"
#include "FUserData.h"

#include "MyMYSQL.h"

char* SQLExplorer::StringToChar(String^ Str)
{
	return (char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Str)).ToPointer();
}

SQL::MyMYSQL* myMYSQL = NULL;
SQL::USER* USER = NULL;

void SQLExplorer::FMySQL::set() {
	Form^ f = gcnew SQLExplorer::FUserData(&USER->host, &USER->user, &USER->password, &USER->dbName);
	f->Show();
}


void SQLExplorer::FMySQL::userdata(const char* host, const char* user, const char* password, const char* dbName)
{
	if (USER == NULL)
	{
		USER = new SQL::USER{ host, user, password, dbName, 0, 0, 0 };
		//USER = new SQL::USER{ "localhost", "root", "1234", "world", 0, 0, 0 };
	}
	else
	{
		USER->host = host;
		USER->user = user;
		USER->password = password;
		USER->dbName = dbName;
	}
}
//登入MySQL
void SQLExplorer::FMySQL::singInMySQL() {
	if (myMYSQL == NULL)
	{
		myMYSQL = new SQL::MyMYSQL(USER);
	}
	lab_errMessage->Text = "";
	if (!myMYSQL->loadConnect())
	{
		lab_errMessage->Text = "!設定錯誤請重新輸入\n";
		lab_errMessage->Text += gcnew String(myMYSQL->mysql_err);
	}
	else
	{
		loadTables();
	}
}
//讀取tables
void SQLExplorer::FMySQL::loadTables() {
	lab_dbName->Text = gcnew String(USER->dbName);
	//顯示TABLES
	MYSQL_RES* res = myMYSQL->query("SHOW TABLES");
	MYSQL_ROW row;
	while (row = mysql_fetch_row(res)) {
		list_tables->Items->Add(gcnew String(row[0]));
	}
	//預設選擇
	list_tables->SelectedIndex = 0;
}


int SQLExplorer::FMySQL::tableDataShow() {
	if (myMYSQL->mysql_err != NULL) return 0;
	String^ sql = "SELECT * FROM " + list_tables->Items[list_tables->SelectedIndex];
	view(myMYSQL->resToTable(myMYSQL->query(StringToChar(sql))));
	return 1;
}
int SQLExplorer::FMySQL::view(std::vector<std::vector<std::string>*>* table) {
	if (table == NULL) return 0;
	//清空view
	this->dataGridView_tabledata->Columns->Clear();
	//標題
	auto row = table->begin();
	System::Windows::Forms::DataGridViewTextBoxColumn^ table_header;
	int column = 0;
	for (auto value = (*row)->begin(); value != (*row)->end(); ++value, ++column)
	{
		table_header = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
		table_header->HeaderText = gcnew String((*value).c_str());;
		this->dataGridView_tabledata->Columns->Add(table_header);
	}
	//內容
	int index, count = 0;
	array<System::Object^>^ tmp = gcnew array<Object^>(column);
	for (++row; row != table->end(); ++row, ++count)
	{
		for (index = 0; index < column; ++index)
		{
			tmp[index] = gcnew String((*row)->at(index).c_str());;
		}
		this->dataGridView_tabledata->Rows->Add(tmp);
		//單偶row顏色不同
		if (count % 2 != 0)
		{
			this->dataGridView_tabledata->Rows[count]->DefaultCellStyle->BackColor = System::Drawing::Color::Green;
			this->dataGridView_tabledata->Rows[count]->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
		}
	}
	return 1;
}
// clck
System::Void SQLExplorer::FMySQL::btn_view_Click(System::Object^ sender, System::EventArgs^ e)
{
	tableDataShow();
}
System::Void SQLExplorer::FMySQL::btn_reload_Click(System::Object^ sender, System::EventArgs^ e)
{
	list_tables->Items->Clear();
	dataGridView_tabledata->Columns->Clear();
	singInMySQL();
}
System::Void SQLExplorer::FMySQL::menu_set_Click(System::Object^ sender, System::EventArgs^ e)
{
	set();
}
System::Void SQLExplorer::FMySQL::list_tables_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
{
	tableDataShow();
}


