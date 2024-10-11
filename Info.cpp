
using namespace std;
class Info{
    private :
    string  ten, dienThoai, diaChi, email;
    public :
    string getTen() {
        return ten;
    }

    void setTen(string tenMoi) {
        ten = tenMoi;
    }

    string getDienThoai() {
        return dienThoai;
    }

    void setDienThoai(string soDienThoaiMoi) {
        dienThoai = soDienThoaiMoi;
    }

    string getDiaChi() {
        return diaChi;
    }

    void setDiaChi(string diaChiMoi) {
        diaChi = diaChiMoi;
    }

    string getEmail() {
        return email;
    }

    void setEmail(string emailMoi) {
        email = emailMoi;
    }

};
