#include "Function.h"

int main()
{
	ifstream file_s;
	ifstream file_t;
	ifstream file_u;
	ifstream file_c;
	ifstream file_o;
	file_s.open("student.csv", ios_base::in);
	file_t.open("teacher.csv", ios_base::in);
	file_u.open("user.csv", ios_base::in);
	file_c.open("course.csv", ios_base::in);
	file_o.open("object.csv", ios_base::in);
	vector<Info_SV> ds_SV;
	vector<Info_GV> ds_GV;
	vector<Info_TK> ds_TK;
	vector<Info_Khoahoc> ds_Khoahoc;
	vector<Info_Object> ds_Object;
	Doc_SV(file_s, ds_SV);
	Doc_GV(file_t, ds_GV);
	Doc_TK(file_u, ds_TK);
	Doc_Khoahoc(file_c, ds_Khoahoc);
	Doc_Object(file_o, ds_Object);

	//--------------------------------------------------------

label: system("cls");
	Info_TK TK = Access(ds_TK);

	//--------------------------------------------------------

	if (TK.type == "admin") {
label3:
		int n;
		cout << "-----------------------------------------------------------------------------" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
		cout << "\t" << "1/ DOI MAT KHAU." << endl;
		cout << "\t" << "2/ TIM KIEM USER." << endl;
		cout << "\t" << "3/ THEM GIANG VIEN VA SINH VIEN." << endl;
		cout << "\t" << "4/ XOA GIANG VIEN VA SINH VIEN." << endl;
		cout << "\t" << "5/ TIM NHIEU USERS" << endl;
		cout << "\t" << "6/ XOA NHIEU USERS" << endl;
		cout << "\t" << "7/ DANG XUAT." << endl;
		cout << "Nhap lua chon: ";	cin >> n;
		fflush(stdin);
		system("cls");

		switch (n) {
		case 1: Change_Pass(ds_TK,TK); goto label3; break;
		case 2: Find_User(ds_TK,ds_GV,ds_SV); goto label3; break;
        case 3: Add_User(ds_TK,ds_GV,ds_SV); goto label3; break;
        case 4: Delete_User(ds_TK,ds_GV,ds_SV); goto label3; break;
        case 5: Find_Users(ds_GV,ds_SV); goto label3; break;
        case 6: Delete_Users(ds_TK,ds_GV,ds_SV); goto label3; break;
		case 7: goto label;	break;
		}
	}

	//--------------------------------------------------------

	else if (TK.type == "teacher") {
label2:
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
		cout << "\t" << "1/ DOI MAT KHAU." << endl;
		cout << "\t" << "2/ MO MON HOC." << endl;
		cout << "\t" << "3/ TONG KET DIEM." << endl;
		cout << "\t" << "4/ SUA DIEM." << endl;
		cout << "\t" << "5/ DANG XUAT." << endl;
		int n;
		cout << "Nhap lua chon: ";	cin >> n;
		fflush(stdin);
		system("cls");

		switch (n) {
		case 1: Change_Pass(ds_TK,TK);	goto label2;	break;
		case 2: open_course(ds_Khoahoc, TK);	goto label2;	break;
		case 3: tongketdiem(ds_Object,ds_Khoahoc, TK);	goto label2;	break;
		case 4: sua_diem(ds_Object,ds_Khoahoc, TK);	goto label2;	break;
		case 5: goto label;	break;
		}
	}

	//--------------------------------------------------------

	else if (TK.type == "student") {
		int n;
label1:
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
		cout << "\t" << "1/ DOI MAT KHAU." << endl;
		cout << "\t" << "2/ DANG KY MON HOC." << endl;
		cout << "\t" << "3/ HUY MON HOC." << endl;
		cout << "\t" << "4/ XEM THONG TIN CA NHAN." << endl;
        cout << "\t" << "5/ TIM KIEM NHIEU KHOA HOC THEO KEYWORD" << endl;
		cout << "\t" << "6/ DANG XUAT." << endl;
		cout << "Nhap lua chon: ";	cin >> n;
		fflush(stdin);
        system("cls");

		switch (n) {
		case 1: Change_Pass(ds_TK,TK); goto label1;	break;
		case 2:	dangki_MonHoc(ds_Khoahoc, ds_Object, TK); goto label1;	break;
        case 3:	huy_Monhoc(ds_Khoahoc, ds_Object, TK); goto label1;	break;
		case 4: check_info(TK, ds_Object);	goto label1;	break;
		case 5: find_Course(ds_Khoahoc);  goto label1;	 break;
		case 6: goto label;	break;
		}
	}

	//--------------------------------------------------------

	file_s.close();
	file_t.close();
	file_u.close();
	file_o.close();
	file_c.close();
    return 0;
}
