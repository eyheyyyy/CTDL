
using namespace std;

class Employee{
    private :
    string username, password;
    Info thongtin;
    public :
    string getUsername() {return username;}
    string getPassword() {return password;}
    Info getThongTin() {return thongtin;}
    void setUsername(string _username) { username = _username;}
    void setPassword (string _password) {password = _password;}
    void setThongTin() {thongtin.setThongtin;}
    void Thoat() {return EXIT_SUCCESS;}
    Info XemThongTin();
    void DoiPassWord(string);

};
