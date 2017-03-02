//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "AdjustDlgUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TAdjustDlg *AdjustDlg;

bool isOK=false;

//---------------------------------------------------------------------------
__fastcall TAdjustDlg::TAdjustDlg(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TAdjustDlg::Button2Click(TObject *Sender)
{
        isOK=false;
        Close();
}
//---------------------------------------------------------------------------

void __fastcall TAdjustDlg::FormClose(TObject *Sender,
      TCloseAction &Action)
{
        Label1->Caption=isOK?"²»Îª¿Õ":"Îª¿Õ";
}
//---------------------------------------------------------------------------
void __fastcall TAdjustDlg::Button1Click(TObject *Sender)
{
        isOK=true;
        Close();
}
//---------------------------------------------------------------------------

