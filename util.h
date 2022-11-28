// Proper formatting of output needed to inform user of an erro of inputted arguments

typedef struct TAG_EDGE
{
    int index;  //is essentially vertex
    int startVertex;
    int endVertex;
    float weight;
    TAG_EDGE *next;
}EDGE;

typedef struct GRAPH
{
    int n; //NUMB OF VERTICES 
    int m; //NUMB OF EDGES
    EDGE *edges;
    EDGE **ADJ;
}GRAPH;

enum GraphType
{
    Directed = 0,
    Undirected = 1,
    InvalidType = 2
};

//typedef EDGE *pEDGE;


// typedef struct TAG_VERTEX
// {
//     int index;
//     COLOR color;
//     float key;
//     int pi;
//     int position;
// }VERTEX;


// typedef struct TAG_HEAPTEST
// {
//     int capacity;
//     int size;
//     VERTEX *a;  //min heap
// } HEAPTEST;

enum COLOR
{
    White = 0,
    Grey = 1,
    Black = 2
};

typedef struct TAG_VERTEX{
    int index;
    COLOR color;
    float key;
    int pi;
    int position;
}VERTEX;
typedef VERTEX *pVERTEX;

void PrintUsage();
void ReadFile(char *secondArg, int *numberOfVertices, int *numberOfEdges, EDGE *edges, pVERTEX *V);
GRAPH* ReadGraph(char *inputFileName, GraphType graphType);
void PrintGraph(GRAPH* graph);
void WriteOutputFile();
void PrintAllEdges(EDGE *_edges, int size);

void AddEdge(GRAPH *graph, EDGE *edge);
EDGE* CloneEdge(EDGE *edge); 
void PrintEdge(EDGE *edge);
void PrintADJ(GRAPH* graph);