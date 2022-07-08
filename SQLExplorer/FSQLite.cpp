#include "pch.h"

#include "FSQLite.h"

SQLExplorer::FSQLite::FSQLite(void)
{
	InitializeComponent();

	mySQLite = NULL;
}
SQLExplorer::FSQLite::~FSQLite()
{
	if (components)
	{
		delete components;
	}
	if (mySQLite != NULL)
	{
		delete mySQLite;
	}
}

char* SQLExplorer::FSQLite::StringToChar(String^ Str)
{
	return (char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(Str)).ToPointer();
}
// data
void SQLExplorer::FSQLite::loadTables() {
	list_tables->Items->Clear();
	lab_errMessage->Text = "";
	// dbName
	std::string dbName(mySQLite->dbPath);
	size_t find = dbName.find_last_of('\\') + 1;
	lab_dbName->Text = gcnew String(dbName.substr(find, dbName.length() - find).c_str());
	//顯示TABLES
	const char* sql =
		"SELECT name FROM sqlite_schema "
		"WHERE type = 'table' "
		"ORDER BY name;";
	std::vector<std::vector<std::string>>* table = mySQLite->query(sql);
	if (table == NULL || table->size() < 1)
	{
		lab_errMessage->Text = gcnew String("No Table");
		mySQLite = NULL;
		return;
	}
	else
	{
		for (auto it = table->begin() + 1; it != table->end(); ++it)
		{
			list_tables->Items->Add(gcnew String(it->begin()->c_str()));
		}
	}
	//預設選擇
	list_tables->SelectedIndex = 0;
}
void SQLExplorer::FSQLite::view(std::vector<std::vector<std::string>>* table) {
	if (table == NULL) return;
	//清空view
	this->dataGridView_tabledata->Columns->Clear();
	//標題
	auto row = table->begin();
	System::Windows::Forms::DataGridViewTextBoxColumn^ table_header;
	int column = 0;
	for (auto value = row->begin(); value != row->end(); ++value, ++column)
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
			tmp[index] = gcnew String(row->at(index).c_str());;
		}
		this->dataGridView_tabledata->Rows->Add(tmp);
		//單偶row顏色不同
		if (count % 2 != 0)
		{
			this->dataGridView_tabledata->Rows[count]->DefaultCellStyle->BackColor = System::Drawing::Color::Green;
			this->dataGridView_tabledata->Rows[count]->DefaultCellStyle->ForeColor = System::Drawing::Color::White;
		}
	}
}
void SQLExplorer::FSQLite::tableDataShow()
{
	if (mySQLite == NULL) return;
	String^ sql = "SELECT * FROM " + list_tables->Items[list_tables->SelectedIndex];
	view(mySQLite->query(StringToChar(sql)));
}
// click
System::Void SQLExplorer::FSQLite::btn_view_Click(System::Object^ sender, System::EventArgs^ e) {
	tableDataShow();
}
System::Void SQLExplorer::FSQLite::list_tables_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	tableDataShow();
}
System::Void SQLExplorer::FSQLite::menu_openfile_Click(System::Object^ sender, System::EventArgs^ e) {
	OpenFileDialog^ ofd = gcnew OpenFileDialog();
	ofd->Filter = "SQLite|*.db";
	ofd->Title = "SQLite Read";
	if (ofd->ShowDialog() != System::Windows::Forms::DialogResult::OK) { return; }
	else
	{
		mySQLite = new SQL::MySQLite(StringToChar(ofd->FileName));
		mySQLite->loadConnect();
		loadTables();
		dataGridView_tabledata->Columns->Clear();
	}
}