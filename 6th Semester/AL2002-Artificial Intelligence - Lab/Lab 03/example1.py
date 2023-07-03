from aima3.agents import *
from aima3.notebook import psource

# Define the locations for the two-state environment
loc_A = (0, 0)
loc_B = (1, 0)

# Define a Simple Reflex Agent Program that takes action based solely on the percept


def SimpleReflexAgentProgram():
    """This agent takes action based solely on the percept. [Figure 2.10]"""
    def program(percept):
        loc, status = percept
        return ('Suck' if status == 'Dirty' else
                'Right' if loc == loc_A else
                'Left')
    return program


# Create a simple reflex agent for the two-state environment
program = SimpleReflexAgentProgram()
simple_reflex_agent = Agent(program)

# Initialize the two-state environment
trivial_vacuum_env = TrivialVacuumEnvironment()

# Check the initial state of the environment
print("State of the Environment: {}.".format(trivial_vacuum_env.status))

# Add the simple reflex agent to the environment
trivial_vacuum_env.add_thing(simple_reflex_agent)
print("SimpleReflexVacuumAgent is located at {}.".format(
    simple_reflex_agent.location))

# Run the environment for three steps
for x in range(3):
    trivial_vacuum_env.step()
    # Check the current state of the environment
    print("State of the Environment: {}.".format(trivial_vacuum_env.status))
    print("SimpleReflexVacuumAgent is located at {}.".format(
        simple_reflex_agent.location))

# Delete the previously added simple reflex agent
trivial_vacuum_env.delete_thing(simple_reflex_agent)

# Check the initial state of the environment
print("State of the Environment: {}.".format(trivial_vacuum_env.status))

# TODO: Implement this function for the two-dimensional environment


def update_state(state, action, percept, model):
    pass


# Create a model-based reflex agent for the two-state environment
model_based_reflex_agent = ModelBasedVacuumAgent()

# Add the model-based reflex agent to the environment
trivial_vacuum_env.add_thing(model_based_reflex_agent)
print("ModelBasedVacuumAgent is located at {}.".format(
    model_based_reflex_agent.location))

# Run the environment for three steps
for x in range(3):
    trivial_vacuum_env.step()
    # Check the current state of the environment
    print("State of the Environment: {}.".format(trivial_vacuum_env.status))
    print("ModelBasedVacuumAgent is located at {}.".format(
        model_based_reflex_agent.location))
