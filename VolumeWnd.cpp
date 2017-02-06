//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "VolumeWnd.h"
#include "MainWnd.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TVolumeForm *VolumeForm;
//---------------------------------------------------------------------------
__fastcall TVolumeForm::TVolumeForm(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
void __fastcall TVolumeForm::ScrollBar1Change(TObject *Sender)
{
	MainForm->speaker->set_Volume(ScrollBar1->Position);
}
//---------------------------------------------------------------------------
