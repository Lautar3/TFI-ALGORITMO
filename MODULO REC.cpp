#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef char cadena [25];

struct name{
	
	char nombrez[30];
	char nombres[30];
	char nombrep[30];
	
};

struct registrar{
	
	char nombre[25];
	char usuario[32];
	char contrasena[25];
	
};

struct fecha{
	
	int dia;
	int mes;
	int anio;
	
};

struct registrosoc{
	
	int dni;
	int edad;
	int nro;
	float peso;
	float altura;
	char nombre[50];
	char apellido[50];
	char indcmed[80];
	char dir[80];
	fecha fec;
	
};

struct check{

	char username [10];
	char pasword [10];
	char name [60];

};


void iniciosesion(void);
void registrodesocios(void);
void registraractividad(void);
bool checkPass(char contrasena[10]);
bool checkUser(char usuario[32]);
void listadozumba(void);
void listadospinning(void);
void listadopilates(void);
void listadopart(void);
void zumbalist(void);
void spinninglist(void);
void pilateslist(void);
void fechapago(void);
void registrarsesion(void);

main(){
	int opc2;
	
	printf("*************************************************\n");
	printf("******    THE OLD GUARD GYM RECEPTION      ******\n");
	printf("*************************************************\n");
	printf("**        1- Iniciar sesion                    **\n");
	printf("*************************************************\n");
	printf("**        2- Registro de sesion                **\n");	
	printf("*************************************************\n");
	printf("**        3- Registro de socios                **\n");
	printf("*************************************************\n");
	printf("**        4- Registro de actividades           **\n");
	printf("*************************************************\n");
	printf("**        5- Listado de participantes          **\n");
	printf("*************************************************\n");
	printf("**        6- Listado de fecha de pago          **\n");
	printf("*************************************************\n");
	printf("**        7- Cerrar sesion                     **\n");
	printf("*************************************************\n");
	
	printf("Ingrese la opcion: ");
	scanf("%d",&opc2);
	
	switch(opc2) {
		case 1:
			iniciosesion();
			break;
		case 2:
			registrarsesion();
			break;
		case 3:
			registrodesocios();
			break;
		case 4:
			registraractividad();
			break;
		case 5:	
			listadopart();
			break;
		case 6:
			fechapago();
			break;
		case 7:
			system("cls");
			printf("Usted decidio salir del programa.../n");
			system("pause");
			break;
		default:
			system("cls");
			printf("Esta opcion no es valida.../n");
			system("pause");
			break;
	}
}

void registrarsesion(void){
	struct registrar reg;
	FILE* arch;
	char contrasena [] = "aBuel123";
	char usuario [] = "mArtiN12";
	arch = fopen("recepcionista.dat","ab");
	int c=0,n=0,legajo,logitud;
	bool contrasenaValida;
	bool usuarioValido;
	
 	printf("*************************************************\n");
	printf("******         THE OLD GUARD GYM           ******\n");
	printf("*************************************************\n");
	
	printf("*************************************************\n");
	printf("**       1- Ingrese el nombre del usuario      **\n");
	printf("*************************************************\n");
	fflush(stdin);
	gets(reg.usuario);
	
	printf("*************************************************\n");
	printf("**       2- Ingrese la contrasena              **\n");
	printf("*************************************************\n");
	fflush(stdin);
	gets(reg.contrasena);		
	
	if(usuarioValido == true && contrasenaValida == true){
		fwrite(&reg, sizeof(registrar), 1, arch);
	}
	
	usuarioValido = checkUser(reg.usuario);
	
	if(usuarioValido == true){
		printf("El usuario se registro correctamenta...");
	}
	else{
		printf("El usuario no es valido...");	
	}
	
	printf("\n");
 	contrasenaValida = checkPass(reg.contrasena);
	
	if(contrasenaValida == true){
		printf("La contrasenia se registro correctamente...");
		
	}
	else{
		printf("La constrasenia no es valida...");	
	}
	
	system("pause");
	system("cls");
	printf("\n");
	fclose(arch);
}

void iniciosesion(void){
	struct check gym;
	struct registrar reg;
	int c = 0, n = 0;
	bool CV;
	bool UV;
 	bool iniciarsesion = false;
 	char contrasena[] = "aBuel123";
	char usuario [] = "Martin12";
	int legajo,valor,valor2;
 	FILE* arch;
	arch = fopen ("recepcionista.dat", "rb");
 	
	system("cls");
	printf("*************************************************\n");
	printf("******         THE OLD GUARD GYM           ******\n");
	printf("*************************************************\n");
	
	printf("*************************************************\n");
	printf("**       1- Ingrese el nombre del usuario      **\n");
	printf("*************************************************\n");
	fflush(stdin);
	gets(reg.usuario);
	
	printf("*************************************************\n");
	printf("**       2- Ingrese la contrasena              **\n");
	printf("*************************************************\n");
	fflush(stdin);
	gets(reg.contrasena);

	
	fread(&gym, sizeof(check), 1, arch);
	while(!feof(arch)){
		valor = strcmp(reg.usuario, gym.username);
		valor2 = strcmp(reg.contrasena, gym.pasword);
		if(valor == 0 && valor2 == 0)
			{
				iniciarsesion = true;
			}
		fread(&gym, sizeof(check), 1, arch);
	}
		
	if(iniciarsesion == true){
	
		UV = checkUser(reg.usuario);
		if(UV == 1){
			printf("El usuario es valido...");
		}else{
			printf("El usuario no es valido...");	
		}
	
		printf("\n");
		
		CV = checkPass(reg.contrasena);
	
		if(CV == 1){
			printf("La contrasenia es valida...");
		}else{
			printf("La constrasenia no es valida...");	
		}
	}else{
		printf("\n");	
		printf("El usuario y/o la contrasena no es valida...");
	}
	fclose(arch);
}

bool checkUser(char usuario[32]){
	
	int mayus = 0;
	int nums = 0;
 
	for(int i = 0; i < strlen(usuario); i++){
  
		if(isblank (usuario[i])) return false;
  
		if(isalpha (usuario[i])) continue;
  
		if(isdigit (usuario[i])) continue;
  
		return false;
 	}
 
 	if(isalpha (usuario[0])){
		if(islower (usuario[0])){
 	
		}else{
 			return false;
 		}
	}
 
	for(int i = 0; i < strlen(usuario); i++){
  
		if(isalpha(usuario[i])){
			if(isupper (usuario[i])) mayus++;
		}
			if(isdigit (usuario[i])) nums++;
	 }
 
 	if(mayus < 2 and nums < 3) return false;
 
 	if(strlen(usuario) < 6 and strlen(usuario) > 10) return false;
 
 	return true;
}
	
bool checkPass(char contrasena[10]){

	int mayus = 0;
	int minus = 0;
 	int nums = 0;
 
 	for(int i = 0; i < strlen(contrasena); i++){
  
  	if(isblank (contrasena[i])) return false;
  
  	if(isalpha (contrasena[i])) continue;
  
  	if(isdigit (contrasena[i])) continue;
  
  	return false;
 	}
 
 	for(int i = 0; i < strlen(contrasena); i++){
  
		if(isalpha (contrasena[i])){
			if(isupper (contrasena[i])) mayus++;
	    	else minus++;
		}
			if(isdigit(contrasena[i])) nums++;
 	}
 
 	if(mayus == 0 or minus == 0 or nums == 0) return false;
 
 	if(strlen (contrasena) < 6) return false;
 
 	int c = 0;
 
 	for(int i = 0; i < strlen (contrasena); i++){
  
	  	if(isdigit (contrasena[i])){
			if(c >= 3) return false;
			c++;
  		}else c = 0;
 	}
 
 	int posicion = 0;
 	int letraActual = 0;
 	int letraSgte = 0;
 	int pos1 = 0;
 	int pos2 = 0;
 
 	for(int i = 0; i < strlen(contrasena); i++){
  
  		if(isalpha (contrasena[i])){

	   	letraActual = tolower (contrasena[i]);
   		letraSgte = tolower (contrasena[i + 1]);
   
   		pos1 = letraActual - 'a' + 1;
   		pos2 = letraSgte - 'a' + 1;
   		 
   		if(pos2 == pos1 + 1) return false;
   
  		}
 	}
	 return true;
}

void registrodesocios(void){
	
	struct registrosoc gol;
	FILE* socio;
	socio = fopen("socios.dat","ab");
	printf("*************************************************\n");
	printf("**        THE OLD GUARD GYM RECEPTION          **\n");
	printf("*************************************************\n");
	printf("*************************************************\n");
	printf("**      1- Ingrese el nombre del usuario       **\n");
	printf("*************************************************\n");
	fflush(stdin);
	gets(gol.nombre);
	printf("*************************************************\n");
	printf("**      2- Ingrese el apellido del usuario     **\n");
	printf("*************************************************\n");
	fflush(stdin);
	gets(gol.apellido);
	printf("*************************************************\n");
	printf("**      3- Ingrese el DNI del usuario          **\n");
	printf("*************************************************\n");
	scanf("%d",&gol.dni);
	printf("*************************************************\n");
	printf("**       4- Ingrese la edad del usuario        **\n");
	printf("*************************************************\n");
	scanf("%d",&gol.edad);
	printf("*************************************************\n");
	printf("**       5- Ingrese el peso del usuario        **\n");
	printf("*************************************************\n");
	scanf("%f",&gol.peso);
	printf("*************************************************\n");
	printf("**       6- Ingrese las indicaciones medicas   **\n");
	printf("*************************************************\n");
	fflush(stdin);
	gets(gol.indcmed);
	printf("*************************************************\n");
	printf("**       7- Ingrese la altura del usuario      **\n");
	printf("*************************************************\n");
	scanf("%f",&gol.altura);
	printf("*************************************************\n");
	printf("**       8- Ingrese la direccion del usuario   **\n");
	printf("*************************************************\n");
	fflush(stdin);
	gets(gol.dir);
	printf("*************************************************\n");
	printf("**		 9- Ingrese el telefono del usuario    **\n");
	printf("*************************************************\n");
	scanf("%d",&gol.nro);
	printf("*************************************************\n");
	printf("**		 10- Fecha de ingreso del usuario      **\n");
	printf("*************************************************\n");
	printf("dia: ");
	scanf("%d",&gol.fec.dia);
	printf("mes: ");
	scanf("%d",&gol.fec.mes);
	printf("anio: ");
	scanf("%d",&gol.fec.anio);
	fwrite(&gol,sizeof(registrosoc),1,socio);
	
	fclose(socio);
}

void registraractividad(void){
	FILE* zumba;
	struct name reg;
 	struct registrar rep;
	cadena sol;
	cadena actividad [3] = {"spinning","zumba","pilates"};
	cadena horario [3] = {"8:00 a 11:00","13:00 a 18:00","19:00 a 23:00"};

	int off=0;
	int i=0,j=0;
	int opc;
	int mp[3][3];
		
	for(int j=0;j<3;j++){
		for(int i=0;i<3;i++){
			mp[i][j]=0;
		}
	}
	 
	FILE* arch;
	arch = fopen("entrenadores.dat","rb");
	printf("Entrenadores disponibles: ");
	fread(&rep, sizeof(registrar), 1, arch);
	while(!feof(arch)){
		printf("\n- ");
		fflush(stdin);
		puts(rep.nombre);
		fread(&rep,sizeof(registrar),1,arch);
	}
		
		
	do{
	
	fflush(stdin);;
		printf("ingrese la actividad: ");
		printf("1. zumba \t 2. spinning \t 3. pilates\n\t:");
		_flushall();
		scanf("%d",&i);
		switch(i){
			case 1:
				listadozumba();
				break;	
			case 2:
				listadospinning();
				break;
			case 3:
				listadopilates();
				break;
			default:
				break;
		}
		
		printf("1. 8:00 a 11:00 \t 2. 13:00 a 18:00 \t 3. 19:00 a 23:00\n: ");
		printf("ingrese el horario: ");
		
		scanf("%d",&j);
		
		mp[i][j]=mp[i][j]+1;
		printf("Si desea continuar ingrese 1...");
		scanf("%d",&off);
		
	}while(off==1);

	
	fclose(arch);
}

void listadozumba(){
	struct name reg;
	FILE* zumba;
	zumba=fopen("zumba.dat","ab");
	printf("Ingrese el nombre del socio: ");
	fflush(stdin);
	gets(reg.nombrez);
	fwrite(&reg,sizeof(name),1,zumba);
	fclose(zumba);
}
	
void listadospinning(){
	struct name reg;
	FILE* spinning;
	printf("Ingrese el nombre del socio: ");
	fflush(stdin);
	gets(reg.nombres);
	spinning=fopen("spinning.dat","ab");
	fwrite(&reg,sizeof(name),1,spinning);
	fclose(spinning);	
	
}
      
void listadopilates(){
	struct name reg;
	FILE* pilates;
	pilates=fopen("pilates.dat","ab");
	printf("Ingrese el nombre del socio: ");
	fflush(stdin);
	gets(reg.nombrep);
	fwrite(&reg,sizeof(name),1,pilates);
	fclose(pilates);
}
     
 void listadopart (){
 	int m;        
 	printf("ingrese la actividad la cual quiere el listado de socios");
 	printf("\n");
 	printf("1. zumba \t 2. spinning \t 3. pilates\n\t:");
 	scanf("%d",&m);
 	switch (m){
 		case 1:
 			zumbalist();
 			break;
 		case 2:
 			spinninglist();
 			break;        
 		case 3:
 			pilateslist();
 			break;               
		default:
			printf("opcion no existente...");
			break;	 	         
	 }
 }
 
 void zumbalist (){
 	FILE* zumba; 
	struct name reg;
 	zumba = fopen("zumba.dat","rb"); 
 	printf("\t\tLISTADO DE ZUMBA");
	fread(&reg,sizeof(name),1,zumba);
	 	while(!feof(zumba)){
 			printf("\n");
			printf("- ");
			fflush(stdin);
 			puts(reg.nombrez);
	 		fread(&reg,sizeof(name),1,zumba);	
 		}                    
 	
	fclose(zumba);
}
 
  void spinninglist(){
  	FILE* spinning;
	struct name reg;
 	spinning = fopen("spinning.dat","rb");
 	   	printf("\t\tLISTA DE SPINNING");
		fread(&reg,sizeof(name),1,spinning);
	 	while(!feof(spinning)){
 			printf("\n");
			printf("- ");
			fflush(stdin);
 			puts(reg.nombres);
		 	fread(&reg,sizeof(name),1,spinning);
		}
	fclose(spinning);
 }    
 
 void pilateslist(){
  	FILE* pilates;
	struct name reg;
 	pilates = fopen("pilates.dat","rb");
 	   	printf("\t\tLISTA DE SPINNING");
		fread(&reg,sizeof(name),1,pilates);
	 	while(!feof(pilates)){
 			printf("\n");
			printf("- ");
			fflush(stdin);
 			puts(reg.nombres);
		 	fread(&reg,sizeof(name),1,pilates);
		}
	fclose(pilates);
 }   
 
 void fechapago(void){
	struct registrosoc gol;
	FILE* socio;
	socio = fopen("socios.dat","rb");	 	
 	
	fread(&gol, sizeof(registrosoc), 1, socio);
	while(!feof(socio)){
		printf("El socio: "); puts(gol.nombre); puts(gol.apellido); 
		printf("Fecha de ingreso: %d / %d / %d \n",gol.fec.dia, gol.fec.mes, gol.fec.anio);
		if(gol.fec.mes==12 && gol.fec.dia==31){
			gol.fec.mes=0;
			gol.fec.dia=0;
			printf("Fecha de pago: %d / %d / %d \n",gol.fec.dia+1, gol.fec.mes+1, gol.fec.anio+1);	
		}else{
			if(gol.fec.mes==12){
				gol.fec.mes=0;
				printf("Fecha de pago: %d / %d / %d \n",gol.fec.dia, gol.fec.mes+1, gol.fec.anio+1);
			}
			if(gol.fec.dia==31){
				gol.fec.dia=0;
				printf("Fecha de pago: %d / %d / %d \n",gol.fec.dia+1, gol.fec.mes+1, gol.fec.anio);
			}else{
				printf("Fecha de pago: %d / %d / %d \n",gol.fec.dia, gol.fec.mes+1, gol.fec.anio);
			}
		}		
		fread(&gol, sizeof(registrosoc), 1, socio);	
	}	
 }