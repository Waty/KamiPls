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

void test()
{
	CMobPool::GetInstance()->GetClosestMob(CUserLocal::GetInstance()->GetPos());
}