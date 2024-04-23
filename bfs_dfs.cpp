#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<queue>
using namespace std;


//here i used set instead u can use list and replace the .insert in addedge with push_back 
class Graph
{
    public:
        unordered_map<int,set<int>> adj;
        unordered_map<int,bool> vis;
        int V;
        int E;

        Graph(int v,int e){
            V=v;
            E=e;
        }

        void addEdge(int u,int v,bool dir){
            //dir =false undirected
            adj[u].insert(v);
            if(!dir){
                adj[v].insert(u);
            }
        }

        void addEdges(vector<pair<int,int>> edges){
            for(auto edge:edges){
                addEdge(edge.first,edge.second,false);
            }
        }

        void printAdjList(){
            for(auto i:adj){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<<j<<" ";
                }
                cout<<endl;
            }
        }

        void bfs(int ele){

            queue<int> q;
            q.push(ele);

            while(!q.empty()){
                int curr=q.front();
                q.pop();
                if(vis[curr]==false){
                    cout<<curr<<" ";
                    vis[curr]=true;
                    for(auto i:adj[curr]){
                        q.push(i);
                    }
                }
            }

        }

        void BFS(){
            for(int i=0;i<V;i++){
                if(vis[i]==false){
                    bfs(i);
                }
            }
        }

        void dfs(int ele){
            cout<<ele<<" ";
            vis[ele]=true;

            for(auto i:adj[ele]){
                if(vis[i]==false){
                    dfs(i);
                }
            }
        }


};


int main(){
    Graph* g=new Graph(7,8);

    // pair<int,int> p1=make_pair(0,2);
    // pair<int,int> p2=make_pair(2,3);
    // pair<int,int> p3=make_pair(1,2);
    // pair<int,int> p4=make_pair(1,3);
    // vector<pair<int,int>> v={p1,p2,p3,p4};
    // g->addEdges(v);

    g->addEdge(0,2,false);
    g->addEdge(0,1,false);
    g->addEdge(4,2,false);
    g->addEdge(1,3,false);
    g->addEdge(4,3,false);
    g->addEdge(5,3,false);
    g->addEdge(5,6,false);
    g->addEdge(5,4,false);

    //g->printAdjList();
    //cout<<endl;

    g->bfs(1);

    //cout<<endl;
    //g->BFS();

    //g->dfs(0);

    return 0;
}
