import pygame
from sys import exit

LENGTH = 900
WIDTH = 700
pygame.init()
screen = pygame.display.set_mode((LENGTH, WIDTH))
pygame.display.set_caption("Snake")
clock = pygame.time.Clock()
snakePosition = [100, 50]
snake_body = [[100, 50],
              [90, 50],
              [80, 50],
              [70, 50]
              ]


while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit()
    pygame.display.update()
    clock.tick(60)

