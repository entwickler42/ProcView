#include <vcl.h>

#pragma hdrstop
#include "main.h"

#pragma package(smart_init)
#pragma resource "*.dfm"

TInterface *Interface;

//---------------------------------------------------------------------------
__fastcall TInterface::TInterface(TComponent* Owner) : TForm(Owner)
{
    hook = SetWindowsHookEx(WH_KEYBOARD_LL,(HOOKPROC)KeyHookProc,GetModuleHandle(NULL),NULL);
}

//---------------------------------------------------------------------------
void __fastcall TInterface::ListViewDblClick(TObject *Sender)
{
    BorderStyle = BorderStyle == bsNone ? bsSingle : bsNone;        
}
//---------------------------------------------------------------------------
void __fastcall TInterface::ActionFetchExecute(TObject *Sender)
{
    HANDLE hSnapshot=CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS,0);
	PROCESSENTRY32 pe;

	pe.dwSize=sizeof(PROCESSENTRY32);
	BOOL retval=Process32First(hSnapshot,&pe);

    TListItem* item;
    ListView->Clear();

	while(retval)
	{
        item = ListView->Items->Add();
        item->Caption = pe.th32ProcessID;
        item->SubItems->Add(pe.szExeFile);
		retval=Process32Next(hSnapshot,&pe);
	}

	CloseHandle(hSnapshot);
}

//---------------------------------------------------------------------------
void __fastcall TInterface::ActionKillExecute(TObject *Sender)
{
    if(ListView->ItemIndex >= 0)
    {
        HANDLE h = OpenProcess(PROCESS_TERMINATE,false,ListView->Selected->Caption.ToInt());

        if(h!=NULL) TerminateProcess(h,0);

        CloseHandle(h);

    } else Application->MessageBoxA("Please select a Process !","Message:",MB_OK);

    Sleep(500); ActionFetchExecute(Sender);
}

//---------------------------------------------------------------------------
void __fastcall TInterface::Button2Click(TObject *Sender)
{
    Application->Terminate();    
}

//---------------------------------------------------------------------------
void __fastcall TInterface::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    UnhookWindowsHookEx(hook);
}

//---------------------------------------------------------------------------
extern "C" __export LRESULT CALLBACK KeyHookProc(int nCode,WPARAM wParam,LPARAM lParam)
{

    if  ((nCode == HC_ACTION) && ((wParam == WM_SYSKEYDOWN) || (wParam == WM_KEYDOWN)))
    {
        KBDLLHOOKSTRUCT hooked = *((KBDLLHOOKSTRUCT*)lParam);

    }

    return CallNextHookEx(hook,nCode,wParam,lParam);
}

