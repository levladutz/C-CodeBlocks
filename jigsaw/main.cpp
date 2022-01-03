#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
ifstream fin("CalcRO.in");
char cuvInutile[100][100] = {"Care", "Ce", "Cat", "este", "sunt", "rezultatul", "cu", "lui", "?", "dintre", NULL},
        cuvInm[10][20] = {"inmultire", "inmultirii", "inmultirea", "produs", "produsul", "produsului", NULL},
        cuvAdun[10][20] = {"suma", "sumei", "adunare", "adunarea", "adunarii", NULL},
        cuvScad[10][20] = {"scadere", "scaderii", "diferenta", "diferentei", NULL},
        cuvImp[10][20] = {"impartire", "impartirea", NULL};
char num[100][100] = {"o", "un", "unu", "doi", "doua", "trei", "patru", "cinci", "sase", "sapte", "opt", "noua", "zece",
                      "unsprezece", "doisprezece", "treisprezece", "paisprezece",
                      "cincisprezece", "saispreceze", "saptesprezece", "optsprezece", "nouasprezece", "douazeci",
                      "treizeci", "patruzeci", "cincizeci", "saizeci", "saptezeci", "optzeci", "nouazeci"
};
int numCif[100] = {1, 1, 1, 2, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 30, 40, 50, 60, 70,
                   80, 90
};
char cuvCheie[100][100] = {"suta", "sute", "mie", "mii", "milion", "milioane", NULL};
int cuvCheieCif[100] = {100, 100, 1000, 1000, 1000000, 1000000};
int ok, aFostcuvCheie, k;
char vecCuv[5000][10000];

char* transfLitCif(char *s) {
    int i = 0;
    char line[1000]= {0};
    int numar = 0, temp = 0;
    strcpy(line, s);
    char *q = new char[1000]();
    strcpy(q,line);
    char *savepointer = NULL;
    q = strtok_r(line, "_", &savepointer);
    while (q) {
        i = 0;
        ok = 0;
        while (num[i][0] != '_' && num[i][0]!='\0') {
            if (strcmp(q, num[i]) == 0) {
                ok = 1;
                if (aFostcuvCheie) {
                    numar = numar + temp;
                    temp = numCif[i];
                } else
                    temp = temp + numCif[i];
            }
            i++;
        }
        aFostcuvCheie = 0;
        if (!ok) {
            i = 0;
            while (cuvCheie[i][0] != '_' && cuvCheie[i][0]!='\0') {
                if (strcmp(q, cuvCheie[i]) == 0) {
                    temp = temp * cuvCheieCif[i];
                    aFostcuvCheie = 1;
                }
                i++;
            }
        }
        q = strtok_s(NULL, "_", &savepointer);
    }
    if (ok && !aFostcuvCheie)numar = numar + temp;
    if (!ok && aFostcuvCheie)numar = numar + temp;
    char* t = new char[1000]();
    int k = 0;
    while(numar)
    {
        t[k++] = numar%10+'0';
        numar/=10;
    }
    return t;
}
int eCuvInutil(char s[]) //verifica daca e cuvant inutil
{
    int i = 0;
    while (cuvInutile[i][0]!='\0') {
        if (strcmp(s, cuvInutile[i]) == 0)
            return 1;
        i++;
    }
    return 0;
}

int eSi(char *s) {
    if (strcmp(s, "si") == 0)
        return 1;
    return 0;
}

int eAdun(char *s) {
    int i = 0;
    while (cuvAdun[i][0]) {
        if (strcmp(s, cuvAdun[i]) == 0)
            return 1;
        i++;
    }
    return 0;
}

int eScad(char *s) {
    int i = 0;
    while (cuvScad[i][0]) {
        if (strcmp(s, cuvScad[i]) == 0)
            return 1;
        i++;
    }
    return 0;
}

int eInm(char *s) {
    int i = 0;
    while (cuvInm[i][0]) {
        if (strcmp(s, cuvInm[i]) == 0)
            return 1;
        i++;
    }
    return 0;
}

int eImp(char *s) {
    int i = 0;
    while (cuvImp[i][0]) {
        if (strcmp(s, cuvImp[i]) == 0)
            return 1;
        i++;
    }
    return 0;
}

void introdVec(char *s) {
    int i;
    char prop[25600]= {0}, cuv[10000]= {0};
    char *savepointer = NULL;
    char *p = strtok_s(s, " ", &savepointer);
    int siFlag = 0, nrp = 0;
    while (p) {
        strcpy(cuv, p);
        if (eSi(cuv)) {
            siFlag = 1;
            p = strtok_s(NULL, " ", &savepointer);
            continue;
        }
        if (eCuvInutil(cuv)) {
            p = strtok_s(NULL, " ", &savepointer);
            continue;
        }
        else if (eAdun(cuv)) {
            strcpy(vecCuv[k], "+");
            nrp++;
        } else if (eScad(cuv)) {
            strcpy(vecCuv[k], "-");
            nrp++;
        } else if (eInm(cuv)) {
            strcpy(vecCuv[k], "*");
            nrp++;
        } else if (eImp(cuv)) {
            strcpy(vecCuv[k], "\\");
            nrp++;
        } else {
            if (cuv[strlen(cuv) - 1] == ',') {
                cuv[strlen(cuv) - 1] = '\0';
                auto x = transfLitCif(cuv);
                strcpy(vecCuv[k],x);
                delete[] x;
            } else {
                auto x = transfLitCif(cuv);
                strcpy(vecCuv[k],x);
                delete[] x;
                if (siFlag) {
                    if (nrp) {
                        nrp--;
                        k++;
                        strcpy(vecCuv[k], ")");
                    }
                    siFlag=0;
                }
            }
        }
        k++;
        p = strtok_s(NULL, " ", &savepointer);
    }
}
int transfCharInt(char *s)
{
    int nr=0;
    for(int i=0;i<strlen(s);i++)
        nr=nr*10+s[i];
    return nr;
}
int evaluator(char exp[1000])
{
    int temp=0;
    char c='\0';
    stack <int> S;
    while(exp[i][0]!='\0')
    {
        if(exp[i]=='+' || exp[i]=='-' || exp[i]=='*' || exp[i]=='\\')
            S.push(exp[i]),strcpy(c,exp[i]);
        else
        if(exp[i][0]!=')')
            S.push(transfCharInt(exp[i]));
        else
        {

        }
    }
}
*/
int main() {
    char a[1000];
    fin.getline(a, 100);
    introdVec(a);
    for(int i=0; i<k; i++)
        cout<<vecCuv[i];


    return 0;

}
