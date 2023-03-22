import numpy as np
import pygame as pg
import sys
import math
# --global variables needed---
ROWS = 6
COLS = 7
BLUE =(36, 7, 153)
BLACK =(0, 2, 3)
GREEN = (154, 236, 3)
ORANGE = (250, 159, 0)
# -----creating board-----
def create_board():
    board = np.zeros((6,7))
    return board
board = create_board()
print("--Board--")
print(board)
# -----dropping piece----
def drop_piece(board,row,col,ball):
    board[row][col] = ball
    pass
# -----valid location or not----
def is_valid_location(board, col):
    return board[ROWS-1][col] == 0
# ----get next row-------
def get_next_open_row(board,col):
    for row in range(ROWS):
        if board[row][col] == 0:
            return row
# --print board---
def show_board(board):
    print(np.flip(board,0))
    # flipping board upside down
# --winner--
def winning_move(board,ball):
    # horizontal 
    for col in range(COLS-3):
        for row in range(ROWS):
            if board[row][col] == ball and board[row][col+1] == ball and board[row][col+2] == ball and board[row][col+3] == ball:
                return True 
    # vertical
    for col in range(COLS):
        for row in range(ROWS-3):
            if board[row][col] == ball and board[row+1][col] == ball and board[row+2][col] == ball and board[row+3][col] == ball:
                return True
    # right diagonal
    for col in range(COLS-3):
        for row in range(ROWS-3):
            if board[row][col] == ball and board[row+1][col+1] == ball and board[row+2][col+2] == ball and board[row+3][col+3] == ball:
                return True
    # left diagonal
    for col in range(COLS-3):
        for row in range(3,ROWS):
            if board[row][col] == ball and board[row-1][col+1] == ball and board[row-2][col+2] == ball and board[row-3][col+3] == ball:
                return True
# --------------------------------------------------------------------------
# draw board 
def draw_board(board):
    # iterate thru every spot
    for col in range(COLS):
        for row in range(ROWS):
            pg.draw.rect(screen,BLUE,(col*SQUARE_SIZE,row*SQUARE_SIZE + SQUARE_SIZE,SQUARE_SIZE,SQUARE_SIZE))
            pg.draw.circle(screen,BLACK,(int(col*SQUARE_SIZE + SQUARE_SIZE/2),int(row*SQUARE_SIZE + SQUARE_SIZE + SQUARE_SIZE/2)),RADIUS)

        for col in range(COLS):
            for row in range(ROWS):
                if board[row][col] == 1:
                    pg.draw.circle(screen,GREEN,(int(col*SQUARE_SIZE + SQUARE_SIZE/2),height -int(row*SQUARE_SIZE  + SQUARE_SIZE/2)),RADIUS)
                elif board[row][col] == 2:
                    pg.draw.circle(screen,ORANGE,(int(col*SQUARE_SIZE + SQUARE_SIZE/2),height -int(row*SQUARE_SIZE  + SQUARE_SIZE/2)),RADIUS)

    pg.display.update()

# initializing py-game
pg.init()
SQUARE_SIZE = 100
width = COLS * SQUARE_SIZE
height = (ROWS+1) * SQUARE_SIZE
size = (width,height)
RADIUS = int(SQUARE_SIZE/2 - 5)
screen = pg.display.set_mode(size)
my_font = pg.font.SysFont("monospace",75)
draw_board(board)
pg.display.update()


# --------------------------------------------------------------------------
# -----starting game------
game_over = False
turn = 0
while not game_over:
    for event in pg.event.get():
        if event.type == pg.QUIT:
            sys.exit()
        if event.type == pg.MOUSEMOTION:
            pg.draw.rect(screen,BLACK,(0,0,width,SQUARE_SIZE))
            posx = event.pos[0]
            if(turn == 0):
                pg.draw.circle(screen,GREEN,(posx,int(SQUARE_SIZE/2)),RADIUS)
            else:
                pg.draw.circle(screen,ORANGE,(posx,int(SQUARE_SIZE/2)),RADIUS)
        pg.display.update()


        if event.type == pg.MOUSEBUTTONDOWN:
            pg.draw.rect(screen,BLACK,(0,0,width,SQUARE_SIZE))
            print(event.pos)
            # ask for player 1 input 
            if turn == 0:
                posx = event.pos[0]
                col = int(math.floor(posx/SQUARE_SIZE))

                print("Selection made by P1 : ",col)
                if is_valid_location(board,col):
                    row = get_next_open_row(board,col)
                    drop_piece(board,row,col,1)

                    if winning_move(board,1):
                        label = my_font.render("Player 1 Wins!",1,GREEN)
                        screen.blit(label,(40,10))
                        game_over = True

    # ask for player 2 input
            else:
                posx = event.pos[0]
                col = int(math.floor(posx/SQUARE_SIZE))
                print("Selection made by P2 : ",col)
                if is_valid_location(board,col):
                    row = get_next_open_row(board,col)
                    drop_piece(board,row,col,2)
                    if winning_move(board,2):
                        label = my_font.render("Player 2 Wins!",1,ORANGE)
                        screen.blit(label,(40,10))
                        game_over = True
                        
            print("---CURRENT BOARD--")
            show_board(board)
            draw_board(board)
            turn+=1
            turn = turn % 2 # 0 , 1
            if game_over:
                pg.time.wait(3000)





