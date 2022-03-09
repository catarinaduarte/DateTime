#include <iostream>
#include <string>

using namespace std;

class Data {
    public:
		Data( int dia, int mes, int ano);
        int dia, mes, ano;
};

class Hora {
    public:
	    Hora(int hora, int min, int seg);
        int hora, min, seg;
};

class DataHora {
	public:

	    DataHora(int hora, int min, int seg, int dia, int mes, int ano);
    	DataHora(int dia, int mes, int ano);
        ~DataHora();
		Hora *getEstaHora();

	private:
		Data *estaData;
        Hora *estaHora;
};

DataHora::DataHora(int hora, int min, int seg, int dia, int mes, int ano) {
	estaData = new Data(dia, mes, ano);
	estaHora = new Hora(hora, min, seg);
}

DataHora::DataHora(int dia, int mes, int ano) {
	estaData = new Data(dia, mes, ano);
	estaHora = new Hora(0, 0, 0);
}

DataHora::~DataHora() {
	delete estaData;
    delete estaHora;
}

Hora *DataHora::getEstaHora() {
    return( estaHora );
}

int main (void)
{
	DataHora dt = DataHora( 1, 1,2022 );
	// dt.estaHora->hora = 12; <- estaHora é privado
	dt.getEstaHora()->hora = 12;
}