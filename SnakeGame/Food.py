import pygame
from random import randrange

class Food:
    def __init__(self, game):
        self.game = game
        self.size = game.TILE_SIZE
        self.rect = pygame.rect.Rect([0, 0, game.TILE_SIZE - 3, game.TILE_SIZE - 3])
        self.rect.center = self.game.snake.getRandomPosition()

    def draw(self):
        pygame.draw.rect(self.game.screen, 'red', self.rect)