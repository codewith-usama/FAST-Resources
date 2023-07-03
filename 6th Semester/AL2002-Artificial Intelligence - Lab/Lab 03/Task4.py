import random


class Cell:
    def __init__(self, status):
        self.status = status

    def __str__(self):
        return self.status


class VacuumEnvironment:
    def __init__(self, n, m):
        self.grid = [[None for _ in range(m)] for _ in range(n)]
        self.agent_location = None
        self.status = self.get_status()

    def add_thing(self, thing, location):
        if self.grid[location[0]][location[1]] is None:
            self.grid[location[0]][location[1]] = thing
            thing.location = location
        else:
            raise Exception("Cell already occupied")

    def delete_thing(self, thing):
        self.grid[thing.location[0]][thing.location[1]] = None

    def move_agent(self, agent, location):
        if self.grid[location[0]][location[1]] is None:
            self.delete_thing(agent)
            self.add_thing(agent, location)
        else:
            raise Exception("Cell already occupied")

    def get_status(self):
        status = {}
        for i in range(len(self.grid)):
            for j in range(len(self.grid[0])):
                if self.grid[i][j] is None:
                    status[(i, j)] = "B"
                else:
                    status[(i, j)] = str(self.grid[i][j])
        return status

    def adjacent_cells(self, location):
        x, y = location
        return [(x-1, y), (x+1, y), (x, y-1), (x, y+1)]

    def is_valid_location(self, location):
        x, y = location
        return x >= 0 and x < len(self.grid) and y >= 0 and y < len(self.grid[0])

    def is_dirty(self, location):
        x, y = location
        return self.grid[x][y] is not None and self.grid[x][y].status == "D"

    def clean(self, location):
        x, y = location
        self.grid[x][y].status = "C"

    def is_goal(self):
        for i in range(len(self.grid)):
            for j in range(len(self.grid[0])):
                if self.grid[i][j] is not None and self.grid[i][j].status == "D":
                    return False
        return True

    def get_vacuum_location(self):
        return self.agent_location

    def __str__(self):
        grid_str = ""
        for i in range(len(self.grid)):
            row_str = ""
            for j in range(len(self.grid[0])):
                if self.agent_location == (i, j):
                    row_str += "V "
                else:
                    row_str += str(self.grid[i][j]) + " "
            grid_str += row_str + "\n"
        return grid_str


class ModelBasedVacuumAgent:
    def __init__(self):
        self.location = None
        self.model = None
        self.previous_action = None

    def program(self, percept):
        location, status = percept
        if self.model is None:
            self.model = {location: "U"}
            self.location = location
            return "Suck"
        else:
            self.update_model(location, status)
            if self.model[self.location] == "D":
                self.previous_action = "Suck"
                return self.previous_action
            elif self.previous_action == "Suck":
                return self.previous_action
