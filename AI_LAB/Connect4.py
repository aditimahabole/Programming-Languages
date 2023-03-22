import numpy as np
import pygame as pg
import sys
# --global variables needed---
ROWS = 6
COLS = 7
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
# def draw_board(board):
#     pass
# # initializing py-game
# pg.init()
# SQUARE_SIZE = 100
# width = COLS * SQUARE_SIZE
# height = (ROWS+1) * SQUARE_SIZE
# size = (width,height)

# screen = pg.display.set_mode(size)
# --------------------------------------------------------------------------
# -----starting game------
game_over = False
turn = 0
while not game_over:
    # ask for player 1 input 
    if turn == 0:
        col = int(input("Player 1's Turn choose (0-6) : "))
        print("Selection made by P1 : ",col)
        if is_valid_location(board,col):
            row = get_next_open_row(board,col)
            drop_piece(board,row,col,1)

            if winning_move(board,1):
                print("P1 WINS!")
                game_over = True

    # ask for player 2 input
    else:
        col = int(input("Player 2's Turn choose (0-6) : "))
        print("Selection made by P2 : ",col)
        if is_valid_location(board,col):
            row = get_next_open_row(board,col)
            drop_piece(board,row,col,2)
            if winning_move(board,2):
                print("P2 WINS!")
                game_over = True
    print("---CURRENT BOARD--")
    show_board(board)
    turn+=1
    turn = turn % 2 # 0 , 1
