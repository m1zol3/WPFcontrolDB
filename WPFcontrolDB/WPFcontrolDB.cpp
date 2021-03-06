

using namespace System;
using namespace System::Windows;
using namespace System::Windows::Controls;
using namespace System::Windows::Media;
using namespace System::Runtime;
#include "stdafx.h"

#include "WPFcontrolDB.h"
//#include <gcroot.h>
#define MAX_LOADSTRING 100
// Globale Variablen:
HINSTANCE hInst; // Aktuelle Instanz
WCHAR szTitle[MAX_LOADSTRING]; // Titelleistentext
WCHAR szWindowClass[MAX_LOADSTRING]; // Klassenname des Hauptfensters
// Vorwärtsdeklarationen der in diesem Codemodul enthaltenen Funktionen:
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);
HWND wpfHwnd; //The hwnd associated with the hosted WPF page

[System::STAThreadAttribute] //Needs to be an STA thread to play nicely with WPF
int APIENTRY _tWinMain(HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPTSTR    lpCmdLine,
    int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Hier Code einfügen.
    // Globale Zeichenfolgen initialisieren

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WPFCONTROLDB, szWindowClass, MAX_LOADSTRING);

    MyRegisterClass(hInstance);
    // Anwendungsinitialisierung ausführen:
    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WPFCONTROLDB));
    MSG msg;

    // Hauptnachrichtenschleife:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int)msg.wParam;
}
//
// FUNKTION: MyRegisterClass()
//
// ZWECK: Registriert die Fensterklasse.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;
    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WPFCONTROLDB));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_WPFCONTROLDB);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}
//
// FUNKTION: InitInstance(HINSTANCE, int)
//
// ZWECK: Speichert das Instanzenhandle und erstellt das Hauptfenster.
//
// KOMMENTARE:
//
// In dieser Funktion wird das Instanzenhandle in einer globalen Variablen gespeichert, und das
// Hauptprogrammfenster wird erstellt und angezeigt.
//

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance; // Instanzenhandle in der globalen Variablen speichern
    HWND hWnd = CreateWindowW(szWindowClass,       // global string containing name of window class
        szTitle,             // global string containing title bar text
        WS_OVERLAPPEDWINDOW,  // window styles
        CW_USEDEFAULT,         // default horizontal position
        CW_USEDEFAULT,         // default vertical position
        CW_USEDEFAULT,         // default width
        CW_USEDEFAULT,         // default height
        (HWND)NULL,           // no parent for overlapped windows
        (HMENU)NULL,          // use the window class menu
        hInstance,               // global instance handle
        (PVOID)NULL           // pointer not needed
    );

    if (!hWnd)
    {
        return FALSE;
    }
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
    return TRUE;
}
//
// FUNKTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
// ZWECK: Verarbeitet Meldungen vom Hauptfenster.
//
// WM_COMMAND - Verarbeiten des Anwendungsmenüs
// WM_PAINT - Darstellen des Hauptfensters
// WM_DESTROY - Ausgeben einer Beendenmeldung und zurückkehren
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
        GetClientRect(hWnd, &rect);
        wpfHwnd = GetHwnd(hWnd, rect.left + 10, 10, 600, 600);
        //CreateDataDisplay(hWnd, 275, rect.right - 375, 375);
        break;
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        // Menüauswahl bearbeiten:
        switch (wmId)
        {
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        //TODO: Zeichencode, der hdc verwendet, hier einfügen...
        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}
// Meldungshandler für Infofeld.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

WPFPageHost::WPFPageHost() {}
HWND GetHwnd(HWND parent, int x, int y, int width, int height)
{
    System::Windows::Interop::HwndSourceParameters^ sourceParams = gcnew System::Windows::Interop::HwndSourceParameters(
        "hi" // NAME
    );
    sourceParams->PositionX = x;
    sourceParams->PositionY = y;
    sourceParams->Height = height;
    sourceParams->Width = width;
    sourceParams->ParentWindow = IntPtr(parent);
    sourceParams->WindowStyle = WS_VISIBLE | WS_CHILD; // style
    System::Windows::Interop::HwndSource^ source = gcnew System::Windows::Interop::HwndSource(*sourceParams);
    pageWPF ^myPage = gcnew pageWPF(width, height);

    //Assign a reference to the WPF page and a set of UI properties to a set of static properties in a class
    //that is designed for that purpose.
    WPFPageHost::hostedPage = myPage;
    myPage->OnButtonClicked += gcnew pageWPF::ButtonClickHandler(WPFButtonClicked);
    myPage->OnItemChange += gcnew pageWPF::ItemChangeHandler(WPFItemChanged);
    source->RootVisual = myPage;
    return (HWND)source->Handle.ToPointer();
}
HWND CreateAHorizontalScrollBar(HWND hwndParent, int sbHeight)
{
    RECT rect;

    // Get the dimensions of the parent window's client area;
    if (!GetClientRect(hwndParent, &rect))
        return NULL;

    // Create the scroll bar.
    return (CreateWindowEx(
        0,                      // no extended styles
        L"SCROLLBAR",           // scroll bar control class
        (PTSTR)NULL,           // no window text
        WS_CHILD | WS_VISIBLE   // window styles
        | SBS_HORZ,         // horizontal scroll bar style
        rect.left,              // horizontal position
        rect.bottom, // vertical position
        rect.right,             // width of the scroll bar
        sbHeight,               // height of the scroll bar
        hwndParent,             // handle to main window
        (HMENU)NULL,           // no menu
        hInst,                // instance owning this window
        (PVOID)NULL            // pointer not needed
    ));
}

void CreateDataDisplay(HWND hWnd, int top, int left, int width)
{
    dataDisplayLabel = CreateWindowEx(0, L"static", L"Data From WPF Control",
        WS_CHILD | WS_VISIBLE | SS_LEFT,
        left, top + 25,
        width, 25,
        hWnd,
        (HMENU)1,
        hInst,
        NULL);

    nameLabel = CreateWindowEx(0, L"static", L"Nachname: ",
        WS_CHILD | WS_VISIBLE | SS_LEFT,
        left+100, top + 60,
        width, 25,
        hWnd,
        (HMENU)1,
        hInst,
        NULL);
}

void WPFButtonClicked(Object ^sender, DBPageEventArgs ^args)
{
    pageWPF ^myPage = WPFPageHost::hostedPage;
    if (args->isOkay) //display data if OK button was clicked
    { //S
        
        myPage->myText->Text = "test";
 
    }
    else
    {
   
    }
}

void WPFItemChanged(Object ^ sender, DBPageEventArgs ^ args)
{
    
    pageWPF ^myPage = WPFPageHost::hostedPage;
    if (args->isChange) //display data if OK button was clicked
    { //S

        myPage->myText->Text = "test 7";

    }
    else
    {
        myPage->myText->Text = "geht nicht";

    }

}

 