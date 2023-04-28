#include <algorithm>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <map>
#include <msclr\marshal_cppstd.h>
#include "MyForm.h"
#include "assign_new_pc.h"
#include "create_report.h"
#include "open_file_form.h"
#include "edit_file_form.h"
#include "reveiew_file_form.h"
#include "decision_form.h"
using namespace System;
using namespace System::Windows::Forms;
std::string current_user;
[STAThreadAttribute]
void main(array < String^ >^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	PCSystemGUI::MyForm lgn_frm(&current_user);
	Application::Run(% lgn_frm);

	if (!current_user.empty()) {
		PCSystemGUI::decision_form dcs_frm(current_user);
		Application::Run(% dcs_frm);
	}
}