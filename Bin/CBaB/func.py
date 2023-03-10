import PySimpleGUI as sg
import os
layout = [[sg.Input(), sg.Button("OK")], [sg.Button("Save"), sg.Button("Open"), sg.Button("Exit")]]
window = sg.Window("Launchpad", layout)

while True:
    event, values = window.read()
    if event == sg.WIN_CLOSED or event == "Exit":
        break
    if event == "OK":
        os.startfile(r"" + values[0])
    if event == "Save":
        with open("queries.txt", 'a') as f:
            f.write(values[0] + "\n")               
    if event == "Open":
        layout2 = [[]]
        possiblequeries = []
        with open("queries.txt", 'r') as r:
            for i in r:
                line = i.strip('\n')
                layout2[0].append(sg.Button(str(line)))
                possiblequeries.append(line)
            window2 = sg.Window("Open File", layout2)
            window.refresh()
            window2.refresh()
            while True:
                event, values = window2.read()
                if event == sg.WIN_CLOSED:
                    break
                if event in possiblequeries:
                    os.startfile(r"" + event)
            window2.close()
window.close()
