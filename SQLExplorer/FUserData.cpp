#include "pch.h"

#include "FUserData.h"


SQLExplorer::FUserData::FUserData(void)
{
	InitializeComponent();

	this->host = this->user = this->password = this->dbName = NULL;

	text_host->Text = "localhost";
	text_user->Text = "root";
	text_password->Text = "1234";
	text_dbName->Text = "world";
}
SQLExplorer::FUserData::FUserData(const char** host, const char** user, const char** password, const char** dbName)
{
	InitializeComponent();

	this->host = host;
	this->user = user;
	this->password = password;
	this->dbName = dbName;

	text_host->Text = gcnew String(*host);
	text_user->Text = gcnew String(*user);
	text_password->Text = gcnew String(*password);
	text_dbName->Text = gcnew String(*dbName);
}
SQLExplorer::FUserData::~FUserData()
{
	if (components)
	{
		delete components;
	}
}


System::Void SQLExplorer::FUserData::button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (host == NULL)
	{
		Form^ f = gcnew SQLExplorer::FMySQL(StringToChar(text_host->Text), StringToChar(text_user->Text), StringToChar(text_password->Text), StringToChar(text_dbName->Text));
		f->Show();
	}
	else
	{
		*host = StringToChar(text_host->Text);
		*user = StringToChar(text_user->Text);
		*password = StringToChar(text_password->Text);
		*dbName = StringToChar(text_dbName->Text);
	}
	this->Close();
}