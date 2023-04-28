#pragma once
struct user {
	std::string name, password;
}users[]{ {"Mahmoud_hussien", "sysMahmoudH"}, {"Admin_No2", "A7686665"}, {"user_No1", "U7689964"}, {"user_No2", "U8790075"} };
namespace PCSystemGUI {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		std::string *current_user = nullptr;
		MyForm(void)
		{
			InitializeComponent();
		}
		MyForm(std::string *tmp)
		{
			InitializeComponent();
			current_user = tmp;
		}
	public: static std::string convert_to_std_str(String^ str) {
		return msclr::interop::marshal_as<std::string>(str);
	}
	public: static std::string clear_commas(std::string txt) {
		for (auto &c : txt)
			if (c == ',')
				c = ';';
		return txt;
	}
	protected:
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ username_label;
	private: System::Windows::Forms::TextBox^ username_input;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ password_input;
	private: System::Windows::Forms::Label^ password_label;
	private: System::Windows::Forms::Label^ title_label;
	private: System::Windows::Forms::Button^ login_button;
	private: System::Windows::Forms::CheckBox^ Show_password;
	private: System::Windows::Forms::Button^ exit_button;
	private: System::Windows::Forms::Label^ credit;


	protected:
	private:
		System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->username_label = (gcnew System::Windows::Forms::Label());
			this->username_input = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->password_input = (gcnew System::Windows::Forms::TextBox());
			this->password_label = (gcnew System::Windows::Forms::Label());
			this->title_label = (gcnew System::Windows::Forms::Label());
			this->login_button = (gcnew System::Windows::Forms::Button());
			this->Show_password = (gcnew System::Windows::Forms::CheckBox());
			this->exit_button = (gcnew System::Windows::Forms::Button());
			this->credit = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// username_label
			// 
			this->username_label->AutoSize = true;
			this->username_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->username_label->ForeColor = System::Drawing::Color::White;
			this->username_label->Location = System::Drawing::Point(58, 171);
			this->username_label->Name = L"username_label";
			this->username_label->Size = System::Drawing::Size(95, 25);
			this->username_label->TabIndex = 0;
			this->username_label->Text = L"Username";
			this->username_label->Click += gcnew System::EventHandler(this, &MyForm::username_label_Click);
			// 
			// username_input
			// 
			this->username_input->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(139)),
				static_cast<System::Int32>(static_cast<System::Byte>(132)));
			this->username_input->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->username_input->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->username_input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->username_input->ForeColor = System::Drawing::Color::White;
			this->username_input->Location = System::Drawing::Point(65, 199);
			this->username_input->MaxLength = 15;
			this->username_input->Name = L"username_input";
			this->username_input->Size = System::Drawing::Size(200, 22);
			this->username_input->TabIndex = 1;
			this->username_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::username_input_KeyDown);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->panel1->Location = System::Drawing::Point(65, 224);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(200, 1);
			this->panel1->TabIndex = 2;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->panel2->Location = System::Drawing::Point(65, 309);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(200, 1);
			this->panel2->TabIndex = 5;
			// 
			// password_input
			// 
			this->password_input->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(139)),
				static_cast<System::Int32>(static_cast<System::Byte>(132)));
			this->password_input->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->password_input->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->password_input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->password_input->ForeColor = System::Drawing::Color::White;
			this->password_input->Location = System::Drawing::Point(65, 284);
			this->password_input->MaxLength = 12;
			this->password_input->Name = L"password_input";
			this->password_input->Size = System::Drawing::Size(200, 22);
			this->password_input->TabIndex = 4;
			this->password_input->UseSystemPasswordChar = true;
			this->password_input->TextChanged += gcnew System::EventHandler(this, &MyForm::password_input_TextChanged);
			this->password_input->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::password_input_KeyDown);
			// 
			// password_label
			// 
			this->password_label->AutoSize = true;
			this->password_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->password_label->ForeColor = System::Drawing::Color::White;
			this->password_label->Location = System::Drawing::Point(58, 256);
			this->password_label->Name = L"password_label";
			this->password_label->Size = System::Drawing::Size(88, 25);
			this->password_label->TabIndex = 3;
			this->password_label->Text = L"Password";
			this->password_label->Click += gcnew System::EventHandler(this, &MyForm::label3_Click);
			// 
			// title_label
			// 
			this->title_label->AutoSize = true;
			this->title_label->Font = (gcnew System::Drawing::Font(L"Segoe UI", 50.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->title_label->ForeColor = System::Drawing::Color::White;
			this->title_label->Location = System::Drawing::Point(28, 40);
			this->title_label->Name = L"title_label";
			this->title_label->Size = System::Drawing::Size(202, 89);
			this->title_label->TabIndex = 6;
			this->title_label->Text = L"Login";
			this->title_label->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// login_button
			// 
			this->login_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->login_button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"login_button.BackgroundImage")));
			this->login_button->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->login_button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->login_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->login_button->ForeColor = System::Drawing::Color::Black;
			this->login_button->Location = System::Drawing::Point(43, 391);
			this->login_button->Name = L"login_button";
			this->login_button->Size = System::Drawing::Size(90, 36);
			this->login_button->TabIndex = 7;
			this->login_button->Text = L"Login";
			this->login_button->UseVisualStyleBackColor = false;
			this->login_button->Click += gcnew System::EventHandler(this, &MyForm::login_button_Click);
			// 
			// Show_password
			// 
			this->Show_password->AutoSize = true;
			this->Show_password->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Show_password->ForeColor = System::Drawing::Color::White;
			this->Show_password->Location = System::Drawing::Point(65, 317);
			this->Show_password->Name = L"Show_password";
			this->Show_password->Size = System::Drawing::Size(108, 17);
			this->Show_password->TabIndex = 8;
			this->Show_password->Text = L"Show password";
			this->Show_password->UseVisualStyleBackColor = true;
			this->Show_password->CheckedChanged += gcnew System::EventHandler(this, &MyForm::show_password_CheckedChanged);
			// 
			// exit_button
			// 
			this->exit_button->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(139)),
				static_cast<System::Int32>(static_cast<System::Byte>(132)));
			this->exit_button->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->exit_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->exit_button->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exit_button->ForeColor = System::Drawing::Color::White;
			this->exit_button->Location = System::Drawing::Point(150, 391);
			this->exit_button->Name = L"exit_button";
			this->exit_button->Size = System::Drawing::Size(90, 36);
			this->exit_button->TabIndex = 9;
			this->exit_button->Text = L"Exit";
			this->exit_button->UseVisualStyleBackColor = false;
			this->exit_button->Click += gcnew System::EventHandler(this, &MyForm::exit_button_Click);
			// 
			// credit
			// 
			this->credit->AutoSize = true;
			this->credit->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->credit->Location = System::Drawing::Point(147, 6);
			this->credit->Name = L"credit";
			this->credit->Size = System::Drawing::Size(498, 17);
			this->credit->TabIndex = 10;
			this->credit->Text = L"THIS PROGRAM IS CREATED BY MAHMOUD HUSSIEN MOHAMED Version 3.6 - 2021";
			this->credit->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(139)),
				static_cast<System::Int32>(static_cast<System::Byte>(132)));
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(780, 470);
			this->Controls->Add(this->credit);
			this->Controls->Add(this->exit_button);
			this->Controls->Add(this->Show_password);
			this->Controls->Add(this->login_button);
			this->Controls->Add(this->title_label);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->password_input);
			this->Controls->Add(this->password_label);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->username_input);
			this->Controls->Add(this->username_label);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void username_label_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void password_input_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void show_password_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		password_input->UseSystemPasswordChar = !(Show_password->Checked);
	}
	private: System::Void exit_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void username_input_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			password_input->Focus();
	}
	private: System::Void password_input_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyValue == (int)Keys::Enter)
			login_button->Focus();
	}
	private: System::Void login_button_Click(System::Object^ sender, System::EventArgs^ e) {
		bool valid = false;
		for (size_t i = 0; i < 4; i++) {
			user tmp{ msclr::interop::marshal_as<std::string>(username_input->Text), msclr::interop::marshal_as<std::string>(password_input->Text) };
			if (tmp.name == users[i].name && tmp.password == users[i].password) {
				valid = true;
				*current_user = users[i].name;
				break;
			}
		}
		if (!valid) 
			MessageBox::Show("Check Username and Password.", "Invalid Username or Password!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		else
			MyForm::~MyForm();
	}
	bool dragging;
	Point pnt;
	private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = true;
		pnt.X = e->X;
		pnt.Y = e->Y;
	}
	private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (dragging) {
			Point current_pos = PointToScreen(Point(e->X, e->Y));
			Location = Point(current_pos.X - pnt.X, current_pos.Y - pnt.Y);
		}
	}
	private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		dragging = false;
	}
};
}
