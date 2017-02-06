//---------------------------------------------------------------------------

#ifndef VolumeWndH
#define VolumeWndH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TVolumeForm : public TForm
{
__published:	// IDE-managed Components
	TScrollBar *ScrollBar1;
	void __fastcall ScrollBar1Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TVolumeForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TVolumeForm *VolumeForm;
//---------------------------------------------------------------------------
#endif
