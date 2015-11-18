#include "MainForm.h"
#include "CMobPool.h"
#include "CUserLocal.h"

using namespace KamiPls;

// called by the native entrypoints
void Main(void)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MainForm);
	Application::Exit();
}


void MainForm::tUpdateUI_Tick(Object^ sender, EventArgs^  e)
{
	auto userPos = CUserLocal::GetInstance()->GetPos();
	auto mobPos = CMobPool::GetInstance()->GetClosestMob(userPos)->GetPos();
	lUserPos->Text = "{" + userPos.x + "; " + userPos.y + "}";
	lMobPos->Text = "{" + mobPos.x + "; " + mobPos.y + "}";
}


void MainForm::cbTimer_CheckedChanged(Object^ sender, EventArgs^ e)
{
	tUpdateUI->Enabled = cbTimer->Enabled;
}
