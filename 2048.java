/*
    Code Samples
    Author: Soomin Lee
    Language: Java
*/



    /*
    This Java Code is part of 2048 game.
    
    In a square grid, a new tile with random number appears
    every time a user makes a move. This number could be either 2 or 4.
    Two is more likely to appear than four - TWO_PROBABILITY is initially set to 80

    */

    public final int TWO_PROBABILITY = 80;

    public void addRandomTile() {

        // count of empty tiles
        int count = 0;

        for(int i = 0; i < GRID_SIZE; i++){
            for(int j = 0; j < GRID_SIZE; j++){
                if(this.grid[i][j] == 0){
                    // need to keep track of 0 locations, but can't use
                    // regular numbers (1,2,3) as labels.
                    // so flip 0's to negative number (-1, -2, -3 ...) and identify them
                    // later when setting random location
                    this.grid[i][j] = -count;
                    count++;
                }
            }
        }

        // no open spot - exit
        if(count == 0){
            return;
        }

        int location = random.nextInt(count);
        // flip location value also bc the 0 locations are labeled with
        // negative numbers
        location = -location;
        int value = random.nextInt(100);

        // flipped - go down the row first
        for(int k = 0; k < GRID_SIZE; k++){
            for(int l = 0; l < GRID_SIZE; l++){ //
                if(this.grid[l][k] == location){
                    if(value < TWO_PROBABILITY){
                        this.grid[l][k] = 2;
                    }else{
                        this.grid[l][k] = 4;
                    }
                }
            }
        }

        // change the negative numbers back to zero
        // to restore original values
        for(int row = 0; row < GRID_SIZE; row++){
            for(int col = 0; col < GRID_SIZE; col++){
                if(this.grid[row][col] < 0)
                    this.grid[row][col] = 0;
            }
        }        

    }




