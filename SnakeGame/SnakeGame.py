import pygame
import sys
from random import randrange
from Snake import *
from Food import *

class Game:
    def __init__(self):
        pygame.init()
        self.WINDOW_X = 1000
        self.WINDOW_Y = 700
        self.TILE_SIZE = 50
        self.screen = pygame.display.set_mode((self.WINDOW_X, self.WINDOW_Y))
        self.clock = pygame.time.Clock()
        self.newGame()

    def drawGrid(self):
        [ pygame.draw.line(self.screen, [50] * 3, (x, 0), (x, self.WINDOW_Y)) for x in range(0, self.WINDOW_X, self.TILE_SIZE) ]
        [ pygame.draw.line(self.screen, [50] * 3, (0, y), (self.WINDOW_X, y)) for y in range(0, self.WINDOW_Y, self.TILE_SIZE) ]

    def newGame(self):
        self.snake = Snake(self)
        self.food = Food(self)

    def update(self):
        self.snake.update()
        pygame.display.flip()
        self.clock.tick(60)

    def draw(self):
        self.screen.fill('black')
        self.drawGrid()
        self.food.draw()
        self.snake.draw()

    def checkEvent(self):
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()
            self.snake.control(event)

    def run(self):
        while True:
            self.checkEvent()
            self.update()
            self.draw()


if __name__ == '__main__':
    game = Game()
    game.run()
