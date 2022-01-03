#include <bits/stdc++.h>

using namespace std;
ifstream fin("in.in");

int v[200][200][200];

int norm(int x) {
    return x + 51;
}

int main() {
    char *p, s[1000];
    while (fin.getline(s, 1000)) {
        int op = 0;
        p = strtok(s, " ");
        if (strcmp(p,"on")==0)
            op = 1;
        p = strtok(NULL, " ");
        char *line = p;
        char *a, *b, *c;
        a = strtok(line, ",");
        b = strtok(NULL, ",");
        c = strtok(NULL, ",");
        int la = 0, ra = 0, ok = 0, sl=0, sr=0;
        for (int i = 0; a[i]; i++) {
            if (a[i] >= '0' && a[i] <= '9') {
                if (!ok)
                    la = la * 10 + a[i] - '0';
                else ra = ra * 10 + a[i] - '0';
            } else if (la > 0)
                ok = 1;
            if(a[i]=='-')
            {
                if(!ok)
                    sl=1;
                else sr=1;
            }
        }
        if(sl==1)
            la=-la;
        if(sr==1)
            ra=-ra;
        ok = 0, sl=0, sr=0;
        int lb = 0, rb = 0;
        for (int i = 0; b[i]; i++) {
            if (b[i] >= '0' && b[i] <= '9') {
                if (!ok)
                    lb = lb * 10 + b[i] - '0';
                else rb = rb * 10 + b[i] - '0';
            } else if (lb > 0)
                ok = 1;
            if(b[i]=='-')
            {
                if(!ok)
                    sl=1;
                else sr=1;
            }
        }
        if(sl==1)
            lb=-lb;
        if(sr==1)
            rb=-rb;
        ok = 0, sl=0, sr=0;
        int lc = 0, rc = 0;
        for (int i = 0; c[i]; i++) {
            if (c[i] >= '0' && c[i] <= '9') {
                if (!ok)
                    lc = lc * 10 + c[i] - '0';
                else rc = rc * 10 + c[i] - '0';
            } else if (lc > 0)
                ok = 1;
            if(c[i]=='-')
            {
                if(!ok)
                    sl=1;
                else sr=1;
            }
        }
        if(sl==1)
            lc=-lc;
        if(sr==1)
            rc=-rc;
        la = norm(la);
        ra = norm(ra);
        lb = norm(lb);
        rb = norm(rb);
        lc = norm(lc);
        rc = norm(rc);
        for (int i = max(norm(-50), la); i <= min(norm(50), ra); i++)
            for (int j = max(norm(-50), lb); j <= min(norm(50), rb); j++)
                for (int k = max(norm(-50), lc); k <= min(norm(50), rc); k++)
                    v[i][j][k] = op;
    }
    int sol=0;
    for (int i = norm(-50); i <= norm(50); i++)
        for (int j = norm(-50); j <= norm(50); j++)
            for (int k = norm(-50); k <= norm(50); k++)
                sol+=v[i][j][k];
    cout<<sol;
                return 0;
}
