#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<iostream>
#include<string.h>

typedef char cadena [30];

using namespace std;

struct compare{
	
	cadena nomb [1][0];
	cadena nbre [1][0];
	
};

struct registrar{
	
	char nombre[25];
	char usuario[32];
	char contrasenia[25];
	int legajo;
	
};

struct matriz{
	
	cadena nombre[3][3];
	cadena actividad[3]={"spinning", "zumba", "pilates"};
	cadena horario [3]={"8:00 a 11:00", "13:00 a 18:00", "19:00 a 23:00"};

};

struct registraradm{
	
	char usuarioadm[32];
	char contrasenadm[10];
	
};

bool checkPass(struct registraradm rep);
bool checkUser(struct registraradm rep);
void registrarusuario(void);
void registraractividad(void);
void calcularpago(void);
void muestramat (void);
void cargahor (void);

main(){
	
	struct registraradm rep;
	
	bool usuarioValido;
	bool contrasenaValida;
	
		int opc3;
	
		printf("*************************************************\n");
		printf("******   THE OLD GUARD ADMINISTRATION      ******\n");	
		printf("*************************************************\n");
		printf("**       1- Registrar usuarios                 **\n");
		printf("*************************************************\n");		
		printf("**       2- Registrar actividad                **\n");
		printf("*************************************************\n");
		printf("**       3- Calcular pago de entrenador        **\n");
		printf("*************************************************\n");
		printf("**       4- Mayor carga horaria                **\n");
		printf("*************************************************\n");
		printf("Ingrese la opcion: ");
		scanf("%d",&opc3);
		switch(opc3){
		case 1:
			registrarusuario();
		break;
			
		case 2:
			registraractividad();
		 	break;
		case 3:
			calcularpago();
			 break;
		case 4:
			cargahor();
			break;
		default: 
			printf("el numero ingresado no pertenece a una opcion del menu...");
			return main ();
			break;	
		}
}

void registrarusuario(){ 
	struct registraradm rep;
	cadena admin;
	FILE* adm;
	adm = fopen("admregistro.dat", "a+b");
	if(adm==NULL) exit (1);
	fwrite(&admin,sizeof(cadena),1,adm);
	int c=0,n=0,legajo,logitud;
	char contrasena[] = "aBuel123";
	char usuario [] = "Martin12";
	bool contrasenaValida;
	bool usuarioValido;
 	
 	system("cls");
	printf("**************************************************\n");
	printf("*******         THE OLD GUARD GYM           ******\n");
	printf("**************************************************\n");
	
	printf("**************************************************\n");
	printf("** 1- Ingrese el nombre del usuario a registrar **\n");
	printf("**************************************************\n");
	gets(rep.usuarioadm);
	
	system("pause");
	printf("**************************************************\n");
	printf("**    2- Ingrese la contrasenia a registrar     **\n");
	printf("**************************************************\n");
	gets(rep.contrasenadm);
	system("pause");
	
	usuarioValido = checkUser(rep);
	
	if(usuarioValido==1){
		printf("El usuario fue registrado...");
	}
	else{
		printf("El usuario no fue registrado...");	
	}
	
	printf("\n");
 	contrasenaValida = checkPass(rep);
	
	if(contrasenaValida==1){
		printf("La contrasenia es valida...");
	}
	else{
		printf("La constrasenia no es valida...");	
	}
 	fclose(adm);
}
	
bool checkUser(struct registraradm rep){
	
 int mayus = 0;
 int nums = 0;
 
 for(int i = 0; i < strlen(rep.usuarioadm); i++){
  
  if(isblank(rep.usuarioadm[i])) return false;
  
  if(isalpha(rep.usuarioadm[i])) continue;
  
  if(isdigit(rep.usuarioadm[i])) continue;
  
  return false;
 }
 
 if(isalpha(rep.usuarioadm[0])){
 	if(islower(rep.usuarioadm[0])){
 	
	 }
 	else{
 	 return false;
 	}
 }
 
 for(int i = 0; i < strlen(rep.usuarioadm); i++){
  
  if(isalpha(rep.usuarioadm[i])){
   if(isupper(rep.usuarioadm[i]))
    mayus++;
  }
  
  if(isdigit(rep.usuarioadm[i])) nums++;
 }
 
 if(mayus < 2 and nums < 3) return false;
 
 if(strlen(rep.usuarioadm) < 6 and strlen(rep.usuarioadm) > 10) return false;
 
 return true;
 
}
	
bool checkPass(struct registraradm rep){

 int mayus = 0;
 int minus = 0;
 int nums = 0;
 
 for(int i = 0; i < strlen(rep.contrasenadm); i++){
  
  if(isblank(rep.contrasenadm[i])) return false;
  
  if(isalpha(rep.contrasenadm[i])) continue;
  
  if(isdigit(rep.contrasenadm[i])) continue;
  
  return false;
 }
 
 for(int i = 0; i < strlen(rep.contrasenadm); i++){
  
  if(isalpha(rep.contrasenadm[i])){
   if(isupper(rep.contrasenadm[i]))
    mayus++;
   else
    minus++;
  }
  
  if(isdigit(rep.contrasenadm[i])) nums++;
 }
 
 if(mayus == 0 or minus == 0 or nums == 0) return false;
 
 if(strlen(rep.contrasenadm) < 6) return false;
 
 int c = 0;
 
 for(int i = 0; i < strlen(rep.contrasenadm); i++){
  
  if(isdigit(rep.contrasenadm[i])){
   if(c >= 3) return false;
   c++;
  }
  else
   c = 0;
 }
 
 int posicion = 0;
 int letraActual = 0;
 int letraSgte = 0;
 int pos1 = 0;
 int pos2 = 0;
 
 for(int i = 0; i < strlen(rep.contrasenadm); i++){
  
  if(isalpha(rep.contrasenadm[i])){
   
   letraActual = tolower(rep.contrasenadm[i]);
   letraSgte = tolower(rep.contrasenadm[i + 1]);
   
   pos1 = letraActual - 'a' + 1;
   pos2 = letraSgte - 'a' + 1;
    
   if(pos2 == pos1 + 1) return false;
   
  }
 }
 return true;
}

void registraractividad(void){
	
	struct matriz mat;
	struct registrar reg;
	
	FILE* archivo;	
	FILE* arch;
	
	arch = fopen("entrenadores.dat","r+b");
	archivo = fopen("registraract.dat","w+b");
	
	if(arch == NULL) exit(1);
	if(archivo == NULL) exit(1);
	
	int k=0;
	int p=0;
	int c=0;
	int i=0;
	int j=0;
	
	_flushall();
	fread(&reg,sizeof(registrar),1,arch);
	_flushall();
	
	while (!feof(arch)){
		
		fread(&reg,sizeof(registrar),1,arch);
		_flushall();
		puts(reg.nombre);
		printf(" - ");
			
	}	
	
	fwrite(&mat,sizeof(matriz),1,archivo);
	
	for (i=0 ; i<3 ; i++){
		for (j=0 ; j<3; j++){			
			
			_flushall();
			cout<<"ingrese el entrenador en la actividad ";puts(mat.actividad[j]);
			cout<<" en el horario ";puts(mat.horario[i]);
			//printf("\t ELEMENTO [%d][%d]",i,j);
			gets(mat.nombre[i][j]);
			
			k=strcmp((mat.nombre[i][j]),(mat.nombre[i][j-1]));
			if(k==0){
				j=j--;
			}
			
			
			p=strcmp((mat.nombre[i][j]),(mat.nombre[i][j-2]));
			if(p==0){
				j=j--;
			}
			
			_flushall();
			
		}
	}

	system("cls");

	fwrite(&mat,sizeof(matriz),1,archivo);
	for(i=0;i<3;i++){
		for( j=0;j<3;j++){
			
			printf("%s", mat.nombre[i][j]);
			printf("\n");
	
		}     
	
	}
	fclose(arch);	
	fclose (archivo);
}


void calcularpago(void){
	
	FILE* archivo;
	FILE* arch;
	arch = fopen("entrenadores.dat","rb");
	archivo = fopen("registraract.dat","rb");
	
	if(archivo == NULL) exit(1);
	if(arch == NULL) exit(1);
	
	struct registrar reg;
	struct compare pig;
	struct matriz mat;
	
	int b=0,i=0,j=0;
	int nom=0;
	int pre=0;
	float pago;
	
	fflush(stdin);
	
	fread(&reg,sizeof(registrar),1,arch);
	while (!feof(arch)){
		fread(&reg,sizeof(registrar),1,arch);
		fflush(stdin);
		puts(reg.nombre);
		printf(" - ");		
	}
	
	printf("ingrese el nombre del entrenador el cual quiera calcular su pago: " );
	fflush(stdin);
	gets(pig.nomb[1][0]);
	
	fread(&mat,sizeof(matriz),1,archivo);
	
	while(!feof(archivo)){
	
		for(int i=0;i<3;i++){
			for( int j=0;j<3;j++){
				fread(&mat,sizeof(matriz),1,archivo);
				b=(strcmp((pig.nomb[1][0]), (mat.nombre[i][j])));
				if(b==0){
					nom++;
				}
			}
		}
		
	}
	
	fread(&mat,sizeof(matriz),1,archivo);
	printf("Ingrese el precio por turno: ");
	scanf("%d",&pre);
	
	pago=nom*pre;
	
	printf("el pago del entrenador fue: ");
	puts(pig.nomb[1][0]);
	printf("%.2f", pago);

	fclose(archivo);
	fclose(arch);
}

void cargahor (void){
	
	FILE* archivo;
	archivo = fopen("registraract.dat","rb");
	if(archivo == NULL) exit(1);
	struct matriz mat;
	struct compare pig;
	int c,b,ch=0,va=0;
	cadena aux[1][0];
	
	do{
	printf("ingrese el nombre del entrenador para comparar su carga horaria: " );
	fflush(stdin);
	gets(pig.nbre[1][0]);
	
	fread(&mat,sizeof(matriz),1,archivo);
	
	while(!feof(archivo)){
		fflush(stdin);
		for(int i=0;i<3;i++){
			for( int j=0;j<3;j++){
				fread(&mat,sizeof(matriz),1,archivo);
				b=(strcmp((pig.nbre[1][0]), (mat.nombre[i][j])));
				if(b==0){
					ch++;
				}
			}
		}
		if(ch>va){
			va=ch;
			strcpy((aux[1][0]),(pig.nbre[1][0]));
		}
	}
	ch=0;
	printf("Si desea continuar coloque uno: ");
	scanf("%d",&c);
	}while(c!=1);
	
	printf("El entrenador con mayor carga horaria es: ");
	fflush(stdin);
	puts(aux[1][0]);
	fclose(archivo);
}


