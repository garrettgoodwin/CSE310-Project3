#include <stdio.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include "util.h"
#include "minheap.h"
#include<list>
#include<iterator>
//#include <stack>

// #include "stack.h"

using namespace std;


// Used when dealing with the user input phase
enum InputPhase
{
    TakeInput,
    StopInput
};

void ReadArguments(char *firstArg, char *secondArg, GraphType &graphType)
{
    if ((strcmp("Directed", firstArg) == 0))
    {
        graphType = Directed;
    }
    else if ((strcmp("Undirected", firstArg) == 0))
    {
        graphType = Undirected;
    }
    else
    {
        graphType = InvalidType;
        PrintUsage();
        exit(1);
    }
}

// void displayAdjList(std::list<int> adj_list[], int v)
// {
//    for(int i = 0; i<v; i++) {
//       cout << i << "--->";
//       list<int> :: iterator it;
//       for(it = adj_list[i].begin(); it != adj_list[i].end(); ++it) {
//          cout << *it << " ";
//       }
//       cout << endl;
//    }
// }
// void add_edge(list<int> adj_list[], int u, int v) {    //add v into the list u, and u into list v
//    adj_list[u].push_front(v);
//    adj_list[v].push_front(u);
// }


int main(int argc, char *argv[])
{
    GraphType graphType = InvalidType;
    bool validArgs;
    // std::stack<int> stack;

    if (argv[1] != NULL && argv[2] != NULL)
    {
        ReadArguments(argv[1], argv[2], graphType);
    }
    else
    {
        PrintUsage();
        exit(1);
    }

    int numberOfVertices = 0;
    int numberOfEdges = 0;
    EDGE *edges;
    pVERTEX *V;

    GRAPH* graph = ReadGraph(argv[2], graphType);
    // PrintGraph(graph);

    // list<int> ADJ[20];

    // PrintAllEdges(edges, numberOfEdges);
    // for(int i = 0; i < graph->m; i++)
    // {
    //     add_edge(ADJ, graph->edges[i].startVertex, graph->edges[i].endVertex);
    // }
    // add_edge(ADJ, 0, 3);
    // displayAdjList(ADJ, graph->m);

    // push(5);
    // push(5);
    // push(5);
    // push(5);
    // pop();
    // display();

    //Commands Needed
    //SinglePair        NOT DONE
    //SingleSource      NOT DONE
    //PrintPath         NOT DONE
    //PrintLength       NOT DONE
    //PrintADJ          NOT DONE

    InputPhase inputPhase = TakeInput;
    while (inputPhase == TakeInput)
    {
        char input[30];
        std::cin.getline(input, 30);
        char *token = strtok(input, " ");

        //SinglePair <source> <destination>
        if (strcmp("SinglePair", token) == 0)
        {
            // int source = atoi(strtok(NULL, " "));
            // int destination = atoi(strtok(NULL, " "));
        }

        //SingleSource <source>
        else if (strcmp("SingleSource", token) == 0)
        {
            // int source = atoi(strtok(NULL, " "));
        }

        //PrintPath <s> <t>
        else if (strcmp("PrintPath", token) == 0)
        {
            // int s = atoi(strtok(NULL, " "));
            // int t = atoi(strtok(NULL, " "));
        }

        //PrintLength <s> <t>
        else if (strcmp("PrintLength", token) == 0)
        {
            // int s = atoi(strtok(NULL, " "));
            // int t = atoi(strtok(NULL, " "));
        }

        //PrintADJ
        else if (strcmp("PrintADJ", token) == 0)
        {
            PrintADJ(graph);
        }

        //Stop Command
        else if (strcmp("Stop", token) == 0)
        {
            inputPhase = StopInput;
        }

        //Invalid Command Condition
        else
        {
            fprintf(stderr, "Invalid command.\n");
        }
    }

    WriteOutputFile();
    return 0;
}



