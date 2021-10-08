from aima_search import Problem, breadth_first_graph_search, greedy_best_first_graph_search, astar_search
import sys
import copy

class State:
    def __init__(self, puzzle):
        self.puzzle = puzzle

    """
    Overload the == operator, comparing the content of each field.
    """

    def __eq__(self, other):
        return self.puzzle == other.puzzle

    def __lt__(self, other):
        return True

    def __hash__(self):
        return hash(repr(self))

    def distance(self, coords1, coords2):
        return (coords2[0] - coords1[0]) + (coords2[1] - coords1[1])

class NPuzzleGame:

    def __init__(self, level):
        self.state = State(readPuzzle(level))
        self.problem = NPuzzle(self.state)
    
    def move(self, action):
        self.state = self.problem.result(self.state, action)

    def displayPuzzle(self):
        for line in self.state.puzzle:
            for piece in line:
                print(piece, end=' ')
            print()
        print()

    def displaySolution(self, actions):

        self.displayPuzzle()

        for action in actions:
            self.move(action)
            print(action)
            self.displayPuzzle()

    def solve(self, algorithm, heuristic=None):

        h = h1 if heuristic == "h1" else h2

        if algorithm == "bfs":
            (goalNode, numNodes) = breadth_first_graph_search(self.problem)
        elif algorithm == "gs":
            (goalNode, numNodes) = greedy_best_first_graph_search(self.problem, h)
        elif algorithm == "astar":
            (goalNode, numNodes) = astar_search(self.problem, h)
        else:
            print("Invalid argument!")
            exit(1)
            
        return (goalNode, numNodes)



class NPuzzle(Problem):

    def __init__(self, initial, goal=None):
        """The constructor specifies the initial state, and possibly a goal
        state, if there is a unique goal. Your subclass's constructor can add
        other arguments."""
        self.initial = copy.deepcopy(initial)
        self.three_goal = [[1, 2, 3], [4, 5, 6], [7, 8, 0]]
        self.four_goal = [[1, 2, 3, 4], [5, 6, 7, 8],
                          [9, 10, 11, 12], [13, 14, 15, 0]]

    def actions(self, state):
        possibleActions = ['Up', 'Down', 'Left', 'Right']
        validActions = []

        for action in possibleActions:
            if self.validate(action, state):
                validActions.append(action)

        return validActions

    def validate(self, action, state):
        actions = ['Up', 'Down', 'Left', 'Right']
        validators = [self.validateUp, self.validateDown,
                      self.validateLeft, self.validateRight]

        return validators[actions.index(action)](state)

    def validateUp(self, state):
        length = len(state.puzzle)
        for i in range(length):
            for j in range(length):
                if state.puzzle[i][j] == 0:
                    return i > 0

    def validateDown(self, state):
        length = len(state.puzzle)
        for i in range(length):
            for j in range(length):
                if state.puzzle[i][j] == 0:
                    return i < length - 1

    def validateLeft(self, state):
        length = len(state.puzzle)
        for i in range(length):
            for j in range(length):
                if state.puzzle[i][j] == 0:
                    return j > 0

    def validateRight(self, state):
        length = len(state.puzzle)
        for i in range(length):
            for j in range(length):
                if state.puzzle[i][j] == 0:
                    return j < length - 1

    def result(self, state, action):
        possibleActions = ['Up', 'Down', 'Left', 'Right']
        changeVers = [-1, 1, 0, 0]
        changeHors = [0, 0, -1, 1]

        return self.doResult(state, changeVers[possibleActions.index(action)], changeHors[possibleActions.index(action)])

    def doResult(self, state, changeVer, changeHor):
        copyState = copy.deepcopy(state)

        length = len(state.puzzle)
        for i in range(length):
            for j in range(length):
                if state.puzzle[i][j] == 0:
                    temp = state.puzzle[i + changeVer][j + changeHor]
                    copyState.puzzle[i + changeVer][j + changeHor] = 0
                    copyState.puzzle[i][j] = temp
                    return copyState

    def goal_test(self, state):
        return state.puzzle == self.three_goal or state.puzzle == self.four_goal

    def path_cost(self, c, state1, action, state2):
        """Return the cost of a solution path that arrives at state2 from
        state1 via action, assuming cost c to get up to state1. If the problem
        is such that the path doesn't matter, this function will only look at
        state2.  If the path does matter, it will consider c and maybe state1
        and action. The default method costs 1 for every step in the path."""
        return c + 1


def readPuzzle(fileName):
    file = open(fileName, "r")
    lines = file.readlines()

    puzzle = []
    for line in lines:
        line = line.strip()
        puzzle.append([])

        numbers = line.split()

        for c in numbers:
                puzzle[-1].append(int(c))

    file.close()
    return puzzle


"""
First heuristic for the greedy and astar methods.
Number of pieces out of place
"""


def h1(node):
    puzzle = node.state.puzzle
    length = len(puzzle)

    outOfPlace = 0

    for i in range(length):
        for j in range(length):
            if i == length - 1 and j == length - 1 and puzzle[i][j] != 0:
                outOfPlace += 1
            elif puzzle[i][j] != j + 1 + i*length:
                outOfPlace += 1

    return outOfPlace


"""
Second heuristic for the greedy and astar methods.
Sum of manhattan distances from out of place pieces to their respective place
"""

def getCoordinates(puzzle, number):
    length = len(puzzle)

    if number == 0:
        return (length - 1, length - 1)

    for i in range(length):
        for j in range(length):
            if j + 1 + i*length == number:
                return (i, j)

def h2(node):
    puzzle = node.state.puzzle
    length = len(puzzle)

    distances = 0

    for i in range(length):
        for j in range(length):
            number = puzzle[i][j]
            (xPlace, yPlace) = getCoordinates(puzzle, number)

            distances += (abs((xPlace) - i) + abs(yPlace - j))

    print(distances)

    return distances
    

if __name__ == "__main__":
    game = NPuzzleGame("../res/puzzles/" + sys.argv[1])

    algorithm = sys.argv[2].lower()
    heuristic = sys.argv[3] if sys.argv == 4 else None

    if algorithm != "bfs" and len(sys.argv) != 4:
        print("Usage: " + sys.argv[0] + "<file> <algorithm> [ <heuristic> ]")
        exit(1)

    (goalNo, numNo) = game.solve(algorithm, heuristic)
    game.displaySolution(goalNo.solution())
