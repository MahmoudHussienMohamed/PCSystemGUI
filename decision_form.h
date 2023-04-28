#pragma once
namespace PCSystemGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for decision_form
	/// </summary>
	public ref class decision_form : public System::Windows::Forms::Form
	{
	public:
		decision_form(std::string usrnm)
		{
			InitializeComponent();
			username = usrnm;
			name->Text = gcnew String((usrnm.substr(0, usrnm.find('_')) + ",").c_str());
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~decision_form()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ operation_q;
	private: System::Windows::Forms::Button^ assigning_button;
	private: System::Windows::Forms::Button^ report_button;
	private: System::Windows::Forms::Button^ merging_button;
	private: System::Windows::Forms::Button^ displaying_button;
	private: System::Windows::Forms::Label^ name;
	private: System::Windows::Forms::Button^ exit_button;
	private: System::Windows::Forms::Button^ edit_file_button;
	private: System::Windows::Forms::Button^ reveiew_button;




	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(decision_form::typeid));
			this->operation_q = (gcnew System::Windows::Forms::Label());
			this->assigning_button = (gcnew System::Windows::Forms::Button());
			this->report_button = (gcnew System::Windows::Forms::Button());
			this->merging_button = (gcnew System::Windows::Forms::Button());
			this->displaying_button = (gcnew System::Windows::Forms::Button());
			this->name = (gcnew System::Windows::Forms::Label());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->edit_file_button = (gcnew System::Windows::Forms::Button());
			this->reveiew_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// operation_q
			// 
			this->operation_q->AutoSize = true;
			this->operation_q->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->operation_q->ForeColor = System::Drawing::Color::White;
			this->operation_q->Location = System::Drawing::Point(74, 80);
			this->operation_q->Name = L"operation_q";
			this->operation_q->Size = System::Drawing::Size(345, 37);
			this->operation_q->TabIndex = 0;
			this->operation_q->Text = L"What do you intend to do\?";
			// 
			// assigning_button
			// 
			this->assigning_button->BackColor = System::Drawing::Color::Black;
			this->assigning_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"assigning_button.BackgroundImage")));
			this->assigning_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->assigning_button->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->assigning_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->assigning_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->assigning_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->assigning_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->assigning_button->Location = System::Drawing::Point(40, 190);
			this->assigning_button->Name = L"assigning_button";
			this->assigning_button->Size = System::Drawing::Size(159, 40);
			this->assigning_button->TabIndex = 1;
			this->assigning_button->Text = L"Assign new PC";
			this->assigning_button->UseVisualStyleBackColor = false;
			this->assigning_button->Click += gcnew System::EventHandler(this, &decision_form::assigning_button_Click);
			// 
			// report_button
			// 
			this->report_button->BackColor = System::Drawing::Color::Black;
			this->report_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"report_button.BackgroundImage")));
			this->report_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->report_button->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->report_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->report_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->report_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->report_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->report_button->Location = System::Drawing::Point(40, 245);
			this->report_button->Name = L"report_button";
			this->report_button->Size = System::Drawing::Size(159, 40);
			this->report_button->TabIndex = 2;
			this->report_button->Text = L"Create report";
			this->report_button->UseVisualStyleBackColor = false;
			this->report_button->Click += gcnew System::EventHandler(this, &decision_form::report_button_Click);
			// 
			// merging_button
			// 
			this->merging_button->BackColor = System::Drawing::Color::Black;
			this->merging_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"merging_button.BackgroundImage")));
			this->merging_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->merging_button->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->merging_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->merging_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->merging_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->merging_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->merging_button->Location = System::Drawing::Point(40, 465);
			this->merging_button->Name = L"merging_button";
			this->merging_button->Size = System::Drawing::Size(159, 40);
			this->merging_button->TabIndex = 37;
			this->merging_button->Text = L"Merge files";
			this->merging_button->UseVisualStyleBackColor = false;
			this->merging_button->Click += gcnew System::EventHandler(this, &decision_form::merging_button_Click);
			// 
			// displaying_button
			// 
			this->displaying_button->BackColor = System::Drawing::Color::Black;
			this->displaying_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"displaying_button.BackgroundImage")));
			this->displaying_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->displaying_button->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->displaying_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->displaying_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->displaying_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->displaying_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->displaying_button->Location = System::Drawing::Point(40, 410);
			this->displaying_button->Name = L"displaying_button";
			this->displaying_button->Size = System::Drawing::Size(159, 39);
			this->displaying_button->TabIndex = 36;
			this->displaying_button->Text = L"Display PC(s) data";
			this->displaying_button->UseVisualStyleBackColor = false;
			this->displaying_button->Click += gcnew System::EventHandler(this, &decision_form::displaying_button_Click);
			// 
			// name
			// 
			this->name->AutoSize = true;
			this->name->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 39.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->name->ForeColor = System::Drawing::Color::White;
			this->name->Location = System::Drawing::Point(12, 9);
			this->name->Name = L"name";
			this->name->Size = System::Drawing::Size(167, 71);
			this->name->TabIndex = 5;
			this->name->Text = L"label1";
			// 
			// exit_button
			// 
			this->exit_button->BackColor = System::Drawing::Color::Black;
			this->exit_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit_button->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exit_button->ForeColor = System::Drawing::Color::White;
			this->exit_button->Location = System::Drawing::Point(573, 9);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(48, 33);
			this->exit_button->TabIndex = 38;
			this->exit_button->Text = L"Exit";
			this->exit_button->UseVisualStyleBackColor = false;
			this->exit_button->Click += gcnew System::EventHandler(this, &decision_form::exit_button_Click);
			// 
			// edit_file_button
			// 
			this->edit_file_button->BackColor = System::Drawing::Color::Black;
			this->edit_file_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"edit_file_button.BackgroundImage")));
			this->edit_file_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->edit_file_button->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->edit_file_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->edit_file_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->edit_file_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->edit_file_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->edit_file_button->Location = System::Drawing::Point(40, 355);
			this->edit_file_button->Name = L"edit_file_button";
			this->edit_file_button->Size = System::Drawing::Size(159, 39);
			this->edit_file_button->TabIndex = 4;
			this->edit_file_button->Text = L"Edit file";
			this->edit_file_button->UseVisualStyleBackColor = false;
			this->edit_file_button->Click += gcnew System::EventHandler(this, &decision_form::edit_file_button_Click);
			// 
			// reveiew_button
			// 
			this->reveiew_button->BackColor = System::Drawing::Color::Black;
			this->reveiew_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"reveiew_button.BackgroundImage")));
			this->reveiew_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->reveiew_button->FlatAppearance->CheckedBackColor = System::Drawing::Color::Black;
			this->reveiew_button->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->reveiew_button->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Black;
			this->reveiew_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->reveiew_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reveiew_button->Location = System::Drawing::Point(40, 300);
			this->reveiew_button->Name = L"reveiew_button";
			this->reveiew_button->Size = System::Drawing::Size(159, 39);
			this->reveiew_button->TabIndex = 3;
			this->reveiew_button->Text = L"Review file";
			this->reveiew_button->UseVisualStyleBackColor = false;
			this->reveiew_button->Click += gcnew System::EventHandler(this, &decision_form::reveiew_button_Click);
			// 
			// decision_form
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(139)),
				static_cast<System::Int32>(static_cast<System::Byte>(132)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(633, 530);
			this->Controls->Add(this->reveiew_button);
			this->Controls->Add(this->edit_file_button);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->name);
			this->Controls->Add(this->displaying_button);
			this->Controls->Add(this->merging_button);
			this->Controls->Add(this->report_button);
			this->Controls->Add(this->assigning_button);
			this->Controls->Add(this->operation_q);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"decision_form";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Decision";
			this->Load += gcnew System::EventHandler(this, &decision_form::decision_form_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &decision_form::decision_form_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &decision_form::decision_form_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &decision_form::decision_form_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void decision_form_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	bool* assign_new_pc_form_working = new bool{false};
	private: System::Void assigning_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!*assign_new_pc_form_working) {
			assign_new_pc^ anp = gcnew assign_new_pc(username, assign_new_pc_form_working);
			anp->Show();
		}
		else
			MessageBox::Show("\'Assign new PC'\ window is already opened!", "Already Opened!", MessageBoxButtons::OK, MessageBoxIcon::Stop);
	}
	bool* create_report_form_working = new bool{false};
	private: System::Void report_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (!*create_report_form_working) {
			create_report^ cr = gcnew create_report(username, create_report_form_working);
			cr->Show();
		}
		else
			MessageBox::Show("\'Create report'\ window is already opened!", "Already Opened!", MessageBoxButtons::OK, MessageBoxIcon::Stop);
	}
	private: bool *display_working = new bool{false}, *merge_working = new bool{false};
	private: void create_ofd(String^ ofd_type_name) {
		if ((ofd_type_name == "Merge" && !*merge_working) || (ofd_type_name == "Display" && !*display_working)) {
			open_file_form^ ofd = gcnew open_file_form(ofd_type_name == "Merge" ? merge_working : display_working);
			ofd->Text = ofd_type_name;
			ofd->title_label->Text = ofd_type_name;
			ofd->operation_button->Text = ofd_type_name;
			ofd->Show();
		}
		else
			MessageBox::Show("\'" + ofd_type_name + "\' window is already opened!", "Already Opened!", MessageBoxButtons::OK, MessageBoxIcon::Stop);
	}
	private: System::Void merging_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (username == users[0].name || username == users[1].name) 
			create_ofd("Merge");
		else
			MessageBox::Show("You're not an ADMIN!", "ACCESS DENIED!", MessageBoxButtons::OK, MessageBoxIcon::Stop);
	}
	private: System::Void displaying_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (username == users[0].name || username == users[1].name)
			create_ofd("Display");
		else
			MessageBox::Show("You're not an ADMIN!", "ACCESS DENIED!", MessageBoxButtons::OK, MessageBoxIcon::Stop);
	}
	private: System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		decision_form::~decision_form();
	}
	bool dragging;
	Point pnt;
	private: System::Void decision_form_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = true;
		pnt.X = e->X;
		pnt.Y = e->Y;
	}
	private: System::Void decision_form_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (dragging) {
			Point current_pos = PointToScreen(Point(e->X, e->Y));
			Location = Point(current_pos.X - pnt.X, current_pos.Y - pnt.Y);
		}
	}
	private: System::Void decision_form_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = false;
	}
	private: System::Void edit_file_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (username == users[0].name || username == users[1].name){
			edit_file_form^ eff = gcnew edit_file_form(username);
			eff->Show();
		}
		else
			MessageBox::Show("You're not an ADMIN!", "ACCESS DENIED!", MessageBoxButtons::OK, MessageBoxIcon::Stop);

	}
	private: System::Void reveiew_button_Click(System::Object^ sender, System::EventArgs^ e) {
		reveiew_file_form^ rff = gcnew reveiew_file_form(username);
		rff->Show();
	}
};
}
