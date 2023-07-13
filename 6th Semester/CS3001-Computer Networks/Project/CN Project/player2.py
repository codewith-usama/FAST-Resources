import socket

# Define the IP address and port number for the server
SERVER_IP = '127.0.0.1'
SERVER_PORT = 8888

# Connect to the server
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.connect((SERVER_IP, SERVER_PORT))

# Receive a message from the server confirming the connection
start_message = server_socket.recv(1024).decode()
print(start_message)

# Get the player's move and send it to the server
move = input('Enter your move (Rock/Paper/Scissors): ')
server_socket.sendall(move.encode())

# Receive the winner of the round from the server
round_winner = server_socket.recv(1024).decode()
print(round_winner)

# Check if the game has ended
if 'wins the game!' in round_winner or 'The game is a tie!' in round_winner:
    # Receive the final messages from the server
    winner_message = server_socket.recv(1024).decode()
    loser_message = server_socket.recv(1024).decode()

    # Print the final messages
    print(winner_message)
    print(loser_message)

# Close the socket
server_socket.close()
