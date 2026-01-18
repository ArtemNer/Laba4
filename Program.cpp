#include <windows.h>

#using <System.dll>
#using <System.Windows.Forms.dll>

#include "MainForm.h"
#include "LoginForm.h"

[System::STAThreadAttribute]
int WINAPI WinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR     lpCmdLine,
    int       nShowCmd)
{
    System::Windows::Forms::Application::EnableVisualStyles();
    System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

    LoginForm^ login = gcnew LoginForm();
    if (login->ShowDialog() == System::Windows::Forms::DialogResult::OK)
    {

        System::Windows::Forms::Application::Run(
            gcnew MainForm(login->UserName, login->IsAdmin)
        );
    }
    return 0;
}