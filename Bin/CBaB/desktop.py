# Import the necessary modules
import os
import PySimpleGUI as sg
import asyncio
import subprocess
from launchpad import lpad
from arithmetic import arithmetics 

# Define the menus
menu_def = [
    ['File', ['Exit']],
    ['Run', ['Launchpad', 'Calculator']],
]
guilayout = [[sg.Image('./wallpaper.png')], [sg.Menu(menu_def)]]

# Create the Cobalt GUI window, with the wallpaper as the background
desktop = sg.Window(title="Cobalt", layout=guilayout)
while True:
    event, values = desktop.read()
    if event == sg.WINDOW_CLOSED or event == 'Exit':
        break
    if event == 'Launchpad':
        lpad()
    if event == 'Calculator':
        arithmetics()
desktop.close()

