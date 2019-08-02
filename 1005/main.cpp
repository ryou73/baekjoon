#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;
int arr[1001][1001];
int time[1001];
int linked[1001];
int answer[1001];
int main()
{
    int T;
    cin>>T;
    while(T--){
        int N,K,a,b;
        cin>>N>>K;
        for(int i=1;i<=N;i++){//init
            for(int j=1;j<=N;j++) arr[i][j]=0;
            time[i]=0;
            linked[i]=0;
            answer[i]=0;
        }
        for(int i=1;i<=N;i++) scanf("%d",&time[i]);
        for(int i=1;i<=K;i++) {
            scanf("%d %d",&a,&b);
            arr[a][b]=1;
            linked[b]++;
        }

        queue<int> q;
        for(int i=1;i<=N;i++) {
            if(linked[i]==0) {
                q.push(i);
                answer[i]=time[i];
            }
        }

        while(!q.empty()){
            int now_v=q.front(); q.pop();

            for(int i=1;i<=N;i++){
                if(arr[now_v][i]){
                    answer[i]=max(answer[i],answer[now_v]+time[i]);
                    linked[i]--;
                    if(linked[i]==0) q.push(i);
                }
            }
        }
        /*while(!q.empty()){
            int now_v=q.front().first;
            int now_time=q.front().second; q.pop();

            answer[now_v]=now_time+time[now_v];
            for(int i=1;i<=N;i++) if(arr[now_v][i]==1) linked[i]--;
            for(int i=1;i<=N;i++) {
                if(linked[i]==0&&answer[i]==0) {
                    int max_time=-1;
                    for(int j=1;j<=N;j++){
                        if(arr[j][i]==1) max_time=max(max_time,answer[j]);
                    }
                    q.push(make_pair(i,max_time));
                }
            }
        }*/
        int W;
        cin>>W;
        //for(int i=1;i<=N;i++) cout<<answer[i]<<" ";
        cout<<answer[W]<<endl;
    }
}
