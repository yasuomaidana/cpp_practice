#include <vector>
#include <random>
#include <iostream>
using namespace std;

class graph
{
private:
    default_random_engine generator;
    uniform_real_distribution<double> random_weigth;
    uniform_real_distribution<double> random_density = uniform_real_distribution<double>(0, 1);
    vector<vector<double>> graphs_matrix;
    double density;
    double nodes;
    void build_graphs()
    {
        graphs_matrix = vector<vector<double>>(nodes, vector<double>(nodes));

        for (int i = 0; i < nodes; i++)
        {
            for (int j = i + 1; j < nodes; j++)
            {
                if (random_density(generator) < density)
                {
                    graphs_matrix[i][j] = graphs_matrix[j][i] = random_weigth(generator);
                } else
                    graphs_matrix[i][j] = graphs_matrix[j][i] = INFINITY;
            }
        }
    }

public:
    graph(int nodes, double density = 0.2, double min_weight = 1.0, double max_weight = 10.0)
    {
        random_weigth = uniform_real_distribution<double>(min_weight, max_weight);
        this->density = density;
        this->nodes = nodes;
        build_graphs();
    }
    void print()
    {
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                cout << graphs_matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph graph_50 = graph(5,0.2);
    graph_50.print();
}