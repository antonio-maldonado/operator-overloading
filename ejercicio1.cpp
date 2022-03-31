//Antonio Maldonado
#include <iostream>
using namespace std;

class Racional{
private:
	int numerador;
	int denominador;
public: 
	Racional();
	Racional(int,int);
	Racional(int);
	friend ostream & operator <<(ostream &,Racional &);
	friend istream & operator >>(istream &,Racional &);
	friend Racional normalizar(Racional &);
	bool operator ==(Racional &);
	bool operator <(Racional &);
	bool operator >(Racional &);
	bool operator <=(Racional &);
	bool operator >=(Racional &);
	void operator +(Racional &);
	void operator -(Racional &);
	void operator /(Racional &);
	void operator *(Racional &);
};

Racional op;

bool Racional::operator<=(Racional &r){
	if((double(numerador)/double(denominador))<=(double(r.numerador)/double(r.denominador)))
		return true;
	else return false;
}

bool Racional::operator>=(Racional &r){
	if((double(numerador)/double(denominador))>=(double(r.numerador)/double(r.denominador)))
		return true;
	else return false;
}

bool Racional::operator>(Racional &r){
	r=normalizar(r);
	if((double(numerador)/double(denominador))>(double(r.numerador)/double(r.denominador)))
		return true;
	else return false;	
}

bool Racional::operator==(Racional &r){
	if(double(numerador)/double(denominador)==double(r.numerador)/double(r.denominador))
		return true;
	else return false;
}

bool Racional::operator<(Racional &r){
	if((double(numerador)/double(denominador))<(double(r.numerador)/double(r.denominador)))
		return true;
	else return false;
}

Racional normalizar(Racional &op){
	Racional nuevo;
	int aux,MCD=1,signo1=1,signo2=1;
	if(op.numerador<0){
		op.numerador=op.numerador*-1;
		signo1=-1;
	}
	if(op.denominador<0){
		op.denominador=op.denominador*-1;
		signo2=-1;
	}
	if(op.numerador>=op.denominador)
		aux=op.denominador;
	else
		aux=op.numerador;
	for(int i=2;i<=aux;i++){
		if(op.numerador%i==0 &&op.denominador%i==0)
			MCD=i;
	}
	nuevo.numerador=(signo1/signo2)*op.numerador/MCD;
	nuevo.denominador=op.denominador/MCD;
return nuevo;
}

void Racional::operator *(Racional &r){
	op.numerador=numerador*r.numerador;
	op.denominador=denominador*r.denominador;
}

void Racional::operator +(Racional &r){
	if(denominador==r.denominador){
		op.denominador=denominador;
		op.numerador=numerador+r.numerador;
	}else{
		op.numerador=numerador*r.denominador+r.numerador*denominador;
		op.denominador=denominador*r.denominador;
	}
}

void Racional::operator-(Racional &r){
	if(denominador==r.denominador){
		op.denominador=denominador;
		op.numerador=numerador-r.numerador;
	}else{
		op.numerador=numerador*r.denominador-r.numerador*denominador;
		op.denominador=denominador*r.denominador;
	}
}

void Racional::operator /(Racional &r){
	op.numerador=numerador*r.denominador;
	op.denominador=denominador*r.numerador;
}

ostream & operator <<(ostream &o,Racional &r){
	o<<r.numerador<<"/"<<r.denominador<<endl;
	return o;
}

istream & operator >>(istream &i,Racional &r){
	cout<<"Escriba el numerador: ";
	i>>r.numerador;
	cout<<"Escriba el denominador: ";
	i>>r.denominador;
	return i;
}

Racional::Racional(){
	numerador=0;
	denominador=1;
}

Racional::Racional(int n,int d){
	numerador=n;
	denominador=d;
}

Racional::Racional(int numero_entero){
	numerador=numero_entero;
	denominador=1;
}

int main(int argc, char *argv[]) {
	Racional n1,n2,nuevo,nn1,nn2;
	cout<<"Escriba el primer numero racional:\n";
	cin>>n1;
	cout<<"Escriba el segundo número racional:\n";
	cin>>n2;
	nn1=normalizar(n1);
	cout<<"Normalizado n1:  "<<nn1;
	nn2=normalizar(n2);
	cout<<"Normalizado n2:  "<<nn2;
    nn1/nn2;
	cout<<"\n(n1>n2)?  "<<((nn1>nn2)?"Es mayor":"No es mayor");
	cout<<"\n(n1<n2)?  "<<((nn1<nn2)?"Es menor":"No es menor");
	cout<<"\n(n1>=n2)?  "<<((nn1>=nn2)?"Es mayor igual":"No es mayor igual");
	cout<<"\n(n1<=n2)?  "<<((nn1<=nn2)?"Es menor igual":"No es menor igual");
	cout<<"\n(n1==n2)?  "<<((nn1==nn2)?"Son iguales":"No son iguales");
	cout<<"\n\nn1/n2:  "<<op;
    nuevo=normalizar(op);
    cout<<"Normalizado:  "<<nuevo;
	n1+n2;
	cout<<"\nn1+n2:  "<<op;
	nuevo=normalizar(op);
	cout<<"Normalizado:  "<<nuevo;
    n1-n2;
	cout<<"\nn1-n2:  "<<op;
	nuevo=normalizar(op);
	cout<<"Normalizado:  "<<nuevo;
	n1*n2;
	nuevo=normalizar(op);
	cout<<"\nn1*n2:  "<<op;
	cout<<"Normalizado:  "<<nuevo;
	return 0;
}
