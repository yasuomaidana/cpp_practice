#include "graph.h"
#include <iomanip>
#include "tree.h"

int main(){
    int nodes = 50;

    graph graph_50 = graph(nodes, 0.6);
    auto matrix = graph_50.graphs_matrix;
    for(auto row: matrix){
        for(auto element: row){
            cout<<setw(3)<<fixed<<setprecision(1)<<element<<"  ";
        }
        cout<<endl;
    }

    jarnik_tree jt = jarnik_tree(nodes);
    jt.build_jarnik_tree(matrix);
    cout<<jt;
}