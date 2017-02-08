object VoiceForm: TVoiceForm
  Left = 410
  Top = 332
  BorderStyle = bsToolWindow
  Caption = #35821#38899#24211#35774#32622
  ClientHeight = 177
  ClientWidth = 169
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object ListBox1: TListBox
    Left = 0
    Top = 0
    Width = 169
    Height = 145
    ItemHeight = 13
    TabOrder = 0
    OnClick = ListBox1Click
  end
  object Button1: TButton
    Left = 120
    Top = 152
    Width = 49
    Height = 25
    Caption = #21047#26032
    TabOrder = 1
    OnClick = Button1Click
  end
end
