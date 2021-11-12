#include <iostream>
#include <string>
using namespace std;

class Movie
{
private:
	string tenphim;
	int ve;
	double giave;
public:
	Movie();
	Movie(string xten, int xve, double xgiave);
	~Movie();

	string get_tenphim();
	int get_ve();
	double get_giave();
	void set_tenphim(string phimmoi);
	void set_ve(int vemoi);
	void set_giave(double giamoi);

	double muave(int vemoi);
	void Display();
};

class Nuoc
{
private:
	string tennuoc;
	int sl;
	double gianuoc;
public:
	Nuoc();
	Nuoc(string xten, int xsl, double xgianuoc);
	~Nuoc();

	string getnuoc();
	int getsl();
	double getgia();
	void set_tennuoc(string nuocmoi);
	void set_sl(int slmoi);
	void set_gianuoc(double giamoi);
	double muanuoc(int slmoi);
	void Display();
};

class MovieTicketMaster
{
private:
	Movie* p_dsphim;
	Nuoc* p_dsnuoc;
	string tenrap;
	string diachi;
public:
	MovieTicketMaster();
	MovieTicketMaster(string my_theater_name, string my_theater_location);
	~MovieTicketMaster();
	void Init(Movie* p_my_MovieList, int array_size);
	void Init(Nuoc* p_my_drinklist, int array_size);
	void Run();
	void DisplayMenu();
	void ViewMovies();
	Movie* SearchMovie();
	Movie* FindMovie(string find_movie_name);
	void MuaVe();
	Nuoc* SearchNuoc();
	Nuoc* FindNuoc(string find_drink_name);
	void MuaNuoc();
	void ViewDrink();
};
