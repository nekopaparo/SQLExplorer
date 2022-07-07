#pragma once

#include "MySQLite.h"

namespace SQLExplorer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class FSQLite : public System::Windows::Forms::Form
	{
	public:

		SQL::MySQLite* mySQLite;

		FSQLite(void);
		char* StringToChar(String^ Str);
		void loadTables();
		void view(std::vector<std::vector<std::string>>* table);
		void tableDataShow();

	protected:

		~FSQLite();
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
	private: System::Windows::Forms::ToolStripMenuItem^ menu_openfile;

	private:
		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->btn_view = (gcnew System::Windows::Forms::Button());
			this->dataGridView_tabledata = (gcnew System::Windows::Forms::DataGridView());
			this->lab_DB = (gcnew System::Windows::Forms::Label());
			this->lab_dbName = (gcnew System::Windows::Forms::Label());
			this->lab_errMessage = (gcnew System::Windows::Forms::Label());
			this->panel_tables = (gcnew System::Windows::Forms::Panel());
			this->lab_tables = (gcnew System::Windows::Forms::Label());
			this->list_tables = (gcnew System::Windows::Forms::ListBox());
			this->menu = (gcnew System::Windows::Forms::MenuStrip());
			this->menu_openfile = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
			this->btn_view->Click += gcnew System::EventHandler(this, &FSQLite::btn_view_Click);
			// 
			// dataGridView_tabledata
			// 
			this->dataGridView_tabledata->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView_tabledata->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView_tabledata->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView_tabledata->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView_tabledata->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"新細明體", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView_tabledata->DefaultCellStyle = dataGridViewCellStyle2;
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
			this->lab_dbName->Location = System::Drawing::Point(80, 37);
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
			this->list_tables->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &FSQLite::list_tables_MouseDoubleClick);
			// 
			// menu
			// 
			this->menu->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menu_openfile });
			this->menu->Location = System::Drawing::Point(0, 0);
			this->menu->Name = L"menu";
			this->menu->Size = System::Drawing::Size(726, 27);
			this->menu->TabIndex = 8;
			this->menu->Text = L"menuStrip1";
			// 
			// menu_openfile
			// 
			this->menu_openfile->Name = L"menu_openfile";
			this->menu_openfile->Size = System::Drawing::Size(53, 23);
			this->menu_openfile->Text = L"開啟";
			this->menu_openfile->Click += gcnew System::EventHandler(this, &FSQLite::menu_openfile_Click);
			// 
			// FSQLite
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(726, 612);
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
			this->Name = L"FSQLite";
			this->Text = L"SQLite";
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
	private: System::Void list_tables_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: System::Void menu_openfile_Click(System::Object^ sender, System::EventArgs^ e);
};
}
