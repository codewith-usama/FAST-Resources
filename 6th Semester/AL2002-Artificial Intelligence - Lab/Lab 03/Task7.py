import numpy as np

# Initialize the environment
env = np.array([['B', 'D', 'C', 'D'],
                ['C', 'C', 'D', 'C'],
                ['D', 'C', 'B', 'D'],
                ['C', 'D', 'C', 'C']])

# Define the possible actions
actions = ['up', 'down', 'left', 'right', 'clean']

# Define the Q-table
q_table = np.zeros((env.shape[0]*env.shape[1], len(actions)))

# Define the hyperparameters
alpha = 0.1  # learning rate
gamma = 0.9  # discount factor
epsilon = 0.1  # exploration rate

# Define a function to get the state of the environment


def get_state(env):
    return env.flatten()

# Define a function to get the next state and reward based on the action taken


def get_next_state_and_reward(env, action):
    # Find the position of the vacuum cleaner
    pos = np.argwhere(env == 'V')[0]

    if action == 'up':
        if pos[0] > 0:
            pos[0] -= 1
    elif action == 'down':
        if pos[0] < env.shape[0]-1:
            pos[0] += 1
    elif action == 'left':
        if pos[1] > 0:
            pos[1] -= 1
    elif action == 'right':
        if pos[1] < env.shape[1]-1:
            pos[1] += 1

    # Check if the next state is clean or dirty
    next_state = env[pos[0], pos[1]]
    if next_state == 'D':
        reward = 1
    else:
        reward = 0

    return pos, next_state, reward


# Define the Q-learning algorithm
for episode in range(10000):
    # Reset the environment
    env = np.array([['B', 'D', 'C', 'D'],
                    ['C', 'C', 'D', 'C'],
                    ['D', 'C', 'B', 'D'],
                    ['C', 'D', 'C', 'C']])

    # Set the initial state and total reward to 0
    state = get_state(env)
    total_reward = 0

    while True:
        # Choose an action using epsilon-greedy policy
        if np.random.uniform(0, 1) < epsilon:
            action = np.random.choice(actions)
        else:
            action = actions[np.argmax(q_table[state])]

        # Take the action and get the next state and reward
        pos, next_state, reward = get_next_state_and_reward(env, action)

        # Update the environment and the state
        env[pos[0], pos[1]] = 'V'
        env[env == 'V'] = 'C'
        state = get_state(env)

        # Update the Q-table
        q_table[state, actions.index(action)] += alpha * (reward + gamma * np.max(
            q_table[get_state(env), :]) - q_table[state, actions.index(action)])

        # Update the total reward
        total_reward += reward

        # Check if the surrounding cells are clean
        if env[pos[0], pos[1]] == 'C':
            print("END")