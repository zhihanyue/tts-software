//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MainWnd.h"
#include "RateWnd.h"
#include "VoiceWnd.h"
#include "VolumeWnd.h"
#include "AboutWnd.h"
#include "HelpWnd.h"
#include "AdjustDlgUnit.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SpeechLib_OCX"
#pragma resource "*.dfm"

AnsiString CurrentFile="无标题";
AnsiString CurrentText="";

TMainForm *MainForm;

//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------

bool OpenAdjustDlg(AnsiString name,int min,int pos,int max,int &value)
{
        TAdjustDlg* pDlg;
        pDlg=new TAdjustDlg(MainForm);
        pDlg->Label1->Caption=name;
        pDlg->ScrollBar1->Min=min;
        pDlg->ScrollBar1->Max=max;
        pDlg->ScrollBar1->Position=pos;
        pDlg->ShowModal();
        if(pDlg->Label1->Caption=="为空") return false;
        value=pDlg->ScrollBar1->Position;
        delete pDlg;
        return true;
}

//---------------------------------------------------------------------------
void AddXML(AnsiString text,int DecPos=0)
{
        int old=MainForm->Memo->SelStart;

        MainForm->Memo->Text=MainForm->Memo->Text.Insert(text,old+1);
	MainForm->Memo->SelStart=old+text.Length()-DecPos;
}
//---------------------------------------------------------------------------
void AddXML(AnsiString textA,AnsiString textB)
{
        int startpos=MainForm->Memo->SelStart+1,stoppos=startpos+MainForm->Memo->SelLength;
        MainForm->Memo->Text=MainForm->Memo->Text.Insert(textB,stoppos);
        MainForm->Memo->Text=MainForm->Memo->Text.Insert(textA,startpos);
}
//---------------------------------------------------------------------------
void RefreshTitle()
{
	MainForm->Caption = CurrentFile + " - 语音朗读助手";
}
//---------------------------------------------------------------------------
void ErrorMessage(AnsiString text)
{
	MessageBox(MainForm->Handle,("对不起，"+text).c_str(),"错误提示：",MB_ICONERROR);
}

//---------------------------------------------------------------------------
bool IsSelOK()
{
        if(MainForm->Memo->SelLength==0)
        {
                MessageBox(MainForm->Handle,"请先选择欲操作的文本。","注意：",MB_OK|MB_ICONWARNING);
                return false;
        }
        else return true;
}

//---------------------------------------------------------------------------
bool SaveFileAs()
{
        MainForm->FileSaver->DefaultExt="txt";
	MainForm->FileSaver->Filter="文本文档(*.txt)|*.txt|XML文件(*.xml)|*.xml|所有文件(*.*)|*.*";
	if(MainForm->FileSaver->Execute())
        {
		try
                {
			MainForm->Memo->Lines->SaveToFile(MainForm->FileSaver->FileName);
                }
                catch(EFCreateError&)
                {
                	ErrorMessage("无法创建文件，请更换文件名或重试。");
                        return false;
                }
                catch(EWriteError&)
                {
                        ErrorMessage("无法写文件，请更换文件名或重试。");
                        return false;
                }
                CurrentFile=MainForm->FileSaver->FileName;
                CurrentText=MainForm->Memo->Text;
                RefreshTitle();
                return true;
        }
        else return false;
}


//---------------------------------------------------------------------------
bool SaveFile()
{
	if(CurrentFile=="无标题")
        {
		return SaveFileAs();
        }
        else if(CurrentText!=MainForm->Memo->Text)
        {
		try
                {
                	MainForm->Memo->Lines->SaveToFile(CurrentFile);
                }
                catch(EFCreateError &error)
                {
                	ErrorMessage("无法创建文件，原因可能为不具有读写权限或文件被其他进程占用，请更换文件名重新保存。");
                        return false;
                }
                catch(EWriteError&)
                {
                        ErrorMessage("无法写文件，请更换文件名或重试。");
                        return false;
                }
                CurrentText=MainForm->Memo->Text;
        }
        return true;
}

//---------------------------------------------------------------------------

bool CloseFile()
{
	bool result=true;
	if(MainForm->Memo->Text != CurrentText)
        {
        	switch(MessageBox(MainForm->Handle,("文件 "+CurrentFile+" 的文字已经改变。\n\n想保存文件吗？").c_str()
                	,"确认：",MB_YESNOCANCEL|MB_ICONQUESTION))
                {
                case IDYES:
                        result=SaveFile();
                	break;
                case IDNO:
                        result=true;
                	break;
                default:
                	result=false;
                }
        }
        return result;
}

//---------------------------------------------------------------------------
void __fastcall TMainForm::SearchFind1FindDialogFind(TObject *Sender)
{
	Memo->SetFocus();
	SearchFindNext1->Execute();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpeechBeginExecute(TObject *Sender)
{
        if(Memo->Text.Length()==0)
        {
        	ErrorMessage("要朗读的文本为空。");
                return;
        }
        if(SpeechStop->Enabled)
        {
                speaker->Resume();
        	SpeechBegin->Enabled=false;
        	SpeechPause->Enabled=true;
        	SpeechStop->Enabled=true;
        	SpeechWAV->Enabled=false;
        }
        else
        {
        	speaker->Resume();
                try
                {
			if(XML2->Checked)
        			speaker->Speak(WideString(Memo->Text),SVSFlagsAsync|SVSFIsXML);
			else speaker->Speak(WideString(Memo->Text),SVSFlagsAsync|SVSFIsNotXML);
                }
                catch(EOleException&)
                {
                	ErrorMessage("欲朗读的文本格式出现错误。\n\n检查并修改错误或关闭XML解析器可解决这个问题。");
                }
        }

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::speakerStartStream(TObject *Sender,
      long StreamNumber, Variant StreamPosition)
{
        SpeechBegin->Enabled=false;
        SpeechPause->Enabled=true;
        SpeechStop->Enabled=true;
        SpeechWAV->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::speakerEndStream(TObject *Sender,
      long StreamNumber, Variant StreamPosition)
{
        SpeechBegin->Enabled=true;
        SpeechPause->Enabled=false;
        SpeechStop->Enabled=false;
        SpeechWAV->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpeechPauseExecute(TObject *Sender)
{
        speaker->Pause();
        SpeechBegin->Enabled=true;
        SpeechPause->Enabled=false;
        SpeechStop->Enabled=true;
        SpeechWAV->Enabled=false;

        int volume=speaker->get_Volume();
	while(speaker->get_Volume()>0)
        {
        	speaker->set_Volume(speaker->get_Volume()-10);
                Sleep(25);
        }
        speaker->set_Volume(volume);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SpeechStopExecute(TObject *Sender)
{
	speaker->Resume();
        speaker->Speak(NULL,SVSFPurgeBeforeSpeak);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::SpeechWAVExecute(TObject *Sender)
{
	if(Memo->Text.Length()==0)
        {
        	ErrorMessage("要合成的文本为空。");
                return;
        }
        FileSaver->DefaultExt="wav";
	FileSaver->Filter="WAV音频文件(*.wav)|*.wav";
	if(FileSaver->Execute())
        {
		AudioFile->Open(WideString(FileSaver->FileName),SSFMCreateForWrite,false);
                ISpeechBaseStreamPtr SysStream=speaker->get_AudioOutputStream();
                speaker->_set_AudioOutputStream(AudioFile->GetDefaultInterface());

        	speaker->Resume();
                try
                {
			if(XML2->Checked)
        			speaker->Speak(WideString(Memo->Text),SVSFlagsAsync|SVSFIsXML);
			else speaker->Speak(WideString(Memo->Text),SVSFlagsAsync|SVSFIsNotXML);
                }
                catch(EOleException&)
                {
                	ErrorMessage("欲合成的文本格式出现错误。\n\n检查并修改错误或关闭XML解析器可解决这个问题。");
                }
                speaker->WaitUntilDone(-1);
        	AudioFile->Close();
                speaker->_set_AudioOutputStream(SysStream);
	}
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FormCreate(TObject *Sender)
{
	AudioFile->Format->Type=SAFT22kHz16BitMono;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N17Click(TObject *Sender)
{
	VolumeForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N18Click(TObject *Sender)
{
	RateForm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N11Click(TObject *Sender)
{
	VoiceForm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N8Click(TObject *Sender)
{
	AboutForm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FileNew1Execute(TObject *Sender)
{
	if(CloseFile())
        {
                CurrentFile="无标题";
                CurrentText="";
                RefreshTitle();
                Memo->Text="";
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCloseQuery(TObject *Sender, bool &CanClose)
{
	CanClose=CloseFile();
}
//---------------------------------------------------------------------------



void __fastcall TMainForm::FileOpen1Execute(TObject *Sender)
{
	if(CloseFile())
        {
		FileOpener->DefaultExt="txt";
        	FileOpener->Filter="文本文档(*.txt)|*.txt|XML文件(*.xml)|*.xml|所有文件(*.*)|*.*";
        	if(FileOpener->Execute())
        	{
                	try
                        {
        			Memo->Lines->LoadFromFile(FileOpener->FileName);
                        }
                        catch(EFOpenError&)
                        {
       				ErrorMessage("无法打开文件，此文件可能被其他进程占用。");
                                return;
                        }
                        catch(EReadError&)
                        {
                                ErrorMessage("无法读取文件，此文件可能被其他进程占用。");
                                return;
                        }
                	CurrentFile=FileOpener->FileName;
                	CurrentText=Memo->Text;
                	RefreshTitle();
        	}
        }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Volume1Click(TObject *Sender)
{
	AddXML("<volume level=\"\">",2);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::volume2Click(TObject *Sender)
{
	AddXML("</volume>");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Volume3Click(TObject *Sender)
{
	AddXML("<volume level=\"\"/>",3);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Rate1Click(TObject *Sender)
{
        AddXML("<rate speed=\"\">",2);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RateSpeed1Click(TObject *Sender)
{
        AddXML("<rate absspeed=\"\">",2);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Rate2Click(TObject *Sender)
{
        AddXML("</rate>");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Rate3Click(TObject *Sender)
{
        AddXML("<rate speed=\"\"/>",3);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::RateAbsSpeed1Click(TObject *Sender)
{
        AddXML("<rate absspeed=\"\"/>",3);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::Pitch1Click(TObject *Sender)
{
	AddXML("<pitch middle=\"\">",2);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Pitch2Click(TObject *Sender)
{
	AddXML("<pitch absmiddle=\"\">",2);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Pit1Click(TObject *Sender)
{
	AddXML("</pitch>");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Pitch3Click(TObject *Sender)
{
	AddXML("<pitch middle=\"\"/>",3);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PitchAbsMiddle1Click(TObject *Sender)
{
	AddXML("<pitch absmiddle=\"\"/>",3);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Emph1Click(TObject *Sender)
{
	AddXML("<emph>");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Emph2Click(TObject *Sender)
{
	AddXML("</emph>");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Spell1Click(TObject *Sender)
{
	AddXML("<spell>");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Spell2Click(TObject *Sender)
{
	AddXML("</spell>");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Silence2Click(TObject *Sender)
{
	AddXML("<silence msec=\"\"/>",3);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Pron1Click(TObject *Sender)
{
	AddXML("<pron sym=\"\"/>",3);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Pron2Click(TObject *Sender)
{
	AddXML("<pron sym=\"\">",2);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Pron3Click(TObject *Sender)
{
	AddXML("</pron>");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N32Click(TObject *Sender)
{
	AddXML("<bookmark mark=\"\"/>",3);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PartOfSp1Click(TObject *Sender)
{
	AddXML("<partofsp part=\"\">",2);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PartOfSp2Click(TObject *Sender)
{
	AddXML("</partofsp>");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Context1Click(TObject *Sender)
{
	AddXML("<context id=\"\">",2);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Context2Click(TObject *Sender)
{
	AddXML("</context>");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileSave1Execute(TObject *Sender)
{
	SaveFile();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileSaveAsExecute(TObject *Sender)
{
	SaveFileAs();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Lang1Click(TObject *Sender)
{
	AddXML("<lang langid=\"\">",2);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Lang2Click(TObject *Sender)
{
	AddXML("</lang>");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Lang3Click(TObject *Sender)
{
	AddXML("<lang langid=\"\"/>",3);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::XML1Click(TObject *Sender)
{
	HelpForm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N46Click(TObject *Sender)
{
        if(!IsSelOK()) return;
        AddXML("<spell>","</spell>");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N45Click(TObject *Sender)
{
        if(!IsSelOK()) return;
        AddXML("<emph>","</emph>");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N51Click(TObject *Sender)
{
        if(!IsSelOK()) return;
        AddXML("<lang langid=\"409\">","</lang>");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N48Click(TObject *Sender)
{
        AnsiString Text;
        if(!InputQuery("请输入","停顿时间(毫秒):               ",Text)) return;
        AddXML(AnsiString("<silence msec=\"\"/>").Insert(Text,16));
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N49Click(TObject *Sender)
{
        AnsiString Text;
        if(!InputQuery("请输入","音素(请用空格分开):                   ",Text)) return;
        AddXML(AnsiString("<pron sym=\"\"/>").Insert(Text,12));
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N44Click(TObject *Sender)
{
        if(!IsSelOK()) return;
        int value;
        if(!OpenAdjustDlg("调整音调的高低：",-10,0,10,value)) return;
        AddXML(AnsiString("<pitch absmiddle=\"\">").Insert(AnsiString(value),19),"</pitch>");
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N7Click(TObject *Sender)
{
        if(!IsSelOK()) return;
        int value;
        if(!OpenAdjustDlg("调整音量的大小：",0,100,100,value)) return;
        AddXML(AnsiString("<volume level=\"\">").Insert(AnsiString(value),16),"</volume>");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N43Click(TObject *Sender)
{
        if(!IsSelOK()) return;
        int value;
        if(!OpenAdjustDlg("调整语速的快慢：",-10,0,10,value)) return;
        AddXML(AnsiString("<rate absspeed=\"\">").Insert(AnsiString(value),17),"</rate>");
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::N52Click(TObject *Sender)
{
        if(!IsSelOK()) return;
        AddXML("<partofsp part=\"noun\">","</emph>");
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::N53Click(TObject *Sender)
{
	if(!IsSelOK()) return;
        AddXML("<context id=\"date_dmy\">","</context>");
}

//---------------------------------------------------------------------------






