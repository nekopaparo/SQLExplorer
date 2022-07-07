#pragma once

#include <iostream>
#include <vector>

namespace SQLExplorer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	char* StringToChar(String^ Str);

	/// <summary>
	/// FMySQL 的摘要
	/// </summary>
	public ref class FMySQL : public System::Windows::Forms::Form
	{
	public:

		FMySQL(void)
		{
			InitializeComponent();
			
			userdata("localhost", "root", "1234", "world");

			singInMySQL();
		}
		FMySQL(const char* host, const char* user, const char* password, const char* dbName)
		{
			InitializeComponent();

			userdata(host, user, password, dbName);

			singInMySQL();
		}

	protected:

		~FMySQL()
		{
			if (components)
			{
				delete components;
			}
		}

	// db
	private: System::Windows::Forms::Label^ lab_DB;
	private: System::Windows::Forms::Label^ lab_dbName;
	private: System::Windows::Forms::Label^ lab_errMessage;
	// tables
	private: System::Windows::Forms::Panel^ panel_tables;
	private: System::Windows::Forms::Label^ lab_tables;
	private: System::Windows::Forms::ListBox^ list_tables;
	// table data
	private: System::Windows::Forms::Button^ btn_view;
	private: System::Windows::Forms::DataGridView^ dataGridView_tabledata;
	
	private: System::Windows::Forms::MenuStrip^ menu;
	private: System::Windows::Forms::ToolStripMenuItem^ menu_set;
	private: System::Windows::Forms::Button^ btn_reload;
	private:

		System::ComponentModel::Container ^components;

		void userdata(const char* host, const char* user, const char* password, const char* dbName);
		void set();
		void singInMySQL();
		void loadTables();
		int tableDataShow();
		int view(std::vector<std::vector<std::string>*>* table);

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->btn_view = (gcnew System::Windows::Forms::Button());
			this->dataGridView_tabledata = (gcnew System::Windows::Forms::DataGridView());
			this->lab_DB = (gcnew System::Windows::Forms::Label());
			this->lab_dbName = (gcnew System::Windows::Forms::Label());
			this->lab_errMessage = (gcnew System::Windows::Forms::Label());
			this->panel_tables = (gcnew System::Windows::Forms::Panel());
			this->lab_tables = (gcnew System::Windows::Forms::Label());
			this->list_tables = (gcnew System::Windows::Forms::ListBox());
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->menu_set = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btn_reload = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_tabledata))->BeginInit();
			this->panel_tables->SuspendLayout();
			this->menu->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_view
			// 
			this->btn_view->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->btn_view->Location = System::Drawing::Point(22, 131);
			this->btn_view->Name = L"btn_view";
			this->btn_view->Size = System::Drawing::Size(139, 41);
			this->btn_view->TabIndex = 1;
			this->btn_view->Text = L"view";
			this->btn_view->UseVisualStyleBackColor = true;
			this->btn_view->Click += gcnew System::EventHandler(this, &FMySQL::btn_view_Click);
			// 
			// dataGridView_tabledata
			// 
			this->dataGridView_tabledata->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView_tabledata->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView_tabledata->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView_tabledata->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView_tabledata->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"新細明體", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView_tabledata->DefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView_tabledata->Location = System::Drawing::Point(10, 180);
			this->dataGridView_tabledata->Name = L"dataGridView_tabledata";
			this->dataGridView_tabledata->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->dataGridView_tabledata->RowHeadersWidth = 100;
			this->dataGridView_tabledata->RowTemplate->Height = 27;
			this->dataGridView_tabledata->Size = System::Drawing::Size(704, 420);
			this->dataGridView_tabledata->TabIndex = 0;
			// 
			// lab_DB
			// 
			this->lab_DB->AutoSize = true;
			this->lab_DB->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_DB->Location = System::Drawing::Point(20, 37);
			this->lab_DB->Name = L"lab_DB";
			this->lab_DB->Size = System::Drawing::Size(60, 30);
			this->lab_DB->TabIndex = 4;
			this->lab_DB->Text = L"DB:";
			// 
			// lab_dbName
			// 
			this->lab_dbName->AutoSize = true;
			this->lab_dbName->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_dbName->Location = System::Drawing::Point(78, 37);
			this->lab_dbName->Name = L"lab_dbName";
			this->lab_dbName->Size = System::Drawing::Size(0, 30);
			this->lab_dbName->TabIndex = 5;
			// 
			// lab_errMessage
			// 
			this->lab_errMessage->AutoSize = true;
			this->lab_errMessage->Font = (gcnew System::Drawing::Font(L"新細明體", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_errMessage->ForeColor = System::Drawing::Color::Red;
			this->lab_errMessage->Location = System::Drawing::Point(167, 72);
			this->lab_errMessage->MaximumSize = System::Drawing::Size(350, 100);
			this->lab_errMessage->Name = L"lab_errMessage";
			this->lab_errMessage->Size = System::Drawing::Size(0, 17);
			this->lab_errMessage->TabIndex = 7;
			// 
			// panel_tables
			// 
			this->panel_tables->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel_tables->Controls->Add(this->lab_tables);
			this->panel_tables->Controls->Add(this->list_tables);
			this->panel_tables->Location = System::Drawing::Point(531, 35);
			this->panel_tables->Name = L"panel_tables";
			this->panel_tables->Size = System::Drawing::Size(179, 137);
			this->panel_tables->TabIndex = 6;
			// 
			// lab_tables
			// 
			this->lab_tables->AutoSize = true;
			this->lab_tables->Font = (gcnew System::Drawing::Font(L"新細明體", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->lab_tables->Location = System::Drawing::Point(-1, 2);
			this->lab_tables->Name = L"lab_tables";
			this->lab_tables->Size = System::Drawing::Size(116, 24);
			this->lab_tables->TabIndex = 7;
			this->lab_tables->Text = L"Tables_List";
			// 
			// list_tables
			// 
			this->list_tables->Font = (gcnew System::Drawing::Font(L"新細明體", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->list_tables->FormattingEnabled = true;
			this->list_tables->ItemHeight = 20;
			this->list_tables->Location = System::Drawing::Point(3, 29);
			this->list_tables->Name = L"list_tables";
			this->list_tables->Size = System::Drawing::Size(171, 104);
			this->list_tables->TabIndex = 3;
			this->list_tables->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &FMySQL::list_tables_MouseDoubleClick);
			// 
			// menu
			// 
			this->menu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menu_set });
			this->menu->Location = System::Drawing::Point(0, 0);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(726, 27);
			this->menu->TabIndex = 8;
			this->menu->Text = L"menuStrip1";
			// 
			// menu_set
			// 
			this->menu_set->Name = L"menu_set";
			this->menu_set->Size = System::Drawing::Size(53, 23);
			this->menu_set->Text = L"設定";
			this->menu_set->Click += gcnew System::EventHandler(this, &FMySQL::menu_set_Click);
			// 
			// btn_reload
			// 
			this->btn_reload->Location = System::Drawing::Point(635, 4);
			this->btn_reload->Name = L"btn_reload";
			this->btn_reload->Size = System::Drawing::Size(75, 23);
			this->btn_reload->TabIndex = 9;
			this->btn_reload->Text = L"重新載入";
			this->btn_reload->UseVisualStyleBackColor = true;
			this->btn_reload->Click += gcnew System::EventHandler(this, &FMySQL::btn_reload_Click);
			// 
			// FMySQL
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(726, 612);
			this->Controls->Add(this->btn_reload);
			this->Controls->Add(this->lab_errMessage);
			this->Controls->Add(this->panel_tables);
			this->Controls->Add(this->lab_dbName);
			this->Controls->Add(this->lab_DB);
			this->Controls->Add(this->btn_view);
			this->Controls->Add(this->dataGridView_tabledata);
			this->Controls->Add(this->menu);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MainMenuStrip = this->menu;
			this->MaximizeBox = false;
			this->Name = L"FMySQL";
			this->Text = L"MySQL";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_tabledata))->EndInit();
			this->panel_tables->ResumeLayout(false);
			this->panel_tables->PerformLayout();
			this->menu->ResumeLayout(false);
			this->menu->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btn_view_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void btn_reload_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void menu_set_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void list_tables_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
};
}
