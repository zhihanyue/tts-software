//---------------------------------------------------------------------------

#ifndef AdjustDlgUnitH
#define AdjustDlgUnitH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TAdjustDlg : public TForm
{
__published:	// IDE-managed Components
        TScrollBar *ScrollBar1;
        TLabel *Label1;
        TButton *Button1;
        TButton *Button2;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TAdjustDlg(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TAdjustDlg *AdjustDlg;
//---------------------------------------------------------------------------
#endif
