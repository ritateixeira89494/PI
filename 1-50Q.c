#include <stdio.h>
#include <math.h>
#include <string.h>


//EXERCICIO 1
void maior(){
    int read,maior;
    scanf("%d",&read);
    maior = read;
    while (read != 0)
    {
        if (read > maior)
            maior = read;
        scanf("%d",&read);
    }
    printf("%d\n",maior);
}



//EXERCICIO 2
void media(){
    int read, soma = 0, count = 0, media;
    scanf("%d", &read);
    while (read != 0){
        soma += read;
        count++;
        scanf("%d", &read);
    }
    media = soma/count;
    printf("%d", media);
}



//EXERCICIO 3
void segundoMaior(){
    int maior = 0, segundo = 0, read;
    scanf("%d", &read);
    while (read != 0){
        if (maior < read) {
            segundo = maior;
            maior = read;
        }
        else if (segundo < read)
            segundo = read;

        scanf("%d", &read);
    }
    printf("%d", segundo);
}



//EXERCICIO 4
int bitsUm (unsigned int x){
    int r=0;
    while(x != 0){
        if(x % 2 == 1){
            r++;
            x /= 2;
        }
        else
            x /= 2;
    }
    return r;
}



//EXERCICIO 5
int trailingZ (unsigned int n){
    int count = 0;

    while (n > 0){
        n /= 2;
        if (n > 0)
            count++;
    }
    return count;
}



//EXERCICIO 6
int qDig (int n) {
    int r = 0;

    while (n > 0){
        r++;
        n /= 10;
    }

    return r;
}



//EXERCICIO 7
char *mystrcat(char s1[], char s2[]) {
    int i = 0, j = 0;

    for(; s1[i]; i++);
    for(; s2[j]; i++, j++){
        s1[i] = s2[j];
    }
    s1[i] = '\0';

    return s1;
}



//EXERCICIO 8
char *mystrcpy(char s1[], const char s2[]) {
    int i = 0;

    for(; s2[i]; i++){
        s1[i] = s2[i];
    }
    s1[i] = '\0';

    return s1;
}



//EXERCICIO 9
int mystrcmp(char s1[], char s2[]) {
    int i = 0;

    for(; s1[i] == s2[i] && s1[i]; i++);

    return s1[i] - s2[i];
}



//EXERCICIO 10
char *mystrstr (char s1[], char s2[]) {
    int i = 0, j = 0;

    for(; s1[i] && s2[j]; i++){
        if (s1[i] == s2[j]) j++;
        else j = 0;
    }

    if (s2[j] == '\0') return s1 + (i-j);

    return NULL;
}



//EXERCICIO 11
void strrev (char s[]) {
    int i = 0, last = strlen(s) - 1;
    char temp;

    while(i < last){
        temp = s[i];
        s[i] = s[last];
        s[last] = temp;
        i++; last--;
    }

}



//EXERCICIO 12
int isVogal(char a){
    if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' ||
        a == 'A' || a == 'E' || a == 'I' || a == 'O' || a == 'U'){
        return 1;

    }
    else return 0;
}

void strnoV (char t[]){
    int len = strlen(t);
    char r[len];
    int res = 0;
    int i = 0;

    for(; t[i]; i++){
        if(!isVogal(t[i])){
            t[res++] = t[i];
        }
    }

    t[res] = '\0';
}



//EXERCICIO 13
void truncW (char t[], int n){
    int i = 0, r = 0, count = 0;

    while(t[i] != '\0'){
        if (t[i] == ' '){
            t[r++] = t[i++];
            count = 0;
        }
        else if (count == n){
            i++;
        }
        else{
            t[r++] = t[i++];
            count++;
        }
    }

    t[r] = '\0';
}




//EXERCICIO 14
int frequenciaAux(char s[], char a){
    int i = 0, count = 0;
    for(; s[i]; i++){
        if(s[i] == a){
            count++;
        }
    }
    return count;
}

char charMaisfreq (char s[]) {

    if(s[0] == '\0'){
        return 0;
    }

    int i = 0, count = 0, countTemp = 0;
    char maisFreq = '\0';

    for(; s[i]; i++){
        countTemp = frequenciaAux(s, s[i]);
        if(countTemp > count){
            maisFreq = s[i];
            count = countTemp;
        }
    }
    return maisFreq;
}



//EXERCICIO 15
int iguaisConsecutivos (char s[]) {
    int i = 0, count = 0, countTemp = 1;
    
    for(; s[i]; i++){
        if(s[i] == s[i+1]){
            countTemp++;
        }
        else{
            if(countTemp > count)
                count = countTemp;
            countTemp = 1;
        }
    }
    
    return count;
}



//EXERCICIO 16
int difConsecutivos(char s[]){
	int i = 0, count = 0, countTemp = 0;
	char last = '\0';

	for (; s[i]; i++){
		if(s[i] != last){
			countTemp++;
			last = s[i];
		}
		else{
			if (countTemp > count)
				count = countTemp;
			countTemp = 0;
		}
	}

	if (countTemp > count){
		count = countTemp;
	}

	return count;
}



//EXERCICIO 17
int maiorPrefixo (char s1 [], char s2 []) {
    int i = 0, count = 0;
    
    while(s1[i] && s2[i] && s1[i] == s2[i]){
        i++;
        count++;
    }
    
    return count;
}



//EXERCICIO 18
int maiorSufixo (char s1 [], char s2 []) {
    int count = 0;
    int len1 = strlen(s1) - 1;
    int len2 = strlen(s2) - 1;
    
    while (s1[len1] && s2[len2]) {
        if (s1[len1] == s2[len2]) {
            count++;
            len1--; len2--;
        }
        else{
            break;
        }
    }

    /*
    Também daria:
    for(; s1[len1] && s2[len2] && s1[len1] == s2[len2]; len1--, len2--){
        count++;
    }
    */
    
    return count;
}



//EXERCICIO 19
int sufPref(char s1[], char s2[])
{
    int i1 = 0, i2 = 0;
    
    for (; s1[i1]; i1++)
    {
        if (s1[i1] == s2[i2]){
            i2++;
        }
        else{
            i2 = 0;
        }
    }
    return i2;
}



//EXERCICIO 20
int contaPal (char s[]) {
    int i = 0, count = 0;
    char last = '\0';
    
    for(i = 0; s[i]; i++){
        if(!isspace(s[i]) && (s[i+1] == ' ' || s[i+1] == '\0'))
        {
            count++;
        }
    }
    
    return count;
}



//EXERCICIO 21




//EXERCICIO 22




//EXERCICIO 23





//EXERCICIO 24




//EXERCICIO 25




//EXERCICIO 26




//EXERCICIO 27





//EXERCICIO 28



//EXERCICIO 29




//EXERCICIO 30




//EXERCICIO 31





int main() {
    return 0;
}
