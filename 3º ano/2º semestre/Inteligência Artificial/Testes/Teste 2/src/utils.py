import os, os.path

"""
Reads the res/levels/ directory and returns the number of levels.
A level MUST be declared sequentially, having the "level" prefix.
"""
def getNumLevels():
    DIR = '../res/puzzles'
    return len([name for name in os.listdir(DIR) if os.path.isfile(os.path.join(DIR, name))])
