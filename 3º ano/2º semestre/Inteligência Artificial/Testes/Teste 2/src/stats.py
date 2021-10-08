import gspread
from oauth2client.service_account import ServiceAccountCredentials
from utils import getNumLevels
from npuzzle import NPuzzleGame
import time


# use creds to create a client to interact with the Google Drive API
scope = ['https://www.googleapis.com/auth/drive']
creds = ServiceAccountCredentials.from_json_keyfile_name('cred.json', scope)
client = gspread.authorize(creds)

# List of the algorithms
algorithms = ["BFS", "GS", "GS", "astar", "astar"]


for alg in range(1, len(algorithms) + 1):  # algorithm
    algorithm = algorithms[alg - 1].lower()
    sheet = client.open("npuzzle").get_worksheet(alg-1)
    for i in range(1, getNumLevels() + 1):  # level

        avg = 0
        mag = 0
        min = 99999

        for j in range(1, 8):  # number of tries

            game = NPuzzleGame("../res/puzzles/npuzzle" + str(i) + ".txt")
            start = time.time()

            if alg - 1 == 3:  # first heuristic a star
                (goalNode, numNodes) = game.solve(algorithm, "h1")
            elif alg - 1 == 4:  # second heuristic a star
                (goalNode, numNodes) = game.solve(algorithm, "h2")
            elif alg - 1 == 2:  # first heuristic greedy
                (goalNode, numNodes) = game.solve(algorithm, "h1")
            elif alg - 1 == 1:  # second heuristic greedy
                (goalNode, numNodes) = game.solve(algorithm, "h2")
            else:
                (goalNode, numNodes) = game.solve(algorithm)

            # To catch timeouts
            if goalNode == {} and numNodes == 73:
                numNodes = 0
                duration = 'TIMEOUT'
            else:
                end = time.time()
                duration = end - start
                avg = avg + duration

                if duration > mag:
                    mag = duration

                if duration < min:
                    min = duration

                solLen = len(goalNode.solution())

            x = 2 + j + 7*(i-1)

            # Update the google sheet
            if duration == 'TIMEOUT':
                sheet.update_cell(x, 5, duration)
                break

            if j == 1:
                time.sleep(1)
                sheet.update_cell(x, 2, solLen)
                time.sleep(1)
                sheet.update_cell(x, 3, numNodes)

            time.sleep(1)
            sheet.update_cell(x, 5, duration)

            if j == 7:
                time.sleep(1)
                sheet.update_cell(x-6, 6, (avg-mag-min)/5)
