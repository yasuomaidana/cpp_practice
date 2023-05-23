#include <vector>
#include <random>
#include <iostream>
#include <list>

using namespace std;

class Node
{

public:
    int index;
    double value;
    Node(int index, double value)
    {
        this->index = index;
        this->value = value;
    }
    bool operator<(const Node &nod) const
    {
        return (value < nod.value);
    }
};

ostream &operator<<(ostream &out, const Node &node)
{
    out << "index: " << node.index << " value: " << node.value;
}
class graph
{
private:
    default_random_engine generator;
    uniform_real_distribution<double> random_weigth;
    uniform_real_distribution<double> random_density = uniform_real_distribution<double>(0, 1);
    vector<double> path_weights;
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
                }
            }
        }
    }

public:
    vector<vector<double>> graphs_matrix;
    graph(int nodes, double density = 0.2, double min_weight = 1.0, double max_weight = 10.0)
    {
        random_weigth = uniform_real_distribution<double>(min_weight, max_weight);
        path_weights = vector<double>(nodes, INFINITY);
        this->density = density;
        this->nodes = nodes;
        build_graphs();
    }

    void calculate_weights(int node = 0)
    {
        calculate_weights(node, 0, node);
    }
    void calculate_weights(int node, double new_weight, int father)
    {
        vector<double> to_explore = graphs_matrix[node];
        double path_weight = to_explore[father];

        if (new_weight >= path_weights[node])
            return;

        list<Node> to_find = list<Node>();

        int i = 0;
        for (double exploring_weight : to_explore)
        {

            if (exploring_weight != 0 && i != father)
            {
                to_find.push_back(Node(i, exploring_weight));
            };
            i++;
        }

        path_weights[node] = new_weight;
        to_find.sort();
        for (auto searching : to_find)
        {

            calculate_weights(searching.index, new_weight + searching.value, node);
        }
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
    void show_connections()
    {
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                cout << (graphs_matrix[i][j] > 0) << " ";
            }
            cout << endl;
        }
    }
    void print_weights()
    {
        for (auto weight : path_weights)
        {
            cout << weight << endl;
        }
    }

    void show_average(){
        double accum = 0;
        for(double weight: path_weights){
            if(weight == INFINITY) continue;
            accum += weight;
        }
        accum /= nodes;
        cout<<"Average weight connections for "<<nodes<<" nodes with "<< density*100<<"% of density"<< " : "<< accum <<endl;
    }
};