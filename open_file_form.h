#pragma once
#include "DealWithENCData.h"

namespace PCSystemGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	struct files_name_struct{ vector<string> data_bases_name, reports_name; }files_name;
	/// <summary>
	/// Summary for open_file_form
	/// </summary>
	public ref class open_file_form : public System::Windows::Forms::Form
	{
	public:
		bool* working = nullptr;
		open_file_form(bool *b)
		{
			InitializeComponent();
			working = b;
			*working = true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~open_file_form()
		{
			if (components)
			{
				delete components;
			}
			*working = false;

		}
	private: System::Windows::Forms::Button^ open_file_button;
	private: System::Windows::Forms::OpenFileDialog^ open_file_dialog;
	public: System::Windows::Forms::Label^ title_label;
	private: System::Windows::Forms::RichTextBox^ selected_files;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ exit_button;
	public: System::Windows::Forms::Button^ operation_button;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(open_file_form::typeid));
			this->open_file_button = (gcnew System::Windows::Forms::Button());
			this->open_file_dialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->title_label = (gcnew System::Windows::Forms::Label());
			this->selected_files = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->operation_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// open_file_button
			// 
			this->open_file_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->open_file_button->Location = System::Drawing::Point(31, 419);
			this->open_file_button->Name = L"open_file_button";
			this->open_file_button->Size = System::Drawing::Size(110, 38);
			this->open_file_button->TabIndex = 0;
			this->open_file_button->Text = L"Open file(s)";
			this->open_file_button->UseVisualStyleBackColor = true;
			this->open_file_button->Click += gcnew System::EventHandler(this, &open_file_form::open_file_button_Click);
			// 
			// open_file_dialog
			// 
			this->open_file_dialog->Filter = L"MHM files|*.mhm|All files|*.*";
			this->open_file_dialog->Multiselect = true;
			// 
			// title_label
			// 
			this->title_label->AutoSize = true;
			this->title_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title_label->ForeColor = System::Drawing::Color::White;
			this->title_label->Location = System::Drawing::Point(0, -4);
			this->title_label->Name = L"title_label";
			this->title_label->Size = System::Drawing::Size(250, 86);
			this->title_label->TabIndex = 21;
			this->title_label->Text = L"Display";
			// 
			// selected_files
			// 
			this->selected_files->BackColor = System::Drawing::Color::Black;
			this->selected_files->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->selected_files->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->selected_files->ForeColor = System::Drawing::Color::White;
			this->selected_files->Location = System::Drawing::Point(31, 123);
			this->selected_files->Name = L"selected_files";
			this->selected_files->ReadOnly = true;
			this->selected_files->Size = System::Drawing::Size(347, 290);
			this->selected_files->TabIndex = 22;
			this->selected_files->Text = L"No files are selected.\nClick \'Open file(s)\' button to select single or multible f"
				L"iles.\n";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(12, 90);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(139, 30);
			this->label1->TabIndex = 23;
			this->label1->Text = L"Selected files:";
			// 
			// exit_button
			// 
			this->exit_button->BackColor = System::Drawing::Color::Black;
			this->exit_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exit_button->ForeColor = System::Drawing::Color::White;
			this->exit_button->Location = System::Drawing::Point(788, 12);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(48, 33);
			this->exit_button->TabIndex = 36;
			this->exit_button->Text = L"Exit";
			this->exit_button->UseVisualStyleBackColor = false;
			this->exit_button->Click += gcnew System::EventHandler(this, &open_file_form::exit_button_Click);
			// 
			// operation_button
			// 
			this->operation_button->BackColor = System::Drawing::Color::Black;
			this->operation_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"operation_button.BackgroundImage")));
			this->operation_button->Cursor = System::Windows::Forms::Cursors::No;
			this->operation_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->operation_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->operation_button->Location = System::Drawing::Point(12, 504);
			this->operation_button->Name = L"operation_button";
			this->operation_button->Size = System::Drawing::Size(113, 47);
			this->operation_button->TabIndex = 37;
			this->operation_button->Text = L"Merge";
			this->operation_button->UseVisualStyleBackColor = false;
			this->operation_button->Click += gcnew System::EventHandler(this, &open_file_form::operation_button_Click);
			// 
			// open_file_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 30);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(139)),
				static_cast<System::Int32>(static_cast<System::Byte>(132)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(848, 563);
			this->Controls->Add(this->operation_button);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->selected_files);
			this->Controls->Add(this->title_label);
			this->Controls->Add(this->open_file_button);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(7);
			this->Name = L"open_file_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"open_file_form";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &open_file_form::open_file_form_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &open_file_form::open_file_form_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &open_file_form::open_file_form_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: void add(string file_name) {
		vector<string>* vec_ptr = (file_name.find("Data_Base") != string::npos ?
			&files_name.data_bases_name : &files_name.reports_name);
		for (auto name : *vec_ptr)
			if (file_name == name)
				return;
		vec_ptr->push_back(file_name);
	}
	private: System::Void open_file_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (open_file_dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (selected_files->Text[0] != '-') {
				selected_files->Text = "";
				operation_button->Cursor = System::Windows::Forms::Cursors::Hand;
			}
			int n = open_file_dialog->FileNames->Length;
			for (size_t i = 0; i < n; i++)
				selected_files->Text += "- " + open_file_dialog->FileNames[i] + "\n\n";
		}
	}
	private: System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		open_file_dialog->Reset();
		open_file_form::~open_file_form();
	}
	bool dragging;
	Point pnt;
	private: System::Void open_file_form_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = true;
		pnt.X = e->X;
		pnt.Y = e->Y;
	}
	private: System::Void open_file_form_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (dragging) {
			Point current_pos = PointToScreen(Point(e->X, e->Y));
			Location = Point(current_pos.X - pnt.X, current_pos.Y - pnt.Y);
		}
	}
	private: System::Void open_file_form_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = false;
	}
	private: System::Void operation_button_Click(System::Object^ sender, System::EventArgs^ e) {
		int n = open_file_dialog->FileNames->Length;
		for (size_t i = 0; i < n; i++) {
			String^ tmp = open_file_dialog->FileNames[i];
			add(MyForm::convert_to_std_str(tmp));
		}
		if(operation_button->Text == "Display") {
			if (files_name.data_bases_name.size())
				DealWithENCData::retrieve_data(files_name.data_bases_name, "PCs_Data.csv");
			if (files_name.reports_name.size())
				DealWithENCData::retrieve_data(files_name.reports_name, "Reports.csv");
		}else{
			if (files_name.data_bases_name.size())
				DealWithENCData::merge_files(files_name.data_bases_name, "Merged_Data_Base.mhm");
			if (files_name.reports_name.size())
				DealWithENCData::merge_files(files_name.reports_name, "Merged_Reports.mhm");
		}
	}
};
}
