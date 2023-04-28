#pragma once

namespace PCSystemGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for edit_file_form
	/// </summary>
	string edit_username;
	public ref class edit_file_form : public System::Windows::Forms::Form
	{
	public:
		edit_file_form(string eun)
		{
			InitializeComponent();
			edit_username = eun;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~edit_file_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ ofd;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::RichTextBox^ selected_file;

	public: System::Windows::Forms::Label^ title_label;
	private:
	private: System::Windows::Forms::Button^ open_file_button;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::TextBox^ id_input;
	private: System::Windows::Forms::Label^ id_label;
	private: System::Windows::Forms::Button^ edit_button;

	private: System::Windows::Forms::Button^ exit_button;
	public:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(edit_file_form::typeid));
			this->ofd = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->selected_file = (gcnew System::Windows::Forms::RichTextBox());
			this->title_label = (gcnew System::Windows::Forms::Label());
			this->open_file_button = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->id_input = (gcnew System::Windows::Forms::TextBox());
			this->id_label = (gcnew System::Windows::Forms::Label());
			this->edit_button = (gcnew System::Windows::Forms::Button());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// ofd
			// 
			this->ofd->FileName = L"Select file_name.mhm";
			this->ofd->Filter = L"MHM files|*.mhm|All files|*.*";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(7, 89);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 30);
			this->label1->TabIndex = 27;
			this->label1->Text = L"Selected file:";
			// 
			// selected_file
			// 
			this->selected_file->BackColor = System::Drawing::Color::Black;
			this->selected_file->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->selected_file->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->selected_file->ForeColor = System::Drawing::Color::White;
			this->selected_file->Location = System::Drawing::Point(23, 122);
			this->selected_file->MaxLength = 1000;
			this->selected_file->Name = L"selected_file";
			this->selected_file->ReadOnly = true;
			this->selected_file->Size = System::Drawing::Size(265, 178);
			this->selected_file->TabIndex = 26;
			this->selected_file->Text = L"No file is selected. Click \'Open file\' button to select a file.";
			// 
			// title_label
			// 
			this->title_label->AutoSize = true;
			this->title_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title_label->ForeColor = System::Drawing::Color::White;
			this->title_label->Location = System::Drawing::Point(8, -2);
			this->title_label->Name = L"title_label";
			this->title_label->Size = System::Drawing::Size(149, 86);
			this->title_label->TabIndex = 25;
			this->title_label->Text = L"Edit";
			// 
			// open_file_button
			// 
			this->open_file_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->open_file_button->Location = System::Drawing::Point(23, 306);
			this->open_file_button->Name = L"open_file_button";
			this->open_file_button->Size = System::Drawing::Size(110, 38);
			this->open_file_button->TabIndex = 24;
			this->open_file_button->Text = L"Open file";
			this->open_file_button->UseVisualStyleBackColor = true;
			this->open_file_button->Click += gcnew System::EventHandler(this, &edit_file_form::open_file_button_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Gray;
			this->panel1->Controls->Add(this->panel8);
			this->panel1->Location = System::Drawing::Point(12, 403);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(161, 1);
			this->panel1->TabIndex = 38;
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::Gray;
			this->panel8->Location = System::Drawing::Point(0, 1);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(314, 1);
			this->panel8->TabIndex = 21;
			// 
			// id_input
			// 
			this->id_input->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(187)));
			this->id_input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->id_input->Location = System::Drawing::Point(78, 371);
			this->id_input->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->id_input->MaxLength = 6;
			this->id_input->Name = L"id_input";
			this->id_input->Size = System::Drawing::Size(96, 33);
			this->id_input->TabIndex = 36;
			this->id_input->Text = L"210";
			this->id_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &edit_file_form::id_input_KeyDown);
			// 
			// id_label
			// 
			this->id_label->AutoSize = true;
			this->id_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->id_label->ForeColor = System::Drawing::Color::White;
			this->id_label->Location = System::Drawing::Point(7, 375);
			this->id_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->id_label->Name = L"id_label";
			this->id_label->Size = System::Drawing::Size(67, 30);
			this->id_label->TabIndex = 35;
			this->id_label->Text = L"PC-ID";
			// 
			// edit_button
			// 
			this->edit_button->BackColor = System::Drawing::Color::Black;
			this->edit_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"edit_button.BackgroundImage")));
			this->edit_button->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->edit_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->edit_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->edit_button->Location = System::Drawing::Point(12, 441);
			this->edit_button->Name = L"edit_button";
			this->edit_button->Size = System::Drawing::Size(113, 47);
			this->edit_button->TabIndex = 39;
			this->edit_button->Text = L"Edit";
			this->edit_button->UseVisualStyleBackColor = false;
			this->edit_button->Click += gcnew System::EventHandler(this, &edit_file_form::edit_button_Click);
			// 
			// exit_button
			// 
			this->exit_button->BackColor = System::Drawing::Color::Black;
			this->exit_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exit_button->ForeColor = System::Drawing::Color::White;
			this->exit_button->Location = System::Drawing::Point(628, 12);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(48, 33);
			this->exit_button->TabIndex = 40;
			this->exit_button->Text = L"Exit";
			this->exit_button->UseVisualStyleBackColor = false;
			this->exit_button->Click += gcnew System::EventHandler(this, &edit_file_form::exit_button_Click);
			// 
			// edit_file_form
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 21);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(139)),
				static_cast<System::Int32>(static_cast<System::Byte>(132)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(688, 500);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->edit_button);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->id_input);
			this->Controls->Add(this->id_label);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->selected_file);
			this->Controls->Add(this->title_label);
			this->Controls->Add(this->open_file_button);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"edit_file_form";
			this->Text = L"Edit file";
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &edit_file_form::edit_file_form_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &edit_file_form::edit_file_form_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &edit_file_form::edit_file_form_MouseUp);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void open_file_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			string tmp = MyForm::convert_to_std_str(ofd->FileName);
			if (tmp.find("Reports") != string::npos || tmp.find("Data_Base") != string::npos){
				selected_file->Text = ofd->FileName;
				id_label->Show();
				panel1->Show();
				id_input->Show();
				edit_button->Show();
			}
			else
				MessageBox::Show("You selected invalid file! Try again with a correct (.MHM) file.", "Invalid_file", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		ofd->Reset();
		edit_file_form::~edit_file_form();
	}
	private: System::Void edit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (assign_new_pc::is_valid_id(id_input->Text)) {
			pair<vector<string>, int> data = DealWithENCData::file_include_id(MyForm::convert_to_std_str(ofd->FileName),
				MyForm::convert_to_std_str(id_input->Text));
			if (data.second == -1)
				MessageBox::Show("The PC-ID you entered doesn't exist in the selected file!", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			else {
				string tmp = MyForm::convert_to_std_str(ofd->FileName);
				if (tmp.find("Data_Base") != string::npos)
					assign_new_pc^ anp = gcnew assign_new_pc(edit_username, MyForm::convert_to_std_str(ofd->FileName),
						data.first, data.second);
				else if (tmp.find("Reports") != string::npos)
					create_report^ cr = gcnew create_report(edit_username, MyForm::convert_to_std_str(ofd->FileName),
						data.first, data.second);
			}
		}
		else
			MessageBox::Show("Enter a valid ID!", "Invalid ID!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	bool dragging;
	Point pnt;
	private: System::Void edit_file_form_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = true;
		pnt.X = e->X;
		pnt.Y = e->Y;
	}
	private: System::Void edit_file_form_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (dragging) {
			Point current_pos = PointToScreen(Point(e->X, e->Y));
			Location = Point(current_pos.X - pnt.X, current_pos.Y - pnt.Y);
		}
	}
	private: System::Void edit_file_form_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = false;
	}
	private: System::Void id_input_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			edit_button->Focus();
	}
};
}
