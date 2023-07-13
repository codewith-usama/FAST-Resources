import socket

# Define the IP address and port number for the server
SERVER_IP = '127.0.0.1'
SERVER_PORT = 8888

# Define the list of possible moves
MOVES = ['Rock', 'Paper', 'Scissors']

# Create a TCP socket and bind it to the server IP address and port number
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((SERVER_IP, SERVER_PORT))

# Listen for incoming connections from clients
server_socket.listen(2)
print('Waiting for players to connect...')

while True:
    # Accept connections from two clients
    player1_socket, player1_address = server_socket.accept()
    print('Player 1 connected')
    player2_socket, player2_address = server_socket.accept()
    print('Player 2 connected')

    # Send a starting message to the players
    start_message = 'Welcome to Rock, Paper, Scissors!\n'
    start_message += 'You will play three rounds, and the winner will be determined by the majority of the rounds.\n'
    player1_socket.sendall(start_message.encode())
    player2_socket.sendall(start_message.encode())

    # Play the game for three rounds
    player1_score = 0
    player2_score = 0
    for i in range(3):
        # Receive the players' moves
        player1_move = player1_socket.recv(1024).decode()
        player2_move = player2_socket.recv(1024).decode()

        # Determine the winner of the round
        if player1_move == player2_move:
            round_winner = 'Round ' + str(i+1) + ' is a tie!'
        elif player1_move == 'Rock' and player2_move == 'Scissors':
            round_winner = 'Player 1 wins round ' + str(i+1) + '!'
            player1_score += 1
        elif player1_move == 'Paper' and player2_move == 'Rock':
            round_winner = 'Player 1 wins round ' + str(i+1) + '!'
            player1_score += 1
        elif player1_move == 'Scissors' and player2_move == 'Paper':
            round_winner = 'Player 1 wins round ' + str(i+1) + '!'
            player1_score += 1
        else:
            round_winner = 'Player 2 wins round ' + str(i+1) + '!'
            player2_score += 1

        # Send the winner of the round to the players
        player1_socket.sendall(round_winner.encode())
        player2_socket.sendall(round_winner.encode())

        # Determine the winner of the game
        if player1_score == player2_score:
               winner_message = 'The game is a tie!'
               loser_message = 'The game is a tie!'
        elif player1_score > player2_score:
            winner_message = 'Player 1 wins the game!'
            loser_message = 'Player 2 loses the game!'
        else:
            winner_message = 'Player 2 wins the game!'
            loser_message = 'Player 1 loses the game!'

        # Send the final messages to the players
        if player1_score > player2_score:
            player1_socket.sendall('Congratulations! You won the game.\n'.encode())
            player2_socket.sendall('Better luck next time!\n'.encode())
        elif player2_score > player1_score:
            player2_socket.sendall('Congratulations! You won the game.\n'.encode())
            player1_socket.sendall('Better luck next time!\n'.encode())
    
    # Close the connections with the players
    player1_socket.close()
    player2_socket.close()
