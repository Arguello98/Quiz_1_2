#include <iostream>
#include <vector>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Nodo_medios{
	string nombreArchivo;
	string tipoArchivo;
	string ubicacion;
	int referencia;
	
	Nodo_medios(string nA, string t, string u, int ref){
		tipoArchivo = t;
		nombreArchivo = nA;
		ubicacion = u; 
		referencia = ref;
	}
};

class Noticia{
	public:
		string titulo;
		string fecha;
		string reportero;
		vector <Nodo_medios> medios;
		Noticia(string t, string f, string r){
			titulo = t;
			fecha = f;
			reportero = r;
		}
		
		void noticiaBase(){
			cout <<"Titulo: "<<titulo<<endl;
			cout<<"Fecha: " <<fecha<<endl;
			cout <<"Reportero: " <<reportero<<endl;
		}
		
		virtual void getinfo() = 0;
};

class NoticiaPaper : public Noticia{
	public:		
		NoticiaPaper(string t, string f, string r, string ruta, string nombre):Noticia(t,f,r){
			medios.push_back( Nodo_medios(nombre, ".txt" ,ruta, medios.size())) ;
		}
		void getinfo(){
			noticiaBase();
			cout <<"Ruta de Archivo: " <<medios[0].ubicacion<<endl;
			cout<<"---------------------------"<<endl;
		}
	
};




class NoticiaDigital : public Noticia{
	public:
		NoticiaDigital(string t, string f, string r):Noticia(t,f,r){
		}
		void agregarMedio(string nA, string tipo,string u){
			medios.push_back(Nodo_medios(nA,tipo,u, medios.size()));
		}
		
		void getinfo(){
			noticiaBase();
			for(int i = 0; i<medios.size();i++){
				cout<<medios[i].nombreArchivo << "  "<<medios[i].tipoArchivo<< " "<<medios[i].ubicacion<< " "<< medios[i].referencia<<endl;
			}
			cout<<"---------------------------"<<endl;
		}
};

class NoticiaRadio : public Noticia{
	public:
		NoticiaRadio(string t, string f, string r, string url, string nombre):Noticia(t,f,r){
			medios.push_back( Nodo_medios(nombre, ".mp3",url , medios.size()));
		}
		void getinfo(){
			noticiaBase();
			cout<<"Url de audio file: "<< medios[0].ubicacion<<endl;
			cout<<"---------------------------"<<endl;
		}
};

int main(int argc, char** argv) {
	NoticiaDigital n("Noticia Digital","28/02/22","Daniel");
	n.agregarMedio("Video_","Video","C:/Persona");
	n.agregarMedio("Foto","JPG","C:");	
	n.agregarMedio("Audio","mp3","C:/algo");
	
	
	vector<Noticia*> h;
	h.push_back(new NoticiaRadio("Noticia Radio","28/02/22","Daniel","AudioFile", "charla"));
	h.push_back(&n);
	
	for(int i=0; i<h.size(); i++){
		h[i]->getinfo();
	}
	return 0;
}
