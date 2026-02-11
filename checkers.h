#include <iostream>
#include <raylib.h>
#include <string>

#define NUM_ROWS 8
#define NUM_COLUMNS 8
#define TILE_DIMENSION 135

using namespace std;





class tile 
{
  public:

    // Data
    int tile_id = -1;
    float tile_x = 0;
    float tile_y = 0;
    float tile_width = 135;
    float tile_height = 135;
    Color tile_color = WHITE;
    bool tile_playable = false;
    Rectangle tile_dimensions = {tile_x, tile_y, tile_width, tile_height};

    // Behavior
    void Draw_Tile() 
    {
        std::cout << "Tile: " << std::to_string(tile_id) << " x: " << to_string(tile_x) << " y: " << to_string(tile_y) << "\n";
        DrawRectangle(tile_x, tile_y, tile_width, tile_height, tile_color); // Draw shape itself
        DrawRectangleLines(tile_x, tile_y, 135, 135, BLACK); // Draw outile
    }
};


class piece 
{
  public:

    // Data
    bool is_king = false;
    bool is_selected = false;
    bool is_elimnated = false;
    int piece_x = 0;
    int piece_y = 0;
    Color piece_color;
    Color piece_lineColor;
    int piece_radius = 30;

    // Behavior
    void Draw_Piece() 
    {
    DrawCircle(piece_x, piece_y, piece_radius, piece_color);

    if (is_king) 
    {
    // Draw outlines of the piece
    DrawCircleLines(piece_x, piece_y, 05, GOLD);
    DrawCircleLines(piece_x, piece_y, 10, GOLD);
    DrawCircleLines(piece_x, piece_y, 15, GOLD);
    DrawCircleLines(piece_x, piece_y, 20, GOLD);
    DrawCircleLines(piece_x, piece_y, 30, GOLD);

    } 
    else // Is normal piece
    {

    // Draw outlines of the piece
    DrawCircleLines(piece_x, piece_y, 05, piece_lineColor);
    DrawCircleLines(piece_x, piece_y, 15, piece_lineColor);
    DrawCircleLines(piece_x, piece_y, 30, piece_lineColor);
    }
    }
};

void Init_Board_Data(tile[][NUM_COLUMNS], int, int);
void Draw_Board(tile [][NUM_COLUMNS], int, int);