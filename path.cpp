 #include <iostream>
 #include <string>
 #include <vector>
 #include <sstream>
 #include <fstream>
 #include <queue>
 #include <deque>

class Grid {

    private:
        std::vector<std::vector<int>> grid;
        int current_max;
        std::string fname, yesno = "no";
        int neighs[4][2] = {{-1,0}, {0,-1}, {1, 0}, {0, 1}};

    public:
        std::vector<std::vector<bool>> bo;
        int rows, cols, min, max;
        int xl = 0, yl = 0, xh = 0, yh = 0;

        Grid(std::string f, int r, int c){
            fname = f;
            rows = r;
            cols = c;
        };
        void ReadFile();
        void MinMax();
        void Path(int xc, int yc, int current);
        void Print();
};

void Grid::ReadFile(){

    std::ifstream file(fname);
    std::string str;

    while(std::getline(file,str)){
        std::vector<int>new_row;
        std::vector<bool>new_bo;

        std::istringstream ss(str);
        double token;
        while(ss >> token){
            new_bo.push_back(false);
            new_row.push_back(token);
        }
    
        bo.push_back(new_bo);
        grid.push_back(new_row);
    }

};

void Grid::MinMax(){

    min = grid[0][0];
    max = grid[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++){
            int value = grid[i][j];
            if (value > max){
                max = value;
                xh = i;
                yh = j;
            }
            if (value < min){
                min = value;
                current_max = value;
                xl = i;
                yl = j;
            }
        }
    xl++, yl++, xh++, yh++;
   
};

void Grid::Path (int xc, int yc, int current){

    if (bo[xc][yc] || grid[xc][yc] < current){
        if (current > current_max)
            current_max = current;
        return;
    }
    else if (current_max != max) {
        current = grid[xc][yc];
        bo[xc][yc] = true;
        for(int i = 0; i < 4; i++){
            int neighs_x = xc + neighs[i][0], neighs_y = yc + neighs[i][1];
            if (neighs_x >= 0 && neighs_x < rows && neighs_y >= 0 && neighs_y < cols)
                Path(neighs_x, neighs_y, current);
        }
    }
};

void Grid::Print(){

    if (current_max == max)
        yesno = "yes";
    std::cout << xl << ' ' << yl << ' ' << xh << ' ' << yh << ' ' << yesno << std::endl;
};

int main(int argc, char** argv){
    (void) argc;
    std::string fname = std::string(argv[1]);
    int rows = std::stoi(argv[2]);
    int cols = std::stoi(argv[3]);

    Grid grid1(fname, rows, cols);
    grid1.ReadFile(); 
    grid1.MinMax();
    grid1.Path(grid1.xl - 1, grid1.yl - 1, grid1.min);
    grid1.Print();
    //std::cout << std::endl;
}