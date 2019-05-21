#include "Function.h"

void Doc_1_SV(ifstream &filein, Info_SV &SV){
	getline(filein, SV.MSSV, ',');
	getline(filein, SV.Ho_Ten, ',');
	getline(filein, SV.Ngaysinh, ',');
	getline(filein, SV.QueQuan);
	for (int i = 0; i < SV.QueQuan.length(); i++) {
		if (SV.QueQuan[i] == '"') {
			SV.QueQuan[i] = ' ';
		}
	}
}

void Doc_SV(ifstream &filein, vector<Info_SV> &ds_SV){
	while (filein.eof()==0)
	{
		Info_SV SV;
		Doc_1_SV(filein, SV);
		ds_SV.push_back(SV);
	}
}

void Doc_1_GV(ifstream &filein, Info_GV &GV) {
	getline(filein, GV.MS, ',');
	getline(filein, GV.Ho_Ten, ',');
	getline(filein, GV.Ngaysinh, ',');
	getline(filein, GV.SDT, ',');
	for (int i = 0; i < GV.SDT.length(); i++) {
		if (GV.SDT[i] == '"') {
			GV.SDT[i] = ' ';
		}
	}
	getline(filein, GV.QueQuan);
	for (int i = 0; i < GV.QueQuan.length(); i++) {
		if (GV.QueQuan[i] == '"') {
			GV.QueQuan[i] = ' ';
		}
	}
}

void Doc_GV(ifstream &filein, vector<Info_GV> &ds_GV) {
	while (filein.eof() == 0) {
		Info_GV GV;
		Doc_1_GV(filein, GV);
		ds_GV.push_back(GV);
	}

}

void Doc_1_TK(ifstream &filein, Info_TK &TK) {
	getline(filein, TK.user, ',');
	getline(filein, TK.pass, ',');
	getline(filein, TK.type);
}

void Doc_TK(ifstream &filein, vector<Info_TK> &ds_TK) {
	while (filein.eof() == 0)
	{
		Info_TK TK;
		Doc_1_TK(filein, TK);
		ds_TK.push_back(TK);
	}
	for (int i = 0; i < ds_TK.size(); i++) { if (ds_TK[i].user == "") { ds_TK.erase(ds_TK.begin() + i); } }
}

void Doc_1_Khoahoc(ifstream &filein, Info_Khoahoc &Khoahoc) {
	getline(filein, Khoahoc.Course_ID, ',');
	getline(filein, Khoahoc.Teacher_ID, ',');
	getline(filein, Khoahoc.Name, ',');
	getline(filein, Khoahoc.Sum_Student, ',');
	getline(filein, Khoahoc.Slot);
	Khoahoc.n_Student = atoi(Khoahoc.Sum_Student.c_str());
	Khoahoc.n_Slot=atoi(Khoahoc.Slot.c_str());
}

void Doc_Khoahoc(ifstream &filein, vector<Info_Khoahoc> &ds_Khoahoc) {
	while (filein.eof() == 0) {
		Info_Khoahoc Khoahoc;
		Doc_1_Khoahoc(filein, Khoahoc);
		ds_Khoahoc.push_back(Khoahoc);
	}
	for (int i = 0; i < ds_Khoahoc.size(); i++) { if (ds_Khoahoc[i].Course_ID == "") { ds_Khoahoc.erase(ds_Khoahoc.begin() + i); } }
}

void Test_3(vector<Info_Khoahoc> ds_Khoahoc) {
	cout << ds_Khoahoc[0].Course_ID << "\t" << ds_Khoahoc[0].Teacher_ID << "\t" << ds_Khoahoc[0].Name << "\t\t\t\t" << "n_Student" << "\t" << ds_Khoahoc[0].Slot << endl;
	for (int i = 1; i < ds_Khoahoc.size(); i++) {
		cout << setw(10) << left << ds_Khoahoc[i].Course_ID << "\t" << setw(10) << ds_Khoahoc[i].Teacher_ID << "\t" << setw(30) << ds_Khoahoc[i].Name << "\t" << setw(5) << ds_Khoahoc[i].n_Student << "\t\t" << ds_Khoahoc[i].n_Slot;
		cout << endl;
	}
}

void Doc_1_Object(ifstream &filein, Info_Object &Object) {
	getline(filein, Object.Course_ID, ',');
	getline(filein, Object.Student_ID, ',');
	getline(filein, Object.Teacher_ID, ',');
	getline(filein, Object.Score, ',');
	getline(filein, Object.Semester_ID);
	Object.n_Score = atof(Object.Score.c_str());
}

void Doc_Object(ifstream &filein, vector<Info_Object> &ds_Object) {
	while (filein.eof() == 0) {
		Info_Object Object;
		Doc_1_Object(filein, Object);
		ds_Object.push_back(Object);
	}
	for (int i = 0; i < ds_Object.size(); i++) { if (ds_Object[i].Course_ID == "") { ds_Object.erase(ds_Object.begin() + i); } }
}

//---------------------------------------------------

Info_TK Access(vector<Info_TK> ds_TK)
{
	string user, pass;	int count = 0, a = 0, i;
	cout << "user: ";	cin >> user;
	cout << "pass: ";	cin >> pass;
	for (i = 0; i < ds_TK.size(); i++) {
		if (user == ds_TK[i].user && pass == ds_TK[i].pass) {
			a = 1;
			break;
		}
	}
	if (a != 1) {
		for (i = 0; i < ds_TK.size(); i++) {
			if (user != ds_TK[i].user || pass != ds_TK[i].pass) {
				user = ds_TK[i].user;
				pass = ds_TK[i].pass;
				count += 1;
			}
		}
	}
	if (count == ds_TK.size()) {
		do {
			count = 0, a = 0;
			cout << "user: ";
			cin >> user;
			cout << "pass: ";
			cin >> pass;
			for (i = 0; i < ds_TK.size(); i++) {
				if (user == ds_TK[i].user && pass == ds_TK[i].pass) {
					a = 1; break;
				}
			}
			if (a != 1) {
				for (i = 0; i < ds_TK.size(); i++) {
					if (user != ds_TK[i].user || pass != ds_TK[i].pass) {
						user = ds_TK[i].user;
						pass = ds_TK[i].pass;
						count += 1;
					}
				}
			}
		} while (count == ds_TK.size() && a == 0 );
	}
	return ds_TK[i];
}

void write_Object(ofstream &fileout, vector<Info_Object> &ds_Object)
{
    fileout << ds_Object[0].Course_ID << "," << ds_Object[0].Student_ID << "," << ds_Object[0].Teacher_ID << "," << ds_Object[0].Score << "," << ds_Object[0].Semester_ID;
    fileout << endl;
	for (int i = 1; i < ds_Object.size(); i++) {
		fileout << ds_Object[i].Course_ID << "," << ds_Object[i].Student_ID << "," << ds_Object[i].Teacher_ID << "," << ds_Object[i].n_Score << "," << ds_Object[i].Semester_ID;
		fileout << endl;
	}
}

void write_Course(ofstream &fileout, vector<Info_Khoahoc> &ds_Course)
{
	fileout << ds_Course[0].Course_ID << "," << ds_Course[0].Teacher_ID << "," << ds_Course[0].Name << "," << "n_student" << "," << ds_Course[0].Slot;
	fileout << endl;
	for (int i = 1; i < ds_Course.size(); i++) {
		fileout << ds_Course[i].Course_ID << "," << ds_Course[i].Teacher_ID << "," << ds_Course[i].Name << "," << ds_Course[i].n_Student << "," << ds_Course[i].n_Slot;
		fileout << endl;
	}
}

void write_Student(ofstream &fileout, vector<Info_SV> &ds_SV)
{
    for (int i = 0; i < ds_SV.size(); i++) {
        if(ds_SV[i].MSSV =="")
        {
            ds_SV.erase(ds_SV.begin()+i);
        }
        else{
			fileout << ds_SV[i].MSSV << ","
        	<< ds_SV[i].Ho_Ten << ","
        	<< ds_SV[i].Ngaysinh << ","
        	<< ds_SV[i].QueQuan;
			fileout << endl;
		}
	}
}

void write_Teacher(ofstream &fileout, vector<Info_GV> &ds_GV)
{
    for (int i = 0; i < ds_GV.size(); i++)
    {
        if(ds_GV[i].MS =="")
        {
            ds_GV.erase(ds_GV.begin()+i);
        }
        else{
			fileout << ds_GV[i].MS << ","
        	<< ds_GV[i].Ho_Ten << ","
        	<< ds_GV[i].Ngaysinh << ","
        	<< ds_GV[i].SDT << ","
        	<< ds_GV[i].QueQuan;
			fileout << endl;
		}
	}
}

void write_User(ofstream &fileout, vector<Info_TK> &ds_User)
{
    for (int i = 0; i < ds_User.size(); i++)
    {
        if(ds_User[i].user =="")
        {
            ds_User.erase(ds_User.begin()+i);
        }
        else{
			fileout << ds_User[i].user << "," << ds_User[i].pass << "," << ds_User[i].type;
			fileout << endl;
		}
	}
}

//---------------------------------------------------

void Change_Pass(vector<Info_TK> &ds_TK,Info_TK tk)
{
	string o_pass, n_pass, test;
	int a = 0;
	do {
		cout << "Nhap mat khau cu: ";
		cin >> o_pass;
		for (int i = 0; i < ds_TK.size(); i++) {
			if (o_pass == ds_TK[i].pass && tk.user == ds_TK[i].user) {
				a = 1;
			}
		}
	} while (a==0);
	cout << "Nhap mat khau moi: ";
	cin >> n_pass;
	do {
		cout << "Nhap lai mat khau moi: ";
		cin >> test;
		if (n_pass== test) {
			break;
		}
	} while (1);
	for (int i = 0; i < ds_TK.size(); i++) {
		if (o_pass == ds_TK[i].pass && tk.user == ds_TK[i].user) {
			ds_TK[i].pass = n_pass;
			break;
		}
	}
	cout << "Doi mat khau thanh cong." << endl;
	ofstream fileout("user.csv");
	for (int i = 0; i < ds_TK.size(); i++) {
		fileout << ds_TK[i].user << "," << ds_TK[i].pass << "," << ds_TK[i].type;
		fileout << endl;
	}
	fileout.close();
}

void Find_User (vector<Info_TK> ds_User, vector<Info_GV> ds_GV, vector<Info_SV> ds_SV)
{
    string KeyWord;
    cout<<"Nhap ID can tim kiem: ";
    cin>>KeyWord;

    for (int i = 0; i < ds_GV.size(); i++)
    {
        if ( KeyWord == ds_GV[i].MS)
        {
            cout<<"\nType: teacher"<<"\nMS: "<<ds_GV[i].MS
            <<"\nHo va ten: "<<ds_GV[i].Ho_Ten
            <<"\nNgay sinh: "<<ds_GV[i].Ngaysinh
            <<"\nSo dien thoai: "<<ds_GV[i].SDT
            <<"\nQue quan: "<<ds_GV[i].QueQuan<<endl;
        }
    }

    for (int i = 0; i < ds_SV.size(); i++)
    {
        if ( KeyWord == ds_SV[i].MSSV)
        {
            cout<<"\nType: student"<<"\nMSSV: "<<ds_SV[i].MSSV
            <<"\nHo va ten: "<<ds_SV[i].Ho_Ten
            <<"\nNgay sinh: "<<ds_SV[i].Ngaysinh
            <<"\nQue Quan: "<<ds_SV[i].QueQuan<<endl;
        }
    }
}

void Add_User (vector<Info_TK> &ds_User, vector<Info_GV> &ds_GV, vector<Info_SV> &ds_SV)
{
    int choose;
    Info_TK new_user;
    Info_GV new_teacher;
    Info_SV new_student;
    cout<<"Nhap 1 de muon them Teacher\nNhap 2 de muon them Student\nLua chon cua ban la: ";
    cin>>choose;
    cin.ignore();
    switch (choose)
    {
        case 1:{
            cout<<"\nNhap ID Teacher: "; getline(cin,new_teacher.MS);
            cout<<"Nhap ho ten: ";     getline(cin,new_teacher.Ho_Ten);
            cout<<"Nhap ngay sinh: ";  getline(cin,new_teacher.Ngaysinh);
            cout<<"Nhap SDT: ";        getline(cin,new_teacher.SDT);
            cout<<"Nhap que quan: ";   getline(cin,new_teacher.QueQuan);
            ds_GV.push_back(new_teacher);   //them giao vien moi khoi tao vao danh sach giao vien
            new_user.user=new_teacher.MS;
            new_user.pass=new_user.user;
            new_user.type="teacher";
            ds_User.push_back(new_user);
            cout << "Them giang vien thanh cong." << endl;   //them user moi khoi tao danh sach user
            // Test_1(ds_GV);  //in danh sach giao vien
            ofstream fileout3("teacher.csv");
    		write_Teacher(fileout3, ds_GV);
            break;
        }
        case 2:{
            cout<<"\nNhap MSSV Student: "; getline(cin,new_student.MSSV);
            cout<<"Nhap ho ten: ";       getline(cin,new_student.Ho_Ten);
            cout<<"Nhap ngay sinh: ";    getline(cin,new_student.Ngaysinh);
            cout<<"Nhap que quan: ";     getline(cin,new_student.QueQuan);
            ds_SV.push_back(new_student);   // them hoc sinh moi khoi tao vao danh sach giao vien
            new_user.user=new_student.MSSV;
            new_user.pass=new_user.user;
            new_user.type="student";
            ds_User.push_back(new_user);
            cout << "Them sinh vien thanh cong." << endl;   //them user moi khoi tao danh sach user
            // Test(ds_SV);    // in danh sach hoc sinh
            ofstream fileout2("student.csv");
			write_Student(fileout2, ds_SV);
            break;
		}
        default:{cout<<"Nhap sai lua chon"<<endl;
            break;}
    }
    ofstream fileout1("user.csv");
    write_User(fileout1, ds_User);
}

void Delete_User (vector<Info_TK> &ds_User, vector<Info_GV> &ds_GV, vector<Info_SV> &ds_SV)
{
    string deleteID;
    cout<<"Nhap ID can xoa: ";  cin>>deleteID;
    for (int i = 0; i < ds_User.size(); i++)
    {
        if ( deleteID == ds_User[i].user)     ds_User.erase(ds_User.begin()+i);
    }
    for (int i = 0; i < ds_SV.size(); i++)
    {
        if ( deleteID == ds_SV[i].MSSV)    { ds_SV.erase(ds_SV.begin()+i); cout << "Xoa sinh vien thanh cong." << endl;}
    }
    for (int i = 0; i < ds_GV.size(); i++)
    {
        if ( deleteID == ds_GV[i].MS)      { ds_GV.erase(ds_GV.begin()+i); cout << "Xoa giang vien thanh cong." << endl;}
    }
    ofstream fileout1("user.csv");
    ofstream fileout2("student.csv");
    ofstream fileout3("teacher.csv");
    write_Teacher(fileout3, ds_GV);
    write_Student(fileout2, ds_SV);
    write_User(fileout1, ds_User);
}

void Find_Users(vector<Info_GV> &ds_gv, vector<Info_SV> &ds_sv)
{
    int i,j;
    string name;
    cout << "Nhap 1 de tim sinh vien, nhap 2 de tim giao vien: ";
    cin >> j;
    fflush(stdin);
    cout << "Nhap keyword can tim: ";
    getline(cin,name);
    if(j==2)
    for (i=0;i<ds_gv.size();i++)
    {
        if (ds_gv[i].Ho_Ten.find(name)!=std::string::npos)
            cout << setw(10) << left << ds_gv[i].MS << setw(30) << ds_gv[i].Ho_Ten << setw(20) << ds_gv[i].Ngaysinh << setw(20) << ds_gv[i].SDT << setw(20) << ds_gv[i].QueQuan << endl;
    }

    else if (j==1)
        for (i=0;i<ds_sv.size();i++)
    {
        if (ds_sv[i].Ho_Ten.find(name)!=std::string::npos)
            cout << setw(10) << left << ds_sv[i].MSSV << setw(30) << ds_sv[i].Ho_Ten << setw(20) << ds_sv[i].Ngaysinh << setw(20) << ds_sv[i].QueQuan << endl;
    }
}

void Delete_Users(vector<Info_TK> &ds_User, vector<Info_GV> &ds_GV, vector<Info_SV> &ds_SV)
{
    int j,n;
    cout << "Nhap so luong tai khoan muon xoa: ";
    cin >> n;
    for (j=1;j<=n;j++)
    {
        Delete_User(ds_User,ds_GV,ds_SV);
        cout << endl;
    }
}

//---------------------------------------------------

float GPA(Info_TK &tk, vector<Info_Object> &ds_Object)
{
	int i, j = 0;
	float ans = 0;
	for (i = 1; i<ds_Object.size(); i++)
	{
		if (ds_Object[i].Student_ID.compare(tk.user) == 0 && ds_Object[i].n_Score != -1)
		{
			ans = ans + ds_Object[i].n_Score;
			j++;
		}
	}
	if (j != 0)
		return ans / j;
	else return -1;
}

int count_curri(Info_TK &tk, vector<Info_Object> &ds_Object)
{
	int i, ans = 0;
	for (i = 0; i<ds_Object.size(); i++)
	{
		if (ds_Object[i].Student_ID.compare(tk.user) == 0) ans++;
	}
	return ans;
}

void dangki_MonHoc(vector<Info_Khoahoc> &ds_khoahoc, vector<Info_Object> &ds_object, Info_TK &tk)
{
	string course;
	string teacher;
	int i, j = 0;
	Info_Object new_object;

	Test_3(ds_khoahoc);
	cout << "Nhap khoa hoc muon dang ki (vd: CC01 S1000): ";
	cin >> course;
	cin >> teacher;
	for (i = 1; i<ds_khoahoc.size(); i++)
	{
		if (teacher.compare(ds_khoahoc[i].Teacher_ID) == 0 && course.compare(ds_khoahoc[i].Course_ID) == 0 && ds_khoahoc[i].n_Student < ds_khoahoc[i].n_Slot && count_curri(tk, ds_object) < 5)
		{
			ds_khoahoc[i].n_Student++;

			new_object.Course_ID = course;
			new_object.Student_ID = tk.user;
			new_object.Teacher_ID = ds_khoahoc[i].Teacher_ID;
			new_object.n_Score = -1;
			new_object.Semester_ID = "171";
			ds_object.push_back(new_object);
			j++;
		}
	}
	if (j == 0) cout << "Nhap sai mon hoc hoac lop da du nguoi hoac dang ki vuot qua 20 tin chi" << endl;
	else
	{
	    cout << "Dang ki mon thanh cong" << endl;
		ofstream fileout1("object.csv");
		ofstream fileout2("course.csv");
		write_Object(fileout1, ds_object);
		write_Course(fileout2, ds_khoahoc);
	}
}

void check_info(Info_TK &tk, vector<Info_Object> &ds_Object)
{
	int i;
	cout << "GPA: " << GPA(tk, ds_Object) << endl;
	cout << "Cac mon da dang ki:   ";
	for (i = 0; i<ds_Object.size(); i++)
	{
		if (tk.user.compare(ds_Object[i].Student_ID) == 0 && ds_Object[i].Semester_ID.compare("171") == 0)
			cout << ds_Object[i].Course_ID << "-" << ds_Object[i].Teacher_ID << "   ";
	}
	cout << endl;

	cout << "Cac mon dang hoc:   ";
	for (i = 0; i<ds_Object.size(); i++)
	{
		if (tk.user.compare(ds_Object[i].Student_ID) == 0 && ds_Object[i].Semester_ID.compare("161") == 0)
			cout << ds_Object[i].Course_ID << "-" << ds_Object[i].Teacher_ID << "   ";
	}
	cout << endl;
}

void huy_Monhoc(vector<Info_Khoahoc> &ds_khoahoc, vector<Info_Object> &ds_object, Info_TK &tk)
{
    string course, teacher;
	int i, j = 0;
	cout << "Nhap khoa hoc muon huy (VD: CC01 S1000):   ";
	for (i = 0; i<ds_object.size(); i++)
	{
		if (tk.user.compare(ds_object[i].Student_ID) == 0 && ds_object[i].Semester_ID.compare("171") == 0)
			cout << ds_object[i].Course_ID << "-" << ds_object[i].Teacher_ID << "   ";
	}
	cout << endl;
	cin >> course;
	cin >> teacher;

	for (i = 1; i<ds_khoahoc.size(); i++)
    {
        if (course.compare(ds_khoahoc[i].Course_ID) == 0 && teacher.compare(ds_khoahoc[i].Teacher_ID) == 0)
        {
            ds_khoahoc[i].n_Student--;
            for (int j = 0; j < ds_object.size(); j++) { if (ds_object[j].Course_ID == course && ds_object[j].Teacher_ID == teacher && tk.user == ds_object[j].Student_ID) { ds_object.erase(ds_object.begin() + j); } }
        }
    }
    cout << "Huy mon thanh cong" << endl;
    ofstream fileout1("object.csv");
    ofstream fileout2("course.csv");
    write_Object(fileout1, ds_object);
    write_Course(fileout2, ds_khoahoc);
}

void find_Course(vector<Info_Khoahoc> ds_khoahoc)
{
    int i,j;
    string key_w;
    cout << "Nhap keyword can tim: ";
    getline(cin,key_w);
    for (i=0;i<ds_khoahoc.size();i++)
    {
        if (ds_khoahoc[i].Name.find(key_w)!=std::string::npos)
            cout << setw(10) << left << ds_khoahoc[i].Course_ID << setw(20) << ds_khoahoc[i].Teacher_ID << setw(30) << ds_khoahoc[i].Name << setw(20) << ds_khoahoc[i].n_Student << setw(20) << ds_khoahoc[i].n_Slot << endl;
    }
}

//---------------------------------------------------

void open_course(vector<Info_Khoahoc> &ds_khoahoc, Info_TK &tk)
{
	cout << "Mo Mon Hoc Moi (VD: CC11 - 'ENTER' - He thong so): " << endl;
	Info_Khoahoc new_khoahoc;
	cin >> new_khoahoc.Course_ID ;
	fflush(stdin);
	new_khoahoc.Teacher_ID = tk.user;
	getline(cin, new_khoahoc.Name);
	new_khoahoc.n_Slot = 50;
	new_khoahoc.n_Student = 0;
	ds_khoahoc.push_back(new_khoahoc);
	cout << "Mo mon thanh cong." << endl;

	ofstream fileout2("course.csv");
	write_Course(fileout2, ds_khoahoc);
}

void tongketdiem(vector<Info_Object>&ds_object, vector<Info_Khoahoc> &ds_khoahoc, Info_TK &tk)
{
    int i,j;
	for (i = 1; i < ds_khoahoc.size(); i++)
	{
		if (ds_khoahoc[i].Teacher_ID == tk.user)
		{
		    cout << ds_khoahoc[i].Course_ID << ":" << "\t" << "MSSV" << "\t\t" << "Score" << "\t\t" << "Semester" << endl;
			for (j=1;j<ds_object.size();j++)
            {
                if (ds_object[j].Teacher_ID == tk.user && ds_object[j].Course_ID == ds_khoahoc[i].Course_ID)
                {
                    cout << "\t" << ds_object[j].Student_ID << "\t\t" << ds_object[j].n_Score << "\t\t" << ds_object[j].Semester_ID << endl;
                }
            }
            cout << endl << endl;
		}
	}
}

void sua_diem(vector<Info_Object>&ds_object, vector<Info_Khoahoc> &ds_khoahoc, Info_TK &tk)
{
    float score;
    string course, student_ID;
	tongketdiem(ds_object,ds_khoahoc,tk);
	cout << "Nhap mon hoc va sinh vien can sua diem (VD: CC01 1712345): ";
	cin >> course;
	cin >> student_ID;
	cout << "Diem moi: ";
	cin >> score;

	int i;
	for (i=1;i<ds_object.size();i++)
    {
        if (student_ID == ds_object[i].Student_ID && course == ds_object[i].Course_ID)
        {
            ds_object[i].n_Score = score;
        }
    }
    cout << "Sua diem thanh cong." << endl;

    ofstream fileout2("object.csv");
	write_Object(fileout2, ds_object);
}

