
#include <fstream>
using namespace std;
ifstream fin("elmaj.in");
ofstream fout("elmaj.out");
int n, v[1000001], cnt, k, i;
int main() {
    fin>>n;
    for(i=1; i<=n; i++) {
        fin>>v[i];
        if(k==v[i])
            cnt++;
        else cnt--;
        if(cnt<=0) {
            k=v[i];
            cnt=1;
        }
    }
    cnt=0;
    for(i=1; i<=n; i++) {
        if(k==v[i])
            cnt++;
    }
    if(cnt>=n/2+1)
        fout<<k<<' '<<cnt;
    else fout<<-1;
    return 0;
}