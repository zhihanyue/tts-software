//---------------------------------------------------------------------------

#ifndef RateWndH
#define RateWndH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TRateForm : public TForm
{
__published:	// IDE-managed Components
	TScrollBar *ScrollBar2;
	void __fastcall ScrollBar2Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TRateForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TRateForm *RateForm;
//---------------------------------------------------------------------------
#endif
