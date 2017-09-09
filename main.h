#ifndef mainH
#define mainH

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ActnList.hpp>
#include <Menus.hpp>
#include <ExtCtrls.hpp>

#include <tlhelp32.h>

static HHOOK hook;

//---------------------------------------------------------------------------
class TInterface : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
    TActionList *ActionList;
    TAction *ActionFetch;
    TAction *ActionKill;
    TPopupMenu *PopupMenu;
    TMenuItem *FetchProcessList1;
    TMenuItem *FetchProcessList2;
    TPanel *Panel1;
    TListView *ListView;
    TButton *BtnFetch;
    TButton *BtnKillProcess;
    TButton *Button2;
    void __fastcall ListViewDblClick(TObject *Sender);
    void __fastcall ActionFetchExecute(TObject *Sender);
    void __fastcall ActionKillExecute(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// Anwender-Deklarationen
public:		// Anwender-Deklarationen
    __fastcall TInterface(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TInterface *Interface;
//---------------------------------------------------------------------------

extern "C" __export LRESULT CALLBACK KeyHookProc(int nCode,WPARAM wParam,LPARAM lParam);
#endif
