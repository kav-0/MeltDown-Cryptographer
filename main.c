#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

       /* 130 = é
          133 = à
          138 = è
          135 = ç
          136 = ê  */

int main()
{
    start:
    switch(menu()){
        case 1:
            cesar:
            system("cls");
            switch(cipher()){
            case 1:
                system("cls");
                cesarChiffrement();
            break;

            case 2:
                system("cls");
                cesarDechiffrement();
            break;
            default:
                system("cls");
                printf("\nChoix indisponible");
                Sleep(5000);
                goto cesar;
            break;
            }
        break;

        case 2:
            vigenere:
            system("cls");
            switch(cipher()){
            case 1:
                system("cls");
                vigenereChiffrement();
            break;

            case 2:
                printf("réussi vigénère 2");
            default:
                system("cls");
                printf("Choix indisponible");
                Sleep(5000);
                goto vigenere;
            break;
            }
        break;

        case 3:
            system("cls");
            switch(cipher()){
            case 1:
                printf("réussi binaire 1");
            break;

            case 2:
                printf("réussi binaire 2");
            default:
                printf("Choix indisponible");
            break;
            }
        break;

        default:
            system("cls");
            printf("Choix indisponible. Veuillez choisir entre les choix propos%cs. (1, 2, 3)", 130);
            Sleep(5000);
            system("cls");
            goto start;
        break;
    }
}
int menu(){
    int cipherChoice;
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
           "|             _____         .__   __ ________                           |\n"
           "|            /     \\   ____ |  |_/  |\\______ \\   ______  _  ______      |\n"
           "|           /  \\ /  \\_/ __ \\|  |\\   __\\    |  \\ /  _ \\ \\/ \\/ /    \\     |\n"
           "|          /    Y    \\  ___/|  |_|  | |    `   (  <_> )     /   |  \\    |\n"
           "|          \\____|__  /\\___  >____/__|/_______  /\\____/ \\/\\_/|___|  \/    |\n"
           "|                  \\/     \\/                 \\/                  \\/     |\n"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n"

            "1: Chiffrement c%csar\n\n"
            "2: Chiffrement vig%cn%cre\n\n"
            "3: Chiffrement binaire\n\n", 130, 130, 138);

    scanf("%d", &cipherChoice);

    return cipherChoice;
}

int cipher(){
    int cipher;
    int i;
    printf("Souhaites-tu chiffrer ? (1)\n"
           "Souhaites-tu d%cchiffrer ? (2)\n", 130, 133);
    scanf("%d", &cipher);
    purge();
    return cipher;
}

void cesarChiffrement() {
    char message[100], ch;
	int i, cle;

	printf("Entrez le message %c chiffrer: ", 133);
	gets(message);
	printf("Entrez la cl%c: ", 130);
	scanf("%d", &cle);

	for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch + cle;

			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1;
			}

			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + cle;

			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}

			message[i] = ch;
		}
	}

	printf("Message chiffr%c: %s", 130, message);

	return 0;
}

int cesarDechiffrement(){
	char message[100], ch;
	int i, key;

	printf("Entrez un message %c d%cchiffrer: ", 133,130);
	gets(message);
	printf("Entrez la cl%c: ", 130);
	scanf("%d", &key);

	for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch - key;

			if(ch < 'a'){
				ch = ch + 'z' - 'a' + 1;
			}

			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch - key;

			if(ch < 'A'){
				ch = ch + 'Z' - 'A' + 1;
			}

			message[i] = ch;
		}
	}

	printf("Message d%cchiffr%c: %s", 130, 130, message);

	return 0;
}

int vigenereChiffrement(){

}
int chargement(){
    system("color 02");
    printf("Chargement en cours\n"
           "0\%");
    Sleep(2000);
    system("cls");
        printf("Chargement en cours\n"
           "23\%");
    Sleep(2000);
    system("cls");
        printf("Chargement en cours\n"
           "42\%");
    Sleep(2000);
    system("cls");
        printf("Chargement en cours\n"
           "56\%");
    Sleep(2000);
    system("cls");
    printf("Chargement en cours\n"
           "63\%");
    Sleep(2000);
    system("cls");
        printf("Chargement en cours\n"
           "72\%");
    Sleep(2000);
    system("cls");
        printf("Chargement en cours\n"
           "87\%");
    Sleep(2000);
    system("cls");
        printf("Chargement en cours\n"
           "96\%");
    Sleep(2000);
    system("cls");
    printf("100\% \n"
           "Chargement terminé. Lancement du programme de chiffrement \"MeltDown\"");
    Sleep(5000);
    system("cls");
}

void purge(void){
    int buffer;
    while ((buffer = getchar()) != '\n' && buffer != EOF)
    {
    }
}
