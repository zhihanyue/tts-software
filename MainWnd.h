//---------------------------------------------------------------------------

#ifndef MainWndH
#define MainWndH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <Menus.hpp>
#include <StdActns.hpp>
#include <ExtCtrls.hpp>
#include <ActnCtrls.hpp>
#include <ActnMan.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <ExtActns.hpp>
#include "SpeechLib_OCX.h"
#include <OleServer.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
	TActionList *ActionList1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *XML;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N12;
	TMenuItem *N13;
	TMenuItem *WAV1;
	TMenuItem *N14;
	TMenuItem *N15;
	TMenuItem *N16;
	TMenuItem *N17;
	TMenuItem *N18;
	TMenuItem *XML2;
	TMenuItem *N20;
	TMenuItem *N21;
	TEditCut *EditCut1;
	TEditCopy *EditCopy1;
	TEditPaste *EditPaste1;
	TEditSelectAll *EditSelectAll1;
	TEditUndo *EditUndo1;
	TEditDelete *EditDelete1;
	TMenuItem *U1;
	TMenuItem *N22;
	TMenuItem *T1;
	TMenuItem *C1;
	TMenuItem *P1;
	TMenuItem *D1;
	TMenuItem *N23;
	TMenuItem *A1;
	TSearchFind *SearchFind1;
	TSearchFindNext *SearchFindNext1;
	TMenuItem *N24;
	TMenuItem *F1;
	TMenuItem *N25;
	TBitBtn *BitBtn1;
	TBitBtn *BitBtn2;
	TControlBar *ControlBar1;
	TStatusBar *StatusBar1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TImageList *ImageList1;
	TToolBar *ToolBar2;
	TToolButton *ToolButton6;
	TToolButton *ToolButton7;
	TToolButton *ToolButton8;
	TToolButton *ToolButton9;
	TToolButton *ToolButton10;
	TToolButton *ToolButton11;
	TToolButton *ToolButton12;
	TToolButton *ToolButton13;
	TToolButton *ToolButton14;
	TToolButton *ToolButton16;
	TToolButton *ToolButton17;
	TToolBar *ToolBar3;
	TToolButton *ToolButton18;
	TToolButton *ToolButton20;
	TToolButton *ToolButton21;
	TMemo *Memo;
	TFileExit *FileExit1;
	TAction *FileNew1;
	TAction *FileSave1;
	TAction *SpeechBegin;
	TAction *SpeechPause;
	TAction *SpeechStop;
	TAction *SpeechWAV;
	TSpVoice *speaker;
	TAction *FileOpen1;
	TAction *FileSaveAs;
	TSpFileStream *AudioFile;
	TOpenDialog *FileOpener;
	TSaveDialog *FileSaver;
	TMenuItem *N11;
	TMenuItem *Volume1;
	TMenuItem *volume2;
	TMenuItem *Rate1;
	TMenuItem *RateSpeed1;
	TMenuItem *Rate2;
	TMenuItem *N26;
	TMenuItem *Pitch1;
	TMenuItem *Pitch2;
	TMenuItem *N27;
	TMenuItem *N28;
	TMenuItem *Emph1;
	TMenuItem *Emph2;
	TMenuItem *Spell1;
	TMenuItem *Spell2;
	TMenuItem *N30;
	TMenuItem *N19;
	TMenuItem *N31;
	TMenuItem *N29;
	TMenuItem *Volume3;
	TMenuItem *N33;
	TMenuItem *N34;
	TMenuItem *Rate3;
	TMenuItem *Pitch3;
	TMenuItem *Pit1;
	TMenuItem *RateAbsSpeed1;
	TMenuItem *PitchAbsMiddle1;
	TMenuItem *N35;
	TMenuItem *Silence1;
	TMenuItem *Silence2;
	TMenuItem *N36;
	TMenuItem *Pron1;
	TMenuItem *N37;
	TMenuItem *Pron2;
	TMenuItem *Pron3;
	TMenuItem *N38;
	TMenuItem *N39;
	TMenuItem *N40;
	TMenuItem *PartOfSp1;
	TMenuItem *PartOfSp2;
	TMenuItem *Context1;
	TMenuItem *Context2;
	TMenuItem *N41;
	TMenuItem *Lang1;
	TMenuItem *Lang2;
	TMenuItem *N42;
	TMenuItem *Lang3;
	TMenuItem *XML1;
        TMenuItem *XML3;
        TMenuItem *N7;
        TMenuItem *N43;
        TMenuItem *N44;
        TMenuItem *N45;
        TMenuItem *N46;
        TMenuItem *N47;
        TMenuItem *N48;
        TMenuItem *N49;
        TMenuItem *N51;
        TMenuItem *N52;
        TMenuItem *N53;
        TMenuItem *N54;
	TToolButton *ToolButton5;
	TMenuItem *P2;
	void __fastcall SearchFind1FindDialogFind(TObject *Sender);
	void __fastcall SpeechBeginExecute(TObject *Sender);
	void __fastcall speakerStartStream(TObject *Sender, long StreamNumber,
          Variant StreamPosition);
	void __fastcall speakerEndStream(TObject *Sender, long StreamNumber,
          Variant StreamPosition);
	void __fastcall SpeechPauseExecute(TObject *Sender);
	void __fastcall SpeechStopExecute(TObject *Sender);
	void __fastcall SpeechWAVExecute(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N17Click(TObject *Sender);
	void __fastcall N18Click(TObject *Sender);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall FileNew1Execute(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall FileOpen1Execute(TObject *Sender);
	void __fastcall Volume1Click(TObject *Sender);
	void __fastcall volume2Click(TObject *Sender);
	void __fastcall Volume3Click(TObject *Sender);
	void __fastcall Rate1Click(TObject *Sender);
	void __fastcall RateSpeed1Click(TObject *Sender);
	void __fastcall Rate2Click(TObject *Sender);
	void __fastcall Rate3Click(TObject *Sender);
	void __fastcall RateAbsSpeed1Click(TObject *Sender);
	void __fastcall Pitch1Click(TObject *Sender);
	void __fastcall Pitch2Click(TObject *Sender);
	void __fastcall Pit1Click(TObject *Sender);
	void __fastcall Pitch3Click(TObject *Sender);
	void __fastcall PitchAbsMiddle1Click(TObject *Sender);
	void __fastcall Emph1Click(TObject *Sender);
	void __fastcall Emph2Click(TObject *Sender);
	void __fastcall Spell1Click(TObject *Sender);
	void __fastcall Spell2Click(TObject *Sender);
	void __fastcall Silence2Click(TObject *Sender);
	void __fastcall Pron1Click(TObject *Sender);
	void __fastcall Pron2Click(TObject *Sender);
	void __fastcall Pron3Click(TObject *Sender);
	void __fastcall N32Click(TObject *Sender);
	void __fastcall PartOfSp1Click(TObject *Sender);
	void __fastcall PartOfSp2Click(TObject *Sender);
	void __fastcall Context1Click(TObject *Sender);
	void __fastcall Context2Click(TObject *Sender);
	void __fastcall FileSave1Execute(TObject *Sender);
	void __fastcall FileSaveAsExecute(TObject *Sender);
	void __fastcall Lang1Click(TObject *Sender);
	void __fastcall Lang2Click(TObject *Sender);
	void __fastcall Lang3Click(TObject *Sender);
	void __fastcall XML1Click(TObject *Sender);
        void __fastcall N46Click(TObject *Sender);
        void __fastcall N45Click(TObject *Sender);
        void __fastcall N51Click(TObject *Sender);
        void __fastcall N48Click(TObject *Sender);
        void __fastcall N49Click(TObject *Sender);
        void __fastcall N44Click(TObject *Sender);
	void __fastcall N7Click(TObject *Sender);
	void __fastcall N43Click(TObject *Sender);
	void __fastcall N52Click(TObject *Sender);
	void __fastcall N53Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
