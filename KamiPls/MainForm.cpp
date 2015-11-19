#include "MainForm.h"
#include "CMobPool.h"
#include "CUserLocal.h"
#include "Kami.h"

using namespace KamiPls;

// called by the native entrypoints
void Main(void)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm);
	Application::Exit();
}

void MainForm::cbKami_CheckedChanged(Object^ sender, EventArgs^ e)
{
	kami::enable(cbKami->Checked);
}