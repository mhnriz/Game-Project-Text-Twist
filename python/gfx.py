import pygame

pygame.init()
window = pygame.display.set_mode((1300,650))

def text(txt, x, y, font, sel=0, size = 25):
    if sel == 1:
        font = pygame.font.Font(font, size)
    else:
        font = pygame.font.SysFont(font, size)

    txt_surf = font.render(txt, True, (255, 255, 255))
    window.blit(txt_surf, (x, y))

def nav_button(surface, rect, width, txt):
    color = (34, 40, 49)
    pygame.draw.rect(surface, color, rect, width, 10)
    text(txt, rect[0]+rect[2]/2-20*(len(txt)/4)*1.3, rect[1]+rect[3]/2-15, "Georgia")
    
