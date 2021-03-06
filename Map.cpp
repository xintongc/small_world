//
// Created by xintong cheng on 2018-02-08.
//

#include "Map.h"

Map* Map::map = 0;

Map* Map::getMap(int n)
{
    if (map == 0)
    {
        try {
            map = new Map(n);
        }catch (std::bad_alloc& ba){
            std::cerr << "bad alloc caught" << ba.what()<< endl;
        }
    }

    return map;
}

Map::Map(int n) {

    this->n = n;
    adjacencyMatrix = new int* [n];   // A 2D matrix to show the connection of regions in map, if two regions are connected, shows 1; otherwise shows 0


    for(int i = 0; i < n; i++){
        adjacencyMatrix[i] = new int[n];
        for(int j = 0; j < n; j++){
            adjacencyMatrix[i][j] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        adjacencyMatrix[0][i] = i;
        adjacencyMatrix[i][0] = i;
    }
}

Map::~Map() {
    for (int i = 0; i < n; ++i) {
        delete [] adjacencyMatrix[i];
    }
    delete [] adjacencyMatrix;
}


void Map::display(){  //display the map created

    cout << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){

            if(j == 0){
                if(i < 10)
                    cout << "0";
            }
            if (i == 0){
                if(j < 10 && j != 0)
                    cout << "0";
            }

            if(i > 0){
                cout << adjacencyMatrix[i][j] <<"  ";
            } else {
                cout << adjacencyMatrix[i][j] <<" ";
            }

        }
        cout << endl;
    }
}

void Map::addEdge(int origin, int destin) {  //set two regions are connected

    if(origin > n || destin > n || origin < 0 || destin < 0){
        cout<<"Invalid edge!\n";
    } else {
            adjacencyMatrix[origin][destin] = 1;
    }
}

bool Map::connected(int origin, int destin) {  //check whether two regions are connected
    if(adjacencyMatrix[origin][destin] == 1){
        return true;
    }
    //cout << "Region " << origin << " and region " << destin <<" are not connected." << endl;
    return false;
}

void Map::checkSymmetry(){ //check whether the map is symmetrical, if region 1 is connected to region 2, then the region2 should also shows connected to region 1

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(adjacencyMatrix[i][j] != adjacencyMatrix[j][i]){
                cout << "missing position: i: " << i << ", j: " << j << endl;
                cout << "Invaild map! This map is not symmetrical, some edges are missing." << endl;
                exit(0);
            }
        }
    }

}
