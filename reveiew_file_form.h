#pragma once
#include "WriteData.h"
namespace PCSystemGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for reveiew_file_form
	/// </summary>
	vector<int> duplications;
	public ref class reveiew_file_form : public System::Windows::Forms::Form
	{
	public:
		reveiew_file_form(string un)
		{
			username = un;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~reveiew_file_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ ofd;
	protected:


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RichTextBox^ selected_file;
	public: System::Windows::Forms::Label^ title_label;
	private:
	private: System::Windows::Forms::Button^ open_file_button;
	public:
	private: System::Windows::Forms::Button^ exit_button;
	private: System::Windows::Forms::Button^ review_button;

	private: System::Windows::Forms::TextBox^ id_input_from;

	private: System::Windows::Forms::Label^ id_label;
	private: System::Windows::Forms::TextBox^ id_input_to;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ reveiew;
	private: System::Windows::Forms::Button^ clear_duplications_button;



	protected:





	private:

	public:





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(reveiew_file_form::typeid));
			this->ofd = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->selected_file = (gcnew System::Windows::Forms::RichTextBox());
			this->title_label = (gcnew System::Windows::Forms::Label());
			this->open_file_button = (gcnew System::Windows::Forms::Button());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->review_button = (gcnew System::Windows::Forms::Button());
			this->id_input_from = (gcnew System::Windows::Forms::TextBox());
			this->id_label = (gcnew System::Windows::Forms::Label());
			this->id_input_to = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->reveiew = (gcnew System::Windows::Forms::RichTextBox());
			this->clear_duplications_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// ofd
			// 
			this->ofd->FileName = L"Select a file (.mhm)";
			this->ofd->Filter = L"MHM files|*.mhm|All files|*.*";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(13, 86);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(132, 30);
			this->label1->TabIndex = 44;
			this->label1->Text = L"Selected file:";
			// 
			// selected_file
			// 
			this->selected_file->BackColor = System::Drawing::Color::Black;
			this->selected_file->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->selected_file->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->selected_file->ForeColor = System::Drawing::Color::White;
			this->selected_file->Location = System::Drawing::Point(146, 92);
			this->selected_file->MaxLength = 1000;
			this->selected_file->Name = L"selected_file";
			this->selected_file->ReadOnly = true;
			this->selected_file->Size = System::Drawing::Size(490, 51);
			this->selected_file->TabIndex = 43;
			this->selected_file->Text = L"No file is selected. Click \'Open file\' button to select a file.";
			// 
			// title_label
			// 
			this->title_label->AutoSize = true;
			this->title_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title_label->ForeColor = System::Drawing::Color::White;
			this->title_label->Location = System::Drawing::Point(-5, -6);
			this->title_label->Name = L"title_label";
			this->title_label->Size = System::Drawing::Size(348, 86);
			this->title_label->TabIndex = 42;
			this->title_label->Text = L"Review file";
			// 
			// open_file_button
			// 
			this->open_file_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->open_file_button->Location = System::Drawing::Point(642, 98);
			this->open_file_button->Name = L"open_file_button";
			this->open_file_button->Size = System::Drawing::Size(110, 38);
			this->open_file_button->TabIndex = 41;
			this->open_file_button->Text = L"Open file";
			this->open_file_button->UseVisualStyleBackColor = true;
			this->open_file_button->Click += gcnew System::EventHandler(this, &reveiew_file_form::open_file_button_Click);
			this->open_file_button->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &reveiew_file_form::open_file_button_KeyDown);
			// 
			// exit_button
			// 
			this->exit_button->BackColor = System::Drawing::Color::Black;
			this->exit_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exit_button->ForeColor = System::Drawing::Color::White;
			this->exit_button->Location = System::Drawing::Point(820, 12);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(48, 33);
			this->exit_button->TabIndex = 49;
			this->exit_button->Text = L"Exit";
			this->exit_button->UseVisualStyleBackColor = false;
			this->exit_button->Click += gcnew System::EventHandler(this, &reveiew_file_form::exit_button_Click);
			// 
			// review_button
			// 
			this->review_button->BackColor = System::Drawing::Color::Black;
			this->review_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"review_button.BackgroundImage")));
			this->review_button->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->review_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->review_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->review_button->Location = System::Drawing::Point(17, 488);
			this->review_button->Name = L"review_button";
			this->review_button->Size = System::Drawing::Size(113, 47);
			this->review_button->TabIndex = 48;
			this->review_button->Text = L"Review";
			this->review_button->UseVisualStyleBackColor = false;
			this->review_button->Click += gcnew System::EventHandler(this, &reveiew_file_form::edit_button_Click);
			// 
			// id_input_from
			// 
			this->id_input_from->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(187)));
			this->id_input_from->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->id_input_from->Location = System::Drawing::Point(146, 430);
			this->id_input_from->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->id_input_from->MaxLength = 6;
			this->id_input_from->Name = L"id_input_from";
			this->id_input_from->Size = System::Drawing::Size(96, 33);
			this->id_input_from->TabIndex = 46;
			this->id_input_from->Text = L"210";
			this->id_input_from->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &reveiew_file_form::id_input_from_KeyDown);
			// 
			// id_label
			// 
			this->id_label->AutoSize = true;
			this->id_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->id_label->ForeColor = System::Drawing::Color::White;
			this->id_label->Location = System::Drawing::Point(25, 429);
			this->id_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->id_label->Name = L"id_label";
			this->id_label->Size = System::Drawing::Size(120, 30);
			this->id_label->TabIndex = 45;
			this->id_label->Text = L"PC-ID from";
			// 
			// id_input_to
			// 
			this->id_input_to->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(187)));
			this->id_input_to->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->id_input_to->Location = System::Drawing::Point(283, 430);
			this->id_input_to->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->id_input_to->MaxLength = 6;
			this->id_input_to->Name = L"id_input_to";
			this->id_input_to->Size = System::Drawing::Size(96, 33);
			this->id_input_to->TabIndex = 50;
			this->id_input_to->Text = L"210";
			this->id_input_to->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &reveiew_file_form::id_input_to_KeyDown);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(246, 429);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 30);
			this->label2->TabIndex = 51;
			this->label2->Text = L"to";
			// 
			// reveiew
			// 
			this->reveiew->BackColor = System::Drawing::Color::Black;
			this->reveiew->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->reveiew->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reveiew->ForeColor = System::Drawing::Color::White;
			this->reveiew->Location = System::Drawing::Point(17, 163);
			this->reveiew->MaxLength = 2000000000;
			this->reveiew->Name = L"reveiew";
			this->reveiew->ReadOnly = true;
			this->reveiew->Size = System::Drawing::Size(377, 259);
			this->reveiew->TabIndex = 52;
			this->reveiew->Text = L"Reveiew:\n";
			// 
			// clear_duplications_button
			// 
			this->clear_duplications_button->BackColor = System::Drawing::Color::Black;
			this->clear_duplications_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"clear_duplications_button.BackgroundImage")));
			this->clear_duplications_button->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->clear_duplications_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->clear_duplications_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->clear_duplications_button->Location = System::Drawing::Point(153, 488);
			this->clear_duplications_button->Name = L"clear_duplications_button";
			this->clear_duplications_button->Size = System::Drawing::Size(177, 47);
			this->clear_duplications_button->TabIndex = 53;
			this->clear_duplications_button->Text = L"Clear Duplications";
			this->clear_duplications_button->UseVisualStyleBackColor = false;
			this->clear_duplications_button->Visible = false;
			this->clear_duplications_button->Click += gcnew System::EventHandler(this, &reveiew_file_form::clear_duplications_button_Click);
			// 
			// reveiew_file_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(139)),
				static_cast<System::Int32>(static_cast<System::Byte>(132)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(880, 547);
			this->Controls->Add(this->clear_duplications_button);
			this->Controls->Add(this->reveiew);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->id_input_to);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->selected_file);
			this->Controls->Add(this->title_label);
			this->Controls->Add(this->open_file_button);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->review_button);
			this->Controls->Add(this->id_input_from);
			this->Controls->Add(this->id_label);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"reveiew_file_form";
			this->Text = L"Review file";
			this->Load += gcnew System::EventHandler(this, &reveiew_file_form::reveiew_file_form_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &reveiew_file_form::reveiew_file_form_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &reveiew_file_form::reveiew_file_form_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &reveiew_file_form::reveiew_file_form_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void reveiew_file_form_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void open_file_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			selected_file->Text = ofd->FileName;
	}
	private: System::Void edit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if(selected_file->Text == "No file is selected. Click 'Open file' button to select a file.")
			MessageBox::Show("Select a file first!", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else if (id_input_from->Text->Length != 6 || id_input_to->Text->Length != 6)
			MessageBox::Show("Invalid ID!", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else {
			bool error_occured = true;
			pair<vector<pair<int, int>>, vector<int>> reveiew_data 
				= DealWithENCData::reveiew_file(error_occured, (username == users[0].name || username == users[1].name ? "Admin" : username)
				, MyForm::convert_to_std_str(ofd->FileName), WriteData::get_time().substr(0, 10)
				, MyForm::convert_to_std_str(id_input_from->Text), MyForm::convert_to_std_str(id_input_to->Text));
			if (!error_occured) {
				if (reveiew->Text != "Reveiew:\n")
					reveiew->Text = "Reveiew:\n";
				reveiew->Text += "Duplicated PCs (";
				reveiew->Text += reveiew_data.first.size();
				reveiew->Text += "):\n";
				for (auto duplicated : reveiew_data.first){
					reveiew->Text += "\tPC-";
					reveiew->Text += duplicated.first;
					reveiew->Text += ", ";
					reveiew->Text += duplicated.second;
					reveiew->Text += " times.\n";
				}
				reveiew->Text += "\nMissing PCs (";
				reveiew->Text += reveiew_data.second.size();
				reveiew->Text += "):\n";
				for (auto missing : reveiew_data.second) {
					reveiew->Text += "\tPC-";
					reveiew->Text += missing;
					reveiew->Text += "\n";
				}
				if (reveiew_data.first.size() > 0) {
					clear_duplications_button->Visible = true;
					for(auto &x : reveiew_data.first)
						duplications.push_back(x.first);
				}
			}
		}
	}
	private: System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		ofd->Reset();
		reveiew_file_form::~reveiew_file_form();
	}
	private: System::Void clear_duplications_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (DealWithENCData::clear_duplicatios(duplications, MyForm::convert_to_std_str(ofd->FileName)))
			MessageBox::Show("Duplications cleared successfully!", "SUCCESS!", MessageBoxButtons::OK, MessageBoxIcon::Information);
		else
			MessageBox::Show("Error occured while clearing Duplications!", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	private: System::Void open_file_button_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			id_input_from->Focus();
	}
	private: System::Void id_input_from_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			id_input_to->Focus();
	}
	private: System::Void id_input_to_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			review_button->Focus();
	}
	bool dragging;
	Point pnt;
	private: System::Void reveiew_file_form_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = true;
		pnt.X = e->X;
		pnt.Y = e->Y;
	}
	private: System::Void reveiew_file_form_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = false;
	}
	private: System::Void reveiew_file_form_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (dragging) {
			Point current_pos = PointToScreen(Point(e->X, e->Y));
			Location = Point(current_pos.X - pnt.X, current_pos.Y - pnt.Y);
		}
	}
};
}
