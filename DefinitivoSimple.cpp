#include <iostream>
#include <cmath>
#define FMAX 10 //cojumna maxima
#define CMAX 10 //fila Maxima

using namespace std;


int Res, Nomv, Nomc, p2, p1, noMov;
float r1,r2;
int AunNO = 0;
float a, b, c;
int i, j ;
int Holgura[2][2];
float TB[CMAX][FMAX];




void datos()
{ 
cout<<"1. Maximizar\n2. Minimizar\n\n";
cin>>Res; 
if( Res == 1)
{
	r1 = 1;
}
if( Res == 2)
{
	r1 = -1;
}
cout<<"Cuantas variables tiene: "; //filas |me mueve hacia abajo |
cin>>Nomv;
cout<<"Cuantas restrinciones tiene: "; //columnas | me mueve hacia la derecha  |
cin>>Nomc;

//Poniendo Holgura

for(i = 2; i <= Nomc+1; i++)
	{
		for(j= 2; j <= Nomc+1; j++)
		{
			if( i == j)
			{
				TB[i][Nomv+j] = 1;
			} /*else{
				TB[i+1][Nomv+(j-1)] = 0;
			} */
		}
	}

cout<<"Ingrese los valores de Z"<<endl;
for(j = 1; j<=Nomv;j++)
	{cout<<"X"<<j<<" :";
	cin>>r2;
	TB[1][j+1] = r2 * r1;
}
cout<<"lado derecho: ";  TB[1][1] = 0;

for(i= 1; i<=Nomc; i++)//columna
{
	cout<<"Ingrese la restrinciones #"<<i<<" : "<<endl;
	for(j = 1; j <= Nomv; j++)//fila
	{
		cout<<"X"<<j<<" : ";
		cin>>r2;
		TB[1+i][1 + j] = r2;
	}
	cout<<"Lado derecho_ :"; cin>>TB[i+1][1];
}
	//Imprecion de Tabla

	for(i = 1; i <=Nomc+1;i++)
	{
		for(j = 1; j<=(Nomv+1)+Nomv; j++)
		{
			cout<<"\t"<<TB[i][j];
		}
			cout<<endl;
	}
	cout<<endl;
	cout<<"precionad una tecla"<<endl;
	cin.get();
	getchar();


	}

void pivote();
void formula();
void optimo();
//void resultado();

void simplex(){
	pivote();
		//Imprecion de Tabla

	for(i = 1; i <=Nomc+1;i++)
	{
		for(j = 1; j<=(Nomv+1)+Nomv; j++)
		{
			cout<<"\t"<<TB[i][j];
		}
			cout<<endl;
	}
	cout<<endl;

	int i, j;
	for(i = 2; i <= Nomv+1+Nomv; i++)
	{
		if(TB[1][i] < 0.0)
			{
				pivote();
			}
	}

	cout <<" Se acabo todo"<<endl;
}


void pivote()
{

	cout<<"ejecutando pivote"<<endl;
	int i, j;
	float aux;
	aux = 0.0;
	float divicion[10];
	float menor = TB[0][0];
	float MAX = 9999.9;
	for(i = 2; i <= Nomv+1; i++)  //Columna menor
	{
		if(TB[1][i]<0){
			if(TB[1][i] < menor){
					menor = TB[1][i];
					p2 = i;
				}
		}					
	}
	cout <<menor<<endl;
	cout<<p2<<endl;
		//MAX = 999999.0; //numero positivo
		for(i = 1; i <=  Nomc+1; i ++)  //Fila Derecha de que la divicion sea menor
		{
			//cout<<i<<endl;
			divicion[i] = fabs(TB[i][1]/TB[i][p2]);
			if(divicion[i]  > 0 and divicion[i] < MAX)
			{
				MAX = divicion[i]; //el menor de divicion
				
				p1 =  i;
				//noMov = i;
			}
		}
		cout<<p1<<endl;
		cout<<MAX<<endl<<endl;
		 TB[p1][1] = MAX;
		cout<<TB[p1][1];
		cout<<endl;
		cout<<"precionad una tecla"<<endl;
		cin.get();
		getchar();

		//Imprecion de Tabla

	for(i = 1; i <=Nomc+1;i++)
	{
		for(j = 1; j<=(Nomv+1)+Nomv; j++)
		{
			cout<<"\t"<<TB[i][j];
		}
			cout<<endl;
	}
	cout<<endl;
	//imprecin off

		b = TB[p1][p2];
		for(i = 2; i <= Nomv+ Nomv +1; i++)
		{
			c =  0;
			c = ((TB[p1][i])/(b));
			a = TB[p1][i];
			
			cout << a << " = " << a << " / " <<b<<endl;
			
			TB[p1][i] = c;
			/*cout<<c<<endl;
			cout<<TB[p1][i]; */
			

		}  
		cout<<endl<<endl<<endl;
		//Imprecion de Tabla

	for(i = 1; i <=Nomc+1;i++)
	{
		for(j = 1; j<=(Nomv+1)+Nomv; j++)
		{
			cout<<"\t"<<TB[i][j];
		}
			cout<<endl;
	}
		//Imprecion off
	cout<<endl;
	cin.get();
	getchar();

	
	cout<<"terminando"<<endl;
	formula();
}

void formula()
{ 
	int i, j;
	for(j = 1; j <= Nomc+1; j++)
	{
		if( j == p1) goto e10;
		for(i = 1; i <= (Nomv+1)+Nomv; i++)
		{ 
			if(i == p2){goto e20;}
			cout <<TB[j][i] << " = "<< TB[p1][i] << " * " << TB[j][p2]<< " + " << TB[j][i]<<endl;
			//TB[j][i] = ( TB[j][i] * -1) * (TB[p1][i]) + TB[j][i];
			TB[j][i] = (((TB[p1][i]) * (TB[j][p2]* -1)) + TB[j][i]);
			//TB[j][i] = (((TB[j][i] *-1)) * TB[p1][i]) + TB[j][i];
			cout << TB[j][i];
			cin.get();
			getchar();

		e20:;}
	e10:;} 
	cout<<"----------"<<endl;
	for( i = 1; i<= Nomc+1; i++)
	{
		if( p1 == i)goto e11;
		for( j = 2; j <= Nomv+1+Nomv; j++)
	{
		if( p2 == j)
		{   //aqui modifico
		cout <<TB[i][p2] << " = "<<TB[i][p2]<< " * "<<TB[p1][j] << " + " << TB[i][p2];
		TB[i][p2] = (((TB[i][p2] *-1)) * TB[p1][j]) + TB[i][p2];
		cout <<TB[i][p2] <<endl;
		cin.get();
		getchar();
		}
	}
	e11:;}

}

void resultado()
{
	int i, j;
	//Imprecion de Tabla

	for(i = 1; i <=Nomc+1;i++)
	{
		for(j = 1; j<=(Nomv+1)+Nomv; j++)
		{
			cout<<"\t"<<TB[i][j];
		}
			cout<<endl;
	}
	cout<<endl;
}
main()
{   //para ver solo 2 decimales .
	//cout.setf(ios::showpoint);
	cout.precision (4);
	cout.showpos;
	datos();
	simplex();
	resultado();

}