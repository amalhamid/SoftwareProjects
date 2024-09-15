#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
bool hasLowercase(char pass[]);
bool hasUppercase(char pass[]);
bool hasDigit(char pass[]);
bool hasSpecialChar(char pass[]);
int evaluateStrength(char pass[]);

bool hasLowercase(char pass[]){
        int i;
	for(i=0; pass[i] != '\0'; i++) {
                if(pass[i] >= 'a' && pass[i] <= 'z')
                        return true;
        }
	return false;
}
bool hasUppercase(char pass[]){
        int i;
	for(i=0; pass[i] != '\0'; i++) {
                if(pass[i] >= 'A' && pass[i] <= 'Z')
                        return true;
        }
	return false;
}
bool hasDigit(char pass[]){
        int i;
	for(i = 0; pass[i] != '\0'; i++){
                if (pass[i] >= '0' && pass[i] <= '9')
                        return true;
        }
	return false;
}
bool hasSpecialChar(char pass[]){
        int i;
	for(i=0; pass[i] != '\0'; i++){
                if(!(pass[i] >= '0' && pass[i] <= '9') && !(pass[i] >= 'a' && pass[i] <= 'z') && !(pass[i] >= 'A' && pass[i] <= 'Z'))
                        return true;
        }
	return false;
}
int evaluateStrength(char pass[]){
        int score = 0;
        if(hasLowercase(pass)){
		score+= 1;
        }
	if(hasUppercase(pass)){
                score+=	1;
	}
	if(hasDigit(pass)){
                score+=	1;
	}
	if(hasSpecialChar(pass)){
                score+=	1;
	}
	if(strlen(pass) >= 12){
		score+=1;
	}
	return score;
}
int main(){
	char pass[100];
        int choice;
        int strength;
	char* pointer;
        while(1){
		printf("\n");
                printf("Password Resilience Analyzer\n");
                printf("1. Test a new password\n");
                printf("2. View strength of the last tested password\n");
                printf("3. Exit\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);
                if(choice == 1){
                        printf("Enter the password: ");
                        scanf("%s", pass);
                        if(strlen(pass) < 8){
                                printf("Error: Password should be at least 8 characters long.\n");
				continue;
			}
			int strength = evaluateStrength(pass);
			if(strength >= 0 && strength <= 2){
				pointer  = strdup("Weak");
			}else if(strength >= 3 && strength <=4){
				pointer = strdup("Moderate");
			}else{
				pointer = strdup("Strong");
			}

                  
                       	printf("Password Strength: %s\n", pointer);
                }
                if(choice == 2){
                        printf("Last tested password strength: %s\n", pointer);
                }
                if(choice == 3){
                        printf("Exiting...\n");
                        break;
                }
        }
	return 0;
}








