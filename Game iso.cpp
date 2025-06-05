#include <iostream>
#include <string>
using namespace std;

class personaje {
protected:  
    string nombre;
    int ataque;
    int salud;
    int defensa;

public:
    personaje(string nombre, int ataque, int salud, int defensa) {
        this->nombre=nombre; //(el this es un puntero y funca para aclar q se accede a un atributo de la clase)
        this->ataque=ataque;
        this->salud=salud;
        this->defensa=defensa;
    }

    virtual void mostrarInformacion(){
        cout<<"Nombre: "<<nombre<<endl;
        cout<<"Ataque: "<<ataque<<endl;
        cout<<"Salud: "<<salud<<endl;
        cout<<"Defensa: "<<defensa<<endl;
    }

    virtual void recibirDanio(int cantidad) {
        int danioReal=cantidad-defensa;
        if(danioReal < 1) danioReal=1;
        salud-=danioReal;
        if(salud<0)salud=0;
        cout<<nombre<<" recibio "<<danioReal<<" dano. Salud restante: "<<salud<<endl;
    }

    bool estaVivo() const{
        return salud > 0;
    }

    string getNombre(){
        return nombre;
    }

    int getAtaque(){
        return ataque;
    }

    void setNombre(string nombre){
        this->nombre=nombre;
    }
};

class Saiyayin:public personaje {
private:
    int kame;
    string tranformation;

public:
    Saiyayin(string nombre, int ataque, int salud, int defensa, int kame, string tranformation)
        : personaje(nombre, ataque, salud, defensa) {
        this->kame=kame;
        this->tranformation=tranformation;
    }

    void atacar(personaje& objetivo) {
        cout<<getNombre()<<" lanza un ataque a "<<objetivo.getNombre()
             <<" con poder de "<< getAtaque()<<"!"<<endl;
        objetivo.recibirDanio(getAtaque());
    }

    void mostrarInformacion() override {
        personaje::mostrarInformacion();
        cout<<"Kamehameha: "<<kame<<endl;
        cout<<"Transformación: "<<tranformation<<endl;
    }
};

int combate(){

}
int main() {
    Saiyayin Gogeta("Gogeta", 40, 100, 10, 80, "Super Saiyajin Blue");
    Saiyayin Broly("Broly", 35, 90, 12, 70, "Super SSj");

    Gogeta.mostrarInformacion();
    cout<<endl;
    Broly.mostrarInformacion();
    cout<<"\n--- COMBATE ---\n";
    
    Gogeta.atacar(Broly);

    Broly.mostrarInformacion();
    cout<<endl;
    Gogeta.mostrarInformacion();
    cout<<"\n--- COMBATE ---\n";
    
    Broly.atacar(Gogeta);

    return 0;

    
}
