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
	/// Summary for create_report
	/// </summary>
	/// string editor_username;
	bool report_edit_mode = false;
	public ref class create_report : public System::Windows::Forms::Form
	{
	public:
		bool* working = nullptr;
		create_report(string usrnm, bool *b)
		{
			InitializeComponent();
			username = usrnm;
			working = b;
			*working = true;
		}
		create_report(string eun, string fn, vector<string> fd, int eln)
		{
			editor_username = eun;
			file_name = fn;
			file_data = fd;
			edited_line_number = eln;
			report_edit_mode = true;
			InitializeComponent();
			fill_cells(file_data[edited_line_number]);
		}
	private: void find_c(string& buffer, char c, vector<size_t>&vec) {
		for (size_t i = 0; i < buffer.length(); i++)
			if (buffer[i] == c)
				vec.push_back(i);
	}
	private: string txt_of(CheckBox^ tmp) {
		return MyForm::convert_to_std_str(tmp->Text);
	}
	private: void fill_cells(string& data_before_edit) {
		find_c(data_before_edit, ',', comma_pos);
		size_t curr_idx = 0;
		id_input->Text = gcnew String(data_before_edit.substr(0, comma_pos[curr_idx]).c_str());
		vector<string> report_component;
		report_component.push_back("None");
		report_component.push_back(txt_of(software));
		report_component.push_back(txt_of(processor));
		report_component.push_back(txt_of(ram));
		report_component.push_back(txt_of(hard_disk));
		report_component.push_back(txt_of(power_supply));
		report_component.push_back(txt_of(motherboard));
		report_component.push_back(txt_of(monitor));
		report_component.push_back(txt_of(input_output_device));
		report_component.push_back(txt_of(printer));
		report_component.push_back(txt_of(ink_cartridge));
		report_component.push_back(txt_of(printer_motherboard));
		bool check_boxes[13]{ false };
		for (size_t i = 0; i < report_component.size(); i++) {
			if (i <= 9)
				check_boxes[i] = (data_before_edit.find(report_component[i]) != string::npos);
			else
				check_boxes[i] = (data_before_edit.find(report_component[i]) != string::npos && check_boxes[9]);
		}
		no_problem->Checked = check_boxes[0];
		software->Checked = check_boxes[1];
		processor->Checked = check_boxes[2];
		ram->Checked = check_boxes[3];
		hard_disk->Checked = check_boxes[4];
		power_supply->Checked = check_boxes[5];
		motherboard->Checked = check_boxes[6];
		monitor->Checked = check_boxes[7];
		input_output_device->Checked = check_boxes[8];
		printer->Checked = check_boxes[9];
		ink_cartridge->Checked = check_boxes[10];
		printer_motherboard->Checked = check_boxes[11];
		description_input->Text = gcnew String(data_before_edit.substr(comma_pos[comma_pos.size() - 2] + 1, comma_pos[comma_pos.size() - 1] - comma_pos[comma_pos.size() - 2] - 1).c_str());
		cost_input->Text = gcnew String(data_before_edit.substr(comma_pos[comma_pos.size() - 1] + 1).c_str());
		create_button->Text = "Edit";
		title_label->Text = "Edit " + title_label->Text;
		this->Text = "Edit Report";
		this->Show();
	}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~create_report()
		{
			if (components)
			{
				delete components;
			}
			if (working)
				*working = false;
		}
	private: System::Windows::Forms::TextBox^ id_input;
	protected:
	private: System::Windows::Forms::Label^ id_label;
	private: System::Windows::Forms::CheckBox^ processor;
	private: System::Windows::Forms::CheckBox^ ram;
	private: System::Windows::Forms::CheckBox^ hard_disk;
	private: System::Windows::Forms::CheckBox^ motherboard;
	private: System::Windows::Forms::CheckBox^ monitor;
	private: System::Windows::Forms::CheckBox^ input_output_device;
	private: System::Windows::Forms::CheckBox^ no_problem;
	private: System::Windows::Forms::CheckBox^ printer;
	private: System::Windows::Forms::CheckBox^ ink_cartridge;
	private: System::Windows::Forms::CheckBox^ printer_motherboard;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::TextBox^ description_input;

	private: System::Windows::Forms::Label^ description_label;

	private: System::Windows::Forms::TextBox^ cost_input;
	private: System::Windows::Forms::Label^ cost_label;

	private: System::Windows::Forms::Label^ title_label;
	private: System::Windows::Forms::Button^ increment_button;
	private: System::Windows::Forms::CheckBox^ confirmation_check_box;
	private: System::Windows::Forms::Button^ create_button;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Button^ exit_button;
	private: System::Windows::Forms::CheckBox^ software;
	private: System::Windows::Forms::CheckBox^ power_supply;



	private: String^ report;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(create_report::typeid));
			this->id_input = (gcnew System::Windows::Forms::TextBox());
			this->id_label = (gcnew System::Windows::Forms::Label());
			this->processor = (gcnew System::Windows::Forms::CheckBox());
			this->ram = (gcnew System::Windows::Forms::CheckBox());
			this->hard_disk = (gcnew System::Windows::Forms::CheckBox());
			this->motherboard = (gcnew System::Windows::Forms::CheckBox());
			this->monitor = (gcnew System::Windows::Forms::CheckBox());
			this->input_output_device = (gcnew System::Windows::Forms::CheckBox());
			this->no_problem = (gcnew System::Windows::Forms::CheckBox());
			this->printer = (gcnew System::Windows::Forms::CheckBox());
			this->ink_cartridge = (gcnew System::Windows::Forms::CheckBox());
			this->printer_motherboard = (gcnew System::Windows::Forms::CheckBox());
			this->description_input = (gcnew System::Windows::Forms::TextBox());
			this->description_label = (gcnew System::Windows::Forms::Label());
			this->cost_input = (gcnew System::Windows::Forms::TextBox());
			this->cost_label = (gcnew System::Windows::Forms::Label());
			this->title_label = (gcnew System::Windows::Forms::Label());
			this->increment_button = (gcnew System::Windows::Forms::Button());
			this->confirmation_check_box = (gcnew System::Windows::Forms::CheckBox());
			this->create_button = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->software = (gcnew System::Windows::Forms::CheckBox());
			this->power_supply = (gcnew System::Windows::Forms::CheckBox());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// id_input
			// 
			this->id_input->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(187)));
			this->id_input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->id_input->Location = System::Drawing::Point(85, 102);
			this->id_input->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->id_input->MaxLength = 6;
			this->id_input->Name = L"id_input";
			this->id_input->Size = System::Drawing::Size(123, 33);
			this->id_input->TabIndex = 3;
			this->id_input->Text = L"210";
			// 
			// id_label
			// 
			this->id_label->AutoSize = true;
			this->id_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->id_label->ForeColor = System::Drawing::Color::White;
			this->id_label->Location = System::Drawing::Point(14, 106);
			this->id_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->id_label->Name = L"id_label";
			this->id_label->Size = System::Drawing::Size(67, 30);
			this->id_label->TabIndex = 2;
			this->id_label->Text = L"PC-ID";
			// 
			// processor
			// 
			this->processor->AutoSize = true;
			this->processor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->processor->ForeColor = System::Drawing::SystemColors::Control;
			this->processor->Location = System::Drawing::Point(35, 209);
			this->processor->Name = L"processor";
			this->processor->Size = System::Drawing::Size(113, 29);
			this->processor->TabIndex = 4;
			this->processor->Text = L"Processor";
			this->processor->UseVisualStyleBackColor = true;
			this->processor->CheckedChanged += gcnew System::EventHandler(this, &create_report::processor_CheckedChanged);
			// 
			// ram
			// 
			this->ram->AutoSize = true;
			this->ram->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ram->ForeColor = System::Drawing::SystemColors::Control;
			this->ram->Location = System::Drawing::Point(35, 234);
			this->ram->Name = L"ram";
			this->ram->Size = System::Drawing::Size(71, 29);
			this->ram->TabIndex = 5;
			this->ram->Text = L"RAM";
			this->ram->UseVisualStyleBackColor = true;
			// 
			// hard_disk
			// 
			this->hard_disk->AutoSize = true;
			this->hard_disk->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hard_disk->ForeColor = System::Drawing::SystemColors::Control;
			this->hard_disk->Location = System::Drawing::Point(35, 259);
			this->hard_disk->Name = L"hard_disk";
			this->hard_disk->Size = System::Drawing::Size(112, 29);
			this->hard_disk->TabIndex = 6;
			this->hard_disk->Text = L"Hard Disk";
			this->hard_disk->UseVisualStyleBackColor = true;
			// 
			// motherboard
			// 
			this->motherboard->AutoSize = true;
			this->motherboard->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->motherboard->ForeColor = System::Drawing::SystemColors::Control;
			this->motherboard->Location = System::Drawing::Point(35, 309);
			this->motherboard->Name = L"motherboard";
			this->motherboard->Size = System::Drawing::Size(143, 29);
			this->motherboard->TabIndex = 7;
			this->motherboard->Text = L"Motherboard";
			this->motherboard->UseVisualStyleBackColor = true;
			// 
			// monitor
			// 
			this->monitor->AutoSize = true;
			this->monitor->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->monitor->ForeColor = System::Drawing::SystemColors::Control;
			this->monitor->Location = System::Drawing::Point(35, 334);
			this->monitor->Name = L"monitor";
			this->monitor->Size = System::Drawing::Size(99, 29);
			this->monitor->TabIndex = 8;
			this->monitor->Text = L"Monitor";
			this->monitor->UseVisualStyleBackColor = true;
			// 
			// input_output_device
			// 
			this->input_output_device->AutoSize = true;
			this->input_output_device->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->input_output_device->ForeColor = System::Drawing::SystemColors::Control;
			this->input_output_device->Location = System::Drawing::Point(35, 359);
			this->input_output_device->Name = L"input_output_device";
			this->input_output_device->Size = System::Drawing::Size(200, 29);
			this->input_output_device->TabIndex = 9;
			this->input_output_device->Text = L"Input/Output device";
			this->input_output_device->UseVisualStyleBackColor = true;
			// 
			// no_problem
			// 
			this->no_problem->AutoSize = true;
			this->no_problem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->no_problem->ForeColor = System::Drawing::SystemColors::Control;
			this->no_problem->Location = System::Drawing::Point(35, 159);
			this->no_problem->Name = L"no_problem";
			this->no_problem->Size = System::Drawing::Size(132, 29);
			this->no_problem->TabIndex = 10;
			this->no_problem->Text = L"No Problem";
			this->no_problem->UseVisualStyleBackColor = true;
			this->no_problem->CheckedChanged += gcnew System::EventHandler(this, &create_report::no_problem_CheckedChanged);
			// 
			// printer
			// 
			this->printer->AutoSize = true;
			this->printer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->printer->ForeColor = System::Drawing::SystemColors::Control;
			this->printer->Location = System::Drawing::Point(35, 384);
			this->printer->Name = L"printer";
			this->printer->Size = System::Drawing::Size(92, 29);
			this->printer->TabIndex = 11;
			this->printer->Text = L"Printer:";
			this->printer->UseVisualStyleBackColor = true;
			this->printer->CheckedChanged += gcnew System::EventHandler(this, &create_report::printer_CheckedChanged);
			// 
			// ink_cartridge
			// 
			this->ink_cartridge->AutoSize = true;
			this->ink_cartridge->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ink_cartridge->ForeColor = System::Drawing::SystemColors::Control;
			this->ink_cartridge->Location = System::Drawing::Point(84, 408);
			this->ink_cartridge->Name = L"ink_cartridge";
			this->ink_cartridge->Size = System::Drawing::Size(140, 29);
			this->ink_cartridge->TabIndex = 12;
			this->ink_cartridge->Text = L"Ink Cartridge";
			this->ink_cartridge->UseVisualStyleBackColor = true;
			this->ink_cartridge->Visible = false;
			// 
			// printer_motherboard
			// 
			this->printer_motherboard->AutoSize = true;
			this->printer_motherboard->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->printer_motherboard->ForeColor = System::Drawing::SystemColors::Control;
			this->printer_motherboard->Location = System::Drawing::Point(84, 430);
			this->printer_motherboard->Name = L"printer_motherboard";
			this->printer_motherboard->Size = System::Drawing::Size(143, 29);
			this->printer_motherboard->TabIndex = 13;
			this->printer_motherboard->Text = L"Motherboard";
			this->printer_motherboard->UseVisualStyleBackColor = true;
			this->printer_motherboard->Visible = false;
			// 
			// description_input
			// 
			this->description_input->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
			this->description_input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->description_input->Location = System::Drawing::Point(38, 505);
			this->description_input->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->description_input->MaxLength = 1000;
			this->description_input->Name = L"description_input";
			this->description_input->Size = System::Drawing::Size(375, 29);
			this->description_input->TabIndex = 15;
			this->description_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &create_report::description_input_KeyDown);
			// 
			// description_label
			// 
			this->description_label->AutoSize = true;
			this->description_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->description_label->ForeColor = System::Drawing::Color::White;
			this->description_label->Location = System::Drawing::Point(35, 483);
			this->description_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->description_label->Name = L"description_label";
			this->description_label->Size = System::Drawing::Size(247, 17);
			this->description_label->TabIndex = 14;
			this->description_label->Text = L"Description (Notes) about selected parts";
			// 
			// cost_input
			// 
			this->cost_input->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(187)));
			this->cost_input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cost_input->Location = System::Drawing::Point(38, 562);
			this->cost_input->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->cost_input->MaxLength = 10;
			this->cost_input->Name = L"cost_input";
			this->cost_input->Size = System::Drawing::Size(107, 29);
			this->cost_input->TabIndex = 17;
			// 
			// cost_label
			// 
			this->cost_label->AutoSize = true;
			this->cost_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cost_label->ForeColor = System::Drawing::Color::White;
			this->cost_label->Location = System::Drawing::Point(35, 540);
			this->cost_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->cost_label->Name = L"cost_label";
			this->cost_label->Size = System::Drawing::Size(35, 17);
			this->cost_label->TabIndex = 16;
			this->cost_label->Text = L"Cost";
			// 
			// title_label
			// 
			this->title_label->AutoSize = true;
			this->title_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 48, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title_label->ForeColor = System::Drawing::Color::White;
			this->title_label->Location = System::Drawing::Point(-6, -3);
			this->title_label->Name = L"title_label";
			this->title_label->Size = System::Drawing::Size(235, 86);
			this->title_label->TabIndex = 20;
			this->title_label->Text = L"Report";
			// 
			// increment_button
			// 
			this->increment_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(187)));
			this->increment_button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->increment_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->increment_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->increment_button->Location = System::Drawing::Point(175, 103);
			this->increment_button->Name = L"increment_button";
			this->increment_button->Size = System::Drawing::Size(33, 31);
			this->increment_button->TabIndex = 31;
			this->increment_button->Text = L"+";
			this->increment_button->UseVisualStyleBackColor = false;
			this->increment_button->Click += gcnew System::EventHandler(this, &create_report::increment_button_Click);
			// 
			// confirmation_check_box
			// 
			this->confirmation_check_box->AutoSize = true;
			this->confirmation_check_box->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9.75F, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->confirmation_check_box->ForeColor = System::Drawing::Color::White;
			this->confirmation_check_box->Location = System::Drawing::Point(164, 646);
			this->confirmation_check_box->Name = L"confirmation_check_box";
			this->confirmation_check_box->Size = System::Drawing::Size(217, 21);
			this->confirmation_check_box->TabIndex = 33;
			this->confirmation_check_box->Text = L"Confirm that all data is Correct!";
			this->confirmation_check_box->UseVisualStyleBackColor = true;
			this->confirmation_check_box->CheckedChanged += gcnew System::EventHandler(this, &create_report::confirmation_check_box_CheckedChanged);
			// 
			// create_button
			// 
			this->create_button->BackColor = System::Drawing::Color::Black;
			this->create_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"create_button.BackgroundImage")));
			this->create_button->Cursor = System::Windows::Forms::Cursors::No;
			this->create_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->create_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->create_button->Location = System::Drawing::Point(28, 630);
			this->create_button->Name = L"create_button";
			this->create_button->Size = System::Drawing::Size(113, 47);
			this->create_button->TabIndex = 32;
			this->create_button->Text = L"Create";
			this->create_button->UseVisualStyleBackColor = false;
			this->create_button->Click += gcnew System::EventHandler(this, &create_report::create_button_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Gray;
			this->panel1->Controls->Add(this->panel8);
			this->panel1->Location = System::Drawing::Point(19, 134);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(188, 1);
			this->panel1->TabIndex = 34;
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::Gray;
			this->panel8->Location = System::Drawing::Point(0, 1);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(314, 1);
			this->panel8->TabIndex = 21;
			// 
			// exit_button
			// 
			this->exit_button->BackColor = System::Drawing::Color::Black;
			this->exit_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exit_button->ForeColor = System::Drawing::Color::White;
			this->exit_button->Location = System::Drawing::Point(812, 12);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(48, 33);
			this->exit_button->TabIndex = 35;
			this->exit_button->Text = L"Exit";
			this->exit_button->UseVisualStyleBackColor = false;
			this->exit_button->Click += gcnew System::EventHandler(this, &create_report::exit_button_Click);
			// 
			// software
			// 
			this->software->AutoSize = true;
			this->software->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->software->ForeColor = System::Drawing::SystemColors::Control;
			this->software->Location = System::Drawing::Point(35, 184);
			this->software->Name = L"software";
			this->software->Size = System::Drawing::Size(411, 29);
			this->software->TabIndex = 36;
			this->software->Text = L"Software (Windows/Programes/Drivers ... etc)";
			this->software->UseVisualStyleBackColor = true;
			// 
			// power_supply
			// 
			this->power_supply->AutoSize = true;
			this->power_supply->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->power_supply->ForeColor = System::Drawing::SystemColors::Control;
			this->power_supply->Location = System::Drawing::Point(35, 284);
			this->power_supply->Name = L"power_supply";
			this->power_supply->Size = System::Drawing::Size(145, 29);
			this->power_supply->TabIndex = 37;
			this->power_supply->Text = L"Power Supply";
			this->power_supply->UseVisualStyleBackColor = true;
			// 
			// create_report
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 21);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(139)),
				static_cast<System::Int32>(static_cast<System::Byte>(132)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(872, 700);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Controls->Add(this->power_supply);
			this->Controls->Add(this->software);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->confirmation_check_box);
			this->Controls->Add(this->create_button);
			this->Controls->Add(this->increment_button);
			this->Controls->Add(this->title_label);
			this->Controls->Add(this->cost_input);
			this->Controls->Add(this->cost_label);
			this->Controls->Add(this->description_input);
			this->Controls->Add(this->description_label);
			this->Controls->Add(this->printer_motherboard);
			this->Controls->Add(this->ink_cartridge);
			this->Controls->Add(this->printer);
			this->Controls->Add(this->no_problem);
			this->Controls->Add(this->input_output_device);
			this->Controls->Add(this->monitor);
			this->Controls->Add(this->motherboard);
			this->Controls->Add(this->hard_disk);
			this->Controls->Add(this->ram);
			this->Controls->Add(this->processor);
			this->Controls->Add(this->id_input);
			this->Controls->Add(this->id_label);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"create_report";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Create Report";
			this->Load += gcnew System::EventHandler(this, &create_report::create_report_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &create_report::create_report_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &create_report::create_report_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &create_report::create_report_MouseUp);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void create_report_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: bool is_valid_id(String^ id) {
		if (id->Length != 6)
			return false;
		for (size_t i = 0; i < 6; i++) {
			if (id[i] < '0' || id[i] > '9')
				return false;
		}
		return true;
	}
	private: System::Void printer_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		ink_cartridge->Visible = printer->Checked;
		printer_motherboard->Visible = printer->Checked;
	}
	private: System::Void processor_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		
	}
	private: System::Void no_problem_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		bool noprob = no_problem->Checked;
		if (noprob) {
			software->Checked = false;
			processor->Checked = false;
			ram->Checked = false;
			hard_disk->Checked = false;
			power_supply->Checked = false;
			motherboard->Checked = false;
			monitor->Checked = false;
			printer->Checked = false;
			input_output_device->Checked = false;
			ink_cartridge->Checked = false;
			printer_motherboard->Checked = false;
		}
		software->Enabled = !noprob;
		processor->Enabled = !noprob;
		ram->Enabled = !noprob;
		hard_disk->Enabled = !noprob;
		power_supply->Enabled = !noprob;
		motherboard->Enabled = !noprob;
		monitor->Enabled = !noprob;
		printer->Enabled = !noprob;
		input_output_device->Enabled = !noprob;
		ink_cartridge->Enabled = !noprob;
		printer_motherboard->Enabled = !noprob;

		description_label->Enabled = !noprob;
		description_input->Enabled = !noprob;
		cost_label->Enabled = !noprob;
		cost_input->Enabled = !noprob;
		description_input->Text = (noprob? "No problem" : "");
		cost_input->Text = (noprob ? "0.0" : "");
	}
	private: System::Void increment_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (is_valid_id(id_input->Text))
			id_input->Text = System::Convert::ToString(System::Convert::ToInt32(id_input->Text) + 1);
		else
			MessageBox::Show("Make sure you entered correct ID!", "Invalid ID", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	private: System::Void description_input_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			cost_input->Focus();
	}
	private: void get_text(System::Windows::Forms::CheckBox^ tmp, string &str) {
		if (tmp->Checked) {
			if (str.length() > 7) // str = "210xxx," or longer
				str += " - ";
			str += MyForm::convert_to_std_str(tmp->Text);
		}
	}
	private: System::Void create_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if ((confirmation_check_box->Checked && description_input->Text->Length != 0 
			&& is_valid_id(id_input->Text) && cost_input->Text->Length != 0)
			&& (no_problem->Checked || software->Checked || processor->Checked || ram->Checked || hard_disk->Checked || power_supply->Checked || motherboard->Checked
				|| monitor->Checked || input_output_device->Checked || (printer->Checked && (ink_cartridge->Checked || printer_motherboard->Checked)))) {
			string report = MyForm::convert_to_std_str(id_input->Text) + ",";
			if (no_problem->Checked) {
				report += "None";
			}else{
				get_text(software, report);
				get_text(processor, report);
				get_text(ram, report);
				get_text(hard_disk, report);
				get_text(power_supply, report);
				get_text(motherboard, report);
				get_text(monitor, report);
				get_text(input_output_device, report);
				get_text(printer, report);
				get_text(ink_cartridge, report);
				get_text(printer_motherboard, report);
			}
			report += "," + MyForm::clear_commas(MyForm::convert_to_std_str(description_input->Text)) +
					  "," + MyForm::clear_commas(MyForm::convert_to_std_str(cost_input->Text));
			if (report_edit_mode) {
				string& tmp = file_data[edited_line_number];
				tmp = MyForm::convert_to_std_str(id_input->Text)
					+ tmp.substr(comma_pos[0], comma_pos[1] - comma_pos[0] - 1)
					+ " - EDITED AT : " + WriteData::get_time()
					+ tmp.substr(comma_pos[1], comma_pos[2] - comma_pos[1])
					+ " - EDITED BY : " + editor_username
					+ report.substr(6);
				if (WriteData::edit_data(file_name, file_data, edited_line_number)) {
					if (MessageBox::Show("PC-" + id_input->Text + " in file " + gcnew String(file_name.c_str()) + " Updated successfuly!",
						"EDITED SUCCESSFULLY!", MessageBoxButtons::OK, MessageBoxIcon::Information) == System::Windows::Forms::DialogResult::OK)
						create_report::~create_report();
				}
				else
					MessageBox::Show("Error occured during editting!\nData hasn't been saved!", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			else if (WriteData::write_data(username, "Reports", report)) {
				if (MessageBox::Show("Do you want to create another report ?", "PC-" + id_input->Text + "\'s report recorded successfully!", MessageBoxButtons::YesNo, MessageBoxIcon::Question)
					== System::Windows::Forms::DialogResult::No)
					create_report::~create_report();
				else {
					confirmation_check_box->Checked = false;
					no_problem->Checked = false;
					software->Checked = false;
					processor->Checked = false;
					ram->Checked = false;
					hard_disk->Checked = false;
					power_supply->Checked = false;
					motherboard->Checked = false;
					monitor->Checked = false;
					input_output_device->Checked = false;
					printer->Checked = false;
					ink_cartridge->Checked = false;
					printer_motherboard->Checked = false;
					description_input->Text = "";
					cost_input->Text = "";
				}
			}
			else
				MessageBox::Show("Error occured during recording!\nData hasn't been saved!", "ERROR!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
			MessageBox::Show("Make sure that all data is correct and there's no empty cell then click the confirmation check box.", "Incorrect data!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			confirmation_check_box->Checked = false;
		}
	}
	private: System::Void confirmation_check_box_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (confirmation_check_box->Checked)
			create_button->Cursor = System::Windows::Forms::Cursors::Hand;
		else
			create_button->Cursor = System::Windows::Forms::Cursors::No;
	}
	private: System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		create_report::~create_report();
	}
	bool dragging;
	Point pnt;
	private: System::Void create_report_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = true;
		pnt.X = e->X;
		pnt.Y = e->Y;
	}
	private: System::Void create_report_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (dragging) {
			Point current_pos = PointToScreen(Point(e->X, e->Y));
			Location = Point(current_pos.X - pnt.X, current_pos.Y - pnt.Y);
		}
	}
	private: System::Void create_report_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = false;
	}
};
}
