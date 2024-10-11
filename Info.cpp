
using namespace std;
class Info{
    private :
    string  ten, dienThoai, diaChi, email;
    public :
    string getTen() {
        return ten;
    }
    string getDienThoai(){
        return dienThoai;
    }
    string getDiaChi(){
        return diaChi;
    }
    string getEmail(){
        return email;
    }
    void setThongTin(string username){
        string fn = username + ".txt";
        ifstream in (fn);
        cin>>ten>>dienThoai>>diaChi>>email;
    }

};
