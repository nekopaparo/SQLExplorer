#pragma once

#include "FMySQL.h"

namespace SQLExplorer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FUserData : public System::Windows::Forms::Form
	{
	public:
		const char** host;
		const char** user;
		const char** password;
		const char** dbName;

		FUserData(void);
		FUserData(const char** host, const char** user, const char** password, const char** dbName);

	protected:
		~FUserData();

	// 標題
	private: System::Windows::Forms::Label^ lab_title;
	// data
	private: System::Windows::Forms::Label^ lab_host;
	private: System::Windows::Forms::TextBox^ text_host;
	private: System::Windows::Forms::Label^ lab_user;
	private: System::Windows::Forms::TextBox^ text_user;
	private: System::Windows::Forms::Label^ lab_password;
	private: System::Windows::Forms::TextBox^ text_password;
	private: System::Windows::Forms::Label^ lab_dbName;
	private: System::Windows::Forms::TextBox^ text_dbName;
	// 送出按鈕
	private: System::Windows::Forms::Button^ btn_submit;

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btn_submit = (gcnew System::Windows::Forms::Button());
			this->lab_host = (gcnew System::Windows::Forms::Label());
			this->text_host = (gcnew System::Windows::Forms::TextBox());
			this->text_user = (gcnew System::Windows::Forms::TextBox());
			this->lab_user = (gcnew System::Windows::Forms::Label());
			this->text_password = (gcnew System::Windows::Forms::TextBox());
			this->lab_password = (gcnew System::Windows::Forms::Label());
			this->text_dbName = (gcnew System::Windows::Forms::TextBox());
			this->lab_dbName = (gcnew System::Windows::Forms::Label());
			this->lab_title = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_submit
			// 
			this->btn_submit->Location = System::Drawing::Point(306, 330);
			this->btn_submit->Name = L"button1";
			this->btn_submit->Size = System::Drawing::Size(131, 46);
			this->btn_submit->TabIndex = 0;
			this->btn_submit->Text = L"送出";
			this->btn_submit->UseVisualStyleBackColor = true;
			this->btn_submit->Click += gcnew System::EventHandler(this, &FUserData::button1_Click);
			// 
			// label1
			// 
			this->lab_host->AutoSize = true;
			this->lab_host->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_host->Location = System::Drawing::Point(141, 102);
			this->lab_host->Name = L"label1";
			this->lab_host->Size = System::Drawing::Size(74, 30);
			this->lab_host->TabIndex = 1;
			this->lab_host->Text = L"Host:";
			// 
			// textBox1
			// 
			this->text_host->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->text_host->Location = System::Drawing::Point(212, 107);
			this->text_host->Name = L"textBox1";
			this->text_host->Size = System::Drawing::Size(163, 31);
			this->text_host->TabIndex = 2;
			// 
			// textBox2
			// 
			this->text_user->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->text_user->Location = System::Drawing::Point(212, 163);
			this->text_user->Name = L"textBox2";
			this->text_user->Size = System::Drawing::Size(163, 31);
			this->text_user->TabIndex = 4;
			// 
			// label2
			// 
			this->lab_user->AutoSize = true;
			this->lab_user->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_user->Location = System::Drawing::Point(141, 158);
			this->lab_user->Name = L"label2";
			this->lab_user->Size = System::Drawing::Size(74, 30);
			this->lab_user->TabIndex = 3;
			this->lab_user->Text = L"User:";
			// 
			// textBox3
			// 
			this->text_password->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->text_password->Location = System::Drawing::Point(212, 219);
			this->text_password->Name = L"textBox3";
			this->text_password->PasswordChar = '*';
			this->text_password->Size = System::Drawing::Size(163, 31);
			this->text_password->TabIndex = 6;
			// 
			// label3
			// 
			this->lab_password->AutoSize = true;
			this->lab_password->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_password->Location = System::Drawing::Point(86, 214);
			this->lab_password->Name = L"label3";
			this->lab_password->Size = System::Drawing::Size(129, 30);
			this->lab_password->TabIndex = 5;
			this->lab_password->Text = L"Password:";
			// 
			// textBox4
			// 
			this->text_dbName->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->text_dbName->Location = System::Drawing::Point(212, 272);
			this->text_dbName->Name = L"textBox4";
			this->text_dbName->Size = System::Drawing::Size(163, 31);
			this->text_dbName->TabIndex = 8;
			// 
			// label4
			// 
			this->lab_dbName->AutoSize = true;
			this->lab_dbName->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_dbName->Location = System::Drawing::Point(98, 267);
			this->lab_dbName->Name = L"label4";
			this->lab_dbName->Size = System::Drawing::Size(117, 30);
			this->lab_dbName->TabIndex = 7;
			this->lab_dbName->Text = L"dbName:";
			// 
			// label5
			// 
			this->lab_title->AutoSize = true;
			this->lab_title->Font = (gcnew System::Drawing::Font(L"新細明體", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_title->Location = System::Drawing::Point(81, 17);
			this->lab_title->Name = L"label5";
			this->lab_title->Size = System::Drawing::Size(330, 60);
			this->lab_title->TabIndex = 10;
			this->lab_title->Text = L"使用者設定";
			// 
			// SetUserData
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(492, 387);
			this->Controls->Add(this->lab_title);
			this->Controls->Add(this->text_dbName);
			this->Controls->Add(this->lab_dbName);
			this->Controls->Add(this->text_password);
			this->Controls->Add(this->lab_password);
			this->Controls->Add(this->text_user);
			this->Controls->Add(this->lab_user);
			this->Controls->Add(this->text_host);
			this->Controls->Add(this->lab_host);
			this->Controls->Add(this->btn_submit);
			this->Name = L"SetUserData";
			this->Text = L"SignIn";
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	// 送出
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
};
}
