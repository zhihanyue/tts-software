//---------------------------------------------------------------------------

#ifndef VoiceWndH
#define VoiceWndH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TVoiceForm : public TForm
{
__published:	// IDE-managed Components
	TListBox *ListBox1;
	TButton *Button1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall ListBox1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TVoiceForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TVoiceForm *VoiceForm;
//---------------------------------------------------------------------------
#endif
