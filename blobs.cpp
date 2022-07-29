#include <iostream>
using namespace std;
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>
#include <string>




void count_cells_4(vector<vector<int>>&vgrid, int nrows, int ncols, int srow, int scol){
    //cout<< count<< "\n";
    int i,j;
    vgrid[srow][scol] = 2;
    
    if(srow>0 && vgrid[srow-1][scol]==1){
        count_cells_4(vgrid, nrows, ncols, srow-1, scol);
    } 
    if(scol<ncols-1 && vgrid[srow][scol+1]==1){
        count_cells_4(vgrid, nrows, ncols, srow, scol+1);
    }
    if(srow<nrows-1 && vgrid[srow+1][scol]==1){
        count_cells_4(vgrid, nrows, ncols, srow+1, scol);
    }
    if(scol>0 && vgrid[srow][scol-1]==1){
        count_cells_4(vgrid, nrows, ncols, srow, scol-1);
    }
    return;
}


void count_cells_8(vector<vector<int>>&vgrid, int nrows, int ncols, int srow, int scol){
    //cout<< count<< "\n";
    int i,j;
    vgrid[srow][scol] = 2;

     
    if(srow>0 && vgrid[srow-1][scol]==1){
        
        count_cells_8(vgrid, nrows, ncols, srow-1, scol);
    }
     

    if(scol<ncols-1 && vgrid[srow][scol+1]==1){
         
        count_cells_8(vgrid, nrows, ncols, srow, scol+1);
    }
     

    if(srow<nrows-1 && vgrid[srow+1][scol]==1){
         
        count_cells_8(vgrid, nrows, ncols, srow+1, scol);
    }
     

    if(scol>0 && vgrid[srow][scol-1]==1){
         
        count_cells_8(vgrid, nrows, ncols, srow, scol-1);
    }
     

    if(scol<ncols-1 && srow>0  && vgrid[srow-1][scol+1]==1){
         
        count_cells_8(vgrid, nrows, ncols, srow-1, scol+1);
    }
    if(scol<ncols-1 && srow<nrows-1 && vgrid[srow+1][scol+1]==1){
         
        count_cells_8(vgrid, nrows, ncols, srow+1, scol+1);
    }
    if(scol>0 && srow<nrows-1 &&vgrid[srow+1][scol-1]==1){
         
        count_cells_8(vgrid, nrows, ncols, srow+1, scol-1);
    }
    if(scol>0 && srow>0 &&vgrid[srow-1][scol-1]==1){
         
        count_cells_8(vgrid, nrows, ncols, srow-1, scol-1);
    }
    return;
}


int main(int argc, char** argv){
    //Sets Inputs
    string fname = argv[1];
    string nrow = argv[2];
    string ncol = argv[3];
    string con = argv[4];
    
    //switch types
    //cout<<"s"<<nrow<<ncol<<sco<<"\n";
    stringstream ss;
    int nrows = stoi(nrow);
    int ncols = stoi(ncol);
    int conn = stoi(con);
    //cout<<"e"<<nrows<<ncols<<srow;

    //create grid
    fstream textFile;
    textFile.open(fname);
    int i, j;
    string tp;
    int grid [nrows][ncols];
    j=0;
    while(getline(textFile,tp)){
        //cout<<tp<<"\n";
        for(i=0;i<ncols+ncols-1;i++){
            grid[j][i] =  tp[2*i]-48;
        }
        j++;
    }
    std::vector<std::vector<int>> vgrid;
    std::vector<int>temp;
    for(i=0;i<nrows;i++){
        temp.clear();
        for(j=0; j<ncols;j++){
            temp.push_back(grid[i][j]);
        }
        vgrid.push_back(temp);
        //cout<<"\n";
    }

    int blobCount = 0;
    for(i=0;i<nrows;i++){
        for(j=0;j<ncols;j++){
            if(vgrid[i][j]==1){
                blobCount++;
                if(conn==4){
                    count_cells_4(vgrid, nrows, ncols, i, j);
                } else {
                    count_cells_8(vgrid, nrows, ncols, i, j);
                }
            }
        }
    }
    cout<< blobCount;
}