#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class edge
{
    
    public:
    int start;
    double value;
    int end;
    edge(){};
    edge(int start, int end, double value) : start(start), end(end), value(value){};

    bool operator<(const edge &other) const
    {
        return value > other.value;
    }

    friend ostream &operator<<(ostream &out, const edge &ed);


};


ostream &operator<<(ostream &out, const edge &ed)
{
    out << ed.start << " -> " << ed.end << ": "<<ed.value;
}

class jarnik_tree
{
public:
    vector<bool> explored;
    vector<edge> edges;
    priority_queue<edge> edges_to_explore;
    int nodes;
    double weight_sum = 0;
    jarnik_tree(int elements) : explored(elements, false), nodes(elements){};

    void build_jarnik_tree(vector<vector<double>> graph_matrix){

        int root_node = find_root(graph_matrix);
        edge to_explore_edge = edge(root_node, root_node, 0.0);
        edges_to_explore.push(to_explore_edge);

        while(edges_to_explore.size()>0){
            to_explore_edge = edges_to_explore.top();
            int node = to_explore_edge.end;
            edges_to_explore.pop();
            
            if (explored[node] == true){
                continue;
            }
            weight_sum += to_explore_edge.value;
            

            if(to_explore_edge.end != to_explore_edge.start)
                edges.push_back(to_explore_edge);
            
            explored[node] = true;

            for(int child_node=0;child_node<nodes; child_node++){
                double weight = graph_matrix[node][child_node];
                if (!explored[child_node] && weight>0){
                    auto add_to_explore = edge(node,child_node, weight);
                    edges_to_explore.push(add_to_explore);
                }
            }
        }
    }

private:
    int find_root(vector<vector<double>> graph_matrix)
    {
        for (int node_i = 0; node_i < graph_matrix.size(); node_i++)
        {
            for (double weight : graph_matrix[node_i])
            {
                if (weight > 0)
                {
                    return node_i;
                }
            }
        }
    }
};


ostream &operator<<(ostream &out, const jarnik_tree &jt)
{
    for(auto ed: jt.edges){
        cout<<ed<<endl;
    }
    cout<<"Weigth sum: "<< jt.weight_sum;

    if(jt.edges.size() != jt.nodes-1){
        cout<<"\nNodes outside tree:"<<endl;
        int outside = 0;
        for(int i=0; i<jt.explored.size();i++){
            if(!jt.explored[i]){
                outside++;
                cout<<i<<",";
            }
        }
        cout<<endl<<"There are "<< outside<<" nodes outside tree";
    }
    
    
}