#include <stdio.h>
#include <windows.h>
#include <string.h>

       /* 130 = é
          133 = à
          138 = è
          135 = ç
          136 = ê  */

int main()
{
    switch(menu()){
        case 1:
            system("cls");
            switch(cipher()){
            case 1:
                cesarChiffrement();
            break;
            case 2:
                printf("réussi césar 2");
            default:
                printf("Choix indisponible");
            break;
            }
        break;
        case 2:
            system("cls");
            switch(cipher()){
            case 1:
                printf("réussi vigénère 1");
            break;
            case 2:
                printf("réussi vigénère 2");
            default:
                printf("Choix indisponible");
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
    printf("Souhaites-tu chiffrer ? (1)\n"
           "Souhaites-tu d%cchiffrer ? (2)\n", 130, 133);
    scanf("%d", &cipher);
    if ( scanf("%d", &cipher) != NULL )
   {
      char *newline = strchr(cipher, '\n');
   }
    return cipher;
}

int cesarChiffrement(){
    char message[2000];
    char ch;
    char rep[3];
    char oui = 'oui';
    int i, key;

    start:
    printf("Entrez un message %c chiffrer: ", 133);
    fgets( message, 2000, stdin );
    printf("\nEntrez la cl%c: ", 130);
    scanf("%d", &key);

    for(i = 0; message[i] != '\0'; ++i){
   	 ch = message[i];

   	 if(ch >= 'a' && ch <= 'z'){
   		 ch = ch + key;

   		 if(ch > 'z'){
   			 ch = ch - 'z' + 'a' - 1;
   		 }

   		 message[i] = ch;
   	 }
   	 else if(ch >= 'A' && ch <= 'Z'){
   		 ch = ch + key;

   		 if(ch > 'Z'){
   			 ch = ch - 'Z' + 'A' - 1;
   		 }

   		 message[i] = ch;
   	 }
    }

    printf("Message chiffr%c: %s", 130, message);
    /*Sleep(1500);
    printf("\nVoulez-vous recommencer ? (oui/non)\n");
    scanf("%s", &rep);
    if(rep == oui){
        goto start;
    }
    else{
        printf("\n\nD'accord. Je vous renvoie au menu.");
        Sleep(5000);
        system("cls");
        menu();
    }*/
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

int chargement(){
    //system("color 02");
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

