#include "graph.h"
#include <iomanip>

int main(){
    graph graph_50 = graph(5, 0.6);
    auto matrix = graph_50.graphs_matrix;
    for(auto row: matrix){
        for(auto element: row){
            cout<<setw(3)<<fixed<<setprecision(1)<<element<<"  ";
        }
        cout<<endl;
    }
}