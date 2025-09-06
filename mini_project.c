/*
 ============================================================================
 Name        : mini project.c
 Author      : Fady Essam
 Version     :
 Copyright   : Your copyright notice
 Description : Vehicle Control system
 ============================================================================
 */




#include <stdio.h>
int main ()
{
	setbuf ( stdout , NULL);
	enum {OFF,ON};
	char choice;
	char choice_2;
	char traffic_light = 'R' ;
	int speed = 0;

	int room_temperature = 25;

	int AC = OFF;

	int Engine_temperature = 0;

	int Engine_state= OFF ;

	int Engine_temperature_controller = OFF;


	while (1)
	{
		printf("a. Turn on the vehicle engine\n");
		printf("b. Turn off the vehicle engine\n");
		printf("c. Quit the system\n");
		scanf(" %c",&choice);

		if (choice == 'c') {
			printf("Quit the program\n");
			break;
		}
		else if (choice == 'b') {
			printf("Engine turned off.\n");
			continue;
		}
		else if(choice =='a')
		{
			printf("Engine turned on.\n");
			Engine_state = ON;
			while(1)
			{
				printf("Sensors set menu.\n");
				printf("a.Turn off the engine\n");
				printf("b.Set the traffic light color.\n");
				printf("c.Set the room temperature.\n");
				printf("d.Set the engine temperature.\n");
				scanf(" %c",&choice_2);
				if (choice_2 =='a')
				{
					Engine_state = OFF ;
					printf("the engine is Turned off\n");
					break;
				}
				if (choice_2 =='b')
				{
					printf("Set the traffic light color\n");
					printf("R-->red \n");
						printf("O -->orange\n");
								printf("G-->green\n");
					scanf(" %c",&traffic_light);
					if (traffic_light == 'R'){
						speed = 0;
					}
					else if (traffic_light == 'O'){
						speed = 30;
					}
					else if (traffic_light == 'G'){
						speed = 100;
					}
					else
					{
						printf("invalid Character");
						continue;
					}


				}
				if (choice_2 =='c')
				{
					printf("Set the room temperature\n");
					scanf("%d",&room_temperature);
					if (room_temperature<10)
					{
						room_temperature=20;
						AC= ON;
					}
					else if (room_temperature>30)
					{
						room_temperature=20;
						AC= ON;
					}
					else
					{
						AC=OFF;
						room_temperature=room_temperature;
					}
				}
				if (choice_2 =='d')
				{
					printf("Set the engine temperature\n");
					scanf("%d",&Engine_temperature);
					if (Engine_temperature<100)
					{
						Engine_temperature=125;
						Engine_temperature_controller = ON;
					}
					else if (Engine_temperature>150)
					{
						Engine_temperature=125;
						Engine_temperature_controller = ON;
					}
					else
					{
						Engine_temperature=Engine_temperature;
						Engine_temperature_controller = OFF;
					}
				}
				break ;
			}

		}

		if (speed==30){
			AC = ON ;
			room_temperature = room_temperature*(5/4) +1 ;
			Engine_temperature_controller = ON ;
			Engine_temperature = Engine_temperature*(5/4) +1 ;
		}
		Engine_state == ON ? printf("i. Engine state: ON \n") : printf("i. Engine state: OFF \n");
		AC == ON ? printf("ii. AC:ON \n") : printf("ii. AC: OFF\n") ;
		printf("iii. Vehicle Speed : %d\n",speed);
		printf("iv. Room Temperature : %d\n",room_temperature);
		Engine_temperature_controller == ON ? printf("v. Engine Temperature Controller State: ON \n") : printf("v. Engine Temperature Controller State: OFF \n");
		printf("vi. Engine Temperature : %d\n", Engine_temperature);
	}

	return 0 ;
}

