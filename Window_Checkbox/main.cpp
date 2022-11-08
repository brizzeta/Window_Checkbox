#include <windows.h>
#include <tchar.h>
#include <cmath>
#include "resource.h"

HWND edit1, edit2;

BOOL CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPTSTR lpszCmdLine, int nCmdShow)
{
    return  DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, (DLGPROC)DlgProc);
}

BOOL CALLBACK DlgProc(HWND hWnd, UINT message, WPARAM wp, LPARAM lp)
{
    switch (message)
    {
    case WM_INITDIALOG:
        edit1 = GetDlgItem(hWnd, IDC_EDIT1);
        edit2 = GetDlgItem(hWnd, IDC_EDIT2);
        return TRUE;
    case WM_COMMAND:
        if (wp == IDC_BUTTON1)
        {
            TCHAR str[20];
            TCHAR answ1[] = TEXT("Медуза"), answ2[] = TEXT("15");
            TCHAR text1[10], text2[10];
            double answer = 0;

            LRESULT res = SendDlgItemMessage(hWnd, IDC_RADIO1, BM_GETCHECK, 0, 0);
            if (res == BST_CHECKED)
            {
                answer += 8.3;
            }

            res = SendDlgItemMessage(hWnd, IDC_RADIO4, BM_GETCHECK, 0, 0);
            if (res == BST_CHECKED)
            {
                answer += 8.3;
            }

            res = SendDlgItemMessage(hWnd, IDC_RADIO6, BM_GETCHECK, 0, 0);
            if (res == BST_CHECKED)
            {
                answer += 8.3;
            }

            res = SendDlgItemMessage(hWnd, IDC_RADIO8, BM_GETCHECK, 0, 0);
            if (res == BST_CHECKED)
            {
                answer += 8.3;
            }

            res = SendDlgItemMessage(hWnd, IDC_RADIO11, BM_GETCHECK, 0, 0);
            if (res == BST_CHECKED)
            {
                answer += 8.3;
            }

            res = SendDlgItemMessage(hWnd, IDC_RADIO13, BM_GETCHECK, 0, 0);
            if (res == BST_CHECKED)
            {
                answer += 8.3;
            }

            res = SendDlgItemMessage(hWnd, IDC_RADIO17, BM_GETCHECK, 0, 0);
            if (res == BST_CHECKED)
            {
                answer += 8.3;
            }

            res = SendDlgItemMessage(hWnd, IDC_CHECK1, BM_GETCHECK, 0, 0);
            if (res == BST_CHECKED)
            {
                answer += 2.8;
            }

            res = SendDlgItemMessage(hWnd, IDC_CHECK2, BM_GETCHECK, 0, 0);
            if (res == BST_CHECKED)
            {
                answer += 2.8;
            }

            res = SendDlgItemMessage(hWnd, IDC_CHECK3, BM_GETCHECK, 0, 0);
            if (res == BST_CHECKED)
            {
                answer += 2.8;
            }

            res = SendDlgItemMessage(hWnd, IDC_CHECK4, BM_GETCHECK, 0, 0);
            if (res == BST_CHECKED)
            {
                answer += 2.8;
            }

            res = SendDlgItemMessage(hWnd, IDC_CHECK5, BM_GETCHECK, 0, 0);
            if (res == BST_CHECKED)
            {
                answer += 2.8;
            }

            res = SendDlgItemMessage(hWnd, IDC_CHECK8, BM_GETCHECK, 0, 0);
            if (res == BST_CHECKED)
            {
                answer += 2.8;
            }

            res = SendDlgItemMessage(hWnd, IDC_CHECK9, BM_GETCHECK, 0, 0);
            if (res == BST_CHECKED)
            {
                answer += 4.2;
            }

            res = SendDlgItemMessage(hWnd, IDC_CHECK12, BM_GETCHECK, 0, 0);
            if (res == BST_CHECKED)
            {
                answer += 4.2;
            }

            GetWindowText(edit1, text1, 10);
            GetWindowText(edit2, text2, 10);
            if (!lstrcmpi(answ1, text1))
            {
                answer += 8.3;
            }
            if (!lstrcmpi(answ2, text2))
            {
                answer += 8.3;
            }

            answer = ceil(answer);
            _stprintf_s(str, TEXT("Results: %i"), (int)answer);
            MessageBox(
                hWnd,
                str,
                TEXT("Results"),
                MB_OK
            );
        }
        return TRUE;
    case WM_CLOSE:
        EndDialog(hWnd, 0);
        return TRUE;
    }
    return FALSE;
}