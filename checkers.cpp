#include "checkers.h"

// void Setup_Pieces(Tile tiles[], Piece player_pieces[], int num_tiles,
//                  int num_pieces, bool is_player_1) 
// {

//   if (is_player_1) 
//   {
//     int tile_num = 0;
//     for (int piece_num = 0; piece_num < num_pieces; tile_num++) {
//       if (tiles[tile_num].playable) {
//         player_pieces[piece_num].x = tiles[tile_num].x + 135 / 2;
//         player_pieces[piece_num].y = tiles[tile_num].y + 135 / 2;
//         player_pieces[piece_num].color = RED;
//         player_pieces[piece_num].lineColor = BLACK;
//         piece_num++;
//       }
//     }
//   }

//   if (!is_player_1) {
//     // start from the back minus 1 for index
//     int tile_num = num_tiles - 1;
//     for (int piece_num = 0; piece_num < num_pieces; tile_num--) {
//       if (tiles[tile_num].playable) {
//         player_pieces[piece_num].x = tiles[tile_num].x + 135 / 2;
//         player_pieces[piece_num].y = tiles[tile_num].y + 135 / 2;
//         player_pieces[piece_num].color = BLUE;
//         player_pieces[piece_num].lineColor = BLACK;
//         piece_num++;
//       }
//     }
//   }
// }



// bool HasNoPieceAlready(Tile selected_tile, Piece player_1_pieces[],
//                        Piece player_2_pieces[], int num_pieces) {
//   for (int piece_num = 0; piece_num < num_pieces; piece_num++) {
//     if (player_1_pieces[piece_num].x == selected_tile.x + 67 &&
//         player_1_pieces[piece_num].y == selected_tile.y + 67) {
//       cout << "false!\n";
//       return false;
//     }

//     if (player_2_pieces[piece_num].x == selected_tile.x + 67 &&
//         player_2_pieces[piece_num].y == selected_tile.y + 67) {
//       cout << "false!\n";
//       return false;
//     }
//   }
//   cout << "true!\n";
//   return true;
// }

// bool CheckWin(Piece player_1_pieces[], Piece player_2_pieces[],
//               int num_pieces) {
//   bool player_1_out = true;
//   bool player_2_out = true;
//   for (int piece_num = 0; piece_num < num_pieces; piece_num++) {
//     if (!player_1_pieces[piece_num].is_removed) {
//       player_1_out = false;
//     }
//     if (!player_2_pieces[piece_num].is_removed) {
//       player_2_out = false;
//     }
//   }
//   if (!player_1_out && !player_2_out) {
//     return false;
//   } else {
//     return true;
//   }
// }

// void RemovePiece(Piece *piece_to_remove) {
//   cout << "trying to remove!\n";
//   piece_to_remove->x = 3000;
//   piece_to_remove->y = 3000;
//   piece_to_remove->is_removed = true;
// }

// void UpdateMouse() 
// {
//   if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
//   {
//     DrawCircleV(GetMousePosition(), 30, RED);
//   }
// }

int main() 
{

  int num_rows = NUM_ROWS;
  int num_columns = NUM_COLUMNS;

  int num_tiles = num_rows * num_columns;

  int num_pieces = (num_columns / 2) * 3; // Calculates number of starting pieces, should be 12

  tile tiles[NUM_ROWS][NUM_COLUMNS];

  piece player_1_pieces[num_pieces];
  piece player_2_pieces[num_pieces];
  const int screen_width = 1440;
  const int screen_height = 1080;
  bool is_player_1_turn = true;
  bool player_1_won = false;
  bool player_2_won = false;
  bool is_draw = false;
  piece *selectedPiece = nullptr;
  tile *selectedTile = nullptr;
  piece *piece_to_remove = nullptr;
  Rectangle draw = {1100, 300, 320, 50};
  Rectangle cant_move = {1100, 400, 320, 50};

  InitWindow(screen_width, screen_height, "Checkers");
  SetTargetFPS(60);

  Init_Board_Data(tiles, num_rows, num_columns);

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

void Init_Board_Data(tile tiles[][NUM_COLUMNS], int num_rows, int num_columns) 
{
  
  int tile_num = 0; // Used to give each tile an id
  int curr_x_axis = 0;
  int curr_y_axis = 0;

  tile* curr_tile = nullptr;

  for (int row = 0; row < num_rows; row++) // For each row
  {
      
      for (int column = 0; column < num_columns; column++) // For each column in the row,
      {
        curr_tile = &tiles[row][column];
        curr_tile->tile_id = tile_num;
        tile_num++;

        curr_tile->tile_x = (TILE_DIMENSION * column);
        curr_tile->tile_y = (TILE_DIMENSION * row);

        // Color tiles, and set playability 

        if(row % 2 == 0 && column % 2 == 0) // It's Even row
        {
            curr_tile->tile_color = DARKBLUE;
            curr_tile->tile_playable = true;
        }
        
        if(row % 2 == 1 && column % 2 == 1) // Even column in the row
        {
            curr_tile->tile_color = DARKBLUE;
            curr_tile->tile_playable = true;
        }


      }
    }
}

void Draw_Board(tile tiles[][NUM_COLUMNS], int num_rows, int num_columns)
{
  
  
  for (int row = 0; row < num_rows; row++) // For each row
  {
      for (int column = 0; column < num_columns; column++) // For each column in the row,
      {
        tiles[row][column].Draw_Tile();
      }

    }


}
