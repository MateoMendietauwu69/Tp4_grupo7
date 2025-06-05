#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
class pj{
    private:
	    string nom;
	    int hp=100;
	    int esc=0;
	    int dano=20;
	    int velocidad;
    public:
	    pj(string nwnom,int a){
		    nom=nwnom;
		    velocidad=a;
	    }
	    string getnom(){
		    return nom;
	    }
	    int gethp(){
		    return hp;
	    }
	    int getesc(){
    	    return esc;
	    }
	    int getdano(){
		    return dano;
	    }
	    int getvelocidad(){
		    return velocidad;
	    }
	    void setvelocidad(int a){
		    velocidad=a;
	    }
	    void sethp(int a){
		    hp=a;
	    }
	    void setesc(int a){
		    esc=a;
	    }
	    void setdano(int a){
		    dano=a;
	    }
	    void golpear(pj* &a){
	        if(a->getesc()>0)
	        {
			    a->setesc(a->getesc()-1);
			    a->sethp(a->gethp()-dano/2);
		    }else{
			    a->sethp(a->gethp()-dano);
		    }
	    }
	    void bloquear(){
		    esc=esc+1;
	    }
	    void curar(){
		    int ex=0;
		    hp=hp+15;
		    if(hp>100)
		    {
			    ex=hp-100;
			    hp=hp-ex;
		    }
	    }
	    virtual void lanzarroca(pj* &a,int b){}
	    virtual void lanzallamas(pj* &a, int b){}
	    virtual void sunami(pj* &a,int b){}
        virtual void tornado(pj* &a,int b){}
	    virtual void curaragua(pj* &a){}
};
class tierra: public pj{
    public:
	    tierra(string a,int b):pj(a,b){
		    setesc(getesc()+1);
	    }
	    void lanzarroca(pj* &a,int b){
		    if(a->getesc()>0)
		    {
			    a->setesc(a->getesc()-1);
			    a->sethp(a->gethp()-b/2);
		    }else
		    {
			    a->sethp(a->gethp()-b);
		    }
	    }
};
class fuego: public pj{
    public:
	    fuego(string a,int b):pj(a,b){
		    setdano(getdano()+10);
	    }
	    void lanzallamas(pj* &a, int b){
		    if(a->getesc()>0)
		    {
			    a->setesc(a->getesc()-1);
			    a->sethp(a->gethp()-b/2);
		    }else
		    {
			    a->sethp(a->gethp()-b);
		    }
	    }
};
class agua: public pj{
    public:
	    agua(string a,int b):pj(a,b){
		    sethp(gethp()+50);
	    }
	    void sunami(pj* &a,int b){
		    if(a->getesc()>0)
		    {
			    a->setesc(a->getesc()-1);
			    a->sethp(a->gethp()-b/2);
		    }else{
			    a->sethp(a->gethp()-b);
		    }
	    }
		void curaragua(pj* &a){
    	    int ex=0;
		    a->sethp(a->gethp()+15);
		    if(a->gethp()>150){
			    ex=a->gethp()-150;
			    a->sethp(a->gethp()-ex);
		    }
	    }
};
class viento: public pj{
    public:
	    viento(string a,int b):pj(a,b){
		    setvelocidad(getvelocidad()+10);
	    }
	    void tornado(pj* &a,int b){
		    if(a->getesc()>0)
		    {
			    a->setesc(a->getesc()-1);
			    a->sethp(a->gethp()-b/2);
		    }else
		    {
			    a->sethp(a->gethp()-b);
		    }
	    }
};

void duelo(pj* &a,pj* &b, char c, char d, char e);
void mostrarsalud(int a, char b);

int main(){
	srand(time(nullptr));
	vector<pj*>per(2,nullptr);
	int vel;
	string a;
	char op;
	vector<char>p(2);
	for(int i=0;i<2;i++){
		cout<<"elija elemento de guerrero:"<<endl;
		cout<<"A-Tierra (+1 escudo)"<<endl;
		cout<<"B-Fuego (+10 dano)"<<endl;
		cout<<"C-Agua (+50 hp)"<<endl;
		cout<<"D-Viento (+10 velocidad)"<<endl;
		cin>>op;
		p[i]=op;
		cout<<"ingrese nombre:";
		cin>>a;
		vel=rand()%10+1;
		if(op=='a' || op=='A'){
			per[i]=new tierra (a,vel);
		}
		if(op=='b' || op=='B'){
			per[i]=new fuego(a,vel);
		}
		if(op=='c' || op=='C'){
			per[i]=new agua(a,vel);
		}
		if(op=='d' || op=='D'){
			per[i]=new viento(a,vel);
		}
		system("cls");
	}
	for(int o=0;o<2;o++){
		cout<<"Stats:"<<endl;
		cout<<"nombre: "<<per[o]->getnom()<<endl;
		cout<<"dano: "<<per[o]->getdano()<<endl;
		cout<<"escudo: "<<per[o]->getesc()<<endl;
		cout<<"hp: "<<per[o]->gethp()<<endl;
		cout<<"velocidad: "<<per[o]->getvelocidad()<<endl<<endl;
	}
	cout<<"---DUELO---"<<endl<<endl;
	if(per[0]->getvelocidad()>=per[1]->getvelocidad()){
		duelo(per[0],per[1],p[0],p[1],op);
	}else{
		duelo(per[1],per[0],p[1],p[0],op);
	}
	if(per[0]->gethp()<=0)
		cout<<per[1]->getnom()<<" es el GANADOR"<<endl;
	else   
		cout<<per[0]->getnom()<<" es el GANADOR"<<endl;
	
	return 0;
}
	
	void duelo(pj* &a,pj* &b, char c, char d, char e){
		cout<<a->getnom()<<" inicia el combate"<<endl<<endl;
		do
		{
			do
			{
				cout<<"turno de "<<a->getnom()<<endl;
				cout<<"1 - Golpe"<<endl;
				if(c=='a' || c=='A'){
					cout<<"2 - Lanzarrocas"<<endl;
				}
				if(c=='b' || c=='B'){
					cout<<"2 - Lanzallamas"<<endl;
				}
				if(c=='c' || c=='C'){
					cout<<"2 - Stunami"<<endl;
				}
				if(c=='d' || c=='D'){
					cout<<"2 - Tornado"<<endl;
				}
				cout<<"3 - Bloquear"<<endl;
				cout<<"4 - Curarse"<<endl<<endl;
				mostrarsalud(a->gethp(),c);
				cout<<"DEFENSA: "<<a->getesc()<<endl;
				cin>>e;
				switch (e)
				{
				case '1':
					system("cls");
					a->golpear(b);
					break;
				case '2':
					system("cls");
					if(c=='a' || c=='A'){
						a->lanzarroca(b,a->getdano());
					}
					if(c=='b' || c=='B'){
						a->lanzallamas(b,a->getdano());
					}
					if(c=='c' || c=='C'){
						a->sunami(b,a->getdano());
					}
					if(c=='d' || c=='D'){
						a->tornado(b,a->getdano());
					}
					break;
				case '3':
					system("cls");
					a->bloquear();
					break;
				case '4':
					system("cls");
					if((tolower(c) != 'c' && a->gethp() == 100) || (tolower(c) == 'c' && a->gethp() == 150)){
						cout<<"Salud al maximo"<<endl;
						e='6';
						break;
					}
					if(c=='c' || c=='C')
																	a->curaragua(a);
					else
						a->curar();
					break;
				default:
					system("cls");
					cout<<"  No es opcion  >:(  "<<endl;
					break;
				}
			} while (e!='1' && e!='2' && e!='3' && e!='4');
			if(b->gethp()<=0)break;
			do
			{
				cout<<"Turno de "<<b->getnom()<<endl;
				cout<<"1 - Golpe"<<endl;
				if(d=='a' || d=='A'){
					cout<<"2 - Lanzarrocas"<<endl;
				}
				if(d=='b' || d=='B'){
					cout<<"2 - Lanzallamas"<<endl;
				}
				if(d=='c' || d=='C'){
					cout<<"2 - Stunami"<<endl;
				}
				if(d=='d' || d=='D'){
					cout<<"2 - Tornado"<<endl;
				}
				cout<<"3 - Bloquear"<<endl;
				cout<<"4 - Curarse"<<endl<<endl;
				mostrarsalud(b->gethp(),d);
				cout<<"DEFENSA: "<<b->getesc()<<endl;
				cin>>e;
				switch (e)
				{
				case '1':
					system("cls");
					b->golpear(a);
					break;
				case '2':
					system("cls");
					if(d=='a' || d=='A'){
						b->lanzarroca(a,b->getdano());
					}
					if(d=='b' || d=='B'){
						b->lanzallamas(a,b->getdano());
					}
					if(d=='c' || d=='C'){
						b->sunami(a,b->getdano());
					}
					if(d=='d' || d=='D'){
						b->tornado(a,b->getdano());
					}
					break;
				case '3':
					system("cls");
					b->bloquear();
					break;
				case '4':
					system("cls");
					if((tolower(d) != 'c' && b->gethp() == 100) || (tolower(d) == 'c' && b->gethp() == 150)){
						cout<<"Salud al maximo"<<endl;
						e='6';
						break;
					}
					if(d=='c' || d=='C')
																	b->curaragua(b);
					else
						b->curar();
					break;
				default:
					system("cls");
					cout<<"No es opcion"<<endl;
					break;
				}
			} while (e!='1' && e!='2' && e!='3' && e!='4');
			if(a->gethp()<=0)break;
		} while (a->gethp()>0 && b->gethp()>0);
	}
		
	void mostrarsalud(int a, char b){
		int hpMax, barras=10;
		if(b=='c' || b=='C')
			hpMax=150; 
		else
			hpMax=100; 
		int bloques = (a*barras)/hpMax;
		cout << "[";
		for (int i = 0; i < bloques; i++) {
			cout << "#";
		}
		for (int i=bloques;i<barras;i++) {
			cout<<"-";
		}
		cout<<"] "<<a<<"/"<<hpMax<<" HP"<<endl;
	}