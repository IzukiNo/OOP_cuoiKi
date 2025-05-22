#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void cls() { cout << "\033[2J\033[1;1H"; }

class cauThu
{
private:
    string ten;
    string quocTich;
    int tuoi;
    int soAo;

protected:
    int kyNangChuyen;
    int kyNangSut;
    string viTri;

public:
    virtual ~cauThu() {}
    cauThu(string ten = "", int tuoi = 0, int soAo = 0, string quocTich = "", string viTri = "") : ten(ten), tuoi(tuoi), soAo(soAo), quocTich(quocTich), viTri(viTri)
    {
        this->kyNangChuyen = 50;
        this->kyNangSut = 50;
    }
    cauThu(const cauThu &other) : ten(other.ten), quocTich(other.quocTich), tuoi(other.tuoi), soAo(other.soAo), viTri(other.viTri)
    {
        this->kyNangChuyen = other.kyNangChuyen;
        this->kyNangSut = other.kyNangSut;
    }
    cauThu &operator=(const cauThu &other)
    {
        if (this != &other)
        {
            ten = other.ten;
            quocTich = other.quocTich;
            tuoi = other.tuoi;
            soAo = other.soAo;
            viTri = other.viTri;
            kyNangChuyen = other.kyNangChuyen;
            kyNangSut = other.kyNangSut;
        }
        return *this;
    }
    friend istream &operator>>(istream &in, cauThu &ct)
    {
        cout << "Nhap ho ten: ";
        in.ignore();
        getline(in, ct.ten);
        cout << "Nhap tuoi: ";
        in >> ct.tuoi;
        in.ignore();
        cout << "Nhap so ao: ";
        in >> ct.soAo;
        in.ignore();
        cout << "Nhap quoc tich: ";
        getline(in, ct.quocTich);
        return in;
    }
    friend ostream &operator<<(ostream &out, const cauThu &ct)
    {
        cout << left;
        cout << setw(16) << "Ten" << ": " << ct.ten << "\n";
        cout << setw(16) << "Quoc tich" << ": " << ct.quocTich << "\n";
        cout << setw(16) << "Tuoi" << ": " << ct.tuoi << "\n";
        cout << setw(16) << "So ao" << ": " << ct.soAo << "\n";
        cout << setw(16) << "Vi tri" << ": " << ct.viTri << "\n";
        cout << "----------------------------------------\n";
        return out;
    }

    string getQuocTich() const { return quocTich; }
    string getViTri() const { return viTri; }
    string getTen() const { return ten; }
    int getTuoi() const { return tuoi; }
    int getSoAo() const { return soAo; }

    static void displayHeader()
    {
        cout << "----------------------------------------\n";
        cout << "          THONG TIN CAU THU\n";
        cout << "----------------------------------------\n";
    };
    virtual void thongTin()
    {
        cout << *this;
    }
    virtual void chiSo()
    {
        cout << setw(16) << "Ky nang chuyen" << ": " << kyNangChuyen << "★" << endl;
        cout << setw(16) << "Ky nang sut" << ": " << kyNangSut << "★" << endl;
    }

    void displayAll()
    {
        displayHeader();
        thongTin();
        chiSo();
    }

    virtual void nhapThongTin()
    {
        cin >> *this;
    }
    virtual void thiDau() = 0;
};

class thuMon : public cauThu
{
protected:
    int kyNangChup;
    int khaNangPhanXa;

public:
    ~thuMon() {}
    thuMon(string ten = "", int tuoi = 0, int soAo = 0, string quocTich = "") : cauThu(ten, tuoi, soAo, quocTich, "Thu Mon")
    {
        this->kyNangChup = 50;
        this->khaNangPhanXa = 50;
    }
    thuMon(const thuMon &other) : cauThu(other)
    {
        this->kyNangChup = other.kyNangChup;
        this->khaNangPhanXa = other.khaNangPhanXa;
    }
    thuMon &operator=(const thuMon &other)
    {
        if (this != &other)
        {
            cauThu::operator=(other);
            this->kyNangChup = other.kyNangChup;
            this->khaNangPhanXa = other.khaNangPhanXa;
        }
        return *this;
    }
    friend istream &operator>>(istream &in, thuMon &tm)
    {
        in >> (cauThu &)tm;
        return in;
    }
    friend ostream &operator<<(ostream &out, const thuMon &tm)
    {
        out << (cauThu &)tm;
        return out;
    }

    void chiSo()
    {
        cauThu::chiSo();
        cout << setw(16) << "Ky nang chup" << ": " << kyNangChup << "★" << endl;
        cout << setw(16) << "Ky nang phan xa" << ": " << khaNangPhanXa << "★" << endl;
        cout << "----------------------------------------\n";
    }
    void thiDau() override
    {
        cout << "Thu mon " << getTen() << " chup banh!" << endl;
        cout << "Ky nang chup +1 ( " << ++kyNangChup << "★ )" << endl;
        cout << "Ky nang phan xa +2 ( " << khaNangPhanXa + 2 << "★ )" << endl;
        khaNangPhanXa = khaNangPhanXa + 2;
    }
};
class hauVe : public cauThu
{
protected:
    int kyNangTranhChap;
    int kyNangLayBanh;

public:
    ~hauVe() {};
    hauVe(string ten = "", int tuoi = 0, int soAo = 0, string quocTich = "") : cauThu(ten, tuoi, soAo, quocTich, "Hau Ve")
    {
        this->kyNangTranhChap = 50;
        this->kyNangLayBanh = 50;
    }
    hauVe(const hauVe &other) : cauThu(other)
    {
        this->kyNangTranhChap = other.kyNangTranhChap;
        this->kyNangLayBanh = other.kyNangLayBanh;
    }
    hauVe &operator=(const hauVe &other)
    {
        if (this != &other)
        {
            cauThu::operator=(other);
            this->kyNangTranhChap = other.kyNangTranhChap;
            this->kyNangLayBanh = other.kyNangLayBanh;
        }
        return *this;
    }
    friend istream &operator>>(istream &in, hauVe &tm)
    {
        in >> (cauThu &)tm;
        return in;
    }
    friend ostream &operator<<(ostream &out, const hauVe &tm)
    {
        out << (cauThu &)tm;
        return out;
    }

    void chiSo()
    {
        cauThu::chiSo();
        cout << "Ky nang tranh chap: " << kyNangTranhChap << "★" << endl;
        cout << "Ky nang lay banh: " << kyNangLayBanh << "★" << endl;
    }
    void thiDau() override
    {
        cout << "Hau ve " << getTen() << " lay banh!" << endl;
        cout << "Ky nang lay banh +1 ( " << ++kyNangLayBanh << "★ )" << endl;
    }
};
class tienVe : public cauThu
{
protected:
    int kyNangChuyenXa;
    int kyNangSutXa;

public:
    ~tienVe() {}
    tienVe(string ten = "", int tuoi = 0, int soAo = 0, string quocTich = "") : cauThu(ten, tuoi, soAo, quocTich, "Tien Ve")
    {
        this->kyNangChuyenXa = 50;
        this->kyNangSutXa = 50;
    }
    tienVe(const tienVe &other) : cauThu(other)
    {
        this->kyNangChuyenXa = other.kyNangChuyenXa;
        this->kyNangSutXa = other.kyNangSutXa;
    }
    tienVe &operator=(const tienVe &other)
    {
        if (this != &other)
        {
            cauThu::operator=(other);
            this->kyNangChuyenXa = other.kyNangChuyenXa;
            this->kyNangSutXa = other.kyNangSutXa;
        }
        return *this;
    }
    friend istream &operator>>(istream &in, tienVe &tm)
    {
        in >> (cauThu &)tm;
        return in;
    }
    friend ostream &operator<<(ostream &out, const tienVe &tm)
    {
        out << (cauThu &)tm;
        return out;
    }

    void chiSo()
    {
        cauThu::chiSo();
        cout << "Ky nang chuyen xa: " << kyNangChuyenXa << "★" << endl;
        cout << "Ky nang sut xa: " << kyNangSutXa << "★" << endl;
    }
    void thiDau() override
    {
        cout << "Tien ve " << getTen() << " chuyen cho dong doi!" << endl;
        cout << "Ky nang chuyen xa +1 ( " << ++kyNangChuyenXa << "★ )" << endl;
    }
};
class tienDao : public cauThu
{
protected:
    int kyNangDanhDau;
    int kyNangSutGan;

public:
    ~tienDao() {}
    tienDao(string ten = "", int tuoi = 0, int soAo = 0, string quocTich = "") : cauThu(ten, tuoi, soAo, quocTich, "Tien Dao")
    {
        this->kyNangDanhDau = 50;
        this->kyNangSutGan = 50;
    }
    tienDao(const tienDao &other) : cauThu(other)
    {
        this->kyNangDanhDau = other.kyNangDanhDau;
        this->kyNangSutGan = other.kyNangSutGan;
    }
    tienDao &operator=(const tienDao &other)
    {
        if (this != &other)
        {
            cauThu::operator=(other);
            this->kyNangDanhDau = other.kyNangDanhDau;
            this->kyNangSutGan = other.kyNangSutGan;
        }
        return *this;
    }
    friend istream &operator>>(istream &in, tienDao &tm)
    {
        in >> (cauThu &)tm;
        return in;
    }
    friend ostream &operator<<(ostream &out, const tienDao &tm)
    {
        out << (cauThu &)tm;
        return out;
    }

    void chiSo()
    {
        cauThu::chiSo();
        cout << "Ky nang danh dau: " << kyNangDanhDau << "★" << endl;
        cout << "Ky nang sut gan: " << kyNangSutGan << "★" << endl;
    }
    void thiDau() override
    {
        cout << "Tien dao " << getTen() << " ghi ban!" << endl;
        cout << "Ky nang sut gan +1 ( " << ++kyNangSutGan << "★ )" << endl;
    }
};

void displayDanhSachCauThu(const vector<cauThu *> &danhSach)
{
    if (danhSach.empty())
    {
        cout << "Danh sach cau thu rong.\n";
        return;
    }

    cout << "----------------------------------------------------------------------------\n";
    cout << left
         << setw(5) << "STT"
         << setw(20) << "Ho Ten"
         << setw(6) << "Tuoi"
         << setw(8) << "So Ao"
         << setw(20) << "Quoc Tich"
         << setw(15) << "Vi Tri" << "\n";
    cout << "----------------------------------------------------------------------------\n";

    for (size_t i = 0; i < danhSach.size(); ++i)
    {
        cauThu *ct = danhSach[i];
        cout << left
             << setw(5) << (i + 1)
             << setw(20) << ct->getTen()
             << setw(6) << ct->getTuoi()
             << setw(8) << ct->getSoAo()
             << setw(20) << ct->getQuocTich()
             << setw(15) << ct->getViTri() << "\n";
    }

    cout << "----------------------------------------------------------------------------\n";
}

void addPlayer(vector<cauThu *> &cauThu_, bool isList = true)
{
    cauThu *A;
    int type = 0;
    do
    {
        cls();
        cout << "---------- CHON LOAI CAU THU (" << cauThu_.size() + 1 << ") ----------\n";
        cout << "  1. Tien Dao\n";
        cout << "  2. Tien Ve\n";
        cout << "  3. Hau Ve\n";
        cout << "  4. Thu Mon\n";
        cout << "---------------------------------------\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> type;

        if (type < 1 || type > 4)
        {
            cls();
            cout << "Khong hop le (1 -> 4), vui long nhap lai!\n";
            cin.ignore();
            cin.get();
        }
    } while (type < 1 || type > 4);

    switch (type)
    {
    case 1:
        A = new tienDao();
        break;
    case 2:
        A = new tienVe();
        break;
    case 3:
        A = new hauVe();
        break;
    case 4:
        A = new thuMon();
        break;
    }

    cls();
    if (isList)
    {
        cout << "\n------ Cau thu thu " << cauThu_.size() + 1 << " ------\n";
    }

    A->nhapThongTin();

    cauThu_.push_back(A);
}
void addListPlayer(vector<cauThu *> &cauThu)
{
    int n;
    cout << "Nhap so luong cau thu: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cls();
        addPlayer(cauThu);
    }
}

void searchPlayer(const vector<cauThu *> &cauThu)
{
    string name;
    cout << "Nhap ten cau thu can tim: ";
    getline(cin, name);
    bool found = false;
    cls();
    for (const auto &ct : cauThu)
    {
        if (ct->getTen() == name)
        {
            ct->displayAll();
            found = true;
            break;
        }
    }
    if (!found)
    {
        cls();
        cout << "Khong tim thay cau thu co ten: " << name << endl;
    }
    cin.get();
}
void deletePlayer(vector<cauThu *> &cauThu)
{
    string name;
    cout << "Nhap ten cau thu can xoa: ";
    getline(cin, name);
    bool found = false;
    cls();
    for (size_t i = 0; i < cauThu.size(); ++i)
    {
        if (cauThu[i]->getTen() == name)
        {
            delete cauThu[i];
            cauThu.erase(cauThu.begin() + i);
            found = true;
            break;
        }
    }
    if (!found)
    {
        cls();
        cout << "Khong tim thay cau thu co ten: " << name << endl;
    }
    else
    {
        cout << "Da xoa cau thu co ten: " << name << endl;
    }
    cin.get();
}

void Menu(vector<cauThu *> &cauThu, bool loop = true)
{
    while (loop)
    {
        int option;
        cout << "\033[2J\033[1;1H";
        cout << "----------------------------------------------------" << endl;
        cout << "\t Menu Quan Ly Cau Thu (Hien co: " << cauThu.size() << ")" << endl
             << endl;
        cout << "1: Nhap Danh Sach Cau Thu" << endl;
        cout << "2: In Danh Sach Cau Thu" << endl;
        cout << "3: Tim kiem Cau Thu" << endl;
        cout << "4: Xoa Cau thu" << endl;
        cout << "5: Exit" << endl
             << endl;
        cout << "Choose your option: " << endl
             << endl;
        cout << "----------------------------------------------------" << endl;

        cout << "\033[10;21H";
        cin >> option;
        cin.ignore();

        switch (option)
        {
        case 1:
            cls();
            addListPlayer(cauThu);
            break;
        case 2:
            cls();
            displayDanhSachCauThu(cauThu);
            cin.get();
            break;
        case 3:
            cls();
            searchPlayer(cauThu);
            break;
        case 4:
            cls();
            deletePlayer(cauThu);
            break;
        case 5:
            loop = false;
            cls();
            break;
        default:
            break;
        }
    }
}

int main()
{
    vector<cauThu *> data = {
        new thuMon("Dang Van Lam", 30, 1, "Viet Nam"),
        new thuMon("Manuel Neuer", 37, 1, "Germany"),
        new thuMon("David De Gea", 33, 1, "Spain"),

        new hauVe("Virgil van Dijk", 32, 4, "Netherlands"),
        new hauVe("Do Duy Manh", 28, 28, "Viet Nam"),
        new hauVe("Sergio Ramos", 37, 4, "Spain"),

        new tienVe("Luka Modric", 38, 10, "Croatia"),
        new tienVe("Nguyen Quang Hai", 27, 19, "Viet Nam"),
        new tienVe("Kevin De Bruyne", 33, 17, "Belgium"),

        new tienDao("Lionel Messi", 36, 10, "Argentina"),
        new tienDao("Cristiano Ronaldo", 39, 7, "Portugal"),
        new tienDao("Nguyen Tien Linh", 28, 22, "Viet Nam")};

    Menu(data);
}
