#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

class Info {
private:
    string ten, dienThoai, diaChi, email;

public:
    string getTen() const {
        return ten;
    }

    string getDienThoai() const {
        return dienThoai;
    }

    string getDiaChi() const {
        return diaChi;
    }

    string getEmail() const {
        return email;
    }

    void setThongTin(const string& filename) {
        ifstream in(filename);
        if (!in) {
            cout<<"Không thể mở file người dùng";
            return;
        }
        getline(in, ten);
        getline(in, dienThoai);
        getline(in, diaChi);
        getline(in, email);
        in.close();
    }

    void XemThongTin() const {
        string thongTin = "Tên: " + ten + "\n"
            + "Điện thoại: " + dienThoai + "\n"
            + "Địa chỉ: " + diaChi + "\n"
            + "Email: " + email;
        cout<<"Thông tin của người dùng "<<ten<<":";
        cout<<thongTin;
    }
};

template <class T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(const T& data) : data(data), next(nullptr) {}
};

template <class T>
class DanhSach {
private:
    Node<T>* Dau;
    Node<T>* Cuoi;
    int SoLuong;

public:
    DanhSach() : SoLuong(0), Dau(nullptr), Cuoi(nullptr) {}

    void XayDanhSach(const T& item) {
        Dau = Cuoi = new Node<T>(item);
        SoLuong = 1;
    }

    void DocDanhSach() {
        ifstream file("Employees.txt");
        if (!file) {
            cout<<"Không thể mở file Employees.txt";
            return;
        }

        string username;
        while (file >> username) {
            Info newInfo;
            newInfo.setThongTin(username + ".txt");
            Them(newInfo);
        }

        file.close();
    }

    void HuyDanhSach() {
        while (Dau != nullptr) {
            Node<T>* temp = Dau;
            Dau = Dau->next;
            delete temp;
        }
        SoLuong = 0;
    }

    void Them(const T& item) {
        Node<T>* newNode = new Node<T>(item);
        if (SoLuong == 0) {
            Dau = Cuoi = newNode;
        }
        else {
            Cuoi->next = newNode;
            Cuoi = newNode;
        }
        SoLuong++;
    }

    void Xoa(const string& tenNguoiDung) {
        if (SoLuong == 0) return;

        Node<T>* current = Dau;
        Node<T>* previous = nullptr;

        while (current != nullptr) {
            if (current->data.getTen() == tenNguoiDung) {
                if (previous == nullptr) {
                    Dau = current->next;
                }
                else {
                    previous->next = current->next;
                }
                if (current == Cuoi) {
                    Cuoi = previous;
                }
                delete current;
                SoLuong--;
                return;
            }
            previous = current;
            current = current->next;
        }
    }

    void CapNhat(const string& tenNguoiDung, const T& newInfo) {
        Node<T>* current = Dau;
        while (current != nullptr) {
            if (current->data.getTen() == tenNguoiDung) {
                current->data.setThongTin(newInfo);
                return;
            }
            current = current->next;
        }
    }

    void DangNhap(const string& tenNguoiDung) {
    Node<T>* user = Tim(tenNguoiDung); 
    int soLanSai=0;
    if (user != nullptr) {
        string filePassword;
        ifstream file;
        file.open("Administrators.txt");
        while (file >> tenNguoiDung >> filePassword) {
            if (user->data.getTen() == tenNguoiDung) {
                break; 
            }
        }
        file.close();
        if (file.eof()) {
            file.open("Employees.txt");
            while (file >> tenNguoiDung >> filePassword) {
                if (user->data.getTen() == tenNguoiDung) {
                    break; 
                }
            }
            file.close();
        }
        string matKhauNhap;
        cout << "Nhập mật khẩu: ";
        cin >> matKhauNhap;

        if (matKhauNhap == filePassword) {
           cout<<"Đăng nhập thành công";
        }
        else {
            cout<<"Sai mật khẩu";
            soLanSai++;
        }
    }
    else {
       cout<<"Không tìm thấy người dùng";
    }
    }

    Node<T>* Tim(const string& tenNguoiDung) {
        Node<T>* current = Dau;
        while (current != nullptr) {
            if (current->data.getTen() == tenNguoiDung) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    int getSoLuong() const { return SoLuong; }

    ~DanhSach() {
        HuyDanhSach();
    }
};

int main() {
    DanhSach<Info> ds;
    ds.DocDanhSach();

    string username;
    ds.DangNhap(username);

    return 0;
}
