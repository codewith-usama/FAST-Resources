import tkinter as tk
import socket
import sys

SERVER_IP = '127.0.0.1'
SERVER_PORT = 8888

server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.connect((SERVER_IP, SERVER_PORT))

message = server_socket.recv(1024).decode()
print(f"{message}")

# Define function to send move to the server
def send_move(move, round_num):
    # Send the move to the server
    server_socket.sendall(move.encode())

    # Receive the winner of the round from the server and update the label
    round_winner = server_socket.recv(1024).decode()
    if round_winner == 'end':
        server_socket.close()
        window.destroy()
        sys.exit()
    result_label.config(text=f'Round {round_num}: {round_winner}')


# Create the GUI window
window = tk.Tk()
window.title('Rock Paper Scissors Game')

window.geometry('400x300')
window.configure(background='#f39c12')

title_label = tk.Label(window, text='Rock Paper Scissors Game', font=(
    'Arial', 24), pady=20, bg='#f39c12', fg='white')
title_label.pack()

welcome_label = tk.Label(window, text='Welcome player to the game!', font=(
    'Arial', 14), pady=10, bg='#f39c12', fg='white')
welcome_label.pack()

rock_button = tk.Button(window, text="Rock", font=('Arial', 14), bg='#34495e',
                        fg='white', padx=20, pady=10, command=lambda: send_move('Rock', 1))
rock_button.pack(pady=5)

paper_button = tk.Button(window, text="Paper", font=(
    'Arial', 14), bg='#34495e', fg='white', padx=20, pady=10, command=lambda: send_move('Paper', 2))
paper_button.pack(pady=5)

scissors_button = tk.Button(window, text="Scissors", font=(
    'Arial', 14), bg='#34495e', fg='white', padx=20, pady=10, command=lambda: send_move('Scissors', 3))
scissors_button.pack(pady=5)

result_label = tk.Label(window, font=('Arial', 14),
                        pady=10, bg='#f39c12', fg='white')
result_label.pack()

# Start the GUI event loop
window.mainloop()

# Close the socket
server_socket.close()
