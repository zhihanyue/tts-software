object AdjustDlg: TAdjustDlg
  Left = 221
  Top = 450
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = #35831#35843#25972
  ClientHeight = 118
  ClientWidth = 334
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 313
    Height = 41
    AutoSize = False
    Caption = #35843#25972#20026#65306
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object ScrollBar1: TScrollBar
    Left = 8
    Top = 56
    Width = 313
    Height = 17
    PageSize = 0
    TabOrder = 0
  end
  object Button1: TButton
    Left = 48
    Top = 88
    Width = 89
    Height = 25
    Caption = #30830#35748'(&C)'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 200
    Top = 88
    Width = 89
    Height = 25
    Caption = #21462#28040'(&Q)'
    TabOrder = 2
    OnClick = Button2Click
  end
end
