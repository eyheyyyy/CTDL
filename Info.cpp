
using namespace std;
class Info{
    private :
    string  ten, dienThoai, diaChi, email;
    public :
    string getTen() {
        return ten;
    }

    void setThongTin(string username){
        string fn = username + ".txt";
        ifstream in (fn);
        cin>>ten>>dienThoai>>diaChi>>email;
    }

};
