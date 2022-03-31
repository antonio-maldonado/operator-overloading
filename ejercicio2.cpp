//Antonio Maldonado
#include <iostream>
using namespace std;

class Complejo{
private:
	double real;
	double imaginario;
public:
	Complejo(double,double);
	Complejo(double);
	Complejo();
	bool operator ==(Complejo &)const;
	void operator -(Complejo &);
	void operator +(Complejo &);
	void operator *(Complejo &);
	friend ostream & operator <<(ostream &,Complejo &);
	friend istream & operator >>(istream &,Complejo &);
};

Complejo Resultado;

void Complejo::operator *(Complejo &c){
	Resultado.real=(real*c.real)-(imaginario*c.imaginario);
	Resultado.imaginario=(real*c.imaginario)+(imaginario*c.real);
}

void Complejo::operator+(Complejo &c){
	Resultado.real=real+c.real;
	Resultado.imaginario=imaginario+c.imaginario;
}

void Complejo::operator-(Complejo &c){
	Resultado.real=real-c.real;
    Resultado.imaginario=imaginario-c.imaginario;
}

bool Complejo::operator==(Complejo &c)const{
	if(real==c.real && imaginario==c.imaginario)
	return true;
	else
	return false;
}

Complejo::Complejo(){
	real=0;
	imaginario=0;
}

Complejo::Complejo(double a, double b){
	real=a;
	imaginario=b;
}

Complejo::Complejo(double parte_real){
	real=parte_real;
	imaginario=0;
}

ostream & operator <<(ostream &o,Complejo &c){
	o<<c.real<<" + "<<c.imaginario<<"i"<<endl;
	return o;
}

istream & operator >>(istream &i,Complejo &c){
	cout<<"Ingrese el valor real: ";
	i>>c.real;
	cout<<"Ingrese el valor imaginario: ";
	i>>c.imaginario;
	return i;
}

int main(int argc, char *argv[]) {
Complejo c1,c2;
cout<<"Escriba los valores de c1:  \n";
cin>>c1;
cout<<"Escriba los valores de c2:  \n";
cin>>c2;
c1-c2;
cout<<"\nc1=  "<<c1;
cout<<"\nc2=  "<<c2;
cout<<"\nResta c1-c2=  "<<Resultado;
c1+c2;
cout<<"\nSuma c1+c2=  "<<Resultado;
c1*c2;
cout<<"\nMultiplicacion c1*c2= "<<Resultado; 
	return 0;
}
