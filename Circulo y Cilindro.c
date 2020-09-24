#include<stdio.h>
#include<conio.h>
#include<math.h>

void menu();
void circunferencia(float x);
void area(float x);
void volumen(float x, float y);
int salir();

FILE *fd;

void menu(){
	float num1,num2;
	int opc;
	
	printf("\n\t\tBienvenido a mi programa.\n");
	
	printf("\nNota: Recuerda que el Radio es la mitad del Diametro.");
	printf("\nDigite el Radio: ");
	scanf("%f",&num1);
	system("cls");
	
	printf("\nElija una opcion\n");
	printf("\n1.- Obtener Circunferencia.");
	printf("\n2.- Obtener el Area.");
	printf("\n3.- Obtener Volumen/Capacidad.");
	printf("\n4.- Obtener todos.");
	printf("\n0.- Salir.\n");
	printf("\nOpcion (Seleccione un numero): ");
	scanf("%i",&opc);
	
	switch(opc){
		case 1:{
			system("cls");
			circunferencia(num1);
			break;
		}
		case 2:{
			system("cls");
			area(num1);
			break;
		}
		case 3:{
			system("cls");
			printf("\nDigite el numero a multiplicar: ");
			scanf("%f",&num2);
			volumen(num1, num2);
			break;
		}
		case 4:{
			system("cls");
			printf("\nDigite el numero a multiplicar: ");		
			scanf("%f",&num2);
			circunferencia(num1);
			area(num1);
			volumen(num1, num2);
			break;
		}
		case 0:{
			break;
		}
		default:{
			system("cls");
			printf("\nSeleccione una opcion correcta (0-4).\n");
			menu();
		}
	}
	
	salir();
}

int main(){
	
	comprobar_archivo();
	
	system("pause");
	return 0;
}

int comprobar_archivo(){
	fd = fopen("instrucciones.txt","r");
	
	if(fopen==NULL){
		
		printf("\nNo se encontro el archivo.\n");
		fclose(fd);
		
		fd=fopen("instrucciones.txt","w");
		
		if(fd==NULL){
			printf("ERROR AL CREAR ARCHIVO");
			return 1;
		}
		else{
			fclose(fd);
			menu();
		}
	}
	else{
		fclose(fd);
		menu();
	}
	
}

void circunferencia(float x){
	float result=0, result2=0;
    fd = fopen("instrucciones.txt","wt");
    
    fprintf(fd,"\t***************Creado por Heber Perez***************\n");
    
	result2 = x*2;
    fprintf(fd,"\nPara obtener el Diametro, se multiplica el Radio por 2.");
    fprintf(fd,"\nEjemplo: (%.2f)(2) = %.3f\n",x,result2);
    result = result2*3.1416;
    fprintf(fd,"\nPara obtener la Circunferencia se multiplica el Diametro por PI");
    fprintf(fd,"\nEjemplo: (%.2f)(3.1416) = %.3f\n",result2,result);
    fclose(fd);
    
    printf("\nDiametro: %.3f",result2);
    printf("\nCircunferencia: %.3f",result);
    	
}

void area(float x){
	float result = 0;
	fd = fopen("instrucciones.txt","at");
	
	result = (pow(x,2)*3.1416);
	fprintf(fd,"\nPara obtener el Area el Radio se multiplica por si mismo y el resultado se multiplica por PI.");
	fprintf(fd,"\nEjemplo: (%.2f)(%.2f)(3.1416) = %.3f\n ",x,x,result);
	fclose(fd);
	
	printf("\nArea: %.3f",result);
}

void volumen(float x, float y){
	float result=0,result2=0;
	fd = fopen("instrucciones.txt","at");
	
	result = (pow(x,2)*3.1416);
	//fprintf(fd,"\nPara obtener el Area el Radio se multiplica por si mismo y el resultado se multiplica por PI.");
	//fprintf(fd,"\nEjemplo: (%f)(%f)(3.1416) = %f\n ",x,x,result);
	result2 = result*y;
	fprintf(fd,"\nAhora para el Volumen, se multiplica el Area por la altura o longitud.");
	fprintf(fd,"\nEjemplo: (%.2f)(%.2f) = %.3f\n",result,y,result2);
	fprintf(fd,"\n\n\n\n\nCodigo Fuente: ");
	fclose(fd);
	 
	printf("\nVolumen: %.3f",result2);
}

int salir(){
	char letra;
	
	fflush(stdin);
	printf("\n\n¿Desea Continuar? (S/N): ");
	scanf("%c",&letra);
	
	if(letra=='S' || letra=='s'){
		system("cls");
		menu();
	}
	else if(letra=='N' || letra=='n'){
		system("cls");
		printf("\t***************Creado por Heber Perez***************\n");
		printf("\nGracias por usar mi programa.\n\n");
	}
	else{
		printf("\nNo selecciono una opcion correcta.\n");
		return 1;
	}
}
