#include "graph.h"

int main()
{
    graph graph_50 = graph(50, .2);
    graph_50.calculate_weights();
    graph_50.show_average();
    cout << "-------" << endl;
    graph graph_40d = graph(50, 0.4);
    graph_40d.calculate_weights();
    graph_40d.show_average();

}