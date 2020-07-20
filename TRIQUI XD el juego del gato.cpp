//TRIQUI
#include <iostream>	//cin>> y cout<<
#include <cstdlib>	//srand() y rand()
#include <ctime>	//time()
#include <cctype>	//isdigit()
#include <conio.h>	//getch()
using namespace std;

//DECLARACION VARIABLES GLOBALES
char board[3][3];
int i,j;

//LANZAR DADO
int throw_dice()
{
	return rand() % 6+ 1;//generar aleatorio entre 1 y 6
}

//REINICIAR TABLERO
void restart_board()
{
	/*
	Esta funcion llena el tablero de espacios vacios, lo reinicia
	*/
	
	for(i=0;i<3;i++)//recorrer filas de la matriz
	{
		for(j=0;j<3;j++)//recorrer columnas de la matriz
		{
			board[i][j] = ' ';//llenar tablero de espacios
		}
	}
}

//IMPRIMIR TABLERO
void print_board()
{
	/*
	Esta funcion imprime el tablero en pantalla con sus valores
	*/
	for(i=0;i<3;i++)//recorrer filas de la matriz
	{
		cout<<" ---  ---  --- "<<endl;//imprimir linea de marco
		
		for(j=0;j<3;j++)//recorrer columnas de la matriz
		{
			cout<<"| "<<board[i][j]<<" |";//imprimir cada casilla
		}
		
		cout<<endl<<" ---  ---  --- "<<endl;//imprimir linea de marco
	}
	cout<<endl;
}

//ES PAR?
bool is_even(int num)
{
	/*
	Esta funcion define si el tirno actual es par o impar
	*/
	if(num%2==0)//si el residuo es divisible entre 2...
	{
		return true;//retorna verdadero
	}
	return false;//retorna falso
}

//PASAR NUMERO CAMPO A CORDENADAS DEL INDICE EN MATRIZ
void number_to_xy(int num, int &x, int &y)
{
	/*
	Esta funcion recibe el numero digitado por el usuario y lo convierte en cordenadas de matriz
	*/
	x=0;
	while(num > 3)
	{ 
		num-=3;
		x++;
	}
	y=num-1;
}

//BUSCAR JUGADA OFENSIVA, DEFENSIVA O MEDIA OFENSIVA
bool machine_game(char level,int &x, int &y)
{
	//En este bucle buscamos si podemos ganar con una jugada, recorrmos la matriz campo por campo...
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(board[i][j]==' ')//si el campo esta vacio
			{
				//asignamos el dato del campo en cordenadas, si encuentra la jugada ya estan llenos, sino, se sobreescribiran al revisar el siguiente campo
				x=i;
				y=j;
				
				//CENTRO + x
				//si el campo es el del centro revisar posible victoria vertical, horizontal, y diagonales
				if((i==1 && j==1) && ((board[0][1]=='O' && board[2][1]=='O') || (board[1][0]=='O' && board[1][2]=='O') || (board[0][0]=='O' && board[2][2]=='O') || (board[0][2]=='O' && board[2][0]=='O')))
				{
					return true;
				}
				
				//DIAGONALES
				//Diagonal \ desde superior
				else if((i==0 && j==0) && (board[1][1]=='O' && board[2][2]=='O'))//si el campo es superior izquierdo revisar centro e inferior izquierdo
				{
					return true;
				}
				//Diagonal / desde superior
				else if((i==0 && j==2) && (board[1][1]=='O' && board[2][0]=='O'))
				{
					return true;
				}
				//Diagonal / desde inferior
				else if((i==2 && j==0) && (board[1][1]=='O' && board[0][2]=='O'))
				{
					return true;
				}
				//Diagonal \ desde inferior
				else if((i==2 && j==2) && (board[1][1]=='O' && board[0][0]=='O'))
				{
					return true;
				}
				
				//VERTICALES
				//verticales llenando superior
				else if((i==0) && (board[1][j]=='O' && board[2][j]=='O'))//si campo esta en la primera fila revisar la misca columna en segunda y tercera fila
				{
					return true;
				}
				//verticales llenando centro
				else if((i==1) && (board[0][j]=='O' && board[2][j]=='O'))
				{
					return true;
				}
				//verticales llenando inferior
				else if((i==2) && (board[0][j]=='O' && board[1][j]=='O'))
				{
					return true;
				}
				
				//HORIZONTALES
				//horizontales llenando izquierdo
				else if((j==0) && (board[i][1]=='O' && board[i][2]=='O'))//si campo esta en primera columna revisar misma fila en columna 2 y 3
				{
					return true;
				}
				//horizontales llenando centro
				else if((j==1) && (board[i][0]=='O' && board[i][2]=='O'))
				{
					return true;
				}
				//horizontales llenando derecho
				else if((j==2) && (board[i][0]=='O' && board[i][1]=='O'))
				{
					return true;
				}
			}
		}
	}
	
	//En este bucle buscamos si el usuario puede ganar en una jugada y la bloqueamos
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(board[i][j]==' ')//si campo esta vacio
			{
				x=i;
				y=j;
				
				//CENTRO + x
				//si el campo es el del centro revisar posible victoria vertical, horizontal, y diagonales
				if((i==1 && j==1) && ((board[0][1]=='X' && board[2][1]=='X') || (board[1][0]=='X' && board[1][2]=='X') || (board[0][0]=='X' && board[2][2]=='X') || (board[0][2]=='X' && board[2][0]=='X')))
				{
					return true;
				}
				
				//DIAGONALES
				//Diagonal \ desde superior
				else if((i==0 && j==0) && (board[1][1]=='X' && board[2][2]=='X'))//si el campo es superior izquierdo revisar centro e inferior izquierdo
				{
					return true;
				}
				//Diagonal / desde superior
				else if((i==0 && j==2) && (board[1][1]=='X' && board[2][0]=='X'))
				{
					return true;
				}
				//Diagonal / desde inferior
				else if((i==2 && j==0) && (board[1][1]=='X' && board[0][2]=='X'))
				{
					return true;
				}
				//Diagonal \ desde inferior
				else if((i==2 && j==2) && (board[1][1]=='X' && board[0][0]=='X'))
				{
					return true;
				}
				
				//VERTICALES
				//verticales llenando superior
				else if((i==0) && (board[1][j]=='X' && board[2][j]=='X'))//si campo esta en la primera fila revisar la misca columna en segunda y tercera fila
				{
					return true;
				}
				//verticales llenando centro
				else if((i==1) && (board[0][j]=='X' && board[2][j]=='X'))
				{
					return true;
				}
				//verticales llenando inferior
				else if((i==2) && (board[0][j]=='X' && board[1][j]=='X'))
				{
					return true;
				}
				
				//HORIZONTALES
				//horizontales llenando izquierdo
				else if((j==0) && (board[i][1]=='X' && board[i][2]=='X'))//si campo esta en primera columna revisar misma fila en columna 2 y 3
				{
					return true;
				}
				//horizontales llenando centro
				else if((j==1) && (board[i][0]=='X' && board[i][2]=='X'))
				{
					return true;
				}
				//horizontales llenando derecho
				else if((j==2) && (board[i][0]=='X' && board[i][1]=='X'))
				{
					return true;
				}
			}
		}
	}
	
	if(level=='2')
	{
		//En este bucle buscamos si tenemos lineas con una casilla marcada por maquina y 2 vacios 
		//y lo llenamos buscando un moovimiento ofensivo de segunda prioridad
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				if(board[i][j]==' ')
				{
					x=i;
					y=j;
					
					//CENTRO
					if((i==1 && j==1) && (
								(board[0][1]==' ' && board[2][1]=='O') || (board[0][1]=='O' && board[2][1]==' ') || 
								(board[1][0]==' ' && board[1][2]=='O') || (board[1][0]=='O' && board[1][2]==' ') || 
								(board[0][0]==' ' && board[2][2]=='O') || (board[0][0]=='O' && board[2][2]==' ') || 
								(board[0][2]==' ' && board[2][0]=='O') || (board[0][2]=='O' && board[2][0]==' ')
							)
						)
					{
						return true;
					}
					
					//DIAGONALES
					//Diagonal \ desde superior
					else if((i==0 && j==0) && ((board[1][1]==' ' && board[2][2]=='O') || (board[1][1]=='O' && board[2][2]==' ')))
					{
						return true;
					}
					//Diagonal / desde superior
					else if((i==0 && j==2) && ((board[1][1]==' ' && board[2][0]=='O')  || (board[1][1]=='O' && board[2][0]==' ')))
					{
						return true;
					}
					//Diagonal / desde inferior
					else if((i==2 && j==0) && ((board[1][1]==' ' && board[0][2]=='O') || (board[1][1]=='O' && board[0][2]==' ')))
					{
						return true;
					}
					//Diagonal \ desde inferior
					else if((i==2 && j==2) && ((board[1][1]==' ' && board[0][0]=='O') || (board[1][1]=='O' && board[0][0]==' ')))
					{
						return true;
					}
					
					//VERTICALES
					//verticales llenando superior
					else if((i==0) && ((board[1][j]==' ' && board[2][j]=='O') || (board[1][j]=='O' && board[2][j]==' ')))
					{
						return true;
					}
					//verticales llenando centro
					else if((i==1) && ((board[0][j]==' ' && board[2][j]=='O') || (board[0][j]=='O' && board[2][j]==' ')))
					{
						return true;
					}
					//verticales llenando inferior
					else if((i==2) && ((board[0][j]==' ' && board[1][j]=='O') || (board[0][j]=='O' && board[1][j]==' ')))
					{
						return true;
					}
					
					//HORIZONTALES
					//horizontales llenando izquierdo
					else if((j==0) && ((board[i][1]==' ' && board[i][2]=='O') || (board[i][1]=='O' && board[i][2]==' ')))
					{
						return true;
					}
					//horizontales llenando centro
					else if((j==1) && ((board[i][0]==' ' && board[i][2]=='O') || (board[i][0]=='O' && board[i][2]==' ')))
					{
						return true;
					}
					//horizontales llenando derecho
					else if((j==2) && ((board[i][0]==' ' && board[i][1]=='O') || (board[i][0]=='O' && board[i][1]==' ')))
					{
						return true;
					}
				}
			}
		}
	}
	
	return false;//si no hay una buena jugada, retornar falso
}

//BUSCAR CAMPO ALEATORIO
void random_field(int &x,int &y)
{
	/*
	Aqui generamos una jugada aleatoria poniendo todos los numeros de casillas vacias en un arreglo y luego escojemos uno al azar y 
	devolvemos los datos en cordenadas de matriz
	*/
	int g=0;
	
	//En este bucle contamos cuantas casillas estan vacias, recorremos la matriz campo por campo...
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(board[i][j]==' ')//si el campo esta vacio
			{
				g++;//sumar 1 al contador g
			}
		}
	}
	
	int h[g];//declara arreglo h con la cantidad de espacios necesarios
	g=0;//reiniciamos el contador g
	
	//recorremos nuevamente la matriz
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(board[i][j]==' ')//si el campo esta vacio
			{
				h[g]=(i*3)+j+1;//colocar en el arreglo h los numeros (1-9) que estan en campos vacios
				g++;
			}
		}
	}
	
	number_to_xy(h[(rand() % g)], x, y);//devolver una de las posiciones del arreglo aleatoriamente en formato x,y
}

//HAY GANADOR?
bool is_winner()
{
	/*
	aqui revisamos cada posible linea de triqui (verticales, horizontales, diagonales), 
	mirando si en la linea el campo1=campo2 y campo1 = campo3 y si campo1 != vacio
	*/
	
	//DIAGONALES
	if(board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
	{
		return true;
	}
	else if(board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != ' ')
	{
		return true;
	}
	//HORIZONTALES
	else if(board[0][0] == board[0][1] && board[0][0] == board[0][2] && board[0][0] != ' ')
	{
		return true;
	}
	else if(board[1][0] == board[1][1] && board[1][0] == board[1][2] && board[1][0] != ' ')
	{
		return true;
	}
	else if(board[2][0] == board[2][1] && board[2][0] == board[2][2] && board[2][0] != ' ')
	{
		return true;
	}
	//VERTICALES
	else if(board[0][0] == board[1][0] && board[0][0] == board[2][0] && board[0][0] != ' ')
	{
		return true;
	}
	else if(board[0][1] == board[1][1] && board[0][1] == board[2][1] && board[0][1] != ' ')
	{
		return true;
	}
	else if(board[0][2] == board[1][2] && board[0][2] == board[2][2] && board[0][2] != ' ')
	{
		return true;
	}
	
	return false;
}

//***********************************************************************
//FUNCION PRINCIPAL
int main()
{
	//Declara variables locales de funcion principal
	int o_dice,x_dice,turn_id,x,y,throw_dices,win_user=0,win_machine=0;
	bool human_even,turn_complete;
	char fill,play='0',level;
	
	//cabezote
	cout<<endl<<"*******************************************"<<endl;
	cout<<"***  TRIQUI XD: El juego del gato v2.0  ***"<<endl;
	cout<<"*******************************************"<<endl<<endl;
	
	cout<<endl<<"****** INSTRUCCIONES ******"<<endl<<endl;
	cout<<"El juego consiste en llenar tres casillas continuas con una X."<<endl<<endl;
	cout<<"Compites contra la maquina la cual jugara con el simbolo O."<<endl<<endl;
	cout<<"Se jugara por turnos y en cada turno un jugador podra ocupar"<<endl<<"una casilla vacia."<<endl<<endl;
	cout<<"El jugador del primer turno se decide al azar por medio"<<endl<<"de lanzamiento de dados."<<endl<<endl;
	cout<<"Cuando sea tu turno puedes seleccionar un numero entre 1 y 9"<<endl<<"para jugar en una casilla."<<endl<<endl;
	cout<<" --- --- ---"<<endl;
	cout<<"| 1 | 2 | 3 |"<<endl;
	cout<<" --- --- ---"<<endl;
	cout<<"| 4 | 5 | 6 |"<<endl;
	cout<<" --- --- ---"<<endl;
	cout<<"| 7 | 8 | 9 |"<<endl;
	cout<<" --- --- ---"<<endl<<endl;
	cout<<"El primer jugador en colocar tres casillas en linea con su"<<endl<<"simbolo gana la partida."<<endl<<endl;
	cout<<"Si el tablero se llena y no hay ganador se declarara empate."<<endl<<endl;
	cout<<"Diviertete intentando vencer a la maquina!"<<endl<<endl<<endl;
	
	cout<<"Presiona una tecla para continuar..."<<endl;
	getch();//pausar hasta q el usuario presione una tecla
	
	while((int)play-48==0)//Inicia bucle de juegos hasta que el usuario decida salir del juego
	{
		//cabezote
	cout<<endl<<"*******************************************"<<endl;
	cout<<"***  TRIQUI XD: El juego del gato v2.0  ***"<<endl;
	cout<<"*******************************************"<<endl<<endl;
		
		level = 0;
		
		while((int)level-48 != 1 && (int)level-48 != 2)
		{
			cout<<endl<<"** DIFICULTAD **"<<endl;
			cout<<"Selecciona el nivel de dificultad 1 o 2"<<endl;
			cout<<"1 Facil"<<endl;
			cout<<"2 Dificil"<<endl<<endl;
			cin>>level;
			cout<<endl;
		}
		
		throw_dices = 0;
		cout<<endl<<"** LANZAMIENTO DE LOS DADOS **"<<endl;
		
		while(throw_dices==0)//Inicia bucle de lanzamiento de dados
		{
			cout<<"Presiona una tecla para lanzar el dado..."<<endl;
			getch();//pausar hasta q el usuario presione una tecla
			srand (time(NULL));
			x_dice = throw_dice();//dado del usuario
			cout<<"DADO USUARIO ==> "<<x_dice<<endl<<endl;
			
			cout<<"Presiona una tecla para que la maquina lance el dado..."<<endl;
			getch();//pausar hasta q el usuario presione una tecla
			srand (time(NULL));
			o_dice = throw_dice();//dado de la maquina
			cout<<"DADO MAQUINA ==> "<<o_dice<<endl<<endl<<endl<<endl;
			
			
			
			if(x_dice>o_dice)//Si dado usuario > dado pc 
			{
				cout<<"******* INICIA EL USUARIO *******"<<endl;
				human_even = true;//turnos usuario en par desde 0
				throw_dices=1;//finaliza bucle lanzamiento de dados
			}
			else if(x_dice<o_dice)//Si dado usuario < dado pc 
			{
				cout<<"******* INICIA LA MAQUINA *******"<<endl;
				human_even = false;//turnos usuario en impar
				throw_dices=1;//finaliza bucle lanzamiento de dados
			}
			else if(x_dice==o_dice)//Si dado usuario == dado pc 
			{
				cout<<"Empate, se lanzaran los dados nuevamente."<<endl<<endl;
			}
		}
		
		cout<<endl;
		
		restart_board();//Vaciar tablero
		print_board();//imprimir tablero
		
		turn_id=0;
		
		while(turn_id<9)//inicia bucle de turnos
		{
			if(is_even(turn_id))//si el turno es par
			{
				if(human_even)//si el usuario juega en turno par
				{
					cout<<endl<<"** TURNO DEL USUARIO **"<<endl;
					turn_complete=false;//marcar turno como NO finalizado
					
					while(!turn_complete)//inicia bucle de preguntas al usuario hasta q conteste con un campo vacio
					{
						cout<<"En que casilla deseas jugar?"<<endl;
						cin>>fill;//solicita campo
						
						if((int)fill-48 >= 1 && (int)fill-48 <= 9)//si el numero digitado esta entre [1 y 9]
						{
							number_to_xy((int)fill-48, x, y);//convierte dato campo a cordenadas de indices de matriz
							
							if(board[x][y]==' ')//si el campo esta vacio
							{
								board[x][y]='X';//llena el campo
								print_board();//imprimir tablero
								turn_complete=true;//finalizar bucle turno de usuario
							}
							else//si el campo NO esta vacio
							{
								cout<<"La casilla ya esta ocupada. Intenta nuevamente."<<endl<<endl;
								print_board();//imprimir tablero
							}
						}
						else//si el dato digitado no esta entre [1 y 9]
						{
							cout<<"Debes seleccionar un numero entre 1 y 9. Intenta nuevamente."<<endl<<endl;
							print_board();//imprimir tablero
						}
					}
				}
				else//si la maquina juega en turno par
				{
					cout<<endl<<"** TURNO DE LA MAQUINA **"<<endl;
					if(machine_game(level,x,y))//si encuentra una buena jugada ofensiva o defensiva
					{
						board[x][y]='O';//Ocupar el campo
						print_board();//imprimir tablero
					}
					else//si no hay jugada ofensiva o defensiva
					{
						srand (time(NULL));//insertamos la semilla del aleatorio
						random_field(x,y);//buscar campo aleatorio disponible
						board[x][y]='O';//ocupar campo
						print_board();//imprimir tablero
					}
				}
			}
			else//si el turno es impar
			{
				if(!human_even)//si el usuario juega en turno impar
				{
					cout<<endl<<"** TURNO DEL USUARIO **"<<endl;
					turn_complete=false;//marcar turno como NO finalizado
					
					while(!turn_complete)//inicia bucle de preguntas al usuario hasta q conteste con un campo vacio
					{
						cout<<"En que casilla deseas jugar?"<<endl;
						cin>>fill;//solicita campo
						
						
						if((int)fill-48 >= 1 && (int)fill-48 <= 9)//si el numero digitado esta entre [1 y 9]
						{
							number_to_xy((int)fill-48, x, y);//convierte dato campo a cordenadas de indices de matriz
							
							if(board[x][y]==' ')//si el campo esta vacio
							{
								board[x][y]='X';//llena el campo
								print_board();//imprimir tablero
								turn_complete=true;//finalizar bucle turno de usuario
							}
							else//si el campo NO esta vacio
							{
								cout<<"La casilla ya esta ocupada."<<endl<<"Intenta nuevamente."<<endl<<endl;
								print_board();//imprimir tablero
							}
						}
						else//si el numero digitado no esta entre [1 y 9]
						{
							cout<<"Debes seleccionar un numero entre 1 y 9."<<endl<<"Intenta nuevamente."<<endl<<endl;
							print_board();//imprimir tablero
						}
					}
				}
				else//si la maquina juega en turno impar
				{
					cout<<endl<<"** TURNO DE LA MAQUINA **"<<endl;
					if(machine_game(level,x,y))//si encuentra una buena jugada ofensiva
					{
						board[x][y]='O';//Ocupar el campo
						print_board();//imprimir tablero
					}
					else//si no hay jugada ofensiva
					{
						srand (time(NULL));//insertamos la semilla del aleatorio
						random_field(x,y);//buscar campo aleatorio disponible
						board[x][y]='O';//ocupar campo
						print_board();//imprimir tablero
					}
				}
			}
			
			if(is_winner())//si hay ganador
			{
				
				if(is_even(turn_id))//si el ultimo turno fue par
				{
					if(human_even)//si el usuario juega en turno par
					{
						win_user++;
						cout<<endl<<"*****  GANA EL USUARIO  *****"<<endl;
					}
					else//si la maquina juega en turno par
					{
						win_machine++;
						cout<<endl<<"*****  GANA LA MAQUINA  *****"<<endl;
					}
				}
				else//si el ultimo turno fue impar
				{
					if(!human_even)//si el usuario juega en turno impar
					{
						win_user++;
						cout<<endl<<"*****  GANA EL USUARIO  *****"<<endl;
					}
					else//si la maquina juega en turno impar
					{
						win_machine++;
						cout<<endl<<"*****  GANA LA MAQUINA  *****"<<endl;
					}
				}
				
				cout<<"******  FIN DEL JUEGO  ******"<<endl<<endl;
				cout<<endl<<"** MARCADOR **"<<endl;
				cout<<"Usuario:"<<win_user<<" Maquina:"<<win_machine<<endl<<endl;
					
				turn_id = 9;//finaliza bucle de turnos
			}
			else if(turn_id==8)//si es el ultimo turno y aun no hay ganador
			{
				cout<<endl<<"**********  EMPATE  *********"<<endl;
				cout<<"******  FIN DEL JUEGO  ******"<<endl<<endl;
				cout<<endl<<"** MARCADOR **"<<endl;
				cout<<"Usuario:"<<win_user<<" Maquina:"<<win_machine<<endl<<endl;
			}
			
			turn_id++;//siguiente turno
		}
		
		cout<<endl<<"** INICIAR NUEVA PARTIDA **"<<endl;
		cout<<"Desea jugar nuevamente? 0=SI, 1=NO."<<endl;
		cin>>play;//ingresa 0 si desea reiniciar el juego
	}
	
	return 0;
}
