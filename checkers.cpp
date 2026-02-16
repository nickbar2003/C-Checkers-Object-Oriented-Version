#include "checkers.h"


int main() 
{

  int num_rows = NUM_ROWS;
  int num_columns = NUM_COLUMNS;

  int num_tiles = NUM_TILES;

  int num_pieces = NUM_PIECES;

  tile tiles[num_tiles];

  piece player_1_pieces[num_pieces];
  piece player_2_pieces[num_pieces];

  const int screen_width = 1440;
  const int screen_height = 1080;

  piece *selectedPiece = nullptr;
  tile *selectedTile = nullptr;
  piece *piece_to_remove = nullptr;
  
  Rectangle draw = {1100, 300, 320, 50};
  Rectangle cant_move = {1100, 400, 320, 50};

  InitWindow(screen_width, screen_height, "Checkers");
  SetTargetFPS(60);

  Init_Board_Data(tiles, num_rows, num_columns);
  // Init_Pieces_Data(player_1_pieces, player_2_pieces, num_pieces);


  while (WindowShouldClose() == false) 
  {

    
    Draw_Board(tiles, num_rows, num_columns);

    // Drawing
    BeginDrawing();
    ClearBackground(DARKGRAY);

    EndDrawing();
  }
  CloseWindow();
  return 0;
}

void Init_Board_Data(tile tiles[], int num_rows, int num_columns) 
{
  
  int tile_num = 0; // Used to give each tile an id
  int curr_row = 0;
  int curr_column = 0;
  int curr_x_axis = 0;
  int curr_y_axis = 0;

  tile* curr_tile = nullptr;

  for (; tile_num < NUM_TILES; tile_num++) // For each row
  {
    curr_tile = &tiles[tile_num];

    curr_row = tile_num  / num_columns;
    curr_column = tile_num - (curr_row * num_columns);

    curr_tile->tile_x = TILE_DIMENSION * curr_column;
    curr_tile->tile_y = TILE_DIMENSION * curr_row;

        if(curr_row % 2 == 0 && curr_column % 2 == 0) // It's Even row
        {
            curr_tile->tile_color = DARKBLUE;
            curr_tile->tile_playable = true;
        }
        
        if(curr_row % 2 == 1 && curr_column % 2 == 1) // Even column in the row
        {
            curr_tile->tile_color = DARKBLUE;
            curr_tile->tile_playable = true;
        }


  }
}

void Draw_Board(tile tiles[], int num_rows, int num_columns)
{
  int tile_num = 0; // Used to give each tile an id

  for (; tile_num < NUM_TILES; tile_num++) // For each row
  {
    tiles[tile_num].Draw_Tile(); // Draw tile
  }
}
  
// void Init_Pieces_Data(piece* player_1_pieces[], piece* player_2_pieces[], int num_pieces)
// {
//   for(int i = 0; i < num_pieces; i++)
//   {
//     player_1_pieces[i]->piece_color = RED;
//     player_2_pieces[i]->piece_color = ORANGE;
//   }

//   for (int row = 0; row < num_rows; row++) // For each row
//   {
      
//       for (int column = 0; column < num_columns; column++) // For each column in the row,
//       {
//     }
//   }
// } 