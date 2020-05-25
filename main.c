#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

       /* 130 = é
          133 = à
          138 = è
          135 = ç
          136 = ê  */

int main(){
    start:
    // ON PERMET DE CHOISIR ENTRE LES DIFFERENTS CHIFFREMENTS
    switch(menu()){
        //CHIFFREMENT CESAR
        case 1:
            cesar:
            system("cls");
            switch(cipher()){
            //ON CHIFFRE EN CESAR
            case 1:
                system("cls");
                cesarChiffrement();
            break;
            //ON DECHIFFRE EN CESAR
            case 2:
                system("cls");
                cesarDechiffrement();
            break;
            //MAUVAISE VALEURE, ON REDEMANDE
            default:
                system("cls");
                printf("\nChoix indisponible");
                Sleep(5000);
                goto cesar;
            break;
            }
        break;
        //CHIFFREMENT VIGENERE
        case 2:
            vigenere:
            system("cls");
            switch(cipher()){
            //ON CHIFFRE EN VIGENERE
            case 1:
                system("cls");
                vigenereChiffrement();
            break;
            //ON DECHIFFRE EN VIGENERE
            case 2:
                system("cls");
                vigenereDechiffrement();
            break;
            //MAUVAISE VALEURE, ON REDEMANDE
            default:
                system("cls");
                printf("Choix indisponible");
                Sleep(5000);
                goto vigenere;
            break;
            }
        break;
        //CHIFFREMENT BINAIRE
        case 3:
            binaire:
            system("cls");
            switch(cipher()){
            //ON CHIFFRE EN BINAIRE
            case 1:
                system("cls");
                binaireChiffrement();
            break;
            //ON DECHIFFRE EN BINAIRE
            case 2:
                system("cls");
                binaireDechiffrement();
            break;
            //MAUVAISE VALEURE, ON REDEMANDE
            default:
                system("cls");
                printf("Choix indisponible");
                Sleep(5000);
                goto binaire;
            break;
            }
        break;
        //MAUVAISE VALEURE DU MENU, ON REDEMANDE
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
    //ON RECUPERE LE CHOIX DE L'UTILISATEUR
    scanf("%d", &cipherChoice);
    //ON RENVOIE LE CHOIX DE L'UTILISATEUR
    return cipherChoice;
}

int cipher(){
    int cipher;
    int i;
    printf("Souhaites-tu chiffrer ? (1)\n"
           "Souhaites-tu d%cchiffrer ? (2)\n", 130, 133);
    scanf("%d", &cipher);
    //ON ENVLEVE LE '\n' QUI FAIT BUGGUER LE PROGRAMME AVEC LA FONCTION purge()
    purge();
    //ON RENVOIE LE CHOIX DE L'UTILISATEUR
    return cipher;
}

void cesarChiffrement() {
    char message[100], ch;
	int i, cle, menu;

	startChiffrement:
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
    Sleep(3000);
    printf("\n\nSouhaitez vous recommencer ?(Pour continuer entrez 1, sinon vous serez ramener au menu.)\n");
    scanf("%d", &menu);
    purge(menu);
    if(menu==1){
        system("cls");
        goto startChiffrement;
    }
    else{
        system("cls");
        main();
    }
	return 0;
}

int cesarDechiffrement(){
	char message[100], ch;
	int i, key, menu;

    startDechiffrement:
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
    Sleep(3000);
    printf("\n\nSouhaitez vous recommencer ?(Pour continuer entrez 1, sinon vous serez ramener au menu.)\n");
    scanf("%d", &menu);
    purge(menu);
    if(menu==1){
        system("cls");
        goto startDechiffrement;
    }
    else{
        system("cls");
        main();
    }
	return 0;
}

void vigenereChiffrement(){

    int i, j, k, menu, numMsg[100], numKey[100], numCipher[100];
    char msg[100], key[100];
    startChiffrement:
    printf("Entrez un message: ");
    gets(msg);
    // on convertit le texte pour qu'il soit en majuscule et n'ait plus d'espace
    for(i=0,j=0;i<strlen(msg);i++){
        if(msg[i]!=' '){
            msg[j]=toupper(msg[i]);
                j++;
        }
    }

    msg[j]='\0';
    printf("Le message est: %s \n", msg);
    //on enregistre en ascii
    for(i=0;i<strlen(msg);i++){
        numMsg[i]=msg[i]-'A';
    }

    printf("Entrez une cl%c: ", 130);
    gets(key);
    //on convertit la clé en majuscule et sans espace
    for(i=0,j=0;i<strlen(key);i++){
        if(key[i]!=' '){
            key[j]=toupper(key[i]);
            j++;
        }
    }

    key[j]='\0';
    //on met la clé à la chaine
    for(i=0;i<strlen(msg);){
        for(j=0;(j<strlen(key))&&(i<strlen(msg));j++){
            numKey[i]=key[j]-'A';
            i++;
        }
    }
    for(i=0;i<strlen(msg);i++){
        numCipher[i]=numMsg[i]+numKey[i];
    }

    for(i=0;i<strlen(msg);i++){
        if(numCipher[i]>25){
            numCipher[i]=numCipher[i]-26;
        }
    }

    printf("La phrase chiffr%ce est: ", 130);

    for(i=0;i<strlen(msg);i++){
        printf("%c",(numCipher[i]+'A'));
    }

    printf("\n");
    Sleep(3000);
    printf("\n\nSouhaitez vous recommencer ?(Pour continuer entrez 1, sinon vous serez ramen%c au menu.)\n", 130);
    scanf("%d", &menu);
    purge(menu);
    if(menu==1){
        system("cls");
        goto startChiffrement;
    }
    else{
        system("cls");
        main();
    }
}

void vigenereDechiffrement(){

    char msg[1000];
    char key[1000];
    char newKey[1000];
    char decryptedMsg[1000];
    int menu;
    startDechiffrement:
    printf("Entrez le texte chiffr%c: ", 130);
    gets(msg);
    printf("Entrez la cl%c: ", 130);
    gets(key);
    int i = 0, j;
    for(i = 0, j = 0; i < strlen(msg); ++i, ++j){
        if(j == strlen(key))
            j = 0;
        newKey[i] = key[j];
    }
    newKey[i] = '\0';

    for(i = 0; i < strlen(msg); i++){
        decryptedMsg[i] = (msg[i] - 'a' - (newKey[i] - 'a') + 26) % 26 + 'a';
    }
    decryptedMsg[i] = '\0';

    printf("Message chiffr%c: %s", 130, msg);
    printf("\nMessage d%cchiffr%c: %s", 130 , 130, decryptedMsg);

    Sleep(3000);
    printf("\n\nSouhaitez vous recommencer ?(Pour continuer entrez 1, sinon vous serez ramener au menu.)\n");
    scanf("%d", &menu);
    purge(menu);
    if(menu==1){
        system("cls");
        goto startDechiffrement;
    }
    else{
        system("cls");
        main();
    }
	return 0;
}

void binaireChiffrement(){
    int i, j=0, menu;
    char msg[100];
    startChiffrement:
    printf("Entrez la phrase %c chiffrer: ", 133);
    gets(msg);
    for(i=0;i<8*strlen(msg);i++){
        j++;
        printf("%d",0 != (msg[i/8] & 1 << (~i&7)));
        while(j==8){
            printf(" ");
            j=0;
        }
    }
    printf("\n");

    Sleep(3000);
    printf("\n\nSouhaitez vous recommencer ?(Pour continuer entrez 1, sinon vous serez ramen%c au menu.)\n", 130);
    scanf("%d", &menu);
    purge(menu);
    if(menu==1){
        system("cls");
        goto startChiffrement;
    }
    else{
        system("cls");
        main();
    }
}

void binaireDechiffrement(){
    int i, rem, sum=0;
    long int n;
    char msg[1000]
    startDechiffrement:
    printf("Entrez le binaire: ");
    gets(msg);
    i=0;
    for(int j=0;j<n/8;j++){
        while(n>0){
            rem = n % 10;
            sum = sum + rem * pow(2,i);
            n = n/10;
            i++;
        }
        printf("%c",sum);
    }
    Sleep(3000);
    printf("\n\nSouhaitez vous recommencer ?(Pour continuer entrez 1, sinon vous serez ramener au menu.)\n");
    scanf("%d", &menu);
    purge(menu);
    if(menu==1){
        system("cls");
        goto startDechiffrement;
    }
    else{
        system("cls");
        main();
    }
}

void purge(void){
    int buffer;
    while ((buffer = getchar()) != '\n' && buffer != EOF)
    {
    }
}
