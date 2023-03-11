# Import the necessary modules
import os
import PySimpleGUI as sg
import asyncio
import subprocess
from launchpad import lpad

# Define the menus
menu_def = [
    ['&File', ['Exit']],
    ['&Run', ['Launchpad']],
]
guilayout = [[sg.Image('./wallpaper.png')], [sg.Menu(menu_def)]]

# Create the Cobalt GUI window, with the wallpaper as the background
window = sg.Window(title="Cobalt", layout=guilayout)

while True:
    event, values = window.read()
    if event == sg.WINDOW_CLOSED or event == 'Exit':
        break
    if event == 'Launchpad':
        lpad()
window.close()
