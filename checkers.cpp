#include "checkers.h"
#include <raylib.h>


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
  Init_Pieces_Data(player_1_pieces, player_2_pieces, num_pieces, tiles);


  while (WindowShouldClose() == false) 
  {

    
    Draw_Board(tiles, num_rows, num_columns);
    Draw_Pieces(player_1_pieces, player_2_pieces);

    // Drawing
    BeginDrawing();
    ClearBackground(DARKGRAY);

    EndDrawing();
  }
  CloseWindow();
  return 0;
}

/// End of Main




/// Subordinate Functions /// 

void Init_Board_Data(tile tiles[], int num_rows, int num_columns) 
{
  int tile_num = 0; // Used to give each tile an id
  int curr_row = 0;
  int curr_column = 0;
  int curr_x_axis = 0;
  int curr_y_axis = 0;

  Color WALNUT = {92, 64, 51, 255};

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
        curr_tile->tile_color = WALNUT;
        curr_tile->tile_playable = true;
    }
    
    if(curr_row % 2 == 1 && curr_column % 2 == 1) // Even column in the row
    {
        curr_tile->tile_color = WALNUT;
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
  
void Init_Pieces_Data(piece* player_1_pieces, piece* player_2_pieces, int num_pieces, tile* tiles)
{

  tile* curr_tile = nullptr;
  int piece_index = 0;
  Color CRIMSON = {180, 40, 45, 255};
  Color SLATE_BLUE = {34, 102, 68, 255};


  int tile_num = 0; // Count from the start

  // Place Player 1 Pieces
  for (; piece_index < NUM_PIECES; tile_num++ ) // Increment through tiles, not thru stop cond.
  {
    if (tiles[tile_num].tile_playable) 
    {
      player_1_pieces[piece_index].piece_x = tiles[tile_num].tile_x + TILE_DIMENSION / 2;
      player_1_pieces[piece_index].piece_y = tiles[tile_num].tile_y + TILE_DIMENSION / 2;
      player_1_pieces[piece_index].piece_color = CRIMSON;
      player_1_pieces[piece_index].piece_line_color = BLACK;
      piece_index++; // Only inc the stop cond. if we place a piece.
    }
  }

  // Place Player 2 Pieces
  tile_num = NUM_TILES - 1; // Start from the back

  for (int piece_num = 0; piece_num < num_pieces; tile_num--) // Decrement thru tiles, not pieces
  {
    if (tiles[tile_num].tile_playable) 
    {
      player_2_pieces[piece_num].piece_x = tiles[tile_num].tile_x + TILE_DIMENSION / 2;
      player_2_pieces[piece_num].piece_y = tiles[tile_num].tile_y + TILE_DIMENSION / 2;
      player_2_pieces[piece_num].piece_color = SLATE_BLUE;
      player_2_pieces[piece_num].piece_line_color = BLACK;
      piece_num++; // Only inc towards stop cond. if placed a piece
    }
  }


} 

void Draw_Pieces(piece* player_1_pieces, piece* player_2_pieces)
{
  int piece_index = 0;

  for (; piece_index < NUM_PIECES; piece_index++)
  {
    player_1_pieces[piece_index].Draw_Piece();
    player_2_pieces[piece_index].Draw_Piece();
  }
}