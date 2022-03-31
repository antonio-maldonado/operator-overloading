//Antonio Maldonado
#include <iostream>
using namespace std;

class Fecha{
private:
	int dia;
	int mes;
	int anio;
public:
	Fecha(int,int,int);
	friend ostream & operator <<(ostream &o,Fecha &);
	friend istream & operator >>(istream &,Fecha &);
	void operator++(); 
	void operator--();
	bool operator==(Fecha &f); 
	bool operator>(Fecha &f);
	bool operator<(Fecha &f);
	bool operator>=(Fecha &f);
	bool operator<=(Fecha &f);
	bool operator!=(Fecha &f);
};

bool Fecha::operator!=(Fecha &f){
	if(anio!=f.anio){
		if(mes!=f.mes){
			return true;
		if(dia!=f.dia)
			return true;
		else
			return false;
		}else return false;
	}else return false;
}

bool Fecha::operator<=(Fecha &f){
	if(anio<=f.anio){
		return true;
		if(mes<=f.mes){
		return true;
		if(dia<=f.dia)
			return true;
		else return false;
	}else return false;
	}else return false;
}

bool Fecha::operator>=(Fecha &f){
	if(anio>=f.anio){
		return true;
		if(mes>=f.mes){
		return true;
		}else if(dia>=f.dia){
			return true;
		}else return false; 
}else return false;
}

bool Fecha::operator>(Fecha &f){
	if(anio>f.anio)
		return true;
	else if(anio==f.anio){
		if(mes>f.mes){
		return true;
	}else if(mes==f.mes){
		if(dia>f.dia)
			return true;
	    else return false;
		}else return false;
	}else return false;
}

bool Fecha::operator<(Fecha &f){
	if(anio<f.anio)
		return true;
	else if(anio==f.anio){
		if(mes<f.mes)
		return true;
		else if(mes==f.mes){
			if(dia<f.dia) 
				return true;
			else return false;
		}else  return false;
	}else return false;
}

void Fecha::operator--(){
	if(mes==8 || mes==9 || mes==6 || mes==4 || mes==2 || mes==11){
		(dia==1)?dia=31&&mes--:dia--;}
	else if(mes==1){
		if(dia==1){
			dia=31;
			mes=12;
			anio--;
		}else
		   dia--;
	}
	else if(mes==3)
			(dia==1)?dia=28&&mes--:dia--;
	else if(mes==12 || mes==10 || mes==7 || mes==5)
		(dia==1)?dia=30&&mes--:dia--;
}

void Fecha::operator ++(){
	if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10){
		(dia==31)?dia=1&&mes++:dia++;}
	else if(mes==12){
		if(dia==31){
			dia=1;
			mes=1;
			anio++;
		}else
	        dia++;
	}
	else if(mes==2)
		(dia==28)?dia=1&&mes++:dia++;
	else if(mes==4 || mes==6 || mes==9 || mes==11)
		(dia==30)?dia=1&&mes++:dia++;
}

bool Fecha::operator ==(Fecha &f){
	if(dia==f.dia && mes==f.mes && anio==f.anio)
	return true;
	else  return false;
}

ostream & operator<<(ostream &o,Fecha &f){
	o<<f.dia<<"/"<<f.mes<<"/"<<f.anio<<endl<<endl;
	return o;
}

istream & operator >>(istream &i,Fecha &f){
	cout<<"Escriba el dia: ";
	i>>f.dia;
	cout<<"Escriba el mes: ";
	i>>f.mes;
	cout<<"Escriba el anio: ";
	i>>f.anio;
	return i;
}

Fecha::Fecha(int d=1,int m=1, int a=2019){
if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12)
(d>31 || d<=0)?dia=1&&cout<<"Dia no valido dia=1"<<endl:dia=d;
else if(m==2)
	(d>28 || d<=0)?dia=1&&cout<<"Dia no valido dia=1"<<endl:dia=d;
else if(m==4 || m==6 || m==9 || m==11)
	(d>30 || d<=0)?dia=1&&cout<<"Dia no valido dia=1"<<endl:dia=d;
else{
	cout<<"Mes no valido mes=1"<<endl;
	dia=d;
	m=1;
	anio=a;
}
mes=m;
(a<1)?anio=2019&&cout<<"Anio no valido anio=2019"<<endl:anio=a;
}

int main(int argc, char *argv[]) {
	Fecha f1(27,10,1997),f2(27,10,1997),f3(31,12,2018),f4(1,1,2020);
	cout<<endl;
	cout<<"f1  "<<f1;
	cout<<"f2  "<<f2;
	cout<<"f3  "<<f3;
	cout<<"f4  "<<f4;
	++f3;
	cout<<"++f3  "<<f3;
	cout<<"f1==f2  "<<((f1==f2)?"Son iguales":"Son diferentes")<<endl;
	++f1;
	cout<<"\n++f1  "<<f1;
	--f1;
	cout<<"--f1  "<<f1;
	cout<<"f1>f3  "<<((f1>f3)?"Es mayor":"No es mayor");
	cout<<"\n\nf2<f4  "<<((f2<f4)?"Es menor":"No es menor");
	cout<<"\n\nf4>=f3  "<<((f4>=f3)?"Es mayor igual":"No es mayor igual");
	cout<<"\n\nf4<=f1  "<<((f4<=f1)?"Es menor igual":"No es menor igual");
	cout<<"\n\nf1!=f2  "<<((f1!=f2)?"Es diferente":"No es diferente");
	return 0;
}
