#include<bits/stdc++.h>

using namespace std;

void matrix_input(int adj_matrix[][100], int node)
{
    for(int i=1;i<=node;i++)
    {
       for(int j=1;j<=node;j++)
        {
            scanf("%d", &adj_matrix[i][j]);
        }
    }


    return ;

}

void node_edge_matrix_input(int adj_mat[][100], int edge)
{
        for(int j=1;j<=edge;j++)
        {
            int n1,n2;
            int cost;
            cin>>n1>>n2>>cost;
            adj_mat[n1][n2]=cost;
            adj_mat[n2][n1]=cost;
        }

    return;
}

void print_matrix(int adj_matrix[][100],int node)
{
    for(int i=1;i<=node;i++)
    {
        for(int j=1;j<=node;j++)
            printf("%d  ", adj_matrix[i][j]);
        puts("");
    }


    return ;

}

int main()
{
    int node, adj_matrix[100][100], edge;
    cin>>node>>edge;

    node_edge_matrix_input(adj_matrix, edge);
    print_matrix(adj_matrix,node);
    return 0;
}
