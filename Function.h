#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include <iomanip>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

typedef struct thong_tin_SV
{
	string MSSV;
	string Ho_Ten;
	string Ngaysinh;
	string QueQuan;
} Info_SV;
void Doc_1_SV(ifstream &filein, Info_SV &SV);
void Doc_SV(ifstream &filein, vector<Info_SV> &ds_SV);

//--------------------------------------------------------

typedef struct thong_tin_GV
{
	string MS;
	string Ho_Ten;
	string Ngaysinh;
	string SDT;
	string QueQuan;
} Info_GV;
void Doc_1_GV(ifstream &filein, Info_GV &GV);
void Doc_GV(ifstream &filein, vector<Info_GV> &ds_GV);

//--------------------------------------------------------

typedef struct thong_tin_TK
{
	string user;
	string pass;
	string type;
} Info_TK;
void Doc_1_TK(ifstream &filein, Info_TK &TK);
void Doc_TK(ifstream &filein, vector<Info_TK> &ds_TK);

//--------------------------------------------------------

typedef struct khoa_hoc
{
	string Course_ID;
	string Teacher_ID;
	string Name;
	string Sum_Student;
	string Slot;
	int n_Student;
	int n_Slot;
} Info_Khoahoc;
void Doc_1_Khoahoc(ifstream &filein, Info_Khoahoc &Khoahoc);
void Doc_Khoahoc(ifstream &filein, vector<Info_Khoahoc> &ds_Khoahoc);
void Test_3(vector<Info_Khoahoc> ds_Khoahoc);

//--------------------------------------------------------

typedef struct object
{
	string Course_ID;
	string Student_ID;
	string Teacher_ID;
	string Score;
	string Semester_ID;
	double n_Score;
} Info_Object;
void Doc_1_Object(ifstream &filein, Info_Object &Object);
void Doc_Object(ifstream &filein, vector<Info_Object> &ds_Object);

//--------------------------------------------------------

void write_Object(ofstream &fileout, vector<Info_Object> &ds_Object);
void write_Course(ofstream &fileout, vector<Info_Khoahoc> &ds_Course);
void write_Student(ofstream &fileout, vector<Info_SV> &ds_SV);
void write_Teacher(ofstream &fileout, vector<Info_GV> &ds_GV);
void write_User(ofstream &fileout, vector<Info_TK> &ds_User);

//--------------------------------------------------------

Info_TK Access(vector<Info_TK> ds_TK);
void Change_Pass(vector<Info_TK> &ds_TK,Info_TK tk);
void Find_User (vector<Info_TK> ds_User, vector<Info_GV> ds_GV, vector<Info_SV> ds_SV);
void Add_User (vector<Info_TK> &ds_User, vector<Info_GV> &ds_GV, vector<Info_SV> &ds_SV);
void Delete_User (vector<Info_TK> &ds_User, vector<Info_GV> &ds_GV, vector<Info_SV> &ds_SV);
void Find_Users(vector<Info_GV> &ds_gv, vector<Info_SV> &ds_sv);
void Delete_Users(vector<Info_TK> &ds_User, vector<Info_GV> &ds_GV, vector<Info_SV> &ds_SV);

//--------------------------------------------------------

float GPA(Info_TK &tk, vector<Info_Object> &ds_Object);
int count_curri(Info_TK &tk, vector<Info_Object> &ds_Object);
void dangki_MonHoc(vector<Info_Khoahoc> &ds_khoahoc, vector<Info_Object> &ds_object, Info_TK &tk);
void huy_Monhoc(vector<Info_Khoahoc> &ds_khoahoc, vector<Info_Object> &ds_object, Info_TK &tk);
void check_info(Info_TK &tk, vector<Info_Object> &ds_Object);
void find_Course(vector<Info_Khoahoc> ds_khoahoc);

//--------------------------------------------------------

void open_course(vector<Info_Khoahoc> &ds_khoahoc, Info_TK &tk);
void tongketdiem(vector<Info_Object>&ds_object, vector<Info_Khoahoc> &ds_khoahoc, Info_TK &tk);
void sua_diem(vector<Info_Object>&ds_object, vector<Info_Khoahoc> &ds_khoahoc, Info_TK &tk);
