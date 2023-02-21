#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
#include<windows.h>
#include<conio.h>

using namespace std;

typedef char cadena[30];


struct name{
	
	cadena nombrez[30];
	cadena nombres[30];
	cadena nombrep[30];
	
};

struct registrar{
	
	char nombre[25];
	char usuario[32];
	char contrasenia[25];
	int legajo;
	
};

struct gym{
	
	char username[10];
	char password[10];
	char ApellidoyNombre[60];

};

void registrar_modulogym (void);
bool iniciosesion_modulogym(void);
	bool checkUser(struct registrar reg);
	bool checkPass(struct registrar reg);
	void listadodesocios(void);
void registrorutina(void);

main(){
	system("cls");
	int opc1;
	registrar reg;
	printf("\033[0;31m");
	
	printf("*************************************************\n");
	printf("**              THE OLD GUARD GYM              **\n");
	printf("*************************************************\n");
	printf("**              1-Registrar sesion             **\n");
	printf("*************************************************\n");
	printf("**              2-Iniciar sesion               **\n");
	printf("*************************************************\n");
	printf("**              3- Listado de socios           **\n");
	printf("*************************************************\n");
	printf("**              4 Registro de rutina           **\n");
	printf("*************************************************\n");
	printf("**              5- Cerrar la app               **\n");
	printf("*************************************************\n");
	printf("Ingrese la opcion: ");
	scanf("%d",&opc1);
	
	printf("\033[0m");
	switch(opc1) {
		case 1:
				registrar_modulogym();
			break;
		case 2:
				iniciosesion_modulogym();
			break;
		case 3:
				listadodesocios();
			break;
		case 4:
				registrorutina();
			break;
		case 5:
				system("cls");
				printf("Usted decidio salir del programa.../n");
				system("pause");
			break;
		default:
				printf("el numero ingresado no pertenece a una opcion del menu...");
			break;
	}
}

void registrar_modulogym(){
	FILE* gym;
	struct registrar reg;
	char contrasena [] = "aBuel123";
	char usuario [] = "mArtiN12";
	gym = fopen("entrenadores.dat", "ab");
	if(gym == NULL) exit(1);
	int c=0,n=0,legajo,logitud;
	bool contrasenaValida;
	bool usuarioValido;
 	
 	system("cls");
 	printf("\033[1;32m");
	printf("*************************************************\n");
	printf("******         THE OLD GUARD GYM           ******\n");
	printf("*************************************************\n");
	
	printf("\n");
	printf("*************************************************\n");
	printf("**   TENER EN CUENTA CONDICIONES PARA QUE EL   **\n");
	printf("**      USUARIO Y CONTRASENA SEAN VALIDOS      **\n");
	printf("*************************************************\n");
	
	printf("*************************************************\n");
	printf("**      1- Ingrese el nombre del entrenador    **\n");
	printf("*************************************************\n");
	printf("\033[0m");
	_flushall();
	gets(reg.nombre);
	system("pause");
		
	printf("\n");
	printf("\033[1;32m");
	printf("*************************************************\n");
	printf("**                   USUARIO                   **\n");
	printf("*************************************************\n");
	printf("** a) Ser unico para cada usuario registrado.  **\n");
	printf("** b) Comenzar con una letra minuscula.        **\n");
	printf("** c) Tener al menos 2 letras mayusculas.      **\n");
	printf("** d) Tener como maximo 3 digitos.             **\n");
	printf("*************************************************\n");
	printf("** EJEMPLO:  mARtin12, jo97!AR                 **\n");
	printf("*************************************************\n");
	printf("\n");
		
	printf("*************************************************\n");
	printf("**      2- Ingrese el nombre de usuario        **\n");
	printf("*************************************************\n");
	printf("\033[0m");
	_flushall();
	cin.getline(reg.usuario,32);
	
	system("pause");
	
	printf("\n");
	printf("\033[1;32m");
	printf("*************************************************\n");
	printf("**                  CONTRASENA                 **\n");
	printf("*************************************************\n");
	printf("** a) Debe tener al menos una letra mayuscula  **\n");
	printf("**    una letra minuscula y un numero.         **\n");
	printf("** b) No podra contener ningun caracter de     **\n");
	printf("**    puntuacion, ni acentos, ni espacios.     **\n");
	printf("**    Solo caracteres alfanumericos.           **\n");
	printf("** c) Debera tener entre 6 y 32 caracteres.    **\n");
	printf("** d) No debe tener mas de 3 caracteres        **\n");
	printf("**    numericos consecutivos.                  **\n");
	printf("** e) No debe tener 2 caracteres consecutivos  **\n");
	printf("**    que refieran a letras alfabeticamente    **\n");
	printf("**    consecutivas (ascendentemente). Este     **\n");
	printf("**    criterio es valido tanto para letras     **\n");
	printf("**    mayusculas, minusculas o combinacion     **\n");
	printf("**    de ambas.                                **\n");
	printf("*************************************************\n");
	printf("** EJEMPLO: Achus32, 125Af89, aLejo123         **\n");
	printf("*************************************************\n");
	printf("\n");
	
	printf("*************************************************\n");
	printf("**      3- Ingrese la contrasenia              **\n");
	printf("*************************************************\n");
	
	_flushall();
	printf("\033[0m");
	cin.getline(reg.contrasenia,10);
	system("pause");
	printf("\033[1;32m");
	printf("*************************************************\n");
	printf("**      4- Ingrese Legajo del entrenador       **\n");
	printf("*************************************************\n");
	printf("\033[0m");
	_flushall();
	scanf("%d",&reg.legajo);
	fwrite(&reg,sizeof(registrar),1,gym);
	
	usuarioValido = checkUser(reg);
	
	if(usuarioValido==true){
		printf("El usuario se registro correctamenta...");
	}
	else{
		printf("El usuario no es valido...");	
	}
	
	printf("\n");
 	contrasenaValida = checkPass(reg);
	
	if(contrasenaValida==true){
		printf("La contrasenia se registro correctamente...");
		
	}
	else{
		printf("La constrasenia no es valida...");	
	}
	system("pause");
	system("cls");
	printf("\n");
	fclose(gym);
}

bool checkUser(struct registrar reg){
	
 int mayus = 0;
 int nums = 0;
 
 for(int i = 0; i < strlen(reg.usuario); i++){
  
  if(isblank(reg.usuario[i])) return false;
  
  if(isalpha(reg.usuario[i])) continue;
  
  if(isdigit(reg.usuario[i])) continue;
  
  return false;
 }

for(int i=0;i<1;i++){
 	if(isalpha(reg.usuario[i])){
 		if(islower(reg.usuario[i])){
			continue; 		
	 	}else{
 	 		return false;
 		}
 	}
}
 
 
 for(int i = 0; i < strlen(reg.usuario); i++){
  
  if(isalpha(reg.usuario[i])){
	if(isupper(reg.usuario[i])){
		mayus++;	
	}
  }
  
  if(isdigit(reg.usuario[i])) nums++;
 }
 
 if(mayus < 2 and nums < 3) return false;
 
 if(strlen(reg.usuario) < 6 and strlen(reg.usuario) > 10) return false;
 
 return true;
}
	
bool checkPass(struct registrar reg){

 int mayus = 0;
 int minus = 0;
 int nums = 0;
 
 for(int i = 0; i < strlen(reg.contrasenia); i++){
  
  if(isblank(reg.contrasenia[i])) return false;
  
  if(isalpha(reg.contrasenia[i])) continue;
  
  if(isdigit(reg.contrasenia[i])) continue;
  
  return false;
 }
 
 for(int i = 0; i < strlen(reg.contrasenia); i++){
  
  if(isalpha(reg.contrasenia[i])){
   if(isupper(reg.contrasenia[i]))
    mayus++;
   else
    minus++;
  }
  
  if(isdigit(reg.contrasenia[i])) nums++;
 }
 
 if(mayus == 0 or minus == 0 or nums == 0) return false;
 
 if(strlen(reg.contrasenia) < 6) return false;
 
 int c = 0;
 
 for(int i = 0; i < strlen(reg.contrasenia); i++){
  
  if(isdigit(reg.contrasenia[i])){
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
 
 for(int i = 0; i < strlen(reg.contrasenia); i++){
  
  if(isalpha(reg.contrasenia[i])){
   
   letraActual = tolower(reg.contrasenia[i]);
   letraSgte = tolower(reg.contrasenia[i + 1]);
   
   pos1 = letraActual - 'a' + 1;
   pos2 = letraSgte - 'a' + 1;
    
   if(pos2 == pos1 + 1) return false;
   
  }
 }
 return true;
}

bool iniciosesion_modulogym(void){
	struct gym check;
	struct registrar reg;
	int valor, valor2;
	char usuario[32], contrasena[10];
	bool iniciarsesion = false;
	
	FILE* arch;
	arch = fopen ("entrenadores.dat", "rb");
	
	system ("cls");
	printf("** Inicio de Sesion: **\n\n");
	
	printf("Ingrese nombre de usuario: ");
	_flushall();
	gets(check.username);
	printf("Ingrese contrasena: ");
	_flushall();
	gets(check.password);
	
	fread(&check, sizeof(gym), 1, arch);
	while(!feof(arch)){
		valor = strcmp(reg.usuario, check.username);
		valor2 = strcmp(reg.contrasenia, check.password);
		if(valor == 0 && valor2 == 0)
			{
				iniciarsesion = true;
			}
		fread(&check, sizeof(gym), 1, arch);
	}
	
	if (iniciarsesion == true){
		printf("Usted ingreso correctamente...");	
	}else{
		printf("El usuario y/o la contrasena no es valida...");
	}
	
	return iniciarsesion;	
	fclose(arch);
 	 
}

void listadodesocios(){
	
	FILE* zumba;
	FILE* pilates;
	FILE* spinning;
	
	name men;
 	
	zumba = fopen("zumba.dat","rb");
	printf("\n");
	printf("\t\tLISTADO DE ZUMBA");
	fread(&men,sizeof(name),1,zumba);
	 	while(!feof(zumba)){
 			printf("\n");
			printf("- ");
 			puts(men.nombrez[30]);
 			fread(&men,sizeof(name),1,zumba);
		}
	system("pause");
	fclose(zumba);
		
	pilates = fopen("pilates.dat","rb");	
	printf("\n");
	printf("\t\tLISTADO DE PILATES");
	fread(&men,sizeof(name),1,pilates);
	 	while(!feof(pilates)){
 			printf("\n");
			printf("- ");
 			puts(men.nombrep[30]);
 			
	 	fread(&men,sizeof(name),1,pilates);
		}
	system("pause");
	fclose(pilates);
	
	spinning = fopen("spinning.dat","rb");	
	printf("\n");
	printf("\t\tLISTADO DE SPINNING");
	fread(&men,sizeof(name),1,spinning);
	 	while(!feof(spinning)){
 			printf("\n");
			printf("- ");
 			puts(men.nombres[30]);
 			
	 	fread(&men,sizeof(name),1,pilates);
		}
	system("pause");	
	fclose(spinning);
}

void registrorutina(){
	system("cls");
	system("pause");
	printf("\033[1;35m");
	printf("*************************************************\n");
	printf("******         THE OLD GUARD GYM           ******\n");
	printf("*************************************************\n");
	printf("*************************************************\n");
	printf("**      INGRESE LA ACTIVIDAD DE LA CUAL        **\n");
	printf("**        QUIERA REGISTRAR LA RUTINA           **\n");
	printf("*************************************************\n");
	printf("**   1. Zumba     2. Spinning     3. Pilates   **\n");
	printf("*************************************************\n");
	printf("**                4. SALIR                     **\n");
	printf("*************************************************\n");
	printf("\033[0m");
	int opc;
	char zumba[380],spinning[380],pilates[380];
	printf("\t:");
	scanf("%d", &opc);
	switch(opc){
		case 1:
			printf("\n");
			printf("*************************************************\n");
			printf("**              RUTINA DE ZUMBA                **\n");
			printf("*************************************************\n");
			_flushall();
			printf("RUTINA: "); cin.getline(zumba,380);
			_flushall();
		case 2:
			printf("\n");
			printf("*************************************************\n");
			printf("**            RUTINA DE SPINNING               **\n");
			printf("*************************************************\n");
			_flushall();
			printf("RUTINA: "); cin.getline(spinning,380);
			_flushall();
		break;
		case 3:
			printf("\n");
			printf("*************************************************\n");
			printf("**             RUTINA DE PILATES               **\n");
			printf("*************************************************\n");
			_flushall();
			printf("RUTINA: "); cin.getline(pilates,380);
			_flushall();
		break;
		case 4:
			system("cls");
			system("pause");
			printf("*************************************************\n");
			printf("**      SALIO DEL PROGRAMA EXITOSAMENTE        **\n");
			printf("*************************************************\n");
		break;
		default: 
		break;
	}
}