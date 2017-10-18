// 204AssignmentGUI.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "204AssignmentGUI.h"
#include "operationFuncs.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Define Views
HWND tBoxInp;
HWND lblRes; 
HWND btnConvert;
HWND lblOperation; 
HWND radioIntToBin;
HWND radioBinToInt;
HWND radioFloatToBin;
HWND radioBinToFloat;
int currOperation=1; 
char* operations[4] = { "Integer to Binary", "Binary to Integer", "Float to Binary", "Binary to Float" };

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY204ASSIGNMENTGUI, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY204ASSIGNMENTGUI));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY204ASSIGNMENTGUI));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY204ASSIGNMENTGUI);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, (LPCWSTR)"204 Assignment", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	const int i_text = 1, i_quit = 2, cmndButton=3, cmndRadioIntToBin = 4, cmndRadioBinToInt = 5,
		cmndRadioFloatToBin = 6, cmndRadioBinToFloat = 7;
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;

			case cmndButton:
				switch (currOperation) {
				case 1 :

					break; 

				case 2 : 

					break;

				case 3 : 

					break; 

				case 4 : 

					break; 
				}
				break;

			case cmndRadioIntToBin:
				switch (HIWORD(wParam)) {
					case BN_CLICKED:
						if (SendDlgItemMessage(hWnd, cmndRadioIntToBin, BM_GETCHECK, 0, 0) == 0) {
							SendDlgItemMessage(hWnd, cmndRadioIntToBin, BM_SETCHECK, 1, 0);
							SendDlgItemMessage(hWnd, cmndRadioBinToInt, BM_SETCHECK, 0, 0);
							SendDlgItemMessage(hWnd, cmndRadioFloatToBin, BM_SETCHECK, 0, 0);
							SendDlgItemMessage(hWnd, cmndRadioBinToFloat, BM_SETCHECK, 0, 0);
						}
					break;
				}

				SetWindowText(lblOperation, operations[0]);
				currOperation = 1;
			break;

			case cmndRadioBinToInt:
				switch (HIWORD(wParam)) {
				case BN_CLICKED:
					if (SendDlgItemMessage(hWnd, cmndRadioBinToInt, BM_GETCHECK, 0, 0) == 0) {
						SendDlgItemMessage(hWnd, cmndRadioBinToInt, BM_SETCHECK, 1, 0);
						SendDlgItemMessage(hWnd, cmndRadioIntToBin, BM_SETCHECK, 0, 0);
						SendDlgItemMessage(hWnd, cmndRadioFloatToBin, BM_SETCHECK, 0, 0);
						SendDlgItemMessage(hWnd, cmndRadioBinToFloat, BM_SETCHECK, 0, 0);
					}
					break;
				}

				SetWindowText(lblOperation, operations[1]);
				currOperation = 2;
			break;

			case cmndRadioFloatToBin:
				switch (HIWORD(wParam)) {
				case BN_CLICKED:
					if (SendDlgItemMessage(hWnd, cmndRadioFloatToBin, BM_GETCHECK, 0, 0) == 0) {
						SendDlgItemMessage(hWnd, cmndRadioFloatToBin, BM_SETCHECK, 1, 0);
						SendDlgItemMessage(hWnd, cmndRadioIntToBin, BM_SETCHECK, 0, 0);
						SendDlgItemMessage(hWnd, cmndRadioBinToInt, BM_SETCHECK, 0, 0);
						SendDlgItemMessage(hWnd, cmndRadioBinToFloat, BM_SETCHECK, 0, 0);
					}
					break;
				}

				SetWindowText(lblOperation, operations[2]);
				currOperation = 3;
			break;

			case cmndRadioBinToFloat:
				switch (HIWORD(wParam)) {
				case BN_CLICKED:
					if (SendDlgItemMessage(hWnd, cmndRadioBinToFloat, BM_GETCHECK, 0, 0) == 0) {
						SendDlgItemMessage(hWnd, cmndRadioBinToFloat, BM_SETCHECK, 1, 0);
						SendDlgItemMessage(hWnd, cmndRadioIntToBin, BM_SETCHECK, 0, 0);
						SendDlgItemMessage(hWnd, cmndRadioBinToInt, BM_SETCHECK, 0, 0);
						SendDlgItemMessage(hWnd, cmndRadioFloatToBin, BM_SETCHECK, 0, 0);
					}
					break;
				}

				SetWindowText(lblOperation, operations[3]);
				currOperation = 4;
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
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
		
	case WM_CREATE:
		//HINSTANCE hInstance = (HINSTANCE)GetWindowLong(hWnd, GWL_HINSTANCE);
		lblOperation = CreateWindow(TEXT("STATIC"),(LPCSTR) operations[0], WS_VISIBLE | WS_CHILD, 10, 10, 200, 20, hWnd, NULL, NULL, NULL);
		tBoxInp = CreateWindow(TEXT("EDIT"), TEXT("Integer"), WS_VISIBLE | WS_BORDER | WS_CHILD | ES_AUTOHSCROLL, 10, 50, 200, 25, hWnd, (HMENU)i_text, NULL, NULL);
		lblRes = CreateWindow(TEXT("STATIC"), TEXT(""), WS_VISIBLE | WS_CHILD | ES_AUTOHSCROLL, 220, 50, 200, 25, hWnd, (HMENU)i_text, NULL, NULL);
		radioIntToBin = CreateWindowEx(0, "BUTTON", operations[0], WS_VISIBLE | WS_CHILD | BS_RADIOBUTTON, 450, 10, 150, 25, hWnd, (HMENU)cmndRadioIntToBin, NULL, NULL);
		radioBinToInt = CreateWindowEx(0,"BUTTON", operations[1], WS_VISIBLE | WS_CHILD | BS_RADIOBUTTON,450, 45, 150, 25, hWnd, (HMENU)cmndRadioBinToInt, NULL, NULL);
		radioFloatToBin = CreateWindowEx(0, "BUTTON", operations[2], WS_VISIBLE | WS_CHILD | BS_RADIOBUTTON, 450, 80, 150, 25, hWnd, (HMENU)cmndRadioFloatToBin, NULL, NULL);
		radioBinToFloat = CreateWindowEx(0, "BUTTON", operations[3], WS_VISIBLE | WS_CHILD | BS_RADIOBUTTON, 450, 115, 150, 25, hWnd, (HMENU)cmndRadioBinToFloat, NULL, NULL);
		btnConvert = CreateWindow(TEXT("button"), TEXT("Convert"), WS_VISIBLE | WS_CHILD, 65, 115, 200, 25, hWnd, (HMENU)cmndButton, NULL, NULL);
		if (SendDlgItemMessage(hWnd, cmndRadioIntToBin, BM_GETCHECK, 0, 0) == 0) {
			SendDlgItemMessage(hWnd, cmndRadioIntToBin, BM_SETCHECK, 1, 0);
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

// Message handler for about box.
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
