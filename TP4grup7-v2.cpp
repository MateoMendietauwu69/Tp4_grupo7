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
        int atontado=0;
        int quemado=0;
        int ahogado=0;
        int mareado=0;
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
        int getatontado(){
            return atontado;
        }
        int getquemado(){
            return quemado;
        }
        int getahogado(){
            return ahogado;
        }
        int getmareado(){
            return mareado;
        }
        void setatontado(int a){
            atontado=a;
        }
        void setquemado(int a){
            quemado=a;
        }
        void setahogado(int a){
            ahogado=a;
        }
        void setmareado(int a){
            mareado=a;
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
        void golpecrit(pj* a){
            if(a->getesc()>0)
	        {
			    a->setesc(a->getesc()-1);
			    a->sethp(a->gethp()-dano+10/2);
		    }else{
			    a->sethp(a->gethp()-dano+10);
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
		    int stun,prob;
            stun=rand()%5+1;
            prob=rand()%5+1;
            if(a->getesc()>0)
		    {
			    a->setesc(a->getesc()-1);
			    a->sethp(a->gethp()-b/2);
		    }else
		    {
			    a->sethp(a->gethp()-b);
		    }
            if(stun==prob)
                a->setatontado(getatontado()+1);
	    }
};
class fuego: public pj{
    public:
	    fuego(string a,int b):pj(a,b){
		    setdano(getdano()+10);
	    }
	    void lanzallamas(pj* &a, int b){
		    int stun,prob;
            stun=rand()%5+1;
            prob=rand()%5+1;
            if(a->getesc()>0)
		    {
			    a->setesc(a->getesc()-1);
			    a->sethp(a->gethp()-b/2);
		    }else
		    {
			    a->sethp(a->gethp()-b);
		    }
            if(stun==prob)
                a->setquemado(getquemado()+2);
	    }
};
class agua: public pj{
    public:
	    agua(string a,int b):pj(a,b){
		    sethp(gethp()+25);
	    }
	    void sunami(pj* &a,int b){
		    int stun,prob;
            stun=rand()%5+1;
            prob=rand()%5+1;
            if(a->getesc()>0)
		    {
			    a->setesc(a->getesc()-1);
			    a->sethp(a->gethp()-b/2);
		    }else{
			    a->sethp(a->gethp()-b);
		    }
            if(stun==prob)
                a->setahogado(getahogado()+2);
	    }
		void curaragua(pj* &a){
    	    int ex=0;
		    a->sethp(a->gethp()+15);
		    if(a->gethp()>125){
			    ex=a->gethp()-125;
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
		    int stun,prob;
            stun=rand()%5+1;
            prob=rand()%5+1;
            if(a->getesc()>0)
		    {
			    a->setesc(a->getesc()-1);
			    a->sethp(a->gethp()-b/2);
		    }else
		    {
			    a->sethp(a->gethp()-b);
		    }
            if(stun==prob)
                a->setmareado(getmareado()+1);
	    }
};

void duelo(pj* &a,pj* &b, char c, char d);
void mostrarsalud(int a, char b);
void estado(pj* &a,pj* v,char A,char V,bool &b);
string colnom(pj* a,char b);

int main(){
	srand(time(nullptr));
	vector<pj*>per(2,nullptr);
	int vel;
	string a;
	char op;
	vector<char>p(2);
    cout<<"\033[1;33mISOS'S ELEMENTS\033[0m"<<endl;
    cout<<"\033[1;31mISOS'S ELEMENTS\033[0m"<<endl;
    cout<<"\033[1;34mISOS'S ELEMENTS\033[0m"<<endl;
    cout<<"\033[1;37mISOS'S ELEMENTS\033[0m"<<endl;
    system("pause");
    system("cls");
	for(int i=0;i<2;i++){
        do{
            cout<<"elija elemento de guerrero "<<i+1<<":"<<endl;
		    cout<<"A-"<<"\033[1;33mTierra\033[0m"<<" (+1 escudo)"<<endl;
		    cout<<"B-"<<"\033[1;31mFuego\033[0m"<<" (+10 ataque)"<<endl;
		    cout<<"C-"<<"\033[1;34mAgua\033[0m"<<" (+25 hp)"<<endl;
		    cout<<"D-"<<"\033[1;37mViento\033[0m"<<" (+10 velocidad)"<<endl;
		    cin>>op;
            system("cls");
        }while(tolower(op)!='a' && tolower(op)!='b' && tolower(op)!='c' && tolower(op)!='d');
        p[i]=op;
	    cout<<"ingrese nombre:";
	    cin>>a;
	    vel=rand()%10+1;
	    if(tolower(op)=='a'){
		    per[i]=new tierra (a,vel);
	    }
	    if(tolower(op)=='b'){
		    per[i]=new fuego(a,vel);
	    }
	    if(tolower(op)=='c'){
		    per[i]=new agua(a,vel);
	    }
	    if(tolower(op)=='d'){
		    per[i]=new viento(a,vel);
		}
        system("cls");
	}
	for(int o=0;o<2;o++){
		cout<<"---Stats---"<<endl;
		cout<<"NOMBRE: "<<colnom(per[o],p[o])<<endl;
		cout<<"ATAQUE: "<<per[o]->getdano()<<endl;
		cout<<"ESCUDO: "<<per[o]->getesc()<<endl;
		cout<<"HP: "<<per[o]->gethp()<<endl;
		cout<<"VELOCIDAD: "<<per[o]->getvelocidad()<<endl<<endl;
	}
    system("pause");
    system("cls");
	cout<<"---DUELO---"<<endl<<endl;
	if(per[0]->getvelocidad()>=per[1]->getvelocidad()){
		duelo(per[0],per[1],p[0],p[1]);
	}else{
		duelo(per[1],per[0],p[1],p[0]);
	}
	if(per[0]->gethp()<=0){
        cout<<"========================================="<<endl;
        cout<<"            !TENEMOS UN GANADOR!"<<endl;
        cout<<"========================================="<<endl;
        cout<<"                 "<<colnom(per[1],p[1])<<endl;
        cout<<"     !Ha demostrado su gran poder!"<<endl;
        cout<<"========================================="<<endl;
    }else{   
	    cout<<"========================================="<<endl;
        cout<<"            !TENEMOS UN GANADOR!"<<endl;
        cout<<"========================================="<<endl;
        cout<<"                 "<<colnom(per[0],p[0])<<endl;
        cout<<"     !Ha demostrado su gran poder!"<<endl;
        cout<<"========================================="<<endl;
    }
	return 0;
}
	
void duelo(pj* &a,pj* &b, char c, char d){
    int crit,valcrit;
    string op;
    char o;
    bool band;
	cout<<colnom(a,c)<<" inicia el combate"<<endl<<endl;
	do
	{
		band=false;
        do
		{
			estado(a,b,c,d,band);
            if(band)break;
            crit=rand()%10+1;
            valcrit=rand()%10+1;
            cout<<"--Turno de "<<colnom(a,c)<<"--"<<endl<<endl;
			cout<<"1 - Golpe"<<endl;
			if(tolower(c)=='a'){
				cout<<"2 - Lanzarrocas"<<endl;
			}
			if(tolower(c)=='b'){
				cout<<"2 - Lanzallamas"<<endl;
			}
			if(tolower(c)=='c'){
				cout<<"2 - Stunami"<<endl;
			}
			if(tolower(c)=='d'){
				cout<<"2 - Tornado"<<endl;
			}
			cout<<"3 - Bloquear"<<endl;
			cout<<"4 - Curarse"<<endl<<endl;
			mostrarsalud(a->gethp(),c);
			cout<<"Escudo: "<<a->getesc()<<endl;
            cout<<"Ataque: "<<a->getdano()<<endl;
			cin>>op;
            o=op[0];
			switch (o)
			{
			case '1':
				system("cls");
                cout<<colnom(a,c)<<" golpeo ferozmente a "<<colnom(b,d)<<endl;
				if(crit==valcrit){
                    a->golpecrit(b);
                    cout<<"GOLPE CRITICO"<<endl;
                }
                a->golpear(b);
				break;
			case '2':
				system("cls");
				if(tolower(c)=='a'){
                    cout<<colnom(a,c)<<" lanzo rocas gigantes a "<<colnom(b,d)<<endl;
					if(crit==valcrit){
                        a->lanzarroca(b,a->getdano()+10);
                        cout<<"GOLPE CRITICO"<<endl;
                    }
                    a->lanzarroca(b,a->getdano());
				}
				if(tolower(c)=='b'){
                    cout<<colnom(a,c)<<" lanzo fuego abrasador sobre "<<colnom(b,d)<<endl;
                    if(crit==valcrit){
                        a->lanzallamas(b,a->getdano()+10);
                        cout<<"GOLPE CRITICO"<<endl;
                    }
					a->lanzallamas(b,a->getdano());
				}
				if(tolower(c)=='c'){
                    cout<<colnom(a,c)<<" inundo el campo de batalla"<<endl;
                    if(crit==valcrit){
                        a->sunami(b,a->getdano()+10);
                        cout<<"GOLPE CRITICO"<<endl;
                    }
					a->sunami(b,a->getdano());
				}
				if(tolower(c)=='d'){
                    cout<<colnom(a,c)<<" creo una poderosa corriente de aire"<<endl;
                    if(crit==valcrit){
                        a->tornado(b,a->getdano()+10);
                        cout<<"GOLPE CRITICO"<<endl;
                    }
					a->tornado(b,a->getdano());
				}
				break;
			case '3':
				system("cls");
                cout<<colnom(a,c)<<" se cubrio"<<endl;
                cout<<"+1 escudo"<<endl;
				a->bloquear();
				break;
			case '4':
				system("cls");
				if((tolower(c)!='c' && a->gethp()==100) || (tolower(c)=='c' && a->gethp()==125)){
					cout<<"Salud al maximo"<<endl;
					o='6';
					break;
				}
				if(tolower(c)=='c'){
                    cout<<colnom(a,c)<<" recupero HP"<<endl;
                    if(a->gethp()>110)
                        cout<<"+"<<125-a->gethp()<<" HP"<<endl;
                    else
                        cout<<"+15 HP"<<endl;
					a->curaragua(a);
                }else{
                    cout<<colnom(a,c)<<" recupero HP"<<endl;
                    if(a->gethp()>85)
                        cout<<"+"<<100-a->gethp()<<" HP"<<endl;
                    else
                        cout<<"+15 HP"<<endl;
					a->curar();
                }
				break;
			default:
				system("cls");
				cout<<"No es opcion"<<endl;
				break;
			}
		} while (o!='1' && o!='2' && o!='3' && o!='4');
        system("pause");
		if(b->gethp()<=0)break;
        band=false;
		do
		{
			estado(b,a,d,c,band);
            if(band)break;
            crit=rand()%10+1;
            valcrit=rand()%10+1;
            cout<<"--Turno de "<<colnom(b,d)<<"--"<<endl<<endl;
			cout<<"1 - Golpe"<<endl;
			if(tolower(d)=='a'){
				cout<<"2 - Lanzarrocas"<<endl;
			}
			if(tolower(d)=='b'){
				cout<<"2 - Lanzallamas"<<endl;
			}
			if(tolower(d)=='c'){
				cout<<"2 - Stunami"<<endl;
			}
			if(tolower(d)=='d'){
				cout<<"2 - Tornado"<<endl;
			}
			cout<<"3 - Bloquear"<<endl;
			cout<<"4 - Curarse"<<endl<<endl;
			mostrarsalud(b->gethp(),d);
			cout<<"Escudo: "<<b->getesc()<<endl;
            cout<<"Ataque: "<<b->getdano()<<endl;
			cin>>op;
            o=op[0];
			switch (o)
			{
			case '1':
				system("cls");
                cout<<colnom(b,d)<<" golpeo ferozmente a "<<colnom(a,c)<<endl;
                if(crit==valcrit){
                    cout<<"GOLPE CRITICO"<<endl;
                    b->golpecrit(a);
                }
				b->golpear(a);
				break;
			case '2':
				system("cls");
				if(tolower(d)=='a'){
                    cout<<colnom(b,d)<<" lanzo rocas gigantes a "<<colnom(a,c)<<endl;
                    if(crit==valcrit){
                        cout<<"GOLPE CRITICO"<<endl;
                        b->lanzarroca(a,b->getdano()+10);
                    }
					b->lanzarroca(a,b->getdano());
				}
				if(tolower(d)=='b'){
                    cout<<colnom(b,d)<<" lanzo fuego abrasador sobre "<<colnom(a,c)<<endl;
                    if(crit==valcrit){
                        cout<<"GOLPE CRITICO"<<endl;
                        b->lanzallamas(a,b->getdano()+10);
                    }
					b->lanzallamas(a,b->getdano());
				}
				if(tolower(d)=='c'){
                    cout<<colnom(b,d)<<" inundo el campo de batalla"<<endl;
                    if(crit==valcrit){
                        cout<<"GOLPE CRITICO"<<endl;
                        b->sunami(a,b->getdano()+10);
                    }
					b->sunami(a,b->getdano());
				}
				if(tolower(d)=='d'){
                    cout<<colnom(b,d)<<" creo una poderosa corriente de aire"<<endl;
                    if(crit==valcrit){
                        cout<<"GOLPE CRITICO"<<endl;
                        b->tornado(a,b->getdano()+10);
                    }
					b->tornado(a,b->getdano());
				}
				break;
			case '3':
				system("cls");
                cout<<colnom(b,d)<<" se cubrio"<<endl;
                cout<<"+1 escudo"<<endl;
				b->bloquear();
				break;
			case '4':
				system("cls");
				if((tolower(d)!='c' && b->gethp()==100) || (tolower(d)=='c' && b->gethp()==125)){
					cout<<"Salud al maximo"<<endl;
					o='6';
					break;
				}
				if(tolower(d)=='c'){
                    cout<<colnom(b,d)<<" recupero HP"<<endl;
                    if(b->gethp()>110)
                        cout<<"+"<<125-b->gethp()<<" HP"<<endl;
                    else
                        cout<<"+15 HP"<<endl;
					b->curaragua(b);
                }else{
                    cout<<colnom(b,d)<<"recupero HP"<<endl;
                    if(b->gethp()>85)
                        cout<<"+"<<100-b->gethp()<<" HP"<<endl;
                    else
                        cout<<"+15 HP"<<endl;
					b->curar();
                }
				break;
			default:
				system("cls");
				cout<<"No es opcion"<<endl;
				break;
			}
		} while (o!='1' && o!='2' && o!='3' && o!='4');
        system("pause");
	    if(a->gethp()<=0)break;
	} while (a->gethp()>0 && b->gethp()>0);
}
		
void mostrarsalud(int a, char b){
	int hpMax, barras=10;
	if(tolower(b)=='c')
		hpMax=125; 
	else
		hpMax=100; 
	int bloques = (a*barras)/hpMax;
	cout << "[";
	for (int i = 0; i < bloques; i++) {
		cout << "\033[32m#\033[0m";
	}
	for (int i=bloques;i<barras;i++) {
		cout<<"-";
	}
	cout<<"] "<<a<<"/"<<hpMax<<" HP"<<endl;
}

void estado(pj* &a,pj* v,char A,char V,bool &b){
    int random;
    if(a->getatontado()>0){
        cout<<colnom(a,A)<<" ESTA ATONTADO"<<endl;
        cout<<"no puede moverse"<<endl;
        
        a->setatontado(a->getatontado()-1);
        b=true;
    }
    if(a->getquemado()>0){
        cout<<colnom(a,A)<<" SE QUEMO"<<endl;
        cout<<"-5 HP"<<endl;
        a->sethp(a->gethp()-5);
        a->setquemado(a->getquemado()-1);
    }
    if(a->getahogado()==0){
        if(tolower(A)=='b')
            a->setdano(30);
        else
            a->setdano(20);
    }
    if(a->getahogado()>0){
        cout<<colnom(a,A)<<" SE AHOGO"<<endl;
        cout<<"ataque reducido a la mitad"<<endl;
        a->setdano(a->getdano()/2);
        a->setahogado(a->getahogado()-1);
    }
    if(a->getmareado()>0){
        random=rand()%4+1;
        cout<<colnom(a,A)<<" ESTA MAREADO"<<endl;
        if(random==1){
            cout<<colnom(a,A)<<"golpeo ferozmente a "<<colnom(v,V)<<endl;
            a->golpear(v);
        }
        if(random==2){
            if(tolower(A)=='a'){
                cout<<colnom(a,A)<<"lanzo rocas gigantes a "<<colnom(v,V)<<endl;
                a->lanzarroca(v,a->getdano());
			}
			if(tolower(A)=='b'){
				cout<<colnom(a,A)<<"lanzo fuego abrasador sobre "<<colnom(v,V)<<endl;
                a->lanzallamas(v,a->getdano());
			}
			if(tolower(A)=='c'){
				cout<<colnom(a,A)<<"inundo el campo de batalla"<<endl;
                a->sunami(v,a->getdano());
			}
			if(tolower(A)=='d'){
				cout<<colnom(a,A)<<"creo una poderosa corriente de aire"<<endl;
                a->tornado(v,a->getdano());
			}
        }
        if(random==3){
            cout<<colnom(a,A)<<" se cubrio"<<endl;
            cout<<"+1 escudo"<<endl;
            a->bloquear();
        }
        if(random==4){
            if((tolower(A)!='c' && a->gethp()==100) || (tolower(A)=='c' && a->gethp()==125)){
				cout<<"Salud al maximo"<<endl;
			}
			if(tolower(A)=='c'){
				cout<<colnom(a,A)<<"recupero HP"<<endl;
                if(a->gethp()>110)
                    cout<<"+"<<125-a->gethp()<<" HP"<<endl;
                else
                    cout<<"+15 HP"<<endl;
                a->curaragua(a);
			}else{
				cout<<colnom(a,A)<<"recupero HP"<<endl;
                if(a->gethp()>85)
                    cout<<"+"<<100-a->gethp()<<" HP"<<endl;
                else
                    cout<<"+15 HP"<<endl;
                a->curar();
            }
        }
        a->setmareado(a->getmareado()-1);
        b=true;
    }
}

string colnom(pj* a,char b){
    if(tolower(b)=='a')
        return "\033[1;33m"+a->getnom()+"\033[0m";
    if(tolower(b)=='b')
        return "\033[1;31m"+a->getnom()+"\033[0m";
    if(tolower(b)=='c')
        return "\033[1;34m"+a->getnom()+"\033[0m";
    if(tolower(b)=='d')
        return "\033[1;37m"+a->getnom()+"\033[0m";
}