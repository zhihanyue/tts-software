//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "RateWnd.h"
#include "MainWnd.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TRateForm *RateForm;
//---------------------------------------------------------------------------
__fastcall TRateForm::TRateForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TRateForm::ScrollBar2Change(TObject *Sender)
{
	MainForm->speaker->set_Rate(ScrollBar2->Position);
}
//---------------------------------------------------------------------------
