#include <bits/stdc++.h>

using namespace std;
ifstream fin("in.in");
int x, y, z, w;
long long input;
char var[4][10] = {"x", "y", "z", "w"};
long long data[4], cinput=100000000000000;
char *p, s[1000];
char op[1000][10][100];
char cop[1000][10][100];
int n=0; 
long long cpow = 10000000000000;
char sa[10], sb[10];
int main() {
   
    while (fin.getline(s, 100)) {
        p=strtok(s," ");
        int k=0;
        n++;
        while(p){
            strcpy(op[n][++k],p);
            p=strtok(NULL," ");
        }
    }
    int ok = 1;
    while (ok) {
        data[0]=data[1]=data[2]=data[3]=0;
        cpow = 10000000000000;
        cinput--;
        input=cinput;
        for (int i = 1; i <= n; i++) {
            p = op[i][1];
            if (strcmp(p, "inp") == 0) {
                p = op[i][2];
                if (strcmp(p, "x") == 0) {
                    data[0] = input / cpow;
                    input -= data[0] * cpow;
                    cpow /= 10;
                } else if (strcmp(p, "y") == 0) {
                    data[1] = input / cpow;
                    input -= data[1] * cpow;
                    cpow /= 10;
                } else if (strcmp(p, "z") == 0) {
                    data[2] = input / cpow;
                    input -= data[2] * cpow;
                    cpow /= 10;
                } else if (strcmp(p, "w") == 0) {
                    data[3] = input / cpow;
                    input -= data[3] * cpow;
                    cpow /= 10;
                }
            } else if (strcmp(p, "add") == 0) {
                p = op[i][2];
                strcpy(sa, p);
                p = op[i][3];
                strcpy(sb, p);
                int flag = 0;
                for (int i = 0; i<4; i++)
                    for (int j = 0; j<4; j++)
                        if (strcmp(sa, var[i]) == 0 && strcmp(sb, var[j]) == 0) {
                            flag = 1;
                            data[i] += data[j];
                        }
                if (flag == 0)
                    for (int i = 0; i<4; i++)
                        if (strcmp(sa, var[i])==0)
                            data[i] += stoi(sb, nullptr);
            } else if (strcmp(p, "mul") == 0) {
                p = op[i][2];;
                strcpy(sa, p);
                p = op[i][3];;
                strcpy(sb, p);
                int flag = 0;
                for (int i = 0; i<4; i++)
                    for (int j = 0; j<4; j++)
                        if (strcmp(sa, var[i]) == 0 && strcmp(sb, var[j]) == 0) {
                            flag = 1;
                            data[i] *= data[j];
                        }
                if (flag == 0)
                    for (int i = 0; i<4; i++)
                        if (strcmp(sa, var[i])==0)
                            data[i] *= stoi(sb, nullptr);
            } else if (strcmp(p, "div") == 0) {
                p = op[i][2];
                strcpy(sa, p);
                p = op[i][3];
                strcpy(sb, p);
                int flag = 0;
                for (int i = 0; i<4; i++)
                    for (int j = 0; j<4; j++)
                        if (strcmp(sa, var[i]) == 0 && strcmp(sb, var[j]) == 0) {
                            flag = 1;
                            data[i] /= data[j];
                        }
                if (flag == 0)
                    for (int i = 0; i<4; i++)
                        if (strcmp(sa, var[i])==0)
                            data[i] /= stoi(sb, nullptr);
            } else if (strcmp(p, "mod") == 0) {
                p = op[i][2];
                strcpy(sa, p);
                p = op[i][3];
                strcpy(sb, p);
                int flag = 0;
                for (int i = 0; i<4; i++)
                    for (int j = 0; j<4; j++)
                        if (strcmp(sa, var[i]) == 0 && strcmp(sb, var[j]) == 0) {
                            flag = 1;
                            data[i] %= data[j];
                        }
                if (flag == 0)
                    for (int i = 0; i<4; i++)
                        if (strcmp(sa, var[i])==0)
                            data[i] %= stoi(sb, nullptr);
            } else if (strcmp(p, "eql") == 0) {
                p = op[i][2];
                strcpy(sa, p);
                p = op[i][3];
                strcpy(sb, p);
                int flag = 0;
                for (int i = 0; i<4; i++)
                    for (int j = 0; j<4; j++)
                        if (strcmp(sa, var[i]) == 0 && strcmp(sb, var[j]) == 0) {
                            flag = 1;
                            data[i] = (data[i] == data[j]);
                        }
                if (flag == 0)
                    for (int i = 0; i<4; i++)
                        if (strcmp(sa, var[i])==0)
                            data[i] = (data[i] == stoi(sb, nullptr));
            }
        }
        if(data[2]==0)
            ok=0;
        cout<<cinput<<'\n';
    }
    cout<<cinput;
    return 0;
}
