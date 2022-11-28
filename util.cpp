#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include<list>
#include<iterator>
#include "util.h"
 
using namespace std;

void PrintUsage()
{
    fprintf(stderr, "Usage: ./PJ3 <GraphType> <InputFile>\n");
}

void ReadFile(char *secondArg, int *numberOfvertices, int *numberOfEdges, EDGE *edges, pVERTEX *V)
{
    FILE *fp;
    fp = fopen(secondArg, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Cannot open file HEAPifile.txt\n");
        exit(1);
    }

    fscanf(fp, "%d", numberOfvertices);
    fscanf(fp, "%d", numberOfEdges);


    // V = (pVERTEX *) calloc(numberOfvertices+1, sizeof(pVERTEX));
    // for (int i=0; i<numOfVerts; i++)
    // {
    //     V[i] = (VERTEX *) calloc(1, sizeof(VERTEX));
    // }
    // //V[1]->key = 74;
    // V[1]->color = Black;

    // printf("VERTICE NUMBER = %d\n", numOfVerts);
    printf("EDGE NUMBER = %d\n", *numberOfEdges);
    
    edges = (EDGE *)calloc(*numberOfEdges , sizeof(EDGE));
   // VERTEX *verts = (VERTEX *)calloc(numOfVerts * sizeof(VERTEX));

    //VERTEX *ptr = verts;
    for (int i = 0; i < *numberOfEdges; i++)
    {
        int val1, val2, val3, val4;

        fscanf(fp, "%d %d %d %d", &val1, &val2, &val3, &val4);

        EDGE newEdge;
        newEdge.index = val1;
        newEdge.startVertex = val2;
        newEdge.endVertex = val3;
        newEdge.weight = val4;
        edges[i] = newEdge;
    }    
    // PrintAllEdges(edges, *numberOfEdges);
    // for (int i = 0; i < numOfEdges; i++)
    // {
    //     printf("Edge[%d]: Index=%d, Start=%d, End=%d, Weight= %f\n", i, edges[i].index, edges[i].startVertex, edges[i].endVertex, edges[i].weight);
    // }

    // for (int i = 0; i < numOfVerts; i++)
    // {
    //     printf("Vertexes[%d]: Index=%d, Pi=%d, Position=%d, Key= %f, Color=%d\n", i, V[i]->index, V[i]->pi, V[i]->position, V[i]->key, V[i]->color);
    // }

}


GRAPH* ReadGraph(char *inputFileName, GraphType graphType)
{
    FILE *fp;
    fp = fopen(inputFileName, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Cannot open file HEAPifile.txt\n");
        exit(1);
    }

    GRAPH *graph = new GRAPH;

    fscanf(fp, "%d %d", &graph->n, &graph->m);

    graph->edges = (EDGE *)calloc(graph->m , sizeof(EDGE));
    graph->ADJ = (EDGE **)calloc(graph->n+1, sizeof(EDGE*));

    for (int i = 0; i < graph->m; i++)
    {
        // EDGE newEdge;
        // fscanf(fp, "%d %d %d %f", &newEdge.index, &newEdge.startVertex, &newEdge.endVertex, &newEdge.weight);

        // graph->edges[i] = newEdge;
        EDGE* edge = new EDGE;
        fscanf(fp, "%d %d %d %f", &edge->index, &edge->startVertex, &edge->endVertex, &edge->weight);
        
        graph->edges[i] = *edge;
        EDGE *directedEdge = CloneEdge(edge);
        AddEdge(graph, directedEdge);
        if(graphType == Undirected)
        {
            EDGE *undirectedEdge = CloneEdge(edge);

            int temp = undirectedEdge->endVertex;
            undirectedEdge->endVertex = undirectedEdge->startVertex;
            undirectedEdge->startVertex = temp;
            AddEdge(graph, undirectedEdge);
        }
    } 

    // PrintADJ(graph);



    return graph;
}

void PrintGraph(GRAPH* graph)
{
    printf("NUMBER of vertices = %d\n", graph->n);
    printf("NUMBER of edges = %d\n", graph->m);

    for (int i = 0; i < graph->m; i++)
    {
        PrintEdge(&graph->edges[i]);
        printf("\n");
       // printf("Edge[%d]: Index=%d, Start=%d, End=%d, Weight= %.2f\n", i, graph->edges[i].index, graph->edges[i].startVertex, graph->edges[i].endVertex, graph->edges[i].weight);
    }
}

void PrintEdge(EDGE *edge)
{
    printf("[%d %d: %.2f]", edge->startVertex, edge->endVertex, edge->weight);
}

void PrintADJ(GRAPH* graph)
{
    for(int i = 1; i <= graph->n; i++)
    {
        printf("ADJ[%d]:", i);
        EDGE* edge = graph->ADJ[i];
        while (edge != NULL)
        {
            printf("-->");
            PrintEdge(edge);
            edge = edge->next;
        }        
        printf("\n");
    }
}

void AddEdge(GRAPH *graph, EDGE *edge)
{
    if(graph->ADJ[edge->startVertex] != NULL)
    {
        edge->next = graph->ADJ[edge->startVertex];
    }
    graph->ADJ[edge->startVertex] = edge;
}

EDGE* CloneEdge(EDGE *edge)
{
    EDGE* newEdge = new EDGE;
    newEdge->index = edge->index;
    newEdge->startVertex = edge->startVertex;
    newEdge->endVertex = edge->endVertex;
    newEdge->weight = edge->weight;
    newEdge->next = edge->next;
    return newEdge;
}









// void PrintAllEdges(EDGE *_edges, int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         printf("Edge[%d]: Index=%d, Start=%d, End=%d, Weight= %f\n", i, _edges[i].index, _edges[i].startVertex, _edges[i].endVertex, _edges[i].weight);
//     }
// }

void WriteOutputFile()
{
    std::ofstream outputFile;
    outputFile.open("Output.txt");
    if (outputFile.is_open())
    {
        outputFile << "File Output \n";

        // outputFile << "capacity=" << (Heap->capacity) << ", size=" << (Heap->size) << "\n";
        // switch (adi)
        // {
        // case 1:
        //     outputFile << "MaxHeap:";
        //     for (int i = 0; i < Heap->size; i++)
        //     {
        //         outputFile << " " << Heap->A[i].key;
        //         if (i != Heap->size - 1)
        //             outputFile << ",";
        //     }
        //     outputFile << "\n";
        //     break;
        // case 2:
        //     outputFile << "MinHeap:";
        //     for (int i = 0; i < Heap->size; i++)
        //     {
        //         outputFile << " " << Heap->a[i].key;
        //         if (i != Heap->size - 1)
        //             outputFile << ",";
        //     }
        //     outputFile << "\n";
        //     break;
        // case 3:
        //     outputFile << "MaxHeap:";
        //     for (int i = 0; i < Heap->size; i++)
        //     {
        //         outputFile << " " << Heap->A[i].key;
        //         if (i != Heap->size - 1)
        //             outputFile << ",";
        //     }
        //     outputFile << "\n";

        //     outputFile << "MinHeap:";
        //     for (int i = 0; i < Heap->size; i++)
        //     {
        //         outputFile << " " << Heap->a[i].key;
        //         if (i != Heap->size - 1)
        //             outputFile << ",";
        //     }
        //     outputFile << "\n";
        //     break;
        // }
        outputFile.close();
    }
    else
    {
        fprintf(stderr, "Error: Cannot open file Output.txt\n");
        return;
    }
}
