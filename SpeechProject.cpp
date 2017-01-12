//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("MainWnd.cpp", MainForm);
USEFORM("RateWnd.cpp", RateForm);
USEFORM("VolumeWnd.cpp", VolumeForm);
USEFORM("VoiceWnd.cpp", VoiceForm);
USEFORM("AboutWnd.cpp", AboutForm);
USEFORM("HelpWnd.cpp", HelpForm);
USEFORM("AdjustDlgUnit.cpp", AdjustDlg);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->Title = "ÓïÒôÀÊ¶ÁÖúÊÖ";
		Application->CreateForm(__classid(TMainForm), &MainForm);
                 Application->CreateForm(__classid(TRateForm), &RateForm);
                 Application->CreateForm(__classid(TVolumeForm), &VolumeForm);
                 Application->CreateForm(__classid(TVoiceForm), &VoiceForm);
                 Application->CreateForm(__classid(TAboutForm), &AboutForm);
                 Application->CreateForm(__classid(THelpForm), &HelpForm);
                 Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
