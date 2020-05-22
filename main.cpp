#include <iostream>
#include<stdlib.h>
#include <fstream>
#include <vector>
using namespace std;

class cgii{
	
	public:
		
		string napis;
		vector<string> tab;
		
		ifstream plik1;
	    ofstream plik2;
			
		cgii();
	    ~cgii();
			
		void wczytaj();
		void wypisz();
};

cgii::cgii(){
    plik1.open("c:\\palindromy.txt");
    plik2.open("c:\\wynikJSON.txt");
};

void cgii::wczytaj(){
	
	 if(plik1.good()) {
		 while(!plik1.eof()){
	        getline(plik1, napis);
			tab.push_back(napis);				
	    };	
	 };
};

void cgii::wypisz(){
	
	cout<<"Content-Type: application/json;Access-Control-Allow-Origin: *" << (char)13 << (char)10;
	cout<<endl<<"[";
	
	for(int i=0;i<tab.size();i+=2){
		cout<<"{\"imie"<<"\":\""<<tab[i]<<"\",\"subtitle\":\""<<tab[i+1]<<"\"}";
		if(i<tab.size()-2)cout<<",";
	};
	
	cout<<"]";
};

cgii::~cgii(){
    plik1.close();
    plik2.close();
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cgii lol;
	lol.wczytaj();
	lol.wypisz();
	return 0;
}
