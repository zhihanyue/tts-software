//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "VoiceWnd.h"
#include "MainWnd.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TVoiceForm *VoiceForm;
//---------------------------------------------------------------------------
__fastcall TVoiceForm::TVoiceForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TVoiceForm::FormCreate(TObject *Sender)
{
	Button1Click(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TVoiceForm::Button1Click(TObject *Sender)
{
	WideString str,C("Microsoft Simplified Chinese"),
        	E1("Microsoft Sam"),E2("Microsoft Mike"),E3("Microsoft Mary");
        int hadC=-1;
	bool hadE=false;
	ListBox1->Clear();
	ISpeechObjectTokensPtr voices=MainForm->speaker->GetVoices(NULL,NULL);
	int count=voices->Count;

        for(int i=0;i<count;++i)
        {
                str=voices->Item(i)->GetDescription(0);
        	ListBox1->Items->Add(str);
                if(str==C) hadC=i;
                if(str==E1 || str==E2 || str==E3) hadE=true;
        }
        if(hadC!=-1 && hadE)
        {
        	ListBox1->ItemIndex=hadC;
        	MainForm->speaker->_set_Voice(MainForm->speaker->GetVoices(NULL,NULL)->Item(hadC));
        }
        else
        {
                bool OK1=false,OK2=false;
        	if(hadC==-1 && (OK1=MessageBox(MainForm->Handle,"找不到微软中文语音库，可能无法正常朗读。\n\n请问是否让系统为您自动安装？约需10秒钟。","询问：",MB_YESNO|MB_ICONQUESTION)==IDYES))
        		WinExec(("msiexec /I "+ExtractFilePath(ParamStr(0))+"database\\微软tts5.1语音引擎(中文).msi").c_str(),SW_SHOWNORMAL);
        	if(!hadE && (OK2=MessageBox(MainForm->Handle,"找不到微软英文语音库，可能无法正常朗读。\n\n请问是否让系统为您自动安装？约需10秒钟。","询问：",MB_YESNO|MB_ICONQUESTION)==IDYES))
        		WinExec(("msiexec /I "+ExtractFilePath(ParamStr(0))+"database\\TTS_51_eng.msi").c_str(),SW_SHOWNORMAL);
                if(OK1 || OK2)
                {
                        MessageBox(MainForm->Handle,"安装完成后单击确认以刷新语音库。","确认：",MB_OK);
                        Button1Click(NULL);
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TVoiceForm::ListBox1Click(TObject *Sender)
{
	MainForm->speaker->_set_Voice(MainForm->speaker->GetVoices(NULL,NULL)->Item(ListBox1->ItemIndex));
}
//---------------------------------------------------------------------------

