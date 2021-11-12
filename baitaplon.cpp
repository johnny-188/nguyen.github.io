
#include "qly.h"
const int g_kArraySize = 8;		

int main()
{
	Movie movie_objects[g_kArraySize];
	Nuoc drink_objects[g_kArraySize];
	MovieTicketMaster* p_MovieTicketMaster = new MovieTicketMaster("DT CINEMA", "1808 LA");
	p_MovieTicketMaster->Init(movie_objects, g_kArraySize);
	p_MovieTicketMaster->Init(drink_objects, g_kArraySize);
	p_MovieTicketMaster->Run();

	delete p_MovieTicketMaster;

	return 0;
}




MovieTicketMaster::MovieTicketMaster()  //set con tro mac dinh den Null
{
	p_dsphim = NULL;
	p_dsnuoc = NULL;
}


MovieTicketMaster::MovieTicketMaster(string my_theater_name, string my_theater_location)  //ten, dia chi va van khoi tao con tro
{
	tenrap = my_theater_name;
	diachi = my_theater_location;
	p_dsphim = NULL;
	p_dsnuoc = NULL;
}

MovieTicketMaster::~MovieTicketMaster()
{
	cout << "Cum Rap " << tenrap << ",Dia Chi " << diachi
		<< " Da dong!!!" << endl;
}


void MovieTicketMaster::Init(Movie* p_my_MovieList, int array_size)  //khoi tao doi tuong cho ds phim
{
	string movie_titles[g_kArraySize] = { "Mat Biec",
		"The Nun",
		"Thap Tam Muoi",
		"Bo Gia",
		"Bo Tre",
		"Vuon Sao Ke",
		"Giac mo 14 ty",
		"Ai dung ai sai?", };

	int theater_tickets[g_kArraySize] = { 100,75,90,90,75,115,120,130 };

	double movie_price[g_kArraySize] = { 11.5,11.5,11.5,11.5,11.5,13.5,13.5,15.0 };

	Movie* p = p_my_MovieList;

	for (int i = 0; i <= g_kArraySize - 1; i++) {
		p->set_tenphim(movie_titles[i]);
		p->set_ve(theater_tickets[i]);
		p->set_giave(movie_price[i]);
		p++;
	}

	p_dsphim = p_my_MovieList;

}

void MovieTicketMaster::Init(Nuoc* p_my_drinklist, int array_size) //khoi tao cho doi tuong ds nuoc
{
	string drink_name[g_kArraySize] = { "Coca Cola" ,
		"Soda",
		"Pepsi",
		"C2",
		"Mirinda",
		"Cam ep",
		"Nuoc loc",
		"Sting" };

	int sl[g_kArraySize] = { 100,100,100,100,100,100,100,100 };
	double drink_price[g_kArraySize] = { 5.00,5.12,7.10,5.00,6.00,5.05,5.00,6.00 };
	Nuoc* p = p_my_drinklist;

	for (int i = 0; i <= g_kArraySize - 1; i++) {
		p->set_tennuoc(drink_name[i]);
		p->set_sl(sl[i]);
		p->set_gianuoc(drink_price[i]);
		p++;
	}
	p_dsnuoc = p_my_drinklist;
}


void MovieTicketMaster::Run()  //chay vong lap de yeu cau su lua chon cua ng dung
{
	int chon;

	do {

		DisplayMenu();

		cout << endl << "\t\t\t\tPlease select an option: ";

		cin >> chon;

		switch (chon)
		{

		case 1:
			ViewMovies();
			system("PAUSE");
			system("CLS");
			break;

		case 2:

			SearchMovie();
			system("PAUSE");
			system("CLS");
			break;

		case 3:

			MuaVe();
			break;

		case 4:
			ViewDrink();
			system("PAUSE");
			system("CLS");
			break;		

		case 5:
			MuaNuoc();
			break;

		case 6 :

			cout << "\nMua ve tai Website : DTcinema.com \n" << endl;
			break;


		default:

			cout << "Please choose a valid option:" << endl
				<< "=============================" << endl;
			cin.ignore();

		}
	} while (chon != 6);
}


void MovieTicketMaster::DisplayMenu()  //hien thi menu, ten rap va vi tri trong khi hien thi cac lua chon
{

	cout << "\t\t\t\tTheater: " << tenrap << " at " << diachi << endl
		<< endl << "\t\t\t\t  =======================  " << endl
		<< "\t\t\t\t||       DT CINEMA       ||" << endl
		<< "\t\t\t\t||   Han Hanh Kinh Chao  ||" << endl
		<< "\t\t\t\t  =======================  " << endl << endl
		<< "\t\t\t\t     MAI DZO MAI DZO!!!" << endl
		<< "\t\t\t\t---------------------------" << endl
		<< "\t\t\t\t\tMAIN MENU: " << endl
		<< "\t\t\t\t1--> Danh Sach Phim" << endl
		<< "\t\t\t\t2--> Tim Phim" << endl
		<< "\t\t\t\t3--> Mua ve" << endl
		<< "\t\t\t\t4--> Danh Sach Nuoc" << endl
		<< "\t\t\t\t5--> Mua Nuoc" << endl
		<< "\t\t\t\t6--> Thoat" << endl;

}


void MovieTicketMaster::ViewMovies()  
{

	Movie* p_view_movies = p_dsphim;
	system("CLS");
	cout << endl
		<< "Tat ca cac phim rap co : " << endl
		<< "DT CINEMA:" << endl
		<< "=========================" << endl << endl;

	for (int i = 0; i < g_kArraySize; i++) {           //vong lap hien thi cac doi tuong
		cout << "Movie showing at theater " << i + 1 << ": " << endl;
		p_view_movies->Display();
		++p_view_movies;
	}
}

void MovieTicketMaster::ViewDrink()
{
	Nuoc* p_view_drink = p_dsnuoc;
	system("CLS");
	cout << "Cac loai nuoc rap co : " << endl;

	for (int i = 0; i < g_kArraySize; i++) {
		cout << "Loai nuoc " << i + 1 << ":" << endl;
		p_view_drink->Display();
		++p_view_drink;
	}
}



Movie* MovieTicketMaster::SearchMovie()  //yeu cau nhap va dung ham de tim
{
	string search_movie_name; 

	cout << "\n\t\t\t\tNhap Ten Phim: ";
	cin.ignore();
	std::getline(std::cin, search_movie_name);

	Movie* p = FindMovie(search_movie_name);       //lay con tro va hien thi doi tuong

	if (p != NULL) {
		p->Display();
	}
	else {
		cout << endl << "\n\t\t\t\tKhong Tim Thay Phim." << endl << endl;
		return NULL;
	}
	return p;
}





Movie* MovieTicketMaster::FindMovie(string timphim)   //su dung vong lap de tim doi tuong
{

	Movie* p_find_movie = p_dsphim;
	//func1353c
	for (int i = 0; i < g_kArraySize; i++) {
		if (p_find_movie->get_tenphim() == timphim) {    //dung vong long de tim phim phu hop, sau do con tro tra lai doi tuong
			cout << endl << "\n\t\t\t\tDa tim thay..." << endl;
			return p_find_movie;
		}
		else {
			p_find_movie++;
		}
	}
	return NULL;
}

Nuoc* MovieTicketMaster::FindNuoc(string timnuoc)
{
	Nuoc* p_find_drink = p_dsnuoc;

	for (int i = 0; i < g_kArraySize; i++) {
		if (p_find_drink->getnuoc() == timnuoc) {
			cout << endl << "\n\t\t\t\tDa tim thay..." << endl;
			return p_find_drink;
		}
		else {
			p_find_drink++;
		}
	}
	return NULL;
}


void MovieTicketMaster::MuaVe()
{
	string phim;

	int ve;
	system("CLS");
	cout << "\n\n\t\t\t\tTen phim: ";
	cin.ignore();
	std::getline(std::cin, phim);

	cout << "\n\t\t\t\tNhap so ve ban muon mua: ";
	cin >>ve;

	Movie* p = FindMovie(phim);

	if (p != NULL) {
		double tienve = p->muave(ve);
		if (tienve == -1) {
			cout << "\n\t\t\t\tPhim da duoc ban het truoc do" << endl
				<< "\n\t\t\t\tkhong du ve cho yeu cau cua ban" << endl << endl;
		}
		else {
			cout << "\n\t\t\t\ttong so tien: " << tienve <<"$"<< endl;
		}
		cout << "\n\n\n\n\t\t\t\t";
		system("PAUSE");
		system("CLS");
	}
	else {
		cout << "Khong tim thay phim" << endl;
	}

}

void MovieTicketMaster::MuaNuoc()
{
	string nuoc;
	int sl;
	system("CLS");
	cout << "\n\n\t\t\t\tLoai Nuoc: ";
	cin.ignore();
	std::getline(std::cin, nuoc);

	cout << "\n\t\t\t\tNhap so luong ban muon mua: ";
	cin >> sl;

	Nuoc* p = FindNuoc(nuoc);

	if (p != NULL) {
		double tiennuoc = p->muanuoc(sl);
		if (tiennuoc == -1) {
			cout << "\n\t\t\t\tNuoc ban chon da duoc ban het truoc do" << endl
				<< "\n\t\t\t\tkhong du so luong cho yeu cau cua ban" << endl << endl;
		}
		else {
			cout << "\n\t\t\t\ttong so tien: " << tiennuoc << "$" << endl;
		}
		cout << "\n\n\n\n\t\t\t\t";
		system("PAUSE");
		system("CLS");
	}
	else {
		cout << "Khong tim thay..." << endl;
	}
}

//Phim
Movie::Movie()  //ham khoi tao k tham so
{
	tenphim = "";
	ve = 0;
	giave = 0.0;
}



Movie::Movie(string xten, int xve, double xgiave)  //khoi tao co tham so
{
	tenphim = xten;
	ve = xve;
	giave = xgiave;
}


Movie::~Movie()  //ham huy
{
	cout << tenphim << " is no longer showing.." << endl;
}


string Movie::get_tenphim()
{
	return tenphim;
}


int Movie::get_ve()
{
	return ve;
}


double Movie::get_giave()
{
	return giave;
}

void Movie::set_tenphim(string phimmoi)
{
	tenphim = phimmoi;
}


void Movie::set_ve(int vemoi)
{
	ve = vemoi;
}


void Movie::set_giave(double giamoi)
{
	giave = giamoi;
}


double Movie::muave(int vemoi)
{
	double total_price;

	if (vemoi <= ve) {
		total_price = vemoi * giave;
		ve = ve - vemoi;
		return total_price;
	}
	else {
		return -1;
	}
}



void Movie::Display()  //hien thi	
{
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << endl << "\t\t\t\tMovie name: " << tenphim << endl
		<< "\n\t\t\t\tTickets available: " << ve << endl
		<< "\n\t\t\t\tPrice per ticket: " << giave <<"$"<< endl << endl;

}

//Nuoc
Nuoc::Nuoc()  //ham khoi tao khong tham so
{
	tennuoc = "";
	sl = 0;
	gianuoc = 0.0;
}

Nuoc::Nuoc(string xten, int xsl, double xgianuoc)  //ham khoi tao co tham so
{
	tennuoc = xten;
	sl = xsl;
	gianuoc = xgianuoc;
}

Nuoc::~Nuoc()  //ham huy
{
	cout << tennuoc << "in no longer showing.." << endl;
}

string Nuoc::getnuoc()
{
	return tennuoc;
}

int Nuoc::getsl()
{
	return sl;
}

double Nuoc::getgia()
{
	return gianuoc;
}

void Nuoc::set_tennuoc(string nuocmoi)
{
	tennuoc = nuocmoi;
}

void Nuoc::set_sl(int slmoi)
{
	sl = slmoi;
}

void Nuoc::set_gianuoc(double giamoi)
{
	gianuoc = giamoi;
}

double Nuoc::muanuoc(int slmoi)
{
	double tongtien;

	if (slmoi <= sl) {
		tongtien = slmoi * gianuoc;
		sl = sl - slmoi;
		return tongtien;
	}
	else
	{
		return -1;
	}
}


void Nuoc::Display()
{

	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << endl << "\t\t\t\tDrink name: " << tennuoc << endl
		<< "\n\t\t\t\tAvailable: " << sl << endl
		<< "\n\t\t\t\tPrice: " << gianuoc <<"$"<< endl << endl;
}