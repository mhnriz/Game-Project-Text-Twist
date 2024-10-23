import pygame
import gfx
import random
import os

def menu():
    xpos = ypos = 0
    done = False

    while(not done):
        window.fill((1,11,19))
        gfx.text("C.Code", 1235, 625, "NotoSansGeorgian-VF")
        gfx.text("Welcome to TEXT TWIST", 350, 130, 'font/Boxy-Bold.ttf', 1, 35)

        gfx.nav_button(window, [550, 240, 200, 50], 0, "PLAY")
        gfx.nav_button(window, [550, 340, 200, 50], 0, "HELP")
        gfx.nav_button(window, [550, 440, 200, 50], 0, "EXIT")
        
        if(xpos >= 550 and xpos <= 750) and (ypos >= 240 and ypos <= 290):
            print("Start game logic")
            play_game()
        if(xpos >= 550 and xpos <= 750) and (ypos >= 340 and ypos <= 390):
            print("test")
            help()
        if(xpos >= 550 and xpos <= 750) and (ypos >= 440 and ypos <= 490):
            print("test")
            done = True
        

        xpos = ypos = 0
        for event in pygame.event.get():
            
            #INTERACTION EVENTS
            if event.type == pygame.MOUSEBUTTONDOWN:
                xpos = a
                ypos = b
            if event.type == pygame.QUIT:
                done = True
        pygame.display.flip()
        a, b = pygame.mouse.get_pos()

def help():
    pygame.draw.rect(window, (1, 11, 19), (500, 200, 400, 400),0)
    gfx.text("Instruction on How To Play.", 400, 250, "Georgia")
    gfx.text("You will be given a word.", 400, 280, "Georgia")
    gfx.text("You may guess using only the letter the word has.", 400, 310, "Georgia")
    gfx.text("The longer the word you guessed.", 400, 340, "Georgia")
    gfx.text("The more points you will achieve. GOODLUCK :).", 400, 370, "Georgia")
    gfx.text("PRESS ANYWHERE TO GO BACK", 400, 430, "Georgia")
    
    done = False
    
    while(not done):
        for event in pygame.event.get():
            if event.type == pygame.MOUSEBUTTONDOWN:
                done = True
        pygame.display.flip()

def play_game():
    game_set()

def game_set():
    fp = open("GameSets.txt")
    sel = x = random.randint(1,3)
    print(x)
    while(x > 1):
        fp.readline()
        x-=1
    gameset = fp.readline()
    print(gameset)
    wordlist(sel)

def wordlist(sel):
    for file_name in os.listdir(os.getcwd()):
        if file_name.endswith(f"{sel}.txt"):
            fp = open(file_name)
            print(f"file name: {file_name}")
    
    temp_list = string_list = [] 
    [temp_list.append(x.rstrip("\n")) for x in fp if x not in temp_list]
    print(temp_list)



pygame.init()
window = pygame.display.set_mode((1300,650))
pygame.display.set_caption("Text Twist")
menu()