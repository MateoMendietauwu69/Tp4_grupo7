#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class personaje
{
private:
	string nombre;
	int vida;
	int vidamax;
public:
	personaje(string nombre, int vida)
	{
		this->nombre=nombre;
		this->vida=vida;
		vidamax=vida;
	}
	void virtual mostrar()
	{
		cout<<"CHARACTER: "<<nombre<<endl;
		cout<<"HEALTH POINTS: "<<vida<<endl;
	}
	void recibirdano(int dano)
	{
		vida=vida-dano;
	}
	string getnombre()
	{
		return nombre;
	}
	void setnombre(string nombre)
	{
		this->nombre=nombre;
	}
	int getvida()
	{
		return vida;
	}
	void setvida(int vida)
	{
		this->vida=vida;
	}
	int getvidamax()
	{
		return vidamax;
	}
	bool morir()
	{
		if(vida<=0)
			return true;
		else
			return false;
	}
};

class guerrero : public personaje
{
private:
	int attack;
	bool escudo;
	bool rebote;
public:
	guerrero(string nombre, int vida, int attack,bool escudo) : personaje(nombre, vida)
	{
		this->attack=attack;
		this->escudo=escudo;
		rebote=false;
	}
	void mostrar() override
	{
		cout<<"      /\\    "<<endl;
		cout<<"      ||       CHARACTER: "<<getnombre()<<endl;
		cout<<"      ||       HEALTH POINTS: "<<getvida()<<endl;
		cout<<"      ||       DAMAGE: "<<attack<<endl;
		cout<<"     (==)      SPECIAL ABILITIES"<<endl;
		cout<<"      []       SHIELD: Proteje del siguiente ataque"<<endl<<endl;
	}
	void pov(int i)
	{
		cout<<"       <<<<<PLAYER "<<i<<" TURN>>>>>"<<endl;
		cout<<"             *   /\\ * "<<endl;
		cout<<"                /  \\  "<<endl;
		cout<<"              * |  |   "<<endl;
		cout<<"                |  | * "<<endl;
		cout<<"                |  |   "<<endl;
		cout<<"             *  |  |   *"<<endl;
		cout<<"                |  |   "<<endl;
		cout<<"                |  | * "<<endl;
		cout<<"              {IIIIII} "<<endl;
		cout<<"                 []    "<<endl;
		cout<<"                 []    "<<endl;
		cout<<"                 <>    "<<endl;
		cout<<"  HP "<<getvida()<<"/"<<getvidamax();
		if(escudo)
			cout<<"   SHIELD ON";
		cout<<endl;
		cout<<" _______________     _______________"<<endl;
		cout<<"| 1. ATTACK ("<<attack<<") |   |   2. SHIELD   |"<<endl;
		cout<<" ---------------     ---------------"<<endl;
		cout<<"            ____________"<<endl;
		cout<<"           | 3. RETURN  |"<<endl;
		cout<<"            ------------"<<endl;
		cout<<" SELECT OPTION: ";
	}
	void povenemigo(int i)
	{
		cout<<"              Player "<<i<<endl;
		cout<<"                 /\\   "<<endl;
		cout<<"                 ||    "<<endl;
		cout<<"                 ||    "<<endl;
		cout<<"                 ||    "<<endl;
		cout<<"                (==)   "<<endl;
		cout<<"                 []    "<<endl;
		cout<<"         HP "<<getvida()<<"/"<<getvidamax()<<"  DAMAGE "<<attack;
		if(escudo)
			cout<<"   SHIELD ON";
		cout<<endl<<endl;
		cout<<"                VS.  "<<endl<<endl;
		
	}
	int atacar()
	{
		return attack;
	}
	bool getescudo()
	{
		return escudo;
	}
	void setescudo(bool escudo)
	{
		this->escudo=escudo;
	}
	bool getrebote()
	{
		return rebote;
	}
	void setrebote(bool rebote)
	{
		this->rebote=rebote;
	}
	int rebotar(int dano)
	{
		if(rebote)
			return trunc(dano/2);
		else
			return 0;
	}
};

class alquimista : public personaje
{
private:
	int attack;
	int cura;
public:
	alquimista(string nombre, int vida, int attack,int cura) : personaje(nombre, vida)
	{
		this->attack=attack;
		this->cura=cura;
	}
	void mostrar() override
	{
		cout<<"     ::::   "<<endl;
		cout<<"      ||       CHARACTER: "<<getnombre()<<endl;
		cout<<"     /  \\      HEALTH POINTS: "<<getvida()<<endl;
		cout<<"    /____\\     DAMAGE: "<<attack<<endl;
		cout<<"   |      |    SPECIAL ABILITIES"<<endl;
		cout<<"    \\____/     HEALING: Cura "<<cura<<" puntos de vida"<<endl<<endl;
	}
	void pov(int i)
	{
		cout<<"       <<<<<PLAYER "<<i<<" TURN>>>>>"<<endl;
		cout<<"              ::::::::     "<<endl;
		cout<<"              ::::::::     "<<endl;
		cout<<"                ||||       "<<endl;
		cout<<"              //    \\\\    "<<endl;
		cout<<"             //      \\\\   "<<endl;
		cout<<"            //        \\\\  "<<endl;
		cout<<"           //          \\\\ "<<endl;
		cout<<"          ||\\/\\/\\/\\/\\/\\/|| "<<endl;
		cout<<"          || o     o    ||  "<<endl;
		cout<<"          ||   o      o ||  "<<endl;
		cout<<"           \\\\__________//  "<<endl;
		cout<<"             ==========     "<<endl;
		cout<<"  HP "<<getvida()<<"/"<<getvidamax()<<endl;
		cout<<" _______________     _________________"<<endl;
		cout<<"| 1. ATTACK ("<<attack<<") |   |   2. HEAL ("<<cura<<")   |"<<endl;
		cout<<" ---------------     -----------------"<<endl<<endl;
		cout<<" SELECT OPTION: ";
	}
	void povenemigo(int i)
	{
		cout<<"              Player "<<i<<endl;
		cout<<"                ::::      "<<endl;
		cout<<"                 ||       "<<endl;
		cout<<"                /  \\     "<<endl;
		cout<<"               /____\\    "<<endl;
		cout<<"              |      |    "<<endl;
		cout<<"               \\____/    "<<endl;
		cout<<"         HP "<<getvida()<<"/"<<getvidamax()<<"  DAMAGE "<<attack<<endl<<endl;
		cout<<"                 VS.  "<<endl<<endl;
		
	}
	int atacar()
	{
		return attack;
	}
	void curacion()
	{
		if(getvidamax()-cura>=getvida())
		{
			setvida(getvida()+cura);
			cout<<"+"<<cura<<" HP"<<endl;
		}
		else
		{
			setvida(getvida()+(getvidamax()-getvida()));
			cout<<"+"<<getvidamax()-getvida()<<" HP"<<endl;
		}
	}
	int getcura()
	{
		return cura;
	}
};

class mago : public personaje
{
private:
	int attack;
	int buff;
	int contadormax;
	int contador;
	int inmovmax;
public:
	int inmov;
	mago(string nombre, int vida, int attack,int buff,int contadormax,int inmovmax) : personaje(nombre, vida)
	{
		this->attack=attack;
		this->buff=buff;
		this->contadormax=contadormax;
		this->inmovmax=inmovmax;
		contador=0;
		inmov=0;
	}
	void mostrar() override
	{
		cout<<"     |\\        CHARACTER: "<<getnombre()<<endl;
		cout<<"     | \\       HEALTH POINTS: "<<getvida()<<endl;
		cout<<"     |  \\      DAMAGE: "<<attack<<endl;
		cout<<"     /___\\     SPECIAL ABILITIES"<<endl;
		cout<<"    /__W__|    DAMAGE INCREASE: Aumenta el ataque en "<<buff<<" durante "<<contadormax<<" rondas"<<endl;
		cout<<"   =========   FREEZE: Cancela "<<inmovmax<<" turnos del rival"<<endl<<endl;
	}
	void pov(int i)
	{
		cout<<"     <<<<<PLAYER "<<i<<" TURN>>>>>"<<endl;
		cout<<"           _____                 "<<endl;
		cout<<"           \\\\   \\\\__             "<<endl;
		cout<<"             \\\\  _  \\\\           "<<endl;
		cout<<"              ||  __   \\\\         "<<endl;
		cout<<"              ||        \\\\       "<<endl;
		cout<<"              ||      __ ||      "<<endl;
		cout<<"              // __       \\\\     "<<endl;
		cout<<"             //____________\\\\    "<<endl;
		cout<<"            //    WIZARD    ||   "<<endl;
		cout<<"           //_______________||   "<<endl;
		cout<<"          //                ||   "<<endl;
		cout<<"       IIIIIIIIIIIIIIIIIIIIIIIII "<<endl;
		cout<<"  HP "<<getvida()<<"/"<<getvidamax()<<endl;
		cout<<" _______________     _________________"<<endl;
		cout<<"| 1. ATTACK (";
		if(contador>0)
			cout<<attack+buff;
		else
			cout<<attack;
		cout<<") |   | 2. INCREASE ("<<buff<<") |"<<endl;
		cout<<" ---------------     -----------------"<<endl;
		cout<<"        _____________________"<<endl;
		cout<<"       | 3. FREEZE ("<<inmovmax<<" turns) |"<<endl;
		cout<<"        ---------------------"<<endl<<endl;
		cout<<" SELECT OPTION: ";
	}
	void povenemigo(int i)
	{
		cout<<"                Player "<<i<<endl;
		cout<<"                  |\\     "<<endl;
		cout<<"                  | \\       "<<endl;
		cout<<"                  |  \\      "<<endl;
		cout<<"                  /___\\     "<<endl;
		cout<<"                 /__W__|    "<<endl;
		cout<<"                =========  "<<endl;
		cout<<"           HP "<<getvida()<<"/"<<getvidamax()<<"  DAMAGE ";
		if(contador>0)
			cout<<attack+buff;
		else
			cout<<attack;
		cout<<endl<<endl;
		cout<<"                VS.  "<<endl<<endl;
	}
	int atacar()
	{
		return attack;
	}
	int incremento()
	{
		if(contador>0)
		{
			contador--;
			return buff;
		}
		else
		   return 0;
	}
	int getcontadormax()
	{
		return contadormax;
	}
	void setcontador(int contador)
	{
		this->contador=contador;
	}
	int getinmovmax()
	{
		return inmovmax;
	}
	bool inmovil()
	{
		if(inmov>0)
		{
			inmov--;
			return true;
		}
		else
		   return false;
	}
};

class vampiro : public personaje
{
private:
	int attack;
	int cura;
	int veneno;
	int contadormax;
public:
	int contador;
	vampiro(string nombre, int vida, int attack,int cura,int veneno,int contadormax) : personaje(nombre, vida)
	{
		this->attack=attack;
		this->cura=cura;
		this->veneno=veneno;
		this->contadormax=contadormax;
		contador=0;
	}
	void mostrar() override
	{
		cout<<"     (\\_/)     CHARACTER: "<<getnombre()<<endl;
		cout<<" ____( oo)____ HEALTH POINTS: "<<getvida()<<endl;
		cout<<" \\   |   |   / DAMAGE: "<<attack<<endl;
		cout<<"  \\/\\|   |/\\/  SPECIAL ABILITIES"<<endl;
		cout<<"      \\_/      DAMAGE HEALS: Roba "<<cura<<" punto de vida cada vez que ataca"<<endl;
		cout<<"               POISON: Envenena al enemigo "<<contadormax<<" rondas ("<<veneno<<"/ronda)"<<endl;
		cout<<"               CHAMALEON: Imita al enemigo y obtiene algunas de sus habilidades reducidas por 1 turno"<<endl;
	}
	void pov(int i)
	{
		cout<<"        <<<<<PLAYER "<<i<<" TURN>>>>>"<<endl;
		cout<<"        /\\                      /\\"<<endl;
		cout<<"      _/  \\      /\\    /\\      /  \\_ "<<endl;
		cout<<"     /     \\    //\\\\__//\\\\    /     \\ "<<endl;
		cout<<"   _/       \\__|          |__/       \\_ "<<endl;
		cout<<"  /              ( O) ( O)             \\"<<endl;
		cout<<" /         \\   |     vv   |   /         \\"<<endl;
		cout<<"|      \\    \\__|          |__/   /       |"<<endl;
		cout<<"|       \\ ___\\  \\        /  /__ /        | "<<endl;
		cout<<" \\   \\ ___\\      \\______/      /___/    /  "<<endl;
		cout<<"  \\  /              \\/              \\  /"<<endl;
		cout<<"   \\/                                \\/ "<<endl;
		cout<<"  HP "<<getvida()<<"/"<<getvidamax()<<endl;
		cout<<" _______________     _____________________"<<endl;
		cout<<"| 1. ATTACK ("<<attack<<") |   | 2. POISON ("<<veneno<<"/ronda) |"<<endl;
		cout<<" ---------------     ---------------------"<<endl;
		cout<<"            _______________"<<endl;
		cout<<"           |  3.CHAMALEON  |"<<endl;
		cout<<"            ---------------"<<endl<<endl;
		cout<<" SELECT OPTION: ";
	}
	void povenemigo(int i)
	{
		cout<<"                  Player "<<i<<endl;
		cout<<"                   (\\_/)     "<<endl;
		cout<<"               ____( oo)____ "<<endl;
		cout<<"               \\   |   |   / "<<endl;
		cout<<"                \\/\\|   |/\\/  "<<endl;
		cout<<"                    \\_/     "<<endl;
		cout<<"            HP "<<getvida()<<"/"<<getvidamax()<<"  DAMAGE "<<attack<<endl<<endl;
		cout<<"                      VS.  "<<endl<<endl;
	}
	int atacar()
	{
		return attack;
	}
	void curacion()
	{
		if(getvidamax()-cura>=getvida())
		{
			setvida(getvida()+cura);
			cout<<"+"<<cura<<" HP"<<endl;
		}
		else
		{
			setvida(getvida()+(getvidamax()-getvida()));
			cout<<"+"<<getvidamax()-getvida()<<" HP"<<endl;
		}
	}
	int envenenar()
	{
		if(contador>0)
		{
			contador--;
			return veneno;
		}
		else
		   return 0;
	}
	int getcontadormax()
	{
		return contadormax;
	}
};

void seleccion(guerrero &gue, alquimista &alq, mago &mag, vampiro &vam,string &j,int i);
void turno(guerrero &gue1, alquimista &alq1, mago &mag1, vampiro &vam1,guerrero &gue2, alquimista &alq2, mago &mag2, vampiro &vam2,string j1,string j2,bool &dead,int pj1,int pj2);

int main()
{
	guerrero gue1("GUERRERO",25,5,false),gue2("GUERRERO",25,5,false);
	alquimista alq1("ALQUIMISTA",20,4,4),alq2("ALQUIMISTA",20,4,4);
	mago mag1("MAGO",27,3,2,2,2),mag2("MAGO",27,3,2,2,2);
	vampiro vam1("VAMPIRO",22,3,1,1,3),vam2("VAMPIRO",22,3,1,1,3);
	string j1,j2;
	bool deadp1=false,deadp2=false;
	int turn=1;
	seleccion(gue1,alq1,mag1,vam1,j1,1);
	seleccion(gue2,alq2,mag2,vam2,j2,2);
	do{
		if(turn%2!=0)
			turno(gue1,alq1,mag1,vam1,gue2,alq2,mag2,vam2,j1,j2,deadp1,1,2);
		else
			turno(gue2,alq2,mag2,vam2,gue1,alq1,mag1,vam1,j2,j1,deadp2,2,1);
		turn++;
	}while(deadp1==false && deadp2==false);
	cout<<"    :::::      ::     ::      ::  ::::::"<<endl;
	cout<<"  ::         ::  ::   ::::  ::::  ::    "<<endl;
	cout<<"  ::  ::::   ::::::   ::  ::  ::  ::::: "<<endl;
	cout<<"  ::    ::  ::    ::  ::      ::  ::    "<<endl;
	cout<<"    :::::   ::    ::  ::      ::  ::::::"<<endl<<endl;
	cout<<"      ::::    ::    ::  ::::::  ::::::  "<<endl;
	cout<<"    ::    ::  ::    ::  ::      ::   :: "<<endl;
	cout<<"    ::    ::  ::    ::  :::::   ::::::  "<<endl;
	cout<<"    ::    ::   ::  ::   ::      ::   :: "<<endl;
	cout<<"      ::::       ::     ::::::  ::   :: "<<endl<<endl;
	if(deadp1)
		cout<<"        ****PLAYER 2 WIN****"<<endl<<endl;
	else if(deadp2)
		cout<<"        ****PLAYER 1 WIN****"<<endl<<endl;
}

void seleccion(guerrero &gue, alquimista &alq, mago &mag, vampiro &vam,string &j,int i)
{
	do{
		cout<<"                             PLAYER "<<i<<endl;
		cout<<"SELECT CHARACTER"<<endl;
		cout<<"___________________________________________________________________"<<endl<<endl;
		gue.mostrar();
		cout<<"___________________________________________________________________"<<endl<<endl;
		alq.mostrar();
		cout<<"___________________________________________________________________"<<endl<<endl;
		mag.mostrar();
		cout<<"___________________________________________________________________"<<endl<<endl;
		vam.mostrar();
		cout<<endl<<"OPTION (ENTER NAME): ";
		cin>>j;
		system("cls");
		if(j!="GUERRERO" && j!="guerrero" && j!="Guerrero" && j!="ALQUIMISTA" && j!="Alquimista" && j!="alquimista" && j!="MAGO" && j!="Mago" && j!="mago" && j!="VAMPIRO" && j!="Vampiro" && j!="vampiro")
			cout<<j<<" IS NOT A CHARACTER"<<endl;
	}while(j!="GUERRERO" && j!="guerrero" && j!="Guerrero" && j!="ALQUIMISTA" && j!="Alquimista" && j!="alquimista" && j!="MAGO" && j!="Mago" && j!="mago" && j!="VAMPIRO" && j!="Vampiro" && j!="vampiro");
}

void turno(guerrero &gue1, alquimista &alq1, mago &mag1, vampiro &vam1,guerrero &gue2, alquimista &alq2, mago &mag2, vampiro &vam2,string j1,string j2,bool &dead,int pj1,int pj2)
{
	int op,op2;
	if(j1=="GUERRERO" || j1=="guerrero" || j1=="Guerrero")
	{
		if(gue1.morir())
			dead=true;
		else
		{
			if(mag2.inmovil()==false)
			{
				do{
					if(j2=="GUERRERO" || j2=="guerrero" || j2=="Guerrero")
						gue2.povenemigo(pj2);
					else if(j2=="ALQUIMISTA" || j2=="Alquimista" || j2=="alquimista")
						alq2.povenemigo(pj2);
					else if(j2=="MAGO" || j2=="Mago" || j2=="mago")
						mag2.povenemigo(pj2);
					else if(j2=="VAMPIRO" || j2=="Vampiro" || j2=="vampiro")
						vam2.povenemigo(pj2);
					gue1.pov(pj1);
					cin>>op;
					if(op==1)
					{
						if(j2=="GUERRERO" || j2=="guerrero" || j2=="Guerrero")
						{
							if(gue2.getescudo())
							{
								gue2.setescudo(false);
								if(gue2.getrebote())
									gue1.recibirdano(gue2.rebotar(gue1.atacar()));
							}
							else
							{
								gue2.recibirdano(gue1.atacar());
								if(gue2.getrebote())
									gue1.recibirdano(gue2.rebotar(gue1.atacar()));
							}
						}
						else if(j2=="ALQUIMISTA" || j2=="Alquimista" || j2=="alquimista")
						   alq2.recibirdano(gue1.atacar());
						else if(j2=="MAGO" || j2=="Mago" || j2=="mago")
							mag2.recibirdano(gue1.atacar());
						else if(j2=="VAMPIRO" || j2=="Vampiro" || j2=="vampiro")
						{
							if(gue2.getescudo())
							{
								vam2.recibirdano(trunc(gue1.atacar()/2));
								gue2.setescudo(false);
							}
							else
											  vam2.recibirdano(gue1.atacar());
						}
					}
					else if(op==2)
					{
						gue1.setescudo(true);
					}
					else if(op==3)
					{
						gue1.setrebote(true);
					}
					system("cls");
					if(op!=1 && op!=2 && op!=3)
						cout<<op<<" NO ES UNA OPCION"<<endl<<endl;
				}while(op!=1 && op!=2 && op!=3);
			}
		}
	}
	else if(j1=="ALQUIMISTA" || j1=="Alquimista" || j1=="alquimista")
	{
		if(alq1.morir())
			dead=true;
		else
		{
			if(mag2.inmovil()==false)
			{
				do{
					if(j2=="GUERRERO" || j2=="guerrero" || j2=="Guerrero")
						gue2.povenemigo(pj2);
					else if(j2=="ALQUIMISTA" || j2=="Alquimista" || j2=="alquimista")
						alq2.povenemigo(pj2);
					else if(j2=="MAGO" || j2=="Mago" || j2=="mago")
						mag2.povenemigo(pj2);
					else if(j2=="VAMPIRO" || j2=="Vampiro" || j2=="vampiro")
						vam2.povenemigo(pj2);
					alq1.pov(pj1);
					cin>>op;
					if(op==1)
					{
						if(j2=="GUERRERO" || j2=="guerrero" || j2=="Guerrero")
						{
							if(gue2.getescudo())
							{
								gue2.setescudo(false);
								if(gue2.getrebote())
									alq1.recibirdano(gue2.rebotar(alq1.atacar()));
							}
							else
							{
								gue2.recibirdano(alq1.atacar());
								if(gue2.getrebote())
									alq1.recibirdano(gue2.rebotar(alq1.atacar()));
							}
						}
						else if(j2=="ALQUIMISTA" || j2=="Alquimista" || j2=="alquimista")
						   alq2.recibirdano(alq1.atacar());
						else if(j2=="MAGO" || j2=="Mago" || j2=="mago")
							mag2.recibirdano(alq1.atacar());
						else if(j2=="VAMPIRO" || j2=="Vampiro" || j2=="vampiro")
							vam2.recibirdano(alq1.atacar());
					}
					else if(op==2)
					{
						alq1.curacion();
					}
					system("cls");
					if(op!=1 && op!=2)
						cout<<op<<" NO ES UNA OPCION"<<endl<<endl;
				}while(op!=1 && op!=2);
			}
		}
	}
	else if(j1=="MAGO" || j1=="Mago" || j1=="mago")
	{
		if(mag1.morir())
			dead=true;
		else
		{
			if(mag2.inmovil()==false)
			{
				do{
					if(j2=="GUERRERO" || j2=="guerrero" || j2=="Guerrero")
						gue2.povenemigo(pj2);
					else if(j2=="ALQUIMISTA" || j2=="Alquimista" || j2=="alquimista")
						alq2.povenemigo(pj2);
					else if(j2=="MAGO" || j2=="Mago" || j2=="mago")
						mag2.povenemigo(pj2);
					else if(j2=="VAMPIRO" || j2=="Vampiro" || j2=="vampiro")
						vam2.povenemigo(pj2);
					mag1.pov(pj1);
					cin>>op;
					if(op==1)
					{
						if(j2=="GUERRERO" || j2=="guerrero" || j2=="Guerrero")
						{
							if(gue2.getescudo())
							{
								gue2.setescudo(false);
								if(gue2.getrebote())
									mag1.recibirdano(gue2.rebotar(mag1.atacar()+mag1.incremento()));
							}
							else
							{
								gue2.recibirdano(mag1.atacar()+mag1.incremento());
								if(gue2.getrebote())
									mag1.recibirdano(gue2.rebotar(mag1.atacar()));
							}
						}
						else if(j2=="ALQUIMISTA" || j2=="Alquimista" || j2=="alquimista")
						   alq2.recibirdano(mag1.atacar()+mag1.incremento());
						else if(j2=="MAGO" || j2=="Mago" || j2=="mago")
							mag2.recibirdano(mag1.atacar()+mag1.incremento());
						else if(j2=="VAMPIRO" || j2=="Vampiro" || j2=="vampiro")
							vam2.recibirdano(mag1.atacar()+mag1.incremento());
					}
					else if(op==2)
					{
						mag1.setcontador(mag1.getcontadormax());
					}
					else if(op==3)
					{
						mag1.inmov=mag1.getinmovmax();
					}
					system("cls");
					if(op!=1 && op!=2 && op!=3)
						cout<<op<<" NO ES UNA OPCION"<<endl<<endl;
				}while(op!=1 && op!=2 && op!=3);
			}
		}
	}
	else if(j1=="VAMPIRO" || j1=="Vampiro" || j1=="vampiro")
	{
		if(vam1.morir())
			dead=true;
		else
		{
			if(mag2.inmovil()==false)
			{
				do{
					if(j2=="GUERRERO" || j2=="guerrero" || j2=="Guerrero")
						gue2.povenemigo(pj2);
					else if(j2=="ALQUIMISTA" || j2=="Alquimista" || j2=="alquimista")
						alq2.povenemigo(pj2);
					else if(j2=="MAGO" || j2=="Mago" || j2=="mago")
						mag2.povenemigo(pj2);
					else if(j2=="VAMPIRO" || j2=="Vampiro" || j2=="vampiro")
						vam2.povenemigo(pj2);
					vam1.pov(pj1);
					cin>>op;
					if(op==1)
					{
						if(j2=="GUERRERO" || j2=="guerrero" || j2=="Guerrero")
						{
							
							if(gue2.getescudo())
							{
								gue2.setescudo(false);
								if(gue2.getrebote())
									vam1.recibirdano(gue2.rebotar(vam1.atacar()));
							}
							else
							{
								gue2.recibirdano(vam1.atacar()+mag1.incremento());
								vam1.curacion();
								gue2.recibirdano(vam1.envenenar());
								if(gue2.getrebote())
									vam1.recibirdano(gue2.rebotar(vam1.atacar()));
							}
						}
						else if(j2=="ALQUIMISTA" || j2=="Alquimista" || j2=="alquimista")
						{
							alq2.recibirdano(vam1.atacar()+mag1.incremento());
							vam1.curacion();
							alq2.recibirdano(vam1.envenenar());
						}
						else if(j2=="MAGO" || j2=="Mago" || j2=="mago")
						{
							mag2.recibirdano(vam1.atacar()+mag1.incremento());
							vam1.curacion();
							mag2.recibirdano(vam1.envenenar());
						}
						else if(j2=="VAMPIRO" || j2=="Vampiro" || j2=="vampiro")
						{
							if(gue2.getescudo())
								gue2.setescudo(false);
							else
							{
								vam2.recibirdano(vam1.atacar()+mag1.incremento());
								vam1.curacion();
								vam2.recibirdano(vam1.envenenar());
							}
						}
					}
					else if(op==2)
					{
						if(j2=="GUERRERO" || j2=="guerrero" || j2=="Guerrero")
						{
							vam1.contador=vam1.getcontadormax();
							if(gue2.getescudo())
								gue2.setescudo(false);
							else
								gue2.recibirdano(vam1.envenenar());
						}
						else if(j2=="ALQUIMISTA" || j2=="Alquimista" || j2=="alquimista")
						{
							vam1.contador=vam1.getcontadormax();
							alq2.recibirdano(vam1.envenenar());
						}
						else if(j2=="MAGO" || j2=="Mago" || j2=="mago")
						{
							vam1.contador=vam1.getcontadormax();
							mag2.recibirdano(vam1.envenenar());
						}
						else if(j2=="VAMPIRO" || j2=="Vampiro" || j2=="vampiro")
						{
							vam1.contador=vam1.getcontadormax();
							if(gue2.getescudo())
								gue2.setescudo(false);
							else
								vam2.recibirdano(vam1.envenenar());
						}
					}
					else if(op==3)
					{
						system("cls");
						do{
							if(j2=="GUERRERO" || j2=="guerrero" || j2=="Guerrero")
							{
								gue2.povenemigo(pj2);
								gue1.pov(pj1);
								cin>>op2;
								if(op2==1)
								{
									if(gue2.getescudo())
										gue2.setescudo(false);
									else
										gue2.recibirdano(gue1.atacar());
								}
								else if(op2==2)
								{
									gue1.setescudo(true);
								}
							}
							else if(j2=="ALQUIMISTA" || j2=="Alquimista" || j2=="alquimista")
							{
								alq2.povenemigo(pj2);
								alq1.pov(pj1);
								cin>>op2;
								if(op2==1)
								{
									alq2.recibirdano(alq1.atacar());
								}
								else if(op2==2)
								{
									vam1.setvida(vam1.getvida()+trunc(alq1.getcura()/2));
								}
							}
							else if(j2=="MAGO" || j2=="Mago" || j2=="mago")
							{
								mag2.povenemigo(pj2);
								mag1.pov(pj1);
								cin>>op2;
								if(op2==1)
								{
									mag2.recibirdano(mag1.atacar());
								}
								else if(op2==2)
								{
									mag1.setcontador(1);
								}
							}
							else if(j2=="VAMPIRO" || j2=="Vampiro" || j2=="vampiro")
							{
								vam2.povenemigo(pj2);
								vam1.pov(pj1);
								cin>>op2;
								if(op2==1)
								{
									vam2.recibirdano(vam1.atacar()+vam1.envenenar());
									vam1.curacion();
								}
								else if(op2==2)
								{
									vam1.contador=1;
								}
							}
							system("cls");
							if(op2==3)
								cout<<" OPCION NO DISPONIBLE"<<endl<<endl;
							else if(op2!=1 && op2!=2)
								cout<<op2<<" NO ES UNA OPCION"<<endl<<endl;
						}while(op2!=1 && op2!=2);
					}
					system("cls");
					if(op!=1 && op!=2 && op!=3)
						cout<<op<<" NO ES UNA OPCION"<<endl<<endl;
				}while(op!=1 && op!=2 && op!=3);
			}
		}
	}
}
