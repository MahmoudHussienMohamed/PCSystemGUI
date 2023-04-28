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
	/// Summary for assign_new_pc
	/// </summary>
	/// For normal assign:
	string username;

	// For editting:
	string file_name;
	string editor_username;
	vector<string> file_data;
	vector<size_t> comma_pos;
	int edited_line_number;
	bool assign_edit_mode = false;
	public ref class assign_new_pc : public System::Windows::Forms::Form
	{
	public:
		bool* working = nullptr;
		assign_new_pc(string usrnm, bool *b)
		{
			InitializeComponent();
			username = usrnm;
			working = b;
			*working = true;
		}
		assign_new_pc(string eun, string fn, vector<string> fd, int eln)
		{
			editor_username = eun;
			file_name = fn;
			file_data = fd;
			edited_line_number = eln;
			assign_edit_mode = true;
			InitializeComponent();
			fill_cells(file_data[edited_line_number]);
		}
	private: vector<size_t> get_commas_pos(string& data) {
		vector<size_t> comm_pos;
		for (size_t i = 0; i < data.length(); i++)
			if (data[i] == ',')
				comm_pos.push_back(i);
		return comm_pos;
	}
	private: void fill(TextBox^ txt_box, string buffer, size_t &idx) {
		txt_box->Text = gcnew String(buffer.c_str());
		idx++;
	}
	private: void fill_cells(string& data_before_edit) {
		comma_pos = get_commas_pos(data_before_edit);
		size_t curr_idx = 0;
		fill(id_input, data_before_edit.substr(0, comma_pos[curr_idx]), curr_idx);
		curr_idx += 2;
		fill(processor_input, data_before_edit.substr(comma_pos[curr_idx - 1] + 1, comma_pos[curr_idx] - comma_pos[curr_idx - 1] - 1), curr_idx);
		fill(ram_input, data_before_edit.substr(comma_pos[curr_idx - 1] + 1, comma_pos[curr_idx] - comma_pos[curr_idx - 1] - 1), curr_idx);
		fill(hard_disk_input, data_before_edit.substr(comma_pos[curr_idx - 1] + 1, comma_pos[curr_idx] - comma_pos[curr_idx - 1] - 1), curr_idx);
		fill(motherboard_input, data_before_edit.substr(comma_pos[curr_idx - 1] + 1, comma_pos[curr_idx] - comma_pos[curr_idx - 1] - 1), curr_idx);
		fill(monitor_input, data_before_edit.substr(comma_pos[curr_idx - 1] + 1, comma_pos[curr_idx] - comma_pos[curr_idx - 1] - 1), curr_idx);
		if (data_before_edit[comma_pos[curr_idx] + 1] != '-') {
			printer_check_box->Checked = true;
			fill(printer_brand_input, data_before_edit.substr(comma_pos[curr_idx - 1] + 1, comma_pos[curr_idx] - comma_pos[curr_idx - 1] - 1), curr_idx);
			fill(printer_model_input, data_before_edit.substr(comma_pos[curr_idx - 1] + 1), curr_idx);
		}
		assign_button->Text = "Edit";
		title_label->Text = "Edit " + title_label->Text;
		this->Text = "Edit PC Specs";
		this->Show();
	}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// 
		~assign_new_pc()
		{
			if (components)
			{
				delete components;
			}
			if(working)
				*working = false;
			assign_edit_mode = false;
		}
	private: System::Windows::Forms::Label^ processor_label;
	protected:

	private: System::Windows::Forms::TextBox^ processor_input;

	private: System::Windows::Forms::TextBox^ ram_input;
	protected:

	protected:


	private: System::Windows::Forms::Label^ ram_label;
	private: System::Windows::Forms::TextBox^ hard_disk_input;


	private: System::Windows::Forms::Label^ hard_disk_label;
	private: System::Windows::Forms::TextBox^ motherboard_input;


	private: System::Windows::Forms::Label^ motherboard_label;
	private: System::Windows::Forms::TextBox^ monitor_input;


	private: System::Windows::Forms::Label^ monitor_label;
	private: System::Windows::Forms::TextBox^ id_input;
	private: System::Windows::Forms::Label^ id_label;
	private: System::Windows::Forms::Button^ assign_button;
	private: System::Windows::Forms::CheckBox^ printer_check_box;
	private: System::Windows::Forms::Label^ printer_brand_label;
	private: System::Windows::Forms::TextBox^ printer_brand_input;
	private: System::Windows::Forms::TextBox^ printer_model_input;
	private: System::Windows::Forms::Label^ printer_model_label;
	private: System::Windows::Forms::CheckBox^ confirmation_check_box;
	private: System::Windows::Forms::Label^ title_label;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ reset_button;
	private: System::Windows::Forms::Button^ increment_button;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(assign_new_pc::typeid));
			this->processor_label = (gcnew System::Windows::Forms::Label());
			this->processor_input = (gcnew System::Windows::Forms::TextBox());
			this->ram_input = (gcnew System::Windows::Forms::TextBox());
			this->ram_label = (gcnew System::Windows::Forms::Label());
			this->hard_disk_input = (gcnew System::Windows::Forms::TextBox());
			this->hard_disk_label = (gcnew System::Windows::Forms::Label());
			this->motherboard_input = (gcnew System::Windows::Forms::TextBox());
			this->motherboard_label = (gcnew System::Windows::Forms::Label());
			this->monitor_input = (gcnew System::Windows::Forms::TextBox());
			this->monitor_label = (gcnew System::Windows::Forms::Label());
			this->id_input = (gcnew System::Windows::Forms::TextBox());
			this->id_label = (gcnew System::Windows::Forms::Label());
			this->assign_button = (gcnew System::Windows::Forms::Button());
			this->printer_check_box = (gcnew System::Windows::Forms::CheckBox());
			this->printer_brand_label = (gcnew System::Windows::Forms::Label());
			this->printer_brand_input = (gcnew System::Windows::Forms::TextBox());
			this->printer_model_input = (gcnew System::Windows::Forms::TextBox());
			this->printer_model_label = (gcnew System::Windows::Forms::Label());
			this->confirmation_check_box = (gcnew System::Windows::Forms::CheckBox());
			this->title_label = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->reset_button = (gcnew System::Windows::Forms::Button());
			this->increment_button = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// processor_label
			// 
			this->processor_label->AutoSize = true;
			this->processor_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->processor_label->ForeColor = System::Drawing::Color::White;
			this->processor_label->Location = System::Drawing::Point(25, 156);
			this->processor_label->Name = L"processor_label";
			this->processor_label->Size = System::Drawing::Size(115, 32);
			this->processor_label->TabIndex = 2;
			this->processor_label->Text = L"Processor";
			// 
			// processor_input
			// 
			this->processor_input->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(187)));
			this->processor_input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->processor_input->Location = System::Drawing::Point(185, 155);
			this->processor_input->Name = L"processor_input";
			this->processor_input->Size = System::Drawing::Size(160, 33);
			this->processor_input->TabIndex = 3;
			this->processor_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &assign_new_pc::processor_input_KeyDown);
			// 
			// ram_input
			// 
			this->ram_input->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(187)));
			this->ram_input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ram_input->Location = System::Drawing::Point(185, 192);
			this->ram_input->Name = L"ram_input";
			this->ram_input->Size = System::Drawing::Size(160, 33);
			this->ram_input->TabIndex = 4;
			this->ram_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &assign_new_pc::ram_input_KeyDown);
			// 
			// ram_label
			// 
			this->ram_label->AutoSize = true;
			this->ram_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ram_label->ForeColor = System::Drawing::Color::White;
			this->ram_label->Location = System::Drawing::Point(25, 193);
			this->ram_label->Name = L"ram_label";
			this->ram_label->Size = System::Drawing::Size(65, 32);
			this->ram_label->TabIndex = 5;
			this->ram_label->Text = L"RAM";
			// 
			// hard_disk_input
			// 
			this->hard_disk_input->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(187)));
			this->hard_disk_input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hard_disk_input->Location = System::Drawing::Point(185, 229);
			this->hard_disk_input->Name = L"hard_disk_input";
			this->hard_disk_input->Size = System::Drawing::Size(160, 33);
			this->hard_disk_input->TabIndex = 6;
			this->hard_disk_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &assign_new_pc::hard_disk_input_KeyDown);
			// 
			// hard_disk_label
			// 
			this->hard_disk_label->AutoSize = true;
			this->hard_disk_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hard_disk_label->ForeColor = System::Drawing::Color::White;
			this->hard_disk_label->Location = System::Drawing::Point(25, 230);
			this->hard_disk_label->Name = L"hard_disk_label";
			this->hard_disk_label->Size = System::Drawing::Size(116, 32);
			this->hard_disk_label->TabIndex = 7;
			this->hard_disk_label->Text = L"Hard Disk";
			// 
			// motherboard_input
			// 
			this->motherboard_input->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
			this->motherboard_input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->motherboard_input->Location = System::Drawing::Point(185, 266);
			this->motherboard_input->Name = L"motherboard_input";
			this->motherboard_input->Size = System::Drawing::Size(160, 33);
			this->motherboard_input->TabIndex = 8;
			this->motherboard_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &assign_new_pc::motherboard_input_KeyDown);
			// 
			// motherboard_label
			// 
			this->motherboard_label->AutoSize = true;
			this->motherboard_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->motherboard_label->ForeColor = System::Drawing::Color::White;
			this->motherboard_label->Location = System::Drawing::Point(23, 267);
			this->motherboard_label->Name = L"motherboard_label";
			this->motherboard_label->Size = System::Drawing::Size(153, 32);
			this->motherboard_label->TabIndex = 9;
			this->motherboard_label->Text = L"Motherboard";
			// 
			// monitor_input
			// 
			this->monitor_input->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(187)));
			this->monitor_input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->monitor_input->Location = System::Drawing::Point(185, 303);
			this->monitor_input->Name = L"monitor_input";
			this->monitor_input->Size = System::Drawing::Size(160, 33);
			this->monitor_input->TabIndex = 10;
			// 
			// monitor_label
			// 
			this->monitor_label->AutoSize = true;
			this->monitor_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->monitor_label->ForeColor = System::Drawing::Color::White;
			this->monitor_label->Location = System::Drawing::Point(25, 304);
			this->monitor_label->Name = L"monitor_label";
			this->monitor_label->Size = System::Drawing::Size(98, 32);
			this->monitor_label->TabIndex = 11;
			this->monitor_label->Text = L"Monitor";
			// 
			// id_input
			// 
			this->id_input->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(187)));
			this->id_input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->id_input->Location = System::Drawing::Point(185, 118);
			this->id_input->MaxLength = 6;
			this->id_input->Name = L"id_input";
			this->id_input->Size = System::Drawing::Size(160, 33);
			this->id_input->TabIndex = 1;
			this->id_input->Text = L"210";
			this->id_input->TextChanged += gcnew System::EventHandler(this, &assign_new_pc::id_input_TextChanged);
			this->id_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &assign_new_pc::id_input_KeyDown);
			// 
			// id_label
			// 
			this->id_label->AutoSize = true;
			this->id_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->id_label->ForeColor = System::Drawing::Color::White;
			this->id_label->Location = System::Drawing::Point(25, 119);
			this->id_label->Name = L"id_label";
			this->id_label->Size = System::Drawing::Size(76, 32);
			this->id_label->TabIndex = 0;
			this->id_label->Text = L"PC-ID";
			// 
			// assign_button
			// 
			this->assign_button->BackColor = System::Drawing::Color::Black;
			this->assign_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"assign_button.BackgroundImage")));
			this->assign_button->Cursor = System::Windows::Forms::Cursors::No;
			this->assign_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->assign_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->assign_button->Location = System::Drawing::Point(27, 480);
			this->assign_button->Name = L"assign_button";
			this->assign_button->Size = System::Drawing::Size(113, 47);
			this->assign_button->TabIndex = 12;
			this->assign_button->Text = L"Assign";
			this->assign_button->UseVisualStyleBackColor = false;
			this->assign_button->Click += gcnew System::EventHandler(this, &assign_new_pc::assign_button_Click);
			// 
			// printer_check_box
			// 
			this->printer_check_box->AutoSize = true;
			this->printer_check_box->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->printer_check_box->ForeColor = System::Drawing::Color::White;
			this->printer_check_box->Location = System::Drawing::Point(31, 354);
			this->printer_check_box->Name = L"printer_check_box";
			this->printer_check_box->Size = System::Drawing::Size(157, 21);
			this->printer_check_box->TabIndex = 13;
			this->printer_check_box->Text = L"Click if PC has printer.";
			this->printer_check_box->UseVisualStyleBackColor = true;
			this->printer_check_box->CheckedChanged += gcnew System::EventHandler(this, &assign_new_pc::printer_check_box_CheckedChanged);
			// 
			// printer_brand_label
			// 
			this->printer_brand_label->AutoSize = true;
			this->printer_brand_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->printer_brand_label->ForeColor = System::Drawing::Color::White;
			this->printer_brand_label->Location = System::Drawing::Point(97, 378);
			this->printer_brand_label->Name = L"printer_brand_label";
			this->printer_brand_label->Size = System::Drawing::Size(150, 32);
			this->printer_brand_label->TabIndex = 14;
			this->printer_brand_label->Text = L"Printer brand";
			this->printer_brand_label->Visible = false;
			// 
			// printer_brand_input
			// 
			this->printer_brand_input->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
			this->printer_brand_input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->printer_brand_input->Location = System::Drawing::Point(257, 377);
			this->printer_brand_input->Name = L"printer_brand_input";
			this->printer_brand_input->Size = System::Drawing::Size(139, 33);
			this->printer_brand_input->TabIndex = 15;
			this->printer_brand_input->Visible = false;
			this->printer_brand_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &assign_new_pc::printer_brand_input_KeyDown);
			// 
			// printer_model_input
			// 
			this->printer_model_input->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
			this->printer_model_input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->printer_model_input->Location = System::Drawing::Point(257, 412);
			this->printer_model_input->Name = L"printer_model_input";
			this->printer_model_input->Size = System::Drawing::Size(139, 33);
			this->printer_model_input->TabIndex = 17;
			this->printer_model_input->Visible = false;
			// 
			// printer_model_label
			// 
			this->printer_model_label->AutoSize = true;
			this->printer_model_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->printer_model_label->ForeColor = System::Drawing::Color::White;
			this->printer_model_label->Location = System::Drawing::Point(97, 413);
			this->printer_model_label->Name = L"printer_model_label";
			this->printer_model_label->Size = System::Drawing::Size(154, 32);
			this->printer_model_label->TabIndex = 16;
			this->printer_model_label->Text = L"Printer model";
			this->printer_model_label->Visible = false;
			// 
			// confirmation_check_box
			// 
			this->confirmation_check_box->AutoSize = true;
			this->confirmation_check_box->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->confirmation_check_box->ForeColor = System::Drawing::Color::White;
			this->confirmation_check_box->Location = System::Drawing::Point(163, 496);
			this->confirmation_check_box->Name = L"confirmation_check_box";
			this->confirmation_check_box->Size = System::Drawing::Size(217, 21);
			this->confirmation_check_box->TabIndex = 18;
			this->confirmation_check_box->Text = L"Confirm that all data is Correct!";
			this->confirmation_check_box->UseVisualStyleBackColor = true;
			this->confirmation_check_box->CheckedChanged += gcnew System::EventHandler(this, &assign_new_pc::confirmation_check_box_CheckedChanged);
			// 
			// title_label
			// 
			this->title_label->AutoSize = true;
			this->title_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title_label->ForeColor = System::Drawing::Color::White;
			this->title_label->Location = System::Drawing::Point(3, 5);
			this->title_label->Name = L"title_label";
			this->title_label->Size = System::Drawing::Size(298, 86);
			this->title_label->TabIndex = 19;
			this->title_label->Text = L"PC Specs";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Gray;
			this->panel1->Controls->Add(this->panel8);
			this->panel1->Location = System::Drawing::Point(31, 150);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(314, 1);
			this->panel1->TabIndex = 20;
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::Gray;
			this->panel8->Location = System::Drawing::Point(0, 0);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(314, 1);
			this->panel8->TabIndex = 21;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Gray;
			this->panel2->Location = System::Drawing::Point(29, 187);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(314, 1);
			this->panel2->TabIndex = 21;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Gray;
			this->panel3->Location = System::Drawing::Point(31, 224);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(314, 1);
			this->panel3->TabIndex = 22;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::Gray;
			this->panel4->Location = System::Drawing::Point(31, 261);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(314, 1);
			this->panel4->TabIndex = 23;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::Gray;
			this->panel5->Location = System::Drawing::Point(31, 298);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(314, 1);
			this->panel5->TabIndex = 24;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::Gray;
			this->panel6->Location = System::Drawing::Point(104, 409);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(292, 1);
			this->panel6->TabIndex = 25;
			this->panel6->Visible = false;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::Gray;
			this->panel7->Location = System::Drawing::Point(103, 444);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(292, 1);
			this->panel7->TabIndex = 26;
			this->panel7->Visible = false;
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::Gray;
			this->panel9->Location = System::Drawing::Point(31, 335);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(314, 1);
			this->panel9->TabIndex = 27;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Black;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(808, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(48, 33);
			this->button1->TabIndex = 28;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &assign_new_pc::button1_Click);
			// 
			// reset_button
			// 
			this->reset_button->BackColor = System::Drawing::Color::White;
			this->reset_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->reset_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reset_button->ForeColor = System::Drawing::Color::Black;
			this->reset_button->Location = System::Drawing::Point(680, 12);
			this->reset_button->Name = L"reset_button";
			this->reset_button->Size = System::Drawing::Size(122, 33);
			this->reset_button->TabIndex = 29;
			this->reset_button->Text = L"Reset all cells";
			this->reset_button->UseVisualStyleBackColor = false;
			this->reset_button->Click += gcnew System::EventHandler(this, &assign_new_pc::reset_button_Click);
			// 
			// increment_button
			// 
			this->increment_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
			this->increment_button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->increment_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->increment_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->increment_button->Location = System::Drawing::Point(312, 119);
			this->increment_button->Name = L"increment_button";
			this->increment_button->Size = System::Drawing::Size(33, 31);
			this->increment_button->TabIndex = 30;
			this->increment_button->Text = L"+";
			this->increment_button->UseVisualStyleBackColor = false;
			this->increment_button->Click += gcnew System::EventHandler(this, &assign_new_pc::increment_button_Click);
			// 
			// assign_new_pc
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 21);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(139)),
				static_cast<System::Int32>(static_cast<System::Byte>(132)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(868, 550);
			this->Controls->Add(this->increment_button);
			this->Controls->Add(this->reset_button);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel9);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->title_label);
			this->Controls->Add(this->confirmation_check_box);
			this->Controls->Add(this->printer_model_input);
			this->Controls->Add(this->printer_model_label);
			this->Controls->Add(this->printer_brand_input);
			this->Controls->Add(this->printer_brand_label);
			this->Controls->Add(this->printer_check_box);
			this->Controls->Add(this->assign_button);
			this->Controls->Add(this->id_input);
			this->Controls->Add(this->id_label);
			this->Controls->Add(this->monitor_input);
			this->Controls->Add(this->monitor_label);
			this->Controls->Add(this->motherboard_input);
			this->Controls->Add(this->motherboard_label);
			this->Controls->Add(this->hard_disk_input);
			this->Controls->Add(this->hard_disk_label);
			this->Controls->Add(this->ram_input);
			this->Controls->Add(this->ram_label);
			this->Controls->Add(this->processor_input);
			this->Controls->Add(this->processor_label);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"assign_new_pc";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Assign New PC";
			this->Load += gcnew System::EventHandler(this, &assign_new_pc::assign_new_pc_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &assign_new_pc::assign_new_pc_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &assign_new_pc::assign_new_pc_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &assign_new_pc::assign_new_pc_MouseUp);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void assign_new_pc_Load(System::Object^ sender, System::EventArgs^ e) {	}
		private: System::Void id_input_TextChanged(System::Object^ sender, System::EventArgs^ e) {

		}
	private: System::Void confirmation_check_box_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (confirmation_check_box->Checked)
			assign_button->Cursor = System::Windows::Forms::Cursors::Hand;
		else
			assign_button->Cursor = System::Windows::Forms::Cursors::No;
	}
	private: System::Void printer_check_box_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (printer_check_box->Checked) {
			printer_brand_label->Show();
			printer_brand_input->Show();
			printer_model_label->Show();
			printer_model_input->Show();
			panel6->Show();
			panel7->Show();
			printer_brand_input->Focus();
		}else {
			printer_brand_label->Hide();
			printer_brand_input->Hide();
			printer_model_label->Hide();
			printer_model_input->Hide();
			panel6->Hide();
			panel7->Hide();
		}
	}
	private: System::Void assign_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (confirmation_check_box->Checked && is_valid_id(id_input->Text)
			&& processor_input->Text->Length != 0 && ram_input->Text->Length != 0
			&& hard_disk_input->Text->Length != 0 && monitor_input->Text->Length != 0) {
			string printer_specs = (printer_check_box->Checked && printer_brand_input->Text->Length != 0 && printer_model_input->Text->Length != 0 ?
				MyForm::clear_commas(MyForm::convert_to_std_str(printer_brand_input->Text))
				+ "," + MyForm::clear_commas(MyForm::convert_to_std_str(printer_model_input->Text)) : "-,-");
			if (assign_edit_mode) {
				string& tmp = file_data[edited_line_number];
				tmp = MyForm::clear_commas(MyForm::convert_to_std_str(id_input->Text)) 
					+ tmp.substr(comma_pos[0], comma_pos[1] - comma_pos[0] - 1)
					+ " - EDITED AT : " + WriteData::get_time() 
					+ tmp.substr(comma_pos[1], comma_pos[2] - comma_pos[1]) 
					+ " - EDITED BY : " + editor_username + ","
					+ MyForm::clear_commas(MyForm::convert_to_std_str(processor_input->Text))
					+ "," + MyForm::clear_commas(MyForm::convert_to_std_str(ram_input->Text))
					+ "," + MyForm::clear_commas(MyForm::convert_to_std_str(hard_disk_input->Text))
					+ "," + MyForm::clear_commas(MyForm::convert_to_std_str(motherboard_input->Text))
					+ "," + MyForm::clear_commas(MyForm::convert_to_std_str(monitor_input->Text))
					+ "," + printer_specs;
				if (WriteData::edit_data(file_name, file_data, edited_line_number)) {
					if (MessageBox::Show("PC-" + id_input->Text + " in file " + gcnew String(file_name.c_str()) + " Updated successfuly!",
						"EDITED SUCCESSFULLY!", MessageBoxButtons::OK, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::OK)
						assign_new_pc::~assign_new_pc();
				}
				else
					MessageBox::Show("Error occured during editting!\nData hasn't been saved!", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else if (WriteData::write_data(username, "Data_Base", MyForm::clear_commas(MyForm::convert_to_std_str(id_input->Text)) +
				"," + MyForm::clear_commas(MyForm::convert_to_std_str(processor_input->Text)) +
				"," + MyForm::clear_commas(MyForm::convert_to_std_str(ram_input->Text)) +
				"," + MyForm::clear_commas(MyForm::convert_to_std_str(hard_disk_input->Text)) +
				"," + MyForm::clear_commas(MyForm::convert_to_std_str(motherboard_input->Text)) +
				"," + MyForm::clear_commas(MyForm::convert_to_std_str(monitor_input->Text)) +
				"," + printer_specs)) {
				if (MessageBox::Show("Do you want to assign another PC?", "PC-" + id_input->Text + " assigend successfully!", MessageBoxButtons::YesNo, MessageBoxIcon::Question)
					== System::Windows::Forms::DialogResult::No)
					assign_new_pc::~assign_new_pc();
				confirmation_check_box->Checked = false;
			}
			else
				MessageBox::Show("Error occured during assigning!\nData hasn't been saved!", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}else{
			MessageBox::Show("Make sure that all data is correct and there's no empty cell then click the confirmation check box.", "Incorrect data!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			confirmation_check_box->Checked = false;
		}
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		assign_new_pc::~assign_new_pc();
	}
	public: static bool is_valid_id(String^ id) {
		if (id->Length != 6)
			return false;
		for (size_t i = 0; i < 6; i++) {
			if (id[i] < '0' || id[i] > '9')
				return false;
		}
		return true;
	}
	private: System::Void id_input_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter) {
			if (is_valid_id(id_input->Text))
				processor_input->Focus();
			else
				MessageBox::Show("Make sure you entered correct ID!", "Invalid ID", MessageBoxButtons::OK, MessageBoxIcon::Error);

		}
	}
	private: System::Void processor_input_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			ram_input->Focus();
	}
	private: System::Void ram_input_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			hard_disk_input->Focus();
	}
	private: System::Void hard_disk_input_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			motherboard_input->Focus();
	}
	private: System::Void motherboard_input_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			monitor_input->Focus();
	}
	private: System::Void printer_brand_input_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			printer_model_input->Focus();
	}
	
	private: System::Void reset_button_Click(System::Object^ sender, System::EventArgs^ e) {
		id_input->Text = "210";
		processor_input->Text = "";
		ram_input->Text = "";
		hard_disk_input->Text = "";
		motherboard_input->Text = "";
		monitor_input->Text = "";
		printer_check_box->Checked = false;
		printer_brand_input->Text = "";
		printer_model_input->Text = "";
	}
	private: System::Void increment_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (is_valid_id(id_input->Text))
			id_input->Text = System::Convert::ToString(System::Convert::ToInt32(id_input->Text) + 1);
		else
			MessageBox::Show("Make sure you entered correct ID!", "Invalid ID", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	bool dragging;
	Point pnt;
	private: System::Void assign_new_pc_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = true;
		pnt.X = e->X;
		pnt.Y = e->Y;
	}
	private: System::Void assign_new_pc_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (dragging) {
			Point current_pos = PointToScreen(Point(e->X, e->Y));
			Location = Point(current_pos.X - pnt.X, current_pos.Y - pnt.Y);
		}
	}
	private: System::Void assign_new_pc_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = false;
	}
};
}
