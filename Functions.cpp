/*======================= Function for launching the form =======================*/
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//ProjectName - name of your project
	//NameForm - name of the form to run
	ProjectName::NameForm form;
	Application::Run(% form);
}

/*======================= Converting System::String ^ to std::string and vice versa =======================*/
#include <string>
using namespace System;

//Function prototypes (for the header file -> .h)
std::string ConvertToString(System::String^ s);		//converting System::string ^ to std::string
String^ ConvertToString(std::string& os);		//converting std::string to System::string ^

//Implementing functions (for the execution file -> .cpp)
//Converting System::string ^ to std::string
std::string ConvertToString(System::String^ s) {
	using namespace Runtime::InteropServices;
	const char* chars =
		(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	std::string	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));

	return os;
}

//Converting std::string to System::string ^ 
System::String^ ConvertToString(std::string& os) {
	System::String^ s = gcnew System::String(os.c_str());

	return s;
}

/*
Usage Example:
System::String^ sysString = "string";
std::string stdString = ConvertToString(sysString);	//converting from system to standard
sysString = ConvertToString(stdString);			//converting from standard to system
*/
