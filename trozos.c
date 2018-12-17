#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int c, i, j, tam, k, m;
	int desplazamiento = 0;
	int n_coincidencias = 0, n_subcoincidencias = 0, encontrada = 0;
	char *cadena = "clesesqqqqes";
	int bytes_cadena = strlen(cadena);
	int n_claves = 1;
	char *claves[2];
	claves[0] = "cleses";
	claves[1] = "acs";
	int pos_claves[2] = {strlen(claves[0]), strlen(claves[1])};
	for(c = 0 ; c<n_claves; c++)
	/*Recorre todas las claves en columnas*/
	{
		tam = pos_claves[c];
		j = tam-1;
		i = tam-1;
		//n_coincidencias = 0;
		printf("bytes clave %i\n\n", tam);
		while(i < bytes_cadena)
		/*Recorremos el vector cadena desde tam hasta bytes_cadena*/		
		{
			printf("\t\t\tcadena: %c(%i) - clave: %c(%i)\n",cadena[i],i, claves[c][j],j);
			if(cadena[i] == claves[c][j])
			/*Ambos caracteres coinciden*/
			{
				n_coincidencias++;								
				i--;
				j--;
				
				if(n_coincidencias == tam)
				/*Se ha encontrado una clave y desplazamos hacia la derecha el tantos
				caracteres como la longitud de la clave*/				
				{
					encontrada++;
					//desplazamiento = tam; 
					desplazamiento = 2*tam;
					//i = pos_ini+desplazamiento;
					i += desplazamiento;
					j = tam-1;/*Se mueve dentro de la clave[]*/	
					n_coincidencias = 0;
					
					printf("Claves encontradas: %i\n", encontrada);
				}
				else if(n_coincidencias >= 1 && cadena[i] != claves[c][j])
				/*Si coincide algun caracter tenemos que buscar subcoincidencias
				dentro del vector claves[][]*/	
				{
					printf("\tBUSCAMOS SUBCOINCIDENCIAS\n");
					printf("n_coincidencias =%i\n",n_coincidencias);

					n_subcoincidencias = 0;
					//printf("coin: %i - tam/2=%i\n", n_coincidencias, tam/2);
					if(n_coincidencias < tam/2)
					/*En este caso la coincidencia se encuentra fuera  del trozo de
					clave que hemos encontrado y buscaremos ese trozo dentro de la 
					misma clave
					* si tam = 7 -> 7/2=3 -> redondea hacia abajo*/
					{
						k = j;
						m = tam-1;
						printf("k=%i - m=%i\n",k,m);
						while(m>j && k >= 0)
						/*Recorremos el vector claves hacia atras en busca de alguna
						coincidencia*/
						{
							printf("\t\t\tclave: %c(%i) - clave: %c(%i)\n",claves[c][m],m, claves[c][k],k);

							if(claves[c][k] == claves[c][m])
							/*Si encuentra alguna coincidencia sigue buscando hasta 
							encontrar la "subclave" con la que habia coincidido antes
							clave y cladena*/	
							{
								
								k--;
								m--;
								n_subcoincidencias++;
								printf("Sub: %i\n", n_subcoincidencias);
								if(n_subcoincidencias == n_coincidencias)
								/*Puede que en esta posicion encontremos la clave*/
								{
									printf("n_subcoincidencias == n_coincidencias\n");
									desplazamiento = tam -(k+n_coincidencias);
								}

							}else
							/*Seguimos buscando el mismo caracter pero movemos el puntero
							con el que comparamos la clave a la izquierda */
							{
								k--;
							}
							
						}// while(m>j && k >= 0)
						
					}
				}
			}
			else
			/*Si no hay coincidencia*/
			{
				if(j > 0){
					j--;	
				}else{
					i ++;
					j = tam-1;/*Se mueve dentro de la clave[]*/
				}		
			}
			
		}
	}
}
