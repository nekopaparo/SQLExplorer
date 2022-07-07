#pragma once

#include "SetUserData.h"
#include "FSQLite.h"

namespace SQLExplorer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
		}

	protected:
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_MySQL;
	private: System::Windows::Forms::Label^ lab_lib_MySQL;
	private: System::Windows::Forms::Label^ lab_SQLit;
	private: System::Windows::Forms::Button^ btn_SQLite;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->btn_MySQL = (gcnew System::Windows::Forms::Button());
			this->lab_lib_MySQL = (gcnew System::Windows::Forms::Label());
			this->lab_SQLit = (gcnew System::Windows::Forms::Label());
			this->btn_SQLite = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_MySQL
			// 
			this->btn_MySQL->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->btn_MySQL->Location = System::Drawing::Point(82, 76);
			this->btn_MySQL->Name = L"btn_MySQL";
			this->btn_MySQL->Size = System::Drawing::Size(214, 69);
			this->btn_MySQL->TabIndex = 0;
			this->btn_MySQL->Text = L"MySQL";
			this->btn_MySQL->UseVisualStyleBackColor = true;
			this->btn_MySQL->Click += gcnew System::EventHandler(this, &Main::MySQL_Click);
			// 
			// lab_lib_MySQL
			// 
			this->lab_lib_MySQL->AutoSize = true;
			this->lab_lib_MySQL->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_lib_MySQL->ForeColor = System::Drawing::Color::Red;
			this->lab_lib_MySQL->Location = System::Drawing::Point(89, 148);
			this->lab_lib_MySQL->Name = L"lab_lib_MySQL";
			this->lab_lib_MySQL->Size = System::Drawing::Size(194, 20);
			this->lab_lib_MySQL->TabIndex = 1;
			this->lab_lib_MySQL->Text = L"using MySQL Server 8.0";
			// 
			// lab_SQLit
			// 
			this->lab_SQLit->AutoSize = true;
			this->lab_SQLit->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_SQLit->ForeColor = System::Drawing::Color::Red;
			this->lab_SQLit->Location = System::Drawing::Point(53, 257);
			this->lab_SQLit->Name = L"lab_SQLit";
			this->lab_SQLit->Size = System::Drawing::Size(271, 20);
			this->lab_SQLit->TabIndex = 3;
			this->lab_SQLit->Text = L"using sqlite-amalgamation-3380500";
			// 
			// btn_SQLite
			// 
			this->btn_SQLite->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->btn_SQLite->Location = System::Drawing::Point(82, 185);
			this->btn_SQLite->Name = L"btn_SQLite";
			this->btn_SQLite->Size = System::Drawing::Size(214, 69);
			this->btn_SQLite->TabIndex = 2;
			this->btn_SQLite->Text = L"SQLite";
			this->btn_SQLite->UseVisualStyleBackColor = true;
			this->btn_SQLite->Click += gcnew System::EventHandler(this, &Main::btn_SQLite_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(377, 361);
			this->Controls->Add(this->lab_SQLit);
			this->Controls->Add(this->btn_SQLite);
			this->Controls->Add(this->lab_lib_MySQL);
			this->Controls->Add(this->btn_MySQL);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Main";
			this->Text = L"Main";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MySQL_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ mysql = gcnew SQLExplorer::SetUserData();
		mysql->Show();
	}
	private: System::Void btn_SQLite_Click(System::Object^ sender, System::EventArgs^ e) {
		Form^ sqlite = gcnew SQLExplorer::FSQLite();
		sqlite->Show();
	}
};
}
