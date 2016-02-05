#include "MainForm.h"

using namespace DLL_FORM_TEMPLATE; 

void CreateApplicationForm( void )
{
 	Application::EnableVisualStyles();
 	Application::SetCompatibleTextRenderingDefault( false ); 
 	Application::Run( gcnew MainForm() );
}