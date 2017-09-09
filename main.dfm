object Interface: TInterface
  Left = 391
  Top = 176
  Width = 640
  Height = 480
  Caption = 'Quick Task 1.0'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnShow = ActionFetchExecute
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 632
    Height = 453
    Align = alClient
    BevelInner = bvLowered
    BorderWidth = 1
    BorderStyle = bsSingle
    TabOrder = 0
    DesignSize = (
      628
      449)
    object ListView: TListView
      Left = 3
      Top = 3
      Width = 626
      Height = 414
      Anchors = [akLeft, akTop, akRight, akBottom]
      Columns = <
        item
          AutoSize = True
          Caption = 'PID'
          MaxWidth = 40
        end
        item
          AutoSize = True
          Caption = 'Executeable'
          MaxWidth = 200
        end>
      GridLines = True
      ReadOnly = True
      RowSelect = True
      PopupMenu = PopupMenu
      TabOrder = 0
      ViewStyle = vsReport
      OnDblClick = ListViewDblClick
    end
    object BtnFetch: TButton
      Left = 6
      Top = 420
      Width = 155
      Height = 25
      Action = ActionFetch
      Anchors = [akLeft, akBottom]
      TabOrder = 1
    end
    object BtnKillProcess: TButton
      Left = 170
      Top = 420
      Width = 155
      Height = 25
      Action = ActionKill
      Anchors = [akLeft, akBottom]
      TabOrder = 2
    end
    object Button2: TButton
      Left = 469
      Top = 420
      Width = 155
      Height = 25
      Anchors = [akRight, akBottom]
      Caption = 'Quit'
      TabOrder = 3
      OnClick = Button2Click
    end
  end
  object ActionList: TActionList
    Left = 598
    Top = 388
    object ActionFetch: TAction
      Caption = '&Fetch Process List'
      OnExecute = ActionFetchExecute
    end
    object ActionKill: TAction
      Caption = '&Kill Process'
      OnExecute = ActionKillExecute
    end
  end
  object PopupMenu: TPopupMenu
    Left = 570
    Top = 388
    object FetchProcessList1: TMenuItem
      Action = ActionFetch
    end
    object FetchProcessList2: TMenuItem
      Action = ActionKill
    end
  end
end
