# Code_Decretemath
#include<bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[1001];//adj[i] là vector chứa các đỉnh kề với đỉnh i.
bool visited[1001];
void input(){
    cin >> n >>m;
    for(int i = 0; i < m; i++){
        int x, y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);//trường hợp cho đồ thị có hướng thì bỏ dòng này đi.
    }
    memset(visited, false, sizeof(visited));
}
void dfs(int u){
    cout<<u;
    visited[u] = true;
    for(int v: adj[u]){//duyệt từng đỉnh kề của v, nếu chưa được thăm thì sẽ thăm đỉnh đó.
        //neu dinh v chua duoc tham 
        if(!visited[v]){
            dfs(v);
        }
        //hàm sẽ thực hiện xong nếu như không còn đỉnh nào chưa được thăm để thăm nữa.
        //khi đó hàm dfs(v) tại thời điểm đó sẽ bị đẩy ra khỏi stack.
    }
}

void demthanhphanlienthong(){
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            cnt++;
            cout<<"cac dinh thuoc thanh phan lien thong thu  "<<cnt<<"la: ";
            dfs(i);
            cout<<endl;
        }
    }
    cout<<"so thanh phan lien thong cua do thi la : "<<cnt<<endl;

}
int main(){
    input();
    demthanhphanlienthong();

    return 0;
}
