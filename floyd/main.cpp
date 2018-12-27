//
//  main.cpp
//  floyd
//
//  Created by Влад Купряков on 19/12/2018.
//  Copyright © 2018 Влад Купряков. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <ctime>
using namespace std;
const int maxV=1000;
int i, j, n;
int GR[maxV][maxV];
//алгоритм Флойда-Уоршелла
void FU(int D[][maxV], int V)
{
    int start_time =  clock();
    int k;
    for (i=0; i<V; i++) D[i][i]=0;
    
    for (k=0; k<V; k++)
        for (i=0; i<V; i++)
            for (j=0; j<V; j++)
                if (D[i][k] && D[k][j] && i!=j)
                    if (D[i][k]+D[k][j]<D[i][j] || D[i][j]==0)
                        D[i][j]=D[i][k]+D[k][j];
    int search_time = clock() - start_time;
    cout << endl << "время работы: " << float(search_time)/CLOCKS_PER_SEC << endl;
    for (i=0; i<V; i++)
    {
        //        for (j=0; j<V; j++) cout<<D[i][j]<<"\t";
        //        cout<<endl;
    }
}
//главная функция
int main()
{
    srand(time(NULL));
    int part;
    cout<<"Количество вершин в графе > "; cin>>n;
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
        {
            part = rand() % 4 + 1;
            switch (part) {
                case 1:
                    GR[i][j] = rand() % 251;
                    break;
                case 2:
                    GR[i][j] = rand() % 251 + 250;
                    break;
                case 3:
                    GR[i][j] = rand() % 251 + 500;
                    break;
                case 4:
                    GR[i][j] = rand() % 251 + 750;
                    break;
                default:
                    break;
            }
        }
    cout<<"Матрица кратчайших путей:"<<endl;
    FU(GR, n);
}
