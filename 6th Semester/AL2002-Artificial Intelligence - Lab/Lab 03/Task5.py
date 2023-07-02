import random

# function to print the board


def print_board(board):
    print(' ' + board[0] + ' | ' + board[1] + ' | ' + board[2])
    print('-----------')
    print(' ' + board[3] + ' | ' + board[4] + ' | ' + board[5])
    print('-----------')
    print(' ' + board[6] + ' | ' + board[7] + ' | ' + board[8])

# function to check if the board is full


def is_board_full(board):
    if board.count(' ') > 1:
        return False
    else:
        return True

# function to check if a player has won


def is_winner(board, player):
    if (board[0] == player and board[1] == player and board[2] == player) or \
        (board[3] == player and board[4] == player and board[5] == player) or \
        (board[6] == player and board[7] == player and board[8] == player) or \
        (board[0] == player and board[3] == player and board[6] == player) or \
        (board[1] == player and board[4] == player and board[7] == player) or \
        (board[2] == player and board[5] == player and board[8] == player) or \
        (board[0] == player and board[4] == player and board[8] == player) or \
            (board[2] == player and board[4] == player and board[6] == player):
        return True
    else:
        return False

# function to get a valid move from the player


def get_player_move(board):
    while True:
        move = input('Enter your move (1-9): ')
        try:
            move = int(move)
            if move >= 1 and move <= 9:
                if board[move - 1] == ' ':
                    return move - 1
                else:
                    print('That space is already occupied!')
            else:
                print('Please enter a number between 1 and 9!')
        except ValueError:
            print('Please enter a number between 1 and 9!')

# function to get the computer's move


def get_computer_move(board, computer_letter):
    for i in range(9):
        if board[i] == ' ':
            board_copy = board[:]
            board_copy[i] = computer_letter
            if is_winner(board_copy, computer_letter):
                return i

    for i in range(9):
        if board[i] == ' ':
            board_copy = board[:]
            board_copy[i] = 'X' if computer_letter == 'O' else 'O'
            if is_winner(board_copy, 'X' if computer_letter == 'O' else 'O'):
                return i

    if board[4] == ' ':
        return 4

    while True:
        move = random.randint(0, 8)
        if board[move] == ' ':
            return move

# function to play the game


def play_game():
    print('Welcome to Tic Tac Toe!')
    board = [' '] * 9
    print_board(board)
    player_letter = input('Choose your letter (X or O): ')
    player_letter = player_letter.upper()
    computer_letter = 'X'
    if player_letter == 'O':
        print("Won")
        
