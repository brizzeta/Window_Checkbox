#include <windows.h>
#include <tchar.h>
#include <cmath>
#include <commctrl.h>
#include "resource.h"

HWND edit[4], hSpin1, hSpin2, hProg;

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
        edit[0] = GetDlgItem(hWnd, IDC_EDIT1);
        edit[1] = GetDlgItem(hWnd, IDC_EDIT2);
        edit[2] = GetDlgItem(hWnd, IDC_EDIT3);
        edit[3] = GetDlgItem(hWnd, IDC_EDIT4);
        hSpin1 = GetDlgItem(hWnd, IDC_SPIN1);
        hSpin2 = GetDlgItem(hWnd, IDC_SPIN2);
        hProg = GetDlgItem(hWnd, IDC_PROGRESS1);
        SendMessage(hSpin1, UDM_SETRANGE32, 0, 1000);
        SendMessage(hSpin2, UDM_SETRANGE32, 0, 100);
        SendMessage(hProg, PBM_SETBKCOLOR, 0, LPARAM(RGB(0, 214, 120)));
        SendMessage(hProg, PBM_SETBARCOLOR, 0,  LPARAM(RGB(255, 255, 0)));
        return TRUE;

    case WM_COMMAND:
    {
        if (wp == IDC_BUTTON1) //���� ������ ������ "���������"
        {
            TCHAR str[20];
            double answer = 0;

            //�������� radio
            LRESULT res_radio[7] =
            {
                SendDlgItemMessage(hWnd, IDC_RADIO1, BM_GETCHECK, 0, 0),
                SendDlgItemMessage(hWnd, IDC_RADIO4, BM_GETCHECK, 0, 0),
                SendDlgItemMessage(hWnd, IDC_RADIO6, BM_GETCHECK, 0, 0),
                SendDlgItemMessage(hWnd, IDC_RADIO8, BM_GETCHECK, 0, 0),
                SendDlgItemMessage(hWnd, IDC_RADIO11, BM_GETCHECK, 0, 0),
                SendDlgItemMessage(hWnd, IDC_RADIO13, BM_GETCHECK, 0, 0),
                SendDlgItemMessage(hWnd, IDC_RADIO17, BM_GETCHECK, 0, 0)
            };
            for (int i = 0; i < 7; i++)
            {
                if (res_radio[i] == BST_CHECKED)
                {
                    answer += 7.1;
                }
            }

            //�������� check
            LRESULT res_check[8] =
            {
                SendDlgItemMessage(hWnd, IDC_CHECK1, BM_GETCHECK, 0, 0),
                SendDlgItemMessage(hWnd, IDC_CHECK2, BM_GETCHECK, 0, 0),
                SendDlgItemMessage(hWnd, IDC_CHECK3, BM_GETCHECK, 0, 0),
                SendDlgItemMessage(hWnd, IDC_CHECK4, BM_GETCHECK, 0, 0),
                SendDlgItemMessage(hWnd, IDC_CHECK5, BM_GETCHECK, 0, 0),
                SendDlgItemMessage(hWnd, IDC_CHECK8, BM_GETCHECK, 0, 0),
                SendDlgItemMessage(hWnd, IDC_CHECK9, BM_GETCHECK, 0, 0),
                SendDlgItemMessage(hWnd, IDC_CHECK12, BM_GETCHECK, 0, 0)
            };

            for (int i = 0; i < 8; i++)
            {
                if (res_check[i] == BST_CHECKED && i < 6)
                {
                    answer += 2.4;
                }
                else if (res_check[i] == BST_CHECKED)
                {
                    answer += 3.6;
                }
            }

            //�������� edit
            TCHAR answ[][7] =
            {
                TEXT("������"),
                TEXT("15"),
                TEXT("112"),
                TEXT("8")
            };
            TCHAR text[4][10];

            for (int i = 0; i < 4; i++)
            {
                GetWindowText(edit[i], text[i], 10);
                if (!lstrcmpi(answ[i], text[i]))
                {
                    answer += 7.1;
                }
            }

            //����� ���������� � progress control
            answer = round(answer);
            SendMessage(hProg, PBM_SETPOS, WPARAM(answer), 0);            
        }

        //���� ������ ����� ���� "�����"
        if (wp == ID_40001)
        {
            EndDialog(hWnd, 0);
        }
    }
        return TRUE;
    case WM_CLOSE:
        EndDialog(hWnd, 0);
        return TRUE;
    }
    return FALSE;
}