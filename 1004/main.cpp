#include <iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--){
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        int n;
        cin>>n;
        int answer=0;
        while(n--){
            int Cx,Cy,r;
            cin>>Cx>>Cy>>r;
            bool Cor_1,Cor_2;
            Cor_1=(Cx-x1)*(Cx-x1)+(Cy-y1)*(Cy-y1)<r*r;
            Cor_2=(Cx-x2)*(Cx-x2)+(Cy-y2)*(Cy-y2)<r*r;
            if(Cor_1!=Cor_2) answer++;
        }
        cout<<answer<<"\n";
    }
}
