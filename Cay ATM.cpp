#include <iostream>
using namespace std;
void rut_tien(int so_du,int so_tien_rut)
{
    if (so_du - so_tien_rut >= 50000)
    {
        so_du -= so_tien_rut;
        cout << "So tien con lai la: " << so_du << endl;
        int n = so_tien_rut / 500000;
        cout << n << " to 500000 dong" << endl;
        so_tien_rut = so_tien_rut % 500000;
        n = so_tien_rut / 200000;
        cout << n << " to 200000 dong" << endl;
        so_tien_rut = so_tien_rut % 200000;
        n = so_tien_rut / 100000;
        cout << n << " to 100000 dong" << endl;
        so_tien_rut = so_tien_rut % 100000;
        n = so_tien_rut / 50000;
        cout << n << " to 50000 dong" << endl;
        so_tien_rut = so_tien_rut % 50000;
        n = so_tien_rut / 20000;
        cout << n << " to 20000 dong" << endl;
        so_tien_rut = so_tien_rut % 20000;
        n = so_tien_rut / 10000;
        cout << n << " to 10000 dong" << endl;
        
    }
    else cout << "So du khong du! Giao dich that bai";
}
int menu()
{
    cout << "**********MENU**********" << endl;
    cout << "1.Gui tien vao tai khoan" << endl;
    cout << "2.Rut tien" << endl;
    cout << "3.Kiem tra so tien con lai" << endl;
    cout << "4.Thoat" << endl;
    cout<<"************************" << endl;
    cout << "*Nhap vao so cua thao tac muon thuc hien:";
    int choice;
    cin >> choice;
    return choice;
}
int main()
{
    string mat_khau = "123456";
    int so_tien = 10000000;
    int so_lan_sai = 0;
    int so_giao_dich = 0;
    while (so_lan_sai < 3)
    {
        if (so_lan_sai == 0) cout << "Vui long nhap mat khau:";
        else
        {
            if (so_lan_sai < 3 && so_lan_sai>0) cout << "Mat khau sai, vui long nhap lai mat khau:";
            
        }
        string nhap_mat_khau;
        cin >> nhap_mat_khau;
        if (nhap_mat_khau == mat_khau) break;
        else so_lan_sai++;
        if(so_lan_sai==3) cout << "Nhap sai qua so lan quy dinh! Dang nhap that bai!";
    }
    if (so_lan_sai < 3)
    {
        so_lan_sai = 0;
        while (so_lan_sai < 3)
        {
            switch (menu())
            {
            case  1:
            {
                cout << "Vui long nhap so tien muon gui:";
                int money;
                cin >> money;
                if (money > 0 && money % 10000 == 0)
                {
                    so_tien += money;
                    cout << "Giao dich thanh cong.";
                    so_lan_sai = 3;
                    so_giao_dich = 1;
                }
                else
                {
                    cout << "Giao dich that bai!"<<endl;
                    if(so_lan_sai<2) cout << "Vui long thuc hien lai giao dich!"<<endl;
                    so_lan_sai++;
                }
                break;
            }
            case 2:
            {
                cout << "Vui long nhap so tien muon rut:";
                int money;
                cin >> money;
                if (money > 0 && money % 10000 == 0)
                {
                    rut_tien(so_tien, money);
                    so_tien -= money;
                    cout << "Giao dich thanh cong.";
                    so_lan_sai = 3;
                    so_giao_dich = 1;
                    break;
                }
                else
                {
                    so_lan_sai++;
                    cout << "Giao dich that bai!"<<endl;
                    if (so_lan_sai < 2) cout << "Vui long thuc hien lai giao dich!" << endl;
                    break;
                }
            }
            case 3:
            {
                cout << "So tien con lai la: " << so_tien;
                so_lan_sai = 3;
                so_giao_dich = 1;
                break;
            }
            case 4:
            {
                so_lan_sai = 3;
                so_giao_dich = 1;
                break;
            }
            default:
            {
                so_lan_sai++;
                if (so_lan_sai < 2) cout << "Vui long chon lai thao tac!" << endl;
                break;
            }
            }
        }
    }
    if (so_lan_sai == 3 && so_giao_dich == 0) cout << "Vui long dang nhap lai!";
    else cout << "Cam on quy khach.";
    return 0;
}

